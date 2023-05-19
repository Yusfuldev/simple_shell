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
void printenv(void);
char *path_handler(char **argv);

#endif
