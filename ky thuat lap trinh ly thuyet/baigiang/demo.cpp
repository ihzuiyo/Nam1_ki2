#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap(int **a, int *n);
void in(const int *a, int n);
float tbc(const int *a, int n);
int ptcln(const int *a, int n);
int kiemtra(const int *a, int n);

int main(){
    int *a;
    int n;
    nhap(&a, &n);
    in(a,n);
    printf("TBC = %f\n", tbc(a,n));
    int tmp = ptcln(a,n);
    if(tmp%2==0){
        printf("Pt chan lon nhat: %d\n", tmp);
    } else {
        printf("Khong co pt chan nao\n");
    }
    if(kiemtra(a,n)){
        printf("Ma tran tam giac duoi\n");
    } else {
        printf("Khong phai ma tran tam giac duoi\n");
    }
}

void nhap(int **a, int *n){
    printf("Nhap n:");
    scanf("%d", n);
    int m = *n;
    *a = (int*)malloc(m*m*sizeof(int));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            printf("Nhap a[%d][%d]:", i, j);
            scanf("%d", *a+i*m+j);
        }
    }
}

void in(const int *a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%6d", *(a+i*n+j));
        }
        printf("\n");
    }
}

float tbc(const int *a, int n){
    int S = 0;
    for(int i=0; i<n; i++){
        S += *(a+i*n+i);
    }
    return (float)S/n;
}

int ptcln(const int *a, int n){
    if(n<=1){
        return 1;
    }
    int max = *(a+1);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((*(a+i*n+j)>max && *(a+i*n+j)%2==0) || max%2!=0){
                max = *(a+i*n+j);
            }
        }
    }
    return max;
}

int kiemtra(const int *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(*(a+i*n+j)!=0){
                return 0;
            }
        }
    }
    return 1;
}