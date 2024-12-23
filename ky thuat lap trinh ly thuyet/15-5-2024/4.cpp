#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
main(){
	//in
	FILE *f_in;
	FILE *f_out;
	char buffer[1000];
	f_in = fopen("file.zip", "rb");
	f_out = fopen("out.zip", "wb");
	while(fread(buffer, 1, 1000, f_in)){
		fwrite(buffer,1,1000,f_out);
	}
	fclose(f_in);
	fclose(f_out);
}