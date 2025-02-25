/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** command_env
*/
#include "my.h"
#include "lib.h"

int over_value_env(char *name, char *value, char **env)
{
    char *new_value = malloc(my_strlen(name) + my_strlen(value) + 2);
    int i = 0;

    if (new_value == NULL)
        return 1;
    my_strcpy(new_value, name);
    my_strcat(new_value, "=");
    my_strcat(new_value, value);
    for (; env[i]; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            env[i] = new_value;
        }
    }
    env[i] = new_value;
    env[i + 1] = NULL; 
    return 0;
}

int new_value_env(char *name, char **env)
{
    char *new_value = malloc(my_strlen(name) + 1);
    int i = 0;

    my_strcpy(new_value, name);
    my_strcat(new_value, "=");
    for (; env[i]; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            env[i] = new_value;
        }
    }
    env[i] = new_value;
    env[i + 1] = NULL; 
    return 0;
}

int my_setenv(char *name, char *value, char **env)
{
    my_uppercase(name);
    if (name != NULL || value != NULL)
        over_value_env(name, value, env);
    else new_value_env(name, env); 
    return 0;
}

int my_unsetenv(char *name, char **env)
{
    char *new_value = malloc(my_strlen(name));
    int i = 0;

    my_uppercase(name);
    my_printf("unsetenv detected\n");
    my_strcpy(new_value, name);
    my_strcat(new_value, "=");
    for (; env[i]; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            env[i] = NULL;
        }
    }
    env[i] = new_value;
    env[i + 1] = NULL; 
    return 0;
}

int my_env(char *buffer, char **env)
{
    char **argv = my_str_to_word_array(buffer);

    if (argv[2] == NULL)
        argv[2] = '\0';
    if (my_strncmp(buffer, "unsetenv", 8) == 0)
        return my_unsetenv(argv[1], env);
    else if (my_strncmp(buffer, "setenv", 6) == 0) {
        if (argv[2] != NULL)
        return my_setenv(argv[1], argv[2], env);
        else return new_value_env(argv[1], env); 
    }
    return 0;
}
