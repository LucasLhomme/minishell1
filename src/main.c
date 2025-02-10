/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** main
*/
#include "lib.h"

int main(int argc, char **argv, char **env)
{
    if (argc < 1)
        return 84;
    for (int i = 0; env[i] != NULL; i++) {
     my_printf("%s\n", env[i]);
    }
    return 0;
}