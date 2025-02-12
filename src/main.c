/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** main
*/
#include "lib.h"
#include <unistd.h>

void cleaning_buffer(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
          if (my_strcmp(buffer[i]) == '\n')
              buffer[i] = '\0';
        }
}

void searching_bin(char *buffer, char **env)
{
    char path[256];
    char *argv[] = {buffer, NULL};

    my_strcpy(path, "/bin/");
    my_strcat(path, buffer);
    cleaning_buffer(buffer);
    printf("buffer: %s", buffer);
    printf("path: %s", path);
    printf("argv: %s", buffer);
    if (access(path, X_OK) == 0) {
        my_printf("Command found in: %s\n", path);
        execve(path, argv, env);
    } else {
        my_printf("Command not found: %s\n", buffer);
    }
}

void loop_terminal(char **env)
{
    size_t len = 0;
    char *buffer = NULL;

    while (1) {
        my_printf("$>");
        if (getline(&buffer, &len, stdin) == -1)
            break;
        my_printf("%s", buffer);
        searching_bin(buffer, env);
    }
}

int main(char **env)
{
    loop_terminal(env);
    return 0;
}
