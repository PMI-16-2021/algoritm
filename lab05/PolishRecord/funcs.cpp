#include "funcs.h"
#include "stack.h"
#include <cmath>

const int pr_size = 6;

std::pair<char, int> priorities[pr_size] {
        {'^', 0},
        {'(', 1},
        {'*', 2},
        {'/', 2},
        {'+', 3},
        {'-', 3}
};

int GetPrior(const char& action){
    for(int i = 0; i < pr_size; ++i) {
        if(action == priorities[i].first){
            return priorities[i].second;
        }
    }
    return -1;
}

bool isDigit(const char& c) {
    return c >= '0' && c <= '9';
}

bool isOperator(const char& c){
    for(int i = 0; i < pr_size; ++i) {
        if(c == priorities[i].first){
            return true;
        }
    }
    return false;
}

std::string PolishRecord(std::string& notation) {
    std::string output;
    Stack<char> stack;
    for(int i = 0; i < notation.length(); i++){
        if(isDigit(notation[i])){  // if current char is digit
            while(isDigit(notation[i+1]) && i < notation.length()){  // if number is multi-digit
                output += notation[i];   // add current char
                ++i;   // go to the next
            }
            output += notation[i];  // add last digit char
            output += '_';   // divisor between  numbers
        }
        else if(notation[i] == '(') {
            stack.Push(notation[i]);
        }
        else if(notation[i] == ')') {
            while(stack.Top() != '(') {
                output += stack.Pop();
            }
            stack.Pop();
        }
        else if(isOperator(notation[i])){
            if(stack.IsEmpty()) {
                stack.Push(notation[i]);
                continue;
            }
            else if(GetPrior(notation[i]) < GetPrior(stack.Top())) {
                stack.Push(notation[i]);
            }
            else if(GetPrior(notation[i]) >= GetPrior(stack.Top())) {
                while(!stack.IsEmpty() && (GetPrior(notation[i]) >= GetPrior(stack.Top())  && stack.Top() != '(')) {
                    output += stack.Pop();
                }
                stack.Push(notation[i]);
            }
        }
        else {
            std::cerr << notation[i] << " is invalid character.\n";
        }
    }
    while(!stack.IsEmpty()) {  // if some operators remained in stack
        output += stack.Pop();
    }
    return output;
}
//234_89_+87_9_+-
double Calculate(const std::string& notation) {
    double result = 0;
    std::string num;
    Stack<std::string> stack;
    for(int i = 0; i < notation.length(); i++) {
        if(isDigit(notation[i])) {
            while (notation[i] != '_' && i < notation.length()) {  // reading number digits
                num += notation[i];   // add current digit to number
                ++i;   // go to the next char
            }
            stack.Push(num);
            num = "";
        }
        if(isOperator(notation[i])){
            double a = std::stod(stack.Pop());  // converting string to double
            double b = std::stod(stack.Pop());
            char action = notation[i];
            switch (action) {
                case '^':
                    result = pow(b,a);
                    break;
                case '/':
                    result = b / a;
                    break;
                case '*':
                    result = b*a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '+':
                    result = b + a;
                    break;
                default:
                    std::cerr << "bad operator in calculating function\n";
            }
            stack.Push(std::to_string(result));
        }
    }
    return std::stod(stack.Top());
}

