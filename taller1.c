#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
/* maximum input line length */
int getline2(char line[], int maxline);
void copy(char to[], char from[]);
int strlen2(char s[]);
void squeeze(char s[], int c);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	if (max > 0) { /* there was a line */
		char entrada = '1';
		char longestcopy[MAXLINE];
		copy(longestcopy, longest);

		printf("Maxima Cadena: %s\n\n", longest);
		while (entrada != '3'){
			
			printf("=============== MENU ==============\n");
			printf("1.- Eliminar el caracter 'e' de la cadena. \n"); 
		  	printf("2.- Hallar longitud de la cadena maxima. \n"); 
		  	printf("3.- Salir - \n");
			printf("Ingresa una opcion: ");
			fflush(stdin);
			scanf(" %c", &entrada);
	  		if (entrada == '1'){
				squeeze(longest, 'e'); 
				printf("\nMaxima Cadena sin caracter e: %s\n", longest);
		  	} else if (entrada == '2'){ 
				printf("\nLongitud de maxima cadena: %d\n", strlen2(longestcopy));				
	  		}
		}
	} return 0;
}

/* getline: read a line into s, return length*/
int getline2(char s[],int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

/* strlen: return length of s */
int strlen2(char s[])
{
	int i;
	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

