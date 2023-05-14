#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <sys/wait.h>

int main()
{
    std::string find;
    std::getline(std::cin, find);

    char *find_char = new char[find.length() + 1];

    // copying the contents of the
    // string to char array
    strcpy(find_char, find.c_str());

    if (fork() == 0)
        wait(0);
    else
        execlp("/bin/cat", "cat", find_char, (char *)NULL);
    return 0;
}