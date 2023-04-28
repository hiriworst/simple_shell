#ifndef _MAIN_H_
#define _MAIN_H_
#define SUPER_USER 2080

#define Space_locate 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
void find_env(char **environ);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);

void *_my_func_works(unsigned int new_num, unsigned int what_to_ptr);

void *_number_func(unsigned int token, unsigned int lenth_of_token);


int exefork(char **bftoken, int goesin, char **environ);
int _putchar(char c);
char **linetoken(char *linea, char **env);
char **findpath(char **environ);
char **usepath(char *fpat);
int _stat(char **bftoken, char **pat);

#endif /* MAIN_H */
