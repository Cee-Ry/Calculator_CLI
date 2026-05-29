#include <iostream>
#include <vector>
#include <string>
using str = std::string;

int sum(std::vector<int> &arg);

int main(int argc, char *argv[]) {
    std::vector<int> nums;
    char cal_operator;
    int index;

    for (int i = 1; i < argc; i++) {
        if (str(argv[i]) == "+" || str(argv[i]) == "add") { 
            cal_operator = '+';
        } else if (str(argv[i]) == "-" || str(argv[i]) == "subtract") {
            cal_operator = '-';
        } else if (str(argv[i]) == "*" || str(argv[i]) == "multiply") {
            cal_operator = '*';
        } else if (str(argv[i]) == "/" || str(argv[i]) == "divide") {
            cal_operator = '*';
        } else {
            nums.push_back(std::stoi(argv[i]));
        }
    }

    switch (cal_operator) {
        case '+':
            std::cout << "Result: " << sum(nums);
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
