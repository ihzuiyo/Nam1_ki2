#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
main(){
	//in
	FILE *f_in;
	f_in = fopen("in.txt", "r");
	char s[100];
	fgets(s,100,f_in);
	s[strlen(s)-1] = '\0';
	fclose(f_in);
	//out
	FILE *f_out;
	f_out = fopen("out.txt", "w");
	fputs(s, f_out);
	fclose(f_out);
}