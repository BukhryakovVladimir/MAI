#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <sys/wait.h>
#include <signal.h>

void onCtrlC(int signal)
{
    pid_t pid = getpid(); // pid текущего процесса (terminal)
    kill(pid, SIGTERM);   // kill terminal
}
int main()
{
    signal(SIGINT, onCtrlC);
    std::string find, arg = "";
    std::getline(std::cin, find);

    if (find[3] == ' ')
    {
        for (int i = 4; i < find.length(); i++)
            arg += find[i];
        find = "cat";
    }

    char *arg_char = new char[arg.length() + 1];

    // copying the contents of the
    // string to char array
    strcpy(arg_char, arg.c_str());

    if (fork() == 0)
        wait(0);
    else
    {
        if (find == "ls")
            execlp("/bin/ls", "ls", (char *)NULL);
        if (find == "cat")
            execlp("/bin/cat", "cat", arg_char, (char *)NULL);
    }
    return 0;
}