/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** command_cd
*/
#include "my.h"
#include "lib.h"
#include <errno.h>

void verify_buffer(char *path, char **current)
{
    if (!path || my_strcmp(path, "") == 0) {
        free(*current);
        *current = NULL;
        return;
    }
}

void prev_cd(char *buffer)
{
    cleaning_buffer(buffer);
    chdir(buffer);
}

int change_directory(char *path, char *current, char **prev)
{
    if (my_strncmp(path, "cd", 2) == 0)
        return 0;
    if (my_strcmp(path, "-") == 0) {
        prev_cd(*prev);
        free(*prev);
        *prev = current;
        return 0;
    }
    if (chdir(path) != 0) {
        if (errno == ENOTDIR)
            my_printf("%s: Not a directory.\n", path);
        else
            my_printf("%s: No such file or directory.\n", path);
        free(current);
        return 1;
    }
    if (*prev)
        free(*prev);
    *prev = current;
    return 0;
}

char *find_env(char *path, char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            path = env[i] + 5;
            break;
            }
        }
        return path;
}

int my_cd(char *buffer, char **env)
{
    static char *prev = NULL;
    char *path = strtok(buffer, " ");
    char *current = getcwd(NULL, 0);

    path = strtok(NULL, " ");
    if (!path || my_strcmp(path, "") == 0) {
        path = find_env(path, env);
        if (!path) {
            free(current);
            return 0;
        }
    }
    verify_buffer(path, &current);
    cleaning_buffer(path);
    return change_directory(path, current, &prev);
}
