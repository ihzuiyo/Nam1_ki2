#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Sach{
    char ten[30];
    char tacgia[30];
    int nam;
}Sach;

void read_input(Sach **p, int *n){
    char filename[] = "input.txt";
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d", n);
    *p = (Sach*)malloc(*n*sizeof(Sach));
    for(int i=0; i<*n; i++){
        fgetc(f);
        fgets((*p+i)->ten, 30, f);
        (*p+i)->ten[strlen((*p+i)->ten)-1] = '\0';
        fgets((*p+i)->tacgia, 30, f);
        (*p+i)->tacgia[strlen((*p+i)->tacgia)-1] = '\0';
        fscanf(f, "%d", &(*p+i)->nam);
    }
    fclose(f);
}

void print(Sach *p, int n){
    if(p->nam >=2000){
        printf("Khong co quyen nao truoc nam 2000\n");
        return;
    }
    for(int i=0; i<n; i++){
        if((p+i)->nam<2000)
            printf("%s - %s - %d\n", (p+i)->ten, (p+i)->tacgia, (p+i)->nam);
    }
}

void print_file(Sach *p, int n){
    FILE *f = fopen("output.txt", "w");
    if(p->nam >=2000){
        fprintf(f, "Khong co quyen nao truoc nam 2000\n");
        return;
    }
    for(int i=0; i<n; i++){
        if((p+i)->nam<2000)
            fprintf(f, "%s - %s - %d\n", (p+i)->ten, (p+i)->tacgia, (p+i)->nam);
    }
    fclose(f);
}

void tim(Sach *p, int n){
    char ten[30];
    printf("Nhap ten sach muon tim:");
    fgets(ten, 30, stdin);
    ten[strlen(ten)-1] = '\0';
    for(int i=0; i<n; i++){
        if(strcmp(ten, (p+i)->ten) == 0){
            printf("%s - %s - %d\n", (p+i)->ten, (p+i)->tacgia, (p+i)->nam);
            return;
        }
    }
    printf("Khong tim thay quyen sach nay\n");
}

int cmp(const void* a, const void* b){
    Sach *p1 = (Sach*)a;
    Sach *p2 = (Sach*)b;
    return p1->nam - p2->nam;
}

int main(){
    int n;
    Sach *p;
    read_input(&p, &n);
    tim(p,n);
    qsort(p, n, sizeof(Sach), cmp);
    printf("Danh sach sach xb truoc 2000, da sap xep:\n");
    print(p,n);
    print_file(p,n);
}