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
	
	// pareil pour la fin
	/*
	int finARetirer=0;
	int i = strlen(str);
	while (i>0){		
		if (str[i] == " " || str[i] == "\t"){
			++finARetirer;
			--i;
		} else {
			// on a trouvé le dernier non espace
			i=-1;
		}		
	}
	memmove(str, str, strlen(str)-finARetirer);
	*/
	
	
	int finARetirer=0;
	int i = strlen(str)-1;
	while (i>0 && str[i] == ' '){
	//if (str[i] == ' ' || str[i] == '\t'){
	//++finARetirer;
		--i;
	//} else {
	// on a trouvé le dernier non espace
	}
	str[i+1]='\0';
	//}		
	//}
	
	//memmove(str, str, strlen(str)-finARetirer+1);
	
	
	
	// OU BIEN SI CA MERDE
	//str[strlen(str)-finARetirer]="\0";
	// mais ça merde aussi en fait
	
	return 0;
}

// supprimer les doublons d'espaces et autres à l'intérieur de la chaîne
int del_doubles_spaces(char * str){
	// tableau des espaces
	/*char mySpaces[]=" \t";
	
	// pointeur bête
	char * p;
	
	p = strstr(str,mySpaces);
	while (p != NULL){
		memmove(p, p+1, strlen(p));
		p = strstr(p,mySpaces);
	}
	*/
	
	int p;
	char* dbl;	
	
	//bool done = false;
	
	while ((dbl = strstr(str, "  ")) != NULL)
		memmove(dbl,dbl+1,strlen(dbl));
	
	return 0;
}

// découper la chaîne
// *str   --- permet de regarder le caractère à l'adresse str


int tokenize(char * str, char * tokens[], size_t max){
	printf("str contient : %s\n",str);
	
	int argv_ind = 0;
	//int i = 0;
	
	while(argv_ind < max){

		printf("debut du while\n");

		tokens[argv_ind]=str;
		
		printf("etape 1\n");

		printf("etape 1 str contient : %s\n",str);

		printf("dans tokenize : %s \n",tokens[argv_ind]);
		
		printf("str contient : %s\n",str);

		while(*str != ' ' && *str != '\0'){
			printf("on est ici\n./");
			//printf("hey %s\n",*str); test sans *
			printf("hey %s\n",str);
			++str;
		}
		
		printf("JE VEUX CETTE LIGNE\n");

		//printf("NO hey %s\n",*str);
		printf("NO hey%csi c\'est collé c\'est pas bien GROSTEST !\n",str[0]);
		
		if (*str == '\0') {
		//if (str[0] == '\0') {
			printf("ya un zero");
			tokens[argv_ind+1] = NULL;
			return 0;
		}

		printf("C\'est pas une fin du tout !\n");
		/*
		char testChar = str[0];
		printf("On a recup le caractere \"%c\"\n chaussette\n",testChar);
		printf("On a recup le caractere \"%c\"\n chaussette\n",testChar);
		printf("On a recup le caractere \"%c\"\n chaussette\n",testChar);
		printf("222mueazuibzebizfeiubezf\n");
*/
#if 1
		if(*str == ' '){
		//if(str[0] == ' '){
		//if(testChar == " "){ // et là une erreur de segmentation qui sort de nulle part
		//if(*str == ' '){
			printf("ya un espace\n");
			*str='\0';
			++str;
			++argv_ind;
		}
#endif
/*
		printf("mueazuibzebizfeiubezf\n");

		// test de toute facon si on est la c'est un espace
		printf("ya un espace\n");
		str='\0';
		++str;

		printf("etape 12000 str contient : %s\n",str);

		++argv_ind;
		printf("fin du bazar\n");
*/
	}
	
	return 0;
}







