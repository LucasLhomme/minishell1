/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** main
*/
#include "lib.h"
#include "my.h"

int main(int ac, char **argv, char **env)
{
    pid_t id = fork();

    if (argv == NULL || ac < 1)
        exit(84);
    if (id > 0)
        loop_terminal(env);
    else if (id == 0)
        wait(NULL);
    exit (0);
}
