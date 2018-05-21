#ifndef EXEC_H
#define EXEC_H

#include <string.h>
#include <stdio.h>
#include "parser.h"

#define MAX_CMD_SIZE 1024
#define MAX_ARGS 256
#define MAX_PATH_SIZE 256

int search_path(char * filename, char * path);

typedef struct {
	char path[MAX_PATH_SIZE];
	char * argv[MAX_ARGS];
} command_t;

int exec_command(command_t * cmd);

int make_commands(char * str, command_t * cmds, int max_cmds);


#endif
