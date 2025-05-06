#include <stdio.h>

int main(int argc, char **argv, char *envp[])
{
    if (argc == 0 || !argv[0])
        return 0;

    int i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    return 0;
}
