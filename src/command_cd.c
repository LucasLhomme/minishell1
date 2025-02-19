/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** command_cd
*/
#include "my.h"
#include "lib.h"

void prev_cd(char *buffer, char **env)
{

}

void my_cd(char *buffer, char **env)
{
    static char *prev = NULL;
    char *path = strtok(buffer, " ");
    char *current = getcwd(NULL, 0);

    if (!current) {
        perror("getcwd");
        return;
    }
    path = strtok(NULL, " ");
    cleaning_buffer(path);
    if (!path || my_strcmp(path, "") == 0) {
        free(current);
        return;
    }
    if (my_strcmp(path, "-") == 0) {
        prev_cd(prev, env);
    } else if (chdir(path) != 0) {
        perror("cd");
        free(current);
        return;
    } else {
        if (prev)
            free(prev);
        prev = current;
    }
    my_printf("%s\n", current);
}
