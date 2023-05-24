#ifndef _MAIN_
#define _MAIN_

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TOK_BUFSIZE 128
#define BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

/* Points an array of pointers to strings called  "environment" */
external char **environ;

/**
 *   struct data - Struct that contains relevant data on a runtime
 *   @status: last status of the shell
 *   @av: argument vector
 *   @input: command line written by the user
 *   @counter: lines counter
 *   @_environ: environment variable
 *   @pid: process ID of the shell
 *   @args: tokens of the command line
 */
typedef struct data
{
	char *input;
	char **av;
	char *pid;
	char **_environ;
	char **args;
	int status;
	int counter;
} data_shell;

/**
 * struct sep_list_s - Single linked list
 * @separator: & ; |
 * @next: next node
 * Description: Single linked list that store separators
 */
typedef struct sep_list_s
{
	struct sep_list_s *next;
	char separator;
} sep_list;

/**
 * struct line_list_s - Single linked list
 * @next: next node
 * @line: command line
 * Description: single linked list to store the command
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct builtin_s - Builtin struct for args.
 * @f: datatypepointer.
 * @name: Name of the command builtin.
 */
typedef struct builtin_s
{
	char *name;
	int (data_shell)(*f);
} builtin_t;

/**
 * struct r_var_list - Single linked list
 * @next: Next node
 * @leng_var: length of variable
 * @leng_val: Length of value
 * @val: Variable value
 */
typedef struct r_var_list
{
	int leng_var;
	int leng-val;
	char *val;
	struct r_var_list *next;
} r_var;

/* aux_lists.c */
void free_line_list(line_list **head);
void free_sep_list(sep_list **head);
sep_list *add_sep_node_end(sep_list **head, char sep);
line_list *add_line_node_end(line_list **head, char *line);

/* aux_lists2.c */
void free_rvar_list(r_var **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);

/* aux_str functions */
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);

/* aux_mem.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
char *_strdup(const char *s);

/* aux_str3.c */
void rev_string(char *s);

/* check_syntax_error.c */
int check_syntax_error(data_shell *datash, char *input);
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int first_char(char *input, int *i);

/* read_line.c */
char *read_line(int *i_eof);

/* shell_loop.c */
void shell_loop(data_shell *datash);
char *without_comment(char *in);

/* rep_var.c */
int check_vars(r_var **h, char *st, char *in, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);
void check_env(r_var **h, char *in, data_shell *data);

/* split.c */
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);

/* get_line.c */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);

/* exec_line */
int exec_line(data_shell *datash);

/* env2.c */
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);
void set_env(char *name, char *value, data_shell *datash);
char *copy_info(char *name, char *value);

/* cd_shell.c */
int cd_shell(data_shell *datash);

/* env1.c */
int _env(data_shell *datash);
char *_getenv(const char *name, char **_environ);

/* cmd_exec.c */
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);
int is_cdir(char *path, int *i);

/* cd.c */
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_dot(data_shell *datash);
void cd_to_home(data_shell *datash);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *datash);

/* _exit.c */
int exit_shell(data_shell *datash);

/* aux_stdlib.c */
int _atoi(char *s);
int get_leng(int n);
char *aux_itoa(int n);

/* aux_error1.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);
char *error_get_cd(data_shell *datash);

/* aux_error2.c */
char *error_permission(char **args);
char *error_path_126(data_shell *datash);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_get_alias(char **args);

/* get_sigint.c */
void get_sigint(int sig);

/* get_error.c */
int get_error(data_shell *datash, int eval);

/* aux_help.c */
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help_env(void);

/* aux_help2.c */
void aux_help_cd(void);
void aux_help(void);
void aux_help_alias(void);

/* get_help.c */
int get_help(data_shell *datash);

#endif



