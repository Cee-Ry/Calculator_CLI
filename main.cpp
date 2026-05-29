#include <iostream>
#include <vector>
#include <string>
using str = std::string;

int sum(std::vector<int> &arg);
int difference(std::vector<int> &arg);
int product(std::vector<int> &arg);
int quotient(std::vector<int> &arg);

int main(int argc, char *argv[]) {
    system("mkdir -p ~/.local/bin");

    std::vector<int> nums;
    char cal_operator;
    int index;

    for (int i = 1; i < argc; i++) {
        if (str(argv[i]) == "+" || str(argv[i]) == "add") { 
            cal_operator = '+';
        } else if (str(argv[i]) == "-" || str(argv[i]) == "subtract") {
            cal_operator = '-';
        } else if (str(argv[i]) == "x" || str(argv[i]) == "multiply") {
            cal_operator = 'x';
        } else if (str(argv[i]) == "/" || str(argv[i]) == "divide") {
            cal_operator = '/';
        } else {
            nums.push_back(std::stoi(argv[i]));
        }
    }

    switch (cal_operator) {
        case '+':
            std::cout << "Result: " << sum(nums);
            break;

        case '-':
            std::cout << "Result: " << difference(nums);
            break;

        case 'x':
            std::cout << "Result: " << product(nums);
            break;

        case '/':
            std::cout << "Result: " << quotient(nums);
            break;

    }

    return 0;
}

int sum(std::vector<int> &arg) {
    int adding {};
    for (int i {}; i < arg.size(); i++) {
        adding += arg[i];
    }

    return adding;
}

int difference(std::vector<int> &arg) {
    int result {};
    result = arg[0];
    for (int i {1}; i < arg.size(); i++) {
        result -= arg[i];
    }

    return result;
}

int product(std::vector<int> &arg) {
    int result {};
    result = arg[0];
    for (int i {1}; i < arg.size(); i++) {
        result *= arg[i];
    }

    return result;
}

int quotient(std::vector<int> &arg) {
    int result {};
    result = arg[0];
    for (int i {1}; i < arg.size(); i++) {
        result /= arg[i];
    }

    return result;
}
