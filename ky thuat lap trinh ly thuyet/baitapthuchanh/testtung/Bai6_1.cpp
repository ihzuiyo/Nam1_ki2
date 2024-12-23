#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void nhap(FILE **file, float **mt, int *m, int *n);
void xuat(float *mt, int m, int n);
float *tbcduonghangle(float *mt, int m, int n);
float findMinDUong(float *mt, int m, int n);

int main(){
    FILE *in;
    float *mt;
    int m, n;
    nhap(&in, &mt, &m, &n);
    xuat(mt, m, n);
    float *sum = tbcduonghangle(mt, m, n);
    if(sum[1]==0){
        printf("\nKhong co phan tu nao co gia tri duong ma thuoc hang le cua ma tran\n");
    }
    else{
        printf("\nTBC cac phan tu co gia tri duong ma thuoc cac hang le cua ma tran la: %.2f\n", sum[0]/sum[1]);
    }    
}

void nhap(FILE **file, float **mt, int *m, int *n){
    char tenfile[100];
    fgets(tenfile, 100, stdin);
    tenfile[strlen(tenfile)-1]='\0';
    //gets(tenfile);
    *file = fopen(tenfile, "r");
    fscanf(*file ,"%d%d", m , n);
    *mt = (float*)malloc((*m)*(*n)*sizeof(float));
    for(int i  = 0; i < *m;  i++){
        for(int j = 0; j < *n; j++){
            fscanf(*file ,"%f", *mt+i*(*m)+j);
        }
    }
    fclose(*file);
}

void xuat(float *mt, int m, int n){
    printf("Ma tran ban vua nhap la:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j  < n; j++){
            printf("%.2f ", *(mt+i*m+j));
        }
        printf("\n");
    }
}

float *tbcduonghangle(float *mt, int m, int n){
    float *sum = (float*)malloc(2);
    for(int i = 0; i < n; i++){
        sum[i]=0;
    }
    for(int i = 0; i < m; i+=2){
        for(int j = 0; j < n; j++){
            if(*(mt+i*m+j) > 0){
               sum[0] += *(mt+i*m+j);
               sum[1] ++; 
            }
        }
    }
    return sum;
}

float findMinDUong(float *mt, int m, int n){
    float check = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(*(mt+i*m+j)>0){
                check = *(mt+i*m+j);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(*(mt+i*m+j)>0 && *(mt+i*m+j)>check){
                check = *(mt+i*m+j);
            }
        }
    }
    return check;
}