#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int ch_dir(char **args);
int printenv(char **args);
int _exitt(char **args);
void update_dir(char *pwd);
typedef struct builtin
{
	char *name;
	int (*func)(char **);
} builtins_t;

extern builtins_t built_ins[];
extern char **environ;
void _prompt(int argc, char **argv);
char *read_input();
void free_args(char **argv);
void signal_handler(int signum);
int execute(int ac, char **args);
char **tokenize(char *buffer);
char *_strtok(char *str, char *delim);
char *_strstr(char *haystack, char *needle);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *path_handler(char **argv);

#endif
