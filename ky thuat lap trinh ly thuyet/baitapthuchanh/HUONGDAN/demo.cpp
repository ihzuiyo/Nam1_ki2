#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Point{
    float x,y;
} Point;

void read_input(Point **p, int *n){
    char filename[30];
    printf("Nhap ten file:");
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d", n);
    *p = (Point*)malloc(*n*sizeof(Point));
    for(int i=0; i<*n; i++){
        fscanf(f, "%f%f", &(*p+i)->x, &(*p+i)->y);
    }
    fclose(f);
}

float kc(Point p){
    return sqrt(p.x*p.x+p.y*p.y);
}

void print(Point p){
    printf("(%.2f;%.2f)", p.x, p.y);
}

int doixung(Point p1, Point p2){
    if(p1.x+p2.x==0 && p1.y+p2.y==0)
        return 1;
    return 0;
}

int dem1(Point *p, int n){
    int d=0;
    for(int i=0; i<n; i++){
        if(kc(*(p+i)) < 5){
            d++;
        }
    }
    return d;
}

int dem2(Point *p, int n){
    int d=0;
    for(int i=0; i<n; i++){
        if(kc(*(p+i)) > 5){
            d++;
        }
    }
    return d;
}

void capdoixung(Point *p, int n){
    int check = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(doixung(*(p+i), *(p+j))){
                print(*(p+i));
                print(*(p+j));
                printf("\n");
                check = 1;
            }
        }
    }
    if(check==0){
        printf("Khong co cap nao\n");
    }
}

int main(){
    int n;
    Point *p;
    read_input(&p, &n);
    printf("Co %d diem nam ben trong drong tron\n", dem1(p,n));
    printf("Co %d diem nam ben ngoai drong tron\n", dem2(p,n));
    printf("Cac cap doi xung la:\n");
    capdoixung(p,n);
}