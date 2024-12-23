#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char Sach[100];
    char Tacgia[100];
    int nam;
}Sach;

void nhap(Sach **sach, int *n);
void xuat(const Sach *sachs, int n);
void findbooks(const Sach *sachs, int n, char s[100]);
int cmp(const void *a, const void *b);

int main(){
    Sach *sachs;
    int n;
    nhap(&sachs, &n);
    xuat(sachs, n);
    char s[100];
    findbooks(sachs, n, s);
    qsort(sachs, n, sizeof(Sach), cmp);
    printf("\n");
    printf("Danh sach cac sach xuat ban truoc nam 2000 la:\n");
    for(int i = 0; i < n; i++){
        if((sachs+i)->nam < 2000){
            printf("|%15s|%15s|%15d|\n", (sachs+i)->Sach, (sachs+i)->Tacgia, (sachs+i)->nam);
        }
    }
}

void nhap(Sach **sach, int *n){
    printf("Nhap so luong quyen sach: ");
    scanf("%d", n);
    sach = (Sach*)malloc((*n)*sizeof(Sach));
    for(int i = 0; i < *n; i++){
        fflush(stdin);
        printf("\nNhap quyen sach thu %d:\n", i+1);
        printf("Nhap ten sach: ");
        fgets((*sach+i)->Sach, 100, stdin);
        (*sach+i)->Sach[strlen((*sach+i)->Sach)-1]='\0';
        fflush(stdin);
        printf("Nhap ten tac gia: ");
        fgets((*sach+i)->Tacgia, 100, stdin);
        (*sach+i)->Tacgia[strlen((*sach+i)->Tacgia)-1]='\0';
        printf("Nhap nam: ");
        scanf("%d", &(*sach+i)->nam);
    }
}

void xuat(const Sach *sachs, int n){
    printf("Nhung quyen sach ban vua nhap la:\n");
    for(int i = 0; i < n; i++){ 
        printf("|%15s|%15s|%15d|\n", (sachs+i)->Sach, (sachs+i)->Tacgia, (sachs+i)->nam);
    }   
}

void findbooks(const Sach *sachs, int n, char s[100]){
    fflush(stdin);
    printf("Nhap ten quyen sach ban muon tim: ");
    int check = 0;
    fgets(s, 100, stdin);
    s[strlen(s)-1] = '\0';
    for(int i = 0; i < n; i++){
        if(strcmp((sachs+i)->Sach,s)==0){
            check = 1;
            printf("|%15s|%15s|%15d|\n", (sachs+i)->Sach, (sachs+i)->Tacgia, (sachs+i)->nam);
        }
    }
    if(check == 0){
        printf("\nKhong co quyen sach nao co ten nhu vay\n");
    }
}

int cmp(const void *a, const void *b){
    Sach *sach1 = (Sach *)a;
    Sach *sach2 = (Sach *)b;
    return sach1->nam - sach2->nam;
}
