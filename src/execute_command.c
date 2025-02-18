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
    if (buffer == NULL)
        return cleaning_buffer;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    return buffer;
}

void searching_bin(char *buffer, char **env)
{
    char *path = malloc(sizeof(char *) + 1);
    char **argv = my_str_to_word_array(buffer);

    if (!argv[0])
        return;
    my_strcpy(path, "/bin/");
    my_strcat(path, argv[0]);
    cleaning_buffer(path);
    if (access(path, X_OK) == 0) {
        if (fork() == 0) {
            execve(path, argv, env);
            perror(execve);
        }
        wait(NULL);
    } else
        my_printf("command not found: %s\n", argv[0]);
}
void hand_command(char *buffer, char **env)
{
    if (my_strncmp(buffer, "cd", 2) == 0)
        my_cd(buffer, env);
    else
        searching_bin(buffer, env);
}
