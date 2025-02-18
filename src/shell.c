/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** shell function
*/
#include "my.h"
#include "lib.h"

int loop_terminal(char **env)
{
    size_t len = 0;
    ssize_t read;
    char *buffer = NULL;

    while (1) {
        my_printf("$>");
        read = getline(&buffer, &len, stdin);
        if (read == -1) {
            free(buffer);
            my_printf("\nexit\n");
        }
        if (my_strcmp(buffer, "\n") != 0) {
            hand_command(buffer, env);
        }
    }
}
