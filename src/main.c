/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-lucas.lhomme
** File description:
** main
*/
#include "lib.h"
#include <unistd.h>

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg) ;
        my_putchar('\n') ;
        arg++;
    }
    return;
}

int main(int argc, char **argv, char **env)
{
    if (argc <= 1)
        return 84;
    /*
    // ouvre le fichier env
    for (int i = 0; env[i] != NULL; i++)
     my_printf("%s\n", env[i]);
    */
   for (int i = 0; i != '\0'; i++) {
    char **args = my_str_to_word_array(argv[i]);
   }
    print_arg(argv);
    return 0;
}