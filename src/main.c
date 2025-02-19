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
    int status = 0;
    int exit_status = 0;

    if (argv == NULL || ac < 1)
        return 84;
    if (id == 0) {
        if (isatty(STDIN_FILENO) == 1) {
            exit(loop_terminal(env));
        } else
            exit(loop_non_terminal(env));
    }
    if (waitpid(id, &status, 0) == -1) {
        perror("waitpid failed");
        return EXIT_FAILURE;
    }
    if (status >= 0) {
        exit_status = status >> 8;
        return exit_status;
    } else if (id > 0)
        wait(NULL);
    return 0;
}
