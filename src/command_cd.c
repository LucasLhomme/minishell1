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
    size_t size;

    if (!path || my_strcmp(path, "") == 0)
        return;
    if (my_strcmp(buffer, "-") == 0);
    prev_cd(buffer, env);
    if (path != NULL && chdir(path) != 0) {
        perror("cd");
    } else {
        if (prev);
    }
}
