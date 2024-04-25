// implement the post expression
#include <stack>
#include <vector>
#include <string>
#include <iostream>

int calculate(int first, int second, const std::string &token) {
    if (!token.compare("+")) {
        return first + second;
    } else if (!token.compare("-")) {
        return first - second;
    } else if (!token.compare("*")) {
        return first * second;
    } else if (!token.compare("/")) {
        return first / second;
    }
    return 100000000;
}

// for a given expression: [2, 1, 3, *, +]
// the calculate procedure are 2 + 1 * 3
int cal(std::vector<std::string> &token_list) {
    std::stack<int> cal_stack;
    int result = 0;
    for (const std::string &elem : token_list) {
        if (!elem.compare("+") || !elem.compare("-") || !elem.compare("*") || !elem.compare("/")) {
                // pop up the top 2 items, and calcualte out 
                // the result, and then push back 
                int first = cal_stack.top();
                cal_stack.pop();
                int second = cal_stack.top();
                cal_stack.pop();
                result = calculate(first, second, elem);
                cal_stack.push(result);
        } else {
                // this is for integer case, the element are 
                // integer
                int val = std::stoi(elem);
                cal_stack.push(val);
        }
    }
    return result;

}

int main(int argc, char **argv) {
    std::vector<std::string> expression;
    // the expression are [2, 1, 3, *, +]
    expression.push_back(std::string{"2"});
    expression.push_back(std::string{"1"});
    expression.push_back(std::string{"3"});
    expression.push_back(std::string{"*"});
    expression.push_back(std::string{"+"});

    int result = cal(expression);
    std::cout << "the calculate result are " << result << std::endl;
    return 0;
}