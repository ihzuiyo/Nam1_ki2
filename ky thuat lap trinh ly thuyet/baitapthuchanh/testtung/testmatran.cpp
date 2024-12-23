#include <stdio.h>

#define M 4 // Số hàng của ma trận
#define N 4 // Số cột của ma trận

int sumAboveAntiDiagonal(int matrix[M][N], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + j < cols - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int matrix[M][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int result = sumAboveAntiDiagonal(matrix, M, N);
    printf("Tổng các phần tử nằm trên đường chéo phụ: %d\n", result);

    return 0;
}