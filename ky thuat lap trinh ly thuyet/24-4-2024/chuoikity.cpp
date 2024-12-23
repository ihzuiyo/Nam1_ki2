//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//// chuoi ky tu // strcmp , strcat, strcpy, strncpy , strncat
//main(){
//	int a = 5;
//	char *s1 = (char*)malloc(6);
//	int b = 10;
//	printf("Nhap s: ");
//	fgets(s1,20,stdin);
//	int l = strlen(s1); // hello\n co 0 1 2 3 4 5 6 ki tu
//	s1[l-1] = '\0'; // doi ki tu o vi tri thu 6-1 == '\0'
//	strcpy(s1,"Happy New Year!");
//	int a = 5;
//	char *s1 = (char*)malloc(6);
//	int b = 10;
//	printf("Nhap s: ");
//	fgets(s1,20,stdin);
//	int l = strlen(s1); // hello\n co 0 1 2 3 4 5 6 ki tu
//	s1[l-1] = '\0'; // doi ki tu o vi tri thu 6-1 == '\0'
//	printf("%d\n",strcmp(s1,"Hello"));
//	printf("%d %d %s\n",a,b,s1);
//	char res[40];
//	char name[] = "Nam";
//	int age = 20;
//	float mark = 8;
//	int len = sprintf(res, "%s ",name);
//	len += sprintf(&res[len], "%d ",age);
//	len += sprintf(&res[len], "%f ",mark);
//	printf("%s\n",res);
//}