#include "exec.h"
#include <stdbool.h>
#include <stdlib.h>

int search_path(char * filename, char * path) {
	// /usr/bin:/bin:/usr/local/bin
	char * env_path = getenv("PATH");
	
	// si $PATH non définie
	if(env_path == NULL) return 1;

	/*
	 * strchr(str, c)
	 * -> renvoie un pointeur sur le premier c de str
	 * strchr(env_path,':');
	 * 
	*/

	while ( env_path != NULL ){
		char * fin = strchr(env_path, ':');
		
		// on vérifie si on est à la fin de la chaîne
		if (fin == NULL){
			fin = strchr(env_path, '\0');
		}
		
		strncpy(path,env_path,fin - env_path);
		// strncpy n'ajoute pas de \0, faut en mettre un
		// faut aussi ajouter le / en fin de chemin pour son ajout dans l'exécution (e.g. pour pas avoir binls mais bin/ls)
		path[fin - env_path]='/';
		path[fin - env_path + 1]='\0';
		strcat(path, filename);
		
		if (*fin == '\0') env_path = NULL;
		else env_path=fin+1;
		
		FILE * f;
		f = fopen(path,"r");
		
		if (f != NULL) {
			fclose(f);
			return 0;
		}
	}
	
	return -1;
	
}

int make_commands(char * str, command_t * cmds, int max_cmds){
	
	int cmd_idx=0, argv_idx=0;
	
	trim(str);
	printf("-%s-\n",str);
	
	
	del_doubles_spaces(str);
	printf("-%s-\n",str);
	
	char *argv[MAX_ARGS];
	
	tokenize(str, argv, MAX_ARGS);
	
	for (int xx = 0; argv[xx] != NULL; ++xx)
		printf("--- %s\n",argv[xx]);
	
	
	
	for (int i=0; argv[i]!=NULL && cmd_idx < max_cmds; ++i){
		
		printf("on est dans le for %d pour %s\n",i,argv[i]);
		
		// plein de if à transformer en une fonction qui gère tous
		// les marqueurs de fin de commande
		if (strcmp(argv[i], ";") == 0){
			
			printf("point-virgule trouvé");
			
			/*
			 * terminer le tableau argv de la commande n°cmd_idx par NULL
			 * chercher le chemin de l'executable
			 * augmenter le compteur cmd_idx
			 * s'il y a une erreur (commande_introuvable) on renvoie -1
			 * réinitialiser argv_idx à 0
			 */
			cmds[cmd_idx].argv[argv_idx]=NULL;
					
			if(search_path(cmds[cmd_idx].argv[0], cmds[cmd_idx].path)!=0){
				return -1;
			}
			
			printf("commande : -%s-\n",cmds[cmd_idx].argv[0]);
					
			
			++cmd_idx;
			argv_idx=0;
			
			continue;
		}
		
		#if 0
		if (strcmp(argv[i], ">") == 0) {
			char* output = argv[i+1];
			cmds[cmd_idx].stdout= open(output, O_WRONLY |
				O_CREAT | O_TRUNC);
			++i;
			
			cmds[cmd_idx].argv[argv_idx]=NULL;
			
			/*
			 * compléter
			 * */
			
			continue;
		}
		
		#endif
		
		
		
		cmds[cmd_idx].argv[argv_idx] = argv[i];
		++argv_idx;
	
	}
	
	// on renvoie le nombre de commandes qu'on a réussi à faire
	return cmd_idx+1;
}









