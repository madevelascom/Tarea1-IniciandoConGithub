#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
/* maximum input line length */
int getline2(char line[], int maxline);
void copy(char to[], char from[]);
int strlen2(char s[]);
void squeeze(char s[], int c);



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

