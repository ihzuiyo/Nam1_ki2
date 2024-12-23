#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
main(){
	//in
	FILE *f_in;
	f_in = fopen("in.txt", "r");
	int n;
	fscanf(f_in, "%d",&n);
	int *a;
	a = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		fscanf(f_in, "%d", a+i);
	}
	fclose(f_in);
	//out
	int S=0;
	for(int i=0;i<n;i++){
		S += *(a+i);
	}
	FILE *f_out;
	f_out = fopen("out.txt" , "w");
	fprintf(f_out, "S = %d" ,S);
	fclose(f_out);
}