#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024

#define USE_GETLINE 0
#define USE_STRTOK 0

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define BUF_FLUSH -1
#define CMD_NORM 0
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096
#define CMD_CHAIN 3
#define CMD_OR 1
#define CMD_AND 2
#define INFO_INIT                                                               \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}

extern char **environ;
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;	  /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int print_charfd(char c, int fd);
int set_alias(info_t *info, char *str);
int print_input(char *str, int fd);
int alias_print(list_t *node);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
int exit_shell(info_t *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
int change_cd(info_t *);
int help_call(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);
void free_list(list_t **);
size_t list_length(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
char **split_to_words2(char *, char *);
char **split_to_words(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int free_p(void **);
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int error_atoi(char *);
void print_error(info_t *, char *);
int print_digit(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
ssize_t get_input(info_t *);
int get_line(info_t *, char **, size_t *);
void block_cc(int);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *get_env(info_t *, const char *);
int myenv(info_t *);
int myset_env(info_t *);
int create_hitory(info_t *info);
int read_history(info_t *info);
int myremove_env(info_t *);
int populate_env_list(info_t *);
char **get_envi(info_t *);
int remove_env(info_t *, char *);
int set_env(info_t *, char *, char *);
char *get_history_file(info_t *info);
int add_history(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
list_t *add_node_start(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int is_cmd(info_t *, char *);
char *duplicate_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int loophsh(char **);
void print_instr(char *);
int delete_node_at_index(list_t **, unsigned int);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
int shell_main(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int write_chatrr(char);

#endif
