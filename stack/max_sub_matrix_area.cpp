#include <cstring>
#include <stack>
#include <iostream>
#include <algorithm>

// the following solution is similar to the problem-39
int calculate_max_rect_area(int *rect_arr, int arr_size) {
    std::cout << "start to calculate the rect of:" << std::endl;
    for (int i = 0; i < arr_size; ++i) {
        std::cout << rect_arr[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}

int cal_max_sub_matrix(int matrix[][5], int row, int column) {

    // the rect to calcualte on
    // the size of the rect are "column"
    int *rect = (int *)malloc(column);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            int rect_height = 0;
            int k = i;
            int init_val = -1;
            while (k >= 0) {
                if (init_val == -1) {
                    init_val = matrix[k][j];
                } else {
                    if (init_val != matrix[k][j]) {
                        break;
                    }
                }
                rect_height += matrix[k][j];
                // std::cout << "the rect height are " << k << "," << j << " are " << rect_height;
                --k;
            }

            rect[j] = rect_height;
        }
        calculate_max_rect_area(rect, column);
    }
    
    free(rect);
    return 0;

}

int main(int argc, char **argv) {
    int matrix[4][5] = {
        {1, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    std::cout << "start to calculate the matrix --> " << std::endl;
    int max_area = cal_max_sub_matrix(matrix, 4, 5);
    std::cout << "the max sub matrix area are " << max_area << std::endl;

    return 0;
}