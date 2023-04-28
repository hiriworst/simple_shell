

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

extern char **environ;

/**
 * struct linkedList - linked list data structure
 * @string: environ variable path name
 * @next: pointer to next node
 */
typedef struct linkedList
{
	char *string;
	struct linkedList *next;
} linked_l;

/**
 * struct configurations - configuration of data settings
 * @env: linked list of local env variables
 * @env_list: array of env variables to put into execve
 * @args: array of argument strings
 * @buffer: string buffer of user input
 * @path: array of $PATH locations
 * @full_path: string of path with correct prepended $PATH
 * @shell_name: name of shell (argv[0])
 * @count_line: counter of lines users have entered
 * @error_status: error status of last child process
 */
typedef struct configurations
{
	linked_l *env;
	char **env_list;
	char **args;
	char *buffer;
	char *path;
	char *full_path;
	char *shell_name;
	unsigned int count_line;
	int error_status;
} config;

/**
 * struct builtInCommands - commands and functions associated with it
 * @command: input command
 * @func: output function
 */
typedef struct builtInCommands
{
	char *command;
	int (*func)(config *data);
} type_b;

/* --- main --- */
config *initialize(config *data);

_Bool builts_commands(config *data);
int exit_function(config *data);
int history_function(config *data);
int alias_function(config *data);

int count_args(char **args);
int _atoi(char *s);

int implement_cd(config *);
_Bool cd_to_home(config *data);
_Bool cd_to_previous(config *data);
_Bool cd_to_custom(config *data);
_Bool update_environ(config *data);

int update_old(config *data);
_Bool update_cur_dir(config *data, int index);

int env_function(config *data);
int set_env_func(config *data);
int unset_env_func(config *data);
int is_alpha(int c);

int help_function(config *data);
int display_help_menu(void);
int help_guide_exit(config *data);
int help_env(config *data);
int help_history(config *data);

int help_alias(config *data);
int help_cd(config *data);

int help_set_env(config *data);
int help_unset_env(config *data);
int help_guide(config *data);

void main_unix(config *data);
void line_value(config *data);
void find_child_exec(config *data);
void _commments(char *str);
void list_ptr_ar(config *data);

char *_getenv(char *input, char **environ);

void handle_errors(config *data);
unsigned int count_num_digits(int num);
char *itoa(unsigned int num);
char *get_error_message();

void null_bytes(char *str, unsigned int index);
void get_prompt(void);
void put_new_line(void);
void init_manage(int sigint);

void free_member(config *data);
void free_args_and_buffer(config *data);
void free_args(char **args);
void free_list(linked_l *head);

_Bool split_string(config *data);
unsigned int count_words(char *s);
_Bool is_space(char c);

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

_Bool check_path(config *);
_Bool validate_constraints(config *data);


linked_l *add_node_to_front(linked_l **head, char *str);
linked_l *add_node_to_end(linked_l **head, char *str);
size_t print_list(const linked_l *h);
int search_node(linked_l *head, char *str);
size_t list_len(linked_l *h);

int delete_node_at_index(linked_l **head, unsigned int index);
linked_l *generateLinkedList(char **array);
linked_l *add_node_at_index(linked_l **head, int index, char *str);
char *get_node_at_index(linked_l *head, unsigned int index);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* MAIN_H */

