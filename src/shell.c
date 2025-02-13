/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** shell function
*/
#include "my.h"
#include "lib.h"

void loop_terminal(char **env)
{
    size_t len = 0;
    char *buffer = NULL;

    while (1) {
        my_printf("$>");
        if (getline(&buffer, &len, stdin) == -1)
            break;
        if (buffer == NULL)
            exit(84);
        my_printf("%s", buffer);
        searching_bin(buffer, env);
    }
}
