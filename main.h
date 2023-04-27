#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/cdefs.h>




#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133

extern char **environ;




typedef struct __attribute__((__packed__))
{
	int argc;                 
	char **argv;              
	int mode;                 
	int error_code;          
	char *command;            
	int n_commands;           
	char *value_path;         
	int now_working;      
	int status_code;          
	char *buffer;            
	char **arguments;         
	char *environment;        
	int pid;                  
} functi_comm_global;

typedef struct __attribute__((__packed__))
{
	char *message;           
	int code;                
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;            /* arguments[0] = cmd */
	void (*func)(functi_comm_global *data, char **arguments);
} func_gen_struct_fil_name;



void check_dif(char **arguments, functi_comm_global *data, char *buff);

int is_executable(char *filename);
int is_file(char *command);

char *command_env(const char *name);
char *specific_elem(char *filename, functi_comm_global *data);
void now_working(char *path, functi_comm_global *data);
void whole_env(void);

void fun(char *commands, char **arguments, functi_comm_global *data, char *buff);
int fol_cur(char *cmd, char **arguments, char *buff,
		functi_comm_global *data);

        int local_func_command(functi_comm_global *data, char **arguments);
int func_read_d(functi_comm_global *data, char **arguments);

void quit(functi_comm_global *data, char **arguments);
int num_elem_data(functi_comm_global *data, char *number);

void environment_bin(functi_comm_global *data, char **arguments);

void bin_echo(functi_comm_global *data, char **arguments);
void echo_printer(int index, char *text, char **arguments);


char *information_user_send(functi_comm_global data);
void faulty(functi_comm_global *data);
void any_faulty_found_outside(functi_comm_global *data, char *exceed);






void start(functi_comm_global *data);



void *_realloc(void *ptr, size_t old_size, size_t new_size);

void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);






/* text.c */
void start_prompt(functi_comm_global *data);
void prompt(functi_comm_global *data);
char *read_prompt();
void sigintHandler(int sig_num);

/* utils_text.c */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

/* utils_text2.c */
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/* printers_out.c */
int _putchar(char c);
int print(char *msg);

int print_err(char *msg);

char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* patterns.c */
void analyze_patterns(functi_comm_global *data, char **arguments);
char *pattern_handler(functi_comm_global *data, char *string);
char *replace_value(functi_comm_global *data, int *index, char *string);

/* patterns_replacer.c */
char *replacement(functi_comm_global *data, int *index, char *string);
char *envrionment_replace(functi_comm_global *data, char *environment);


#endif /* MAIN_H */

