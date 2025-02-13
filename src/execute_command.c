/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** execute command
*/
#include "my.h"
#include "lib.h"

char *cleaning_buffer(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    return buffer;
}

void searching_bin(char *buffer, char **env)
{
    char *path = malloc(sizeof(char *) + 1);
    char **argv = {NULL};

    my_strcpy(path, "/bin/");
    my_strcat(path, buffer);
    cleaning_buffer(path);
    if (access(path, X_OK) == 0) {
        execve(path, argv, env);
        my_printf("Command found in: %s\n", path);
    } else {
        my_printf("Command not found: %s\n", buffer);
    }
}
