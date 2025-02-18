/*
** EPITECH PROJECT, 2024
** Mon H
** File description:
** Header avec les fonctions
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
char *cleaning_buffer(char *buffer);
int searching_bin(char *buffer, char **env);
int loop_terminal(char **env);
int hand_command(char *buffer, char **env);
void my_cd(char *command, char **env);

#endif /* MY_H_ */
