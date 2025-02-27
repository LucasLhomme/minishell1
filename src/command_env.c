/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** command_env
*/
#include "my.h"
#include "lib.h"

int print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        printf("%s\n", env[i]);
    return 0;
}

int my_setenv(char *name, char *value, char **env)
{
    if (name != NULL || value != NULL)
        over_value_env(name, value, env);
    else
        new_value_env(name, env);
    return 0;
}

int my_env(char *buffer, char **env)
{
    char **argv = my_str_to_word_array(buffer);

    if (argv[2] == NULL)
        argv[2] = '\0';
    if (my_strncmp(buffer, "unsetenv", 8) == 0)
        return my_unsetenv(argv[1], env);
    if (my_strncmp(buffer, "env", 3) == 0)
        return print_env(env);
    if (my_strncmp(buffer, "setenv", 6) == 0) {
        if (argv[2] != NULL)
            return my_setenv(argv[1], argv[2], env);
        else
            return new_value_env(argv[1], env);
    }
    return 0;
}
