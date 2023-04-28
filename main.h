#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

extern char **environ;

char *show_input(void);
void prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
void place(char *str);
char *findfile(char *command);
char *com_fun_struc(char *command);
int compare(char *fast_string, char *second_string);
int _strcmpdir(char *fast_string, char *second_string);
int charput(char c);
void place(char *str);
char *str_concat(char *fast_string, char *second_string);
int code_identifiar(char *first_str);
int differentiate_func(char *fast_string, char *second_string);
int compareEnv(char *fast_string, char *second_string);
void program_run(char **first_str);
char **search_str(char *argumnt);
void fun_cont(int no_stop);

#endif
