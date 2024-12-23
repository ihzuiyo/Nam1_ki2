#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
// bai nao cung phai co nhap va xuat
// dạng bài điểm tọa độ X,Y - Danh sách (nhân viên,thư viện...) dùng typedef struct

//cau 1
//Dạng nhập 1: tên tệp nhập từ bàn phím
// *(p+i)->x = p[i].x (thể hiện giá trị của biến đấy)
// (*p+i)->x là địa chỉ của biến đấy
typedef struct Diem{
	float x,y;
};
void nhap(Diem **diem,int *n){ // HÀM NÀY NHẬN VIỆC NHẬP DỮ LIỆU CỦA FILE (CÂU NÀO CŨNG CÓ HÀM NHẬP BẤT KỂ DẠNG BÀI)
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename); // nhập tên tệp từ bàn phím
	FILE *f = fopen(filename , "r");
	fscanf(f ,"%d",n); // nhập n từ tệp sẵn có
	*diem = (Diem*)malloc( (*n) * sizeof(Diem));
	for(int i=0;i<*n;i++){
		fscanf(f, "%f %f", &(*diem+i)->x, &(*diem+i)->y); //nhập điểm x và y từ file (đọc dữ liệu)
	}
	printf("\n");
	fclose(f);	
}
void xuat(Diem *diem,int n){ //(Kiểm tra) Xuất các giá trị được hàm nhập đọc vào chương trình (tùy bài có hay không nhưng tốt nhất là nên có)
	printf("Danh sach cac diem la: \n");
	for(int i=0;i<n;i++){
		printf("(%.2f ; %.2f) ",(diem+i)->x ,(diem+i)->y);
	}
	printf("\n");
}
float kc(Diem *diem){ // Hàm tính khoảng cách của 1 điểm x,y (nó có thể dùng lại nhiều lần)
	return sqrt(diem->x * diem->x + diem->y * diem->y); // căn của x bình + y bình = khoảng cách của điểm đấy từ tâm tọa độ
}
void demxembaonhieudiemnamtrongnamngoai(Diem *diem,int n){ //a va b
	int dtrong = 0; // int = %d float = %f
	int dngoai = 0;
	for(int i=0;i<n;i++){
		if(kc(diem+i) > 5){ //nếu khoảng cách của điểm i > 5 thì điểm nằm ngoài có thêm 1 điểm
			dngoai +=1;
		}
		if(kc(diem+i) < 5){ //nếu khoảng cách của điểm i < 5 thì điểm nằm trong có thêm 1 điểm
			dtrong +=1;
		}
//		if(kc(diem+i) == 5){ điểm nằm bên trên đường tròn
//	
//		}
	}
	printf("Co %d diem nam ben ngoai duong tron\n",dngoai);
	printf("Co %d diem nam ben trong duong tron\n",dtrong);
	
}
float timdoixung(Diem diem1,Diem diem2){ //Khai báo biến struct diem1 và diem2 để so sánh có đối xứng không(2 điểm này nằm trong file dữ liệu)
	if(diem1.x+diem2.x==0 && diem1.y+diem2.y==0){
        return 1; //2 điểm đấy đối xứng nhau thì nó trả về 1 (Tương đương với giá trị TRUE ở trong kiểu dữ liệu Bool)
    }
    return 0; //2 điểm này không đối xứng nhau thì nó sẽ trả về 0 (FALSE)
}
void doixung(Diem *diem,int n){
	//đối xứng là x = -x ; y = -y
    int check = 0; //biến này để kiểm tra xem có cặp đối xứng nào không
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(timdoixung(*(diem+i), *(diem+j))){ //gọi hàm timdoixung ở trên để kiểm tra 2 điểm i và j có đối xứng nhau ko?
                printf("(%.2f ; %.2f) va (%.2f ; %.2f)",(diem+i)->x,(diem+i)->y,(diem+j)->x,(diem+j)->y);
                printf("\n");
                check = 1;
            }
        }
    }
    if(check==0){
        printf("Khong co cap nao\n"); //nếu check = 0 thì ko có cặp nào
    }
}
main(){
	int n; //khai báo n
	Diem *diem; //khai báo biến của struct
	nhap(&diem,&n);
	xuat(diem,n);
	demxembaonhieudiemnamtrongnamngoai(diem,n);
	printf("Cac cap doi xung nhau la: \n");
	doixung(diem,n);
}