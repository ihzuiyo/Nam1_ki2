#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
main(){
	//in
	FILE *f_in;
	f_in = fopen("in.txt", "r");
	int *a;
	int n=0;
	int tmp;
	while(fscanf(f_in, "%d", &tmp) != EOF){
		n++;
	}
	fclose(f_in);
	f_in = fopen("in.txt","r");
	a = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f_in,"%d",a+i);
	}
	
	fclose(f_in);
	//out
	int S = 0;
	for(int i=0;i<n;i++){
		S+= a[i];
	}
	printf("S = %d\n",S);
	
}