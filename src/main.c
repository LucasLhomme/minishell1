/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** main
*/
#include "lib.h"
#include <unistd.h>

void searching_bin(char *cmd, char **env)
{
    char path[256];
    char *argv[] = {cmd, NULL};

    my_strcpy(path, "/bin/");
    my_strcat(path, cmd);
    my_printf("/bin/%s\n", cmd);
    if (access(path, X_OK) == 0) {
        my_printf("Command found in: %s\n", path);
        execve(path, argv, env);
    } else {
        my_printf("Command not found: %s\n", cmd);
    }
}

int main(int argc, char **argv, char **env)
{
    char **tab = my_str_to_word_array(argv[1]);
    if (argc <= 1 || argv[1] == NULL)
        return 84;
    if (tab == NULL || tab[0] == NULL)
        return 84;
    searching_bin(tab[0], env);
    return 0;
}
