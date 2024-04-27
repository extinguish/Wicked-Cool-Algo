#include <cstdint>
#include <iostream>
#include <stack>
#include <algorithm>

// calculate the max array with the given rect set
int cal_max_area(int *rect_arr, size_t rect_count) {
    std::cout << "to calcualte the max array with count " << rect_count << std::endl;

    std::stack<int> rect_stack;
    // put an initial -1 into the stack in order to
    // indicate the end of the stack
    rect_stack.push_back(-1);

    int max_area = 0;
    for (int i = 0; i < rect_count; ++i) {
        while (stack.top() != -1 && rect_arr[stack.top()] >= rect_arr[i]) {
            int height = rect_arr[stack.top()];
            stack.pop();
            int width = i - stack.top() - 1;
            max_area = std::max(max_area, height * width);
        }
        stack.push(i);
    }

    

}

int main(int argc, char **argv) {
    int rect_arr[8] = {3, 2, 5, 4, 6, 1, 4, 2};
    int area = cal_max_area(rect_arr, sizeof(rect_arr) / sizeof(int));

    return 0;
}