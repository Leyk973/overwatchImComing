#include "parser.h"


// supprimer les espaces avant et après la chaîne
int trim(char * str){
	// supprimer les espaces/tabulations au début et à la fin de str
	// "   a   bcd	 	" => "a   bcd"
	
	char mySpaces[] = " \t";
	
	// trouver le début de la chaîne sans espaces précédents
	int posDeb = strspn (str, mySpaces);
	
	// copier
	// +1 pour copier le \0 de fin
	memmove(str,str+posDeb,strlen(str+posDeb)+1);
	
	
	int finARetirer=0;
	int i = strlen(str)-1;
	while (i>0 && str[i] == ' '){
		--i;
	}
	str[i+1]='\0';
	
	return 0;
}

// supprimer les doublons d'espaces et autres à l'intérieur de la chaîne
int del_doubles_spaces(char * str){
	
	int p;
	char* dbl;
	
	while ((dbl = strstr(str, "  ")) != NULL)
		memmove(dbl,dbl+1,strlen(dbl));
	
	return 0;
}

// découper la chaîne
// *str   --- permet de regarder le caractère à l'adresse str


int tokenize(char * str, char * tokens[], size_t max){
	printf("str contient : %s\n",str);
	
	int argv_ind = 0;
	
	while(argv_ind < max){
		tokens[argv_ind]=str;

		while(*str != ' ' && *str != '\0'){
			printf("on est ici\n./");
			printf("hey %s\n",str);
			++str;
		}
		
		if (*str == '\0') {
			printf("ya un zero");
			tokens[argv_ind+1] = NULL;
			return 0;
		}

		if(*str == ' '){
			printf("ya un espace\n");
			*str='\0';
			++str;
			++argv_ind;
		}

	}
	
	return 0;
}







