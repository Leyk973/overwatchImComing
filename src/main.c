#include <stdio.h>
#include "parser.h"
#include "exec.h"

// pour recompiler, se mettre dans build et faire make

int main (int argc, char * argv[]){
	printf("Hello world chaussette !\n");
	
	// dupliquer la chaine constante
	//
	
	
	
	
	#if 1
	char * str = strdup("   bonjour    je mets des   espaces      ");
	printf("-%s-\n",str);
	
	trim(str);
	printf("-%s-\n",str);
	
	del_doubles_spaces(str);
	printf("-%s-\n",str);
	
	

	printf("la chaine str : %s\n", str);
	char * mestokens[MAX_ARGS];
	tokenize(str, mestokens, MAX_ARGS);

	printf("arrive apres tokenize\n");

	for (int xx = 0; mestokens[xx] != NULL; ++xx)
		printf("--- %s\n",mestokens[xx]);
	
	char path[MAX_PATH_SIZE];
	
	search_path("ls",path);
	
	printf("path : %s\n", path);
	
	#endif
	
	#if 0
	char * str = strdup(" ls -l   ; ps    waux   ");
	printf("-%s-\n",str);
	command_t myCommands[MAX_ARGS];
	
	make_commands(str,myCommands,MAX_CMD_SIZE);
	
	#endif
	
	return 0;
}
