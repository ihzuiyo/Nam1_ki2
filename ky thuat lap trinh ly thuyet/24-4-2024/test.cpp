#include<stdio.h>
#include<String.h>
main(){
//	printf("%s","Hello\0World\n");
//	char s1[] = "Hello\0World\n";
//	printf("%s",&s1[6]);
//	char s2[20];
//	strcpy(s2,s1);
//	printf("%s",s2);
//	char *ptr = s;
//	printf("%s\n",ptr + ptr[3] - ptr[1]);
	char s[] = "CNTT2 - K64 - 2023/2024";
	char *ptr = s;
	printf("%s\n",ptr + ptr[3] - ptr[1]);
}