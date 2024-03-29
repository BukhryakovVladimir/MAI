#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <cstring>

using namespace std;

class Zipper
{

private:
    vector<string> files; // набор файлов (-files)
    string path;          // путь (-path)
    string real_bin_file; // имя выходного файла-архива( используется при архивации )
public:
    Zipper(vector<string> &vec, string p)
    {
        if (vec.size() > 0)
            files.assign(vec.begin(), vec.end());
        path = p + "/";
        real_bin_file = path + "binary.zipper";
    }

    void getInfo();                  // Метод для получения информации о файлах на этапе архивации
    void InCompress();               // Архивация данных
    void OutCompress(string binary); // Распаковка данных ( binary - путь до архива )

    // Статический метод для выделения имени файла из полного пути.
    // Используется для внутренних нужд.
    static string get_file_name(string fn) { return fn.substr(fn.find_last_of("/") + 1, fn.size()); }
};

int digs(double w)
{
    int yield = 0;
    while (w > 10)
    {
        yield++;
        w /= 10;
    }
    return yield + 1;
}

void Zipper::InCompress()
{
    char byte[1]; // единичный буфер для считывания одного байта

    getInfo(); // получаем необходимую информацию о том, что архивируем

    FILE *f;
    FILE *main = fopen((this->real_bin_file).c_str(), "wb");     // файл - архив
    FILE *info = fopen((this->path + "info.txt").c_str(), "rb"); // файл с информацией

    // переписываем информацию в архив
    while (!feof(info))
    {
        if (fread(byte, 1, 1, info) == 1)
            fwrite(byte, 1, 1, main);
    }

    fclose(info);
    remove((this->path + "info.txt").c_str()); // прибираемся за собой

    // последовательная запись в архив архивируемых файлов побайтно :
    for (vector<string>::iterator itr = this->files.begin(); itr != this->files.end(); ++itr)
    {
        f = fopen((*itr).c_str(), "rb");
        if (!f)
        {
            cout << *itr << " не найден!" << endl;
            break;
        }
        while (!feof(f))
        {
            if (fread(byte, 1, 1, f) == 1)
                fwrite(byte, 1, 1, main);
        }
        cout << *itr << " добавлен в архив '" << this->real_bin_file << endl;
        fclose(f);
    }
    fclose(main);
}

void Zipper::getInfo()
{
    char byte[1]; // единичный буфер для считывания одного байта

    basic_string<char> s_info = "";
    remove((this->path + "info.txt").c_str());                   // на всякий случай
    FILE *info = fopen((this->path + "info.txt").c_str(), "a+"); // сохраняем информацию в наш текстовый файл
    int bytes_size = 0;                                          // длина информационного блока в байтах
    for (vector<string>::iterator itr = this->files.begin(); itr != this->files.end(); ++itr)
    {
        FILE *f = fopen((*itr).c_str(), "rb");
        if (!f)
            break;

        // получаем размер архивируемого файла
        fseek(f, 0, SEEK_END);
        int size = ftell(f);

        string name = Zipper::get_file_name(*itr); // получаем имя архивируемого файла

        char *m_size = new char[digs(size)];
        sprintf(m_size, "%d", size);
        fclose(f);

        bytes_size += digs(size);
        bytes_size += strlen(name.c_str());

        // все, что "нарыли", сохраняем в промежуточный буфер :
        s_info.append(m_size);
        s_info.append("||");
        s_info.append(name);
        s_info.append("||");

        delete[] m_size;
    }
    bytes_size = s_info.size() + 2;
    char *b_buff = new char[digs(bytes_size)];
    sprintf(b_buff, "%d", bytes_size);

    // форматируем до 5 байт
    if (digs(bytes_size) < 5)
        fputs(string(5 - digs(bytes_size), '0').c_str(), info);

    fputs(b_buff, info);
    fputs("||", info);
    fputs(s_info.c_str(), info);

    fclose(info);
}

void Zipper::OutCompress(string binary)
{
    FILE *bin = fopen(binary.c_str(), "rb"); // открываем архив в режиме чтения
    char info_block_size[5];                 // размер информационного блока
    fread(info_block_size, 1, 5, bin);       // получаем размер
    int _sz = atoi(info_block_size);         // преобразуем буфер в число

    char *info_block = new char[_sz]; // информационный блок
    fread(info_block, 1, _sz, bin);   // считываем его

    // Парсинг информационного блока :
    vector<string> tokens;
    char *tok = strtok(info_block, "||");
    int toks = 0;
    while (tok)
    {
        if (strlen(tok) == 0)
            break;
        tokens.push_back(tok);
        tok = strtok(NULL, "||");
        toks++;
    }

    if (toks % 2 == 1)
        toks--;           // удаляем мусор
    int files = toks / 2; // количество обнаруженных файлов в архиве

    char byte[1]; // единичный буфер для считывания одного байта

    // Процесс распаковки всех файлов( по правилам полученным из блока с информацией ) :
    for (int i = 0; i < files; i++)
    {
        const char *size = tokens[i * 2].c_str();
        const char *name = tokens[i * 2 + 1].c_str();
        char full_path[255];
        strcpy(full_path, this->path.c_str());
        strcat(full_path, name);
        int _sz = atoi(size);
        cout << "--  '" << name << "' извлечен в '" << this->path << endl;
        FILE *curr = fopen(full_path, "wb");
        for (int r = 1; r <= _sz; r++)
        {
            if (fread(byte, 1, 1, bin) == 1)
                fwrite(byte, 1, 1, curr);
        }
        fclose(curr);

        delete[] size;
        delete[] name;
    }
    fclose(bin);
}

int main(int argv, char *argc[])
{
    /*/  Supported args:
    //
    //    -pack, -unpack, -files, -path
    //
    /*/

    setlocale(LC_ALL, "Russian");
    cout << endl
         << "######################## ZIPPER ########################" << endl
         << endl;
    if (argv > 1)
    {
        vector<string> files;                    // массив файлов, переданных через параметры из консоли
        string path = "";                        // путь
        bool flag_fs = false, flag_path = false; // флаги режима чтения/записи
        char type[7];                            // тип: упаковка или распаковка
        memset(type, 0, 7);

        for (int i = 1; i < argv; i++)
        {
            if (strcmp(argc[i], "-pack") == 0)
            {
                strcpy(type, "pack");
                flag_fs = flag_path = false;
            }
            if (strcmp(argc[i], "-unpack") == 0)
            {
                strcpy(type, "unpack");
                flag_fs = flag_path = false;
            }
            if (strcmp(argc[i], "-path") == 0)
            {
                flag_path = true;
                flag_fs = false;
                continue;
            }
            if (strcmp(argc[i], "-files") == 0)
            {
                flag_fs = true;
                flag_path = false;
                continue;
            }

            if (flag_path)
            {
                path.assign(argc[i]);
            }
            if (flag_fs)
                files.push_back(string(argc[i]));
        }
        Zipper *zip = new Zipper(files, path);
        if (strcmp(type, "pack") == 0)
            zip->InCompress();
        if (strcmp(type, "unpack") == 0)
            zip->OutCompress(files[0]);
    }
    else
        cout << "Параметры -pack/-unpack , -files, -path обязательны!" << endl;
    cout << endl
         << "########################################################" << endl
         << endl;
}