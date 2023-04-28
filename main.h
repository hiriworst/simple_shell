#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strcmp(char *str_len, char *str_ptr);
char *_strcpy(char *ptr_where_to, char *ptr_len);
char *get_path_location(char *command);
void *_calloc(unsigned int input_arr, unsigned int size);
void _var_location(void);
int run_func(char **args);
int line_free(char *buff);
char **_split(char *str, char *take_out);
char *_strcat(char *ptr_where_to, char *ptr_len);
int _strlen(char *str);
char *_capture(char *ptr_var);

extern char **environ;

#endif
