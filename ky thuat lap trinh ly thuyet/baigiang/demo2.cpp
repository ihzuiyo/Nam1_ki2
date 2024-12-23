#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct SV{
    char ht[30];
    int d;
    char t;
} SV;

void nhap(SV **a, int *n);
void in(const SV *a, int n);
void truongdiemcao(const SV *a, int n);
void SVdiemcao(const SV *a, int n);
int cmp(const void *a, const void *b);

int main(){
    SV *a;
    int n;
    nhap(&a, &n);
    in(a,n);
    truongdiemcao(a,n);
    SVdiemcao(a,n);
    qsort(a, n, sizeof(SV), cmp);
    printf("\n");
    in(a,n);
}

void nhap(SV **a, int *n){
    printf("Nhap n:");
    scanf("%d", n);
    int m = *n;
    *a = (SV*)malloc(m*sizeof(SV));
    for(int i=0; i<m; i++){
        fflush(stdin);
        printf("Nhap ho ten:");
        fgets((*a+i)->ht, 30, stdin);
        (*a+i)->ht[strlen((*a+i)->ht)-1] = '\0';
        printf("Nhap diem:");
        scanf("%d", &(*a+i)->d);
        fflush(stdin);
        printf("Nhap truong:");
        scanf("%c", &(*a+i)->t);
    }
}

void in(const SV *a, int n){
    for(int i=0; i<n; i++){
        printf("%s - %d - %c\n", (a+i)->ht, (a+i)->d, (a+i)->t);
    }
}

void truongdiemcao(const SV *a, int n){
    int tong[] = {0,0,0,0};
    for(int i=0; i<n; i++){
        tong[(a+i)->t - 'A'] += (a+i)->d;
    }
    int max = tong[0];
    for(int i=0; i<4; i++){
        if(tong[i]>max){
            max = tong[i];
        }
    }
    printf("Truong co tong diem cao nhat:");
    for(int i=0; i<4; i++){
        if(tong[i] == max){
            printf("%c ", 'A'+i);
        }
    }
    printf("\n");
}

void SVdiemcao(const SV *a, int n){
    int max = a->d;
    for(int i=0; i<n; i++){
        if((a+i)->d>max){
            max = (a+i)->d;
        }
    }
    printf("SV co tong diem cao nhat:");
    for(int i=0; i<n; i++){
        if((a+i)->d==max){
            printf("\n%s", (a+i)->ht);
        }
    }
}

int cmp(const void *a, const void *b){
    SV *sv1 = (SV*)a;
    SV *sv2 = (SV*)b;
    if(strcmp(sv1->ht, sv2->ht) == 0){
        return sv1->d - sv2->d;
    }
    return strcmp(sv1->ht, sv2->ht);
}