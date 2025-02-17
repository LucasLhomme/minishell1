/*
** EPITECH PROJECT, 2024
** Mon H
** File description:
** Header avec les fonctions
*/

#include <unistd.h>
#include <sys/wait.h>

#ifndef MY_H_
    #define MY_H_
char *cleaning_buffer(char *buffer);
void searching_bin(char *buffer, char **env);
void loop_terminal(char **env);
void hand_command(char *buffer, char **env);
void my_cd(char *buffer, char **env);

#endif /* MY_H_ */
