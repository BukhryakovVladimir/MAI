#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <sys/wait.h>
#include <cmath>
#include <string>

std::string RandomString(int ch)
{
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                      'h', 'i', 'j', 'k', 'l', 'm', 'n',
                      'o', 'p', 'q', 'r', 's', 't', 'u',
                      'v', 'w', 'x', 'y', 'z'};
    std::string result = "";
    for (int i = 0; i < ch; i++)
        result = result + alpha[rand() % 26];

    return result;
}

std::string xorStrings(std::string a, std::string b)
{
    std::string s = "";
    // use the longer of the two words to calculate the length of the result
    for (int i = 0; i < std::max(a.length(), b.length()); i++)
    {
        // append the result of the char from the code-point that results from
        // XORing the char codes (or 0 if one string is too short)
        s += a[i] ^ b[i];
    }

    return s;
};

std::string stream_as_string(std::istream &stm)
{
    std::string str;
    char c;
    while (stm.get(c))
        str += c;
    return str;
}

int main()
{
    std::string find;
    std::getline(std::cin, find);

    std::ifstream in(find);
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string data = stream_as_string(in);

    std::string random_string;
    char choice;
    do
    {
        std::cout << "Create new random string?(Y/n)\n";
        std::cin >> choice;
        choice = tolower(choice);
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y')
    {
        random_string = RandomString(buffer.str().length());

        std::ofstream rand("random.txt");
        rand << random_string;
        rand.close();
    }
    else
    {
        std::ifstream random("random.txt");
        random_string = stream_as_string(random);
    }

    std::string result = xorStrings(data, random_string);
    std::ofstream res("output.txt");
    res << result;
    res.close();
    return 0;
}