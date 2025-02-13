/*
** EPITECH PROJECT, 2024
** Mon H
** File description:
** Header avec les fonctions
*/

#include <unistd.h>
#include <sys/wait.h>

#ifndef MY_H
    #define MY_H
char *cleaning_buffer(char *buffer);
void searching_bin(char *buffer, char **env);
void loop_terminal(char **env);

#endif MY_H
