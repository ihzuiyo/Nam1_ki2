#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct{
    char tendoi;
    int sobanthang;
    int sobanthua;
    int sodiem;
}DOIBONG;

void nhap(FILE **file, DOIBONG **doibong, int *n){
    char ten_chu_nha, ten_khach;
    int diem_chu_nha, diem_khach;
    *doibong = (DOIBONG*)malloc(4*sizeof(DOIBONG));
    for(int i = 0; i < 4; i++){
        ((*doibong+i)->tendoi) = 'A'+i;
        (*doibong+i)->sobanthang = 0;
        (*doibong+i)->sobanthua = 0;
        (*doibong+i)->sodiem = 0;
        // (*doibong)[i].tendoi = 'A'+i;
        // (*doibong)[i].sobanthang= 0;
        // (*doibong)[i].sobanthua = 0;
        // (*doibong)[i].sodiem =0;
    }
    char filename[100];
    printf("Nhap ten file: ");
    // gets(filename);
    fgets(filename, 100, stdin);
    filename[strlen(filename)-1]='\0';
    *file = fopen(filename, "r");
    fscanf(*file, "%d ", n);
    for(int i = 0; i < *n; i++){
        fscanf(*file ,"%c ", &ten_chu_nha);
        fscanf(*file, "%c ", &ten_khach);
        fscanf(*file, "%d ", &diem_chu_nha);
        fscanf(*file , "%d ", &diem_khach);
        (*doibong+(ten_chu_nha-'A'))->sobanthang+=diem_chu_nha;
        (*doibong+(ten_khach-'A'))->sobanthang+=diem_khach;
        (*doibong+(ten_chu_nha-'A'))->sobanthua+=diem_khach;
        (*doibong+(ten_khach-'A'))->sobanthua+=diem_chu_nha;
        if(diem_chu_nha>diem_khach){
            (*doibong+(ten_chu_nha-'A'))->sodiem += 3;
        }
        else if(diem_khach>diem_chu_nha){
            (*doibong + (ten_khach-'A'))->sodiem+=3;
        }
        else{
            (*doibong+(ten_chu_nha-'A'))->sodiem += 1;
            (*doibong + (ten_khach-'A'))->sodiem +=1;
        }
    }
    // printf("YES");
    fclose(*file);
}
void diemmax(DOIBONG *doibong){
    int max = (doibong)->sodiem;
    for(int i = 0 ; i < 4; i++){
        if((doibong+i)->sodiem > max){
            max = (doibong+i)->sodiem;
        }
    }
    printf("Doi bong dang dan dau la:\n");
    for(int i = 0; i < 4; i++){
        if((doibong+i)->sodiem==max){
            printf("%c ", 'A'+i);
        }
    }
}
void xuatfile(FILE **file, DOIBONG *doibong, int n){
    *file = fopen("output2.txt", "w");
    fprintf(*file ,"Doi bong ban vua nhap la:\n");
    for(int i = 0; i < 4; i++){
        fprintf(*file ,"%c %d %d %d\n", (doibong+i)->tendoi, (doibong+i)->sodiem, (doibong+i)->sobanthang, (doibong+i)->sobanthua);
    }
    fclose(*file);
}
int main(){
    FILE *in, *out;
    DOIBONG *doibong; 
    int n;
    nhap(&in, &doibong, &n);
    diemmax(doibong);
    xuatfile(&out, doibong, n);
}