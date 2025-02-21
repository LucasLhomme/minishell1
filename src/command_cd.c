/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** command_cd
*/
#include "my.h"
#include "lib.h"

void verify_buffer(char *path, char *current)
{
    if (!path || my_strcmp(path, "") == 0) {
        free(current);
        current = NULL;
        return;
    }
}

void prev_cd(char *buffer)
{
    cleaning_buffer(buffer);
    chdir(buffer);
}

void change_directory(char *path, char *current, char **prev)
{
    if (my_strncmp(path, "cd", 2) == 0)
        return;
    if (my_strcmp(path, "-") == 0) {
        prev_cd(*prev);
        free(*prev);
        *prev = current;
        return;
    }
    if (chdir(path) != 0) {
        perror("cd");
        free(current);
        return;
    }
    if (*prev)
        free(*prev);
    *prev = current;
}

int my_cd(char *buffer, char **env)
{
    static char *prev = NULL;
    char *path = strtok(buffer, " ");
    char *current = getcwd(NULL, 0);

    (void)env;
    path = strtok(NULL, " ");
    if (!path || my_strcmp(path, "") == 0) {
        free(current);
        return 1;
    }
    verify_buffer(path, current);
    cleaning_buffer(path);
    change_directory(path, current, &prev);
    return 0;
}
