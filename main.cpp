#include <iostream>
#include <vector>
#include <string>
using str = std::string;

int sum(std::vector<int> &arg);
int difference(std::vector<int> &arg);
int product(std::vector<int> &arg);
int quotient(std::vector<int> &arg);
void help();

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
        } else if (str(argv[i]) == "--help" || str(argv[i]) == "-h") {
            help();
            return 0;
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
            
        default:
            std::cout << "Invalid Argument: try '--help' to learn more\n";
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

void help() {
    std::cout << "Usage: calc <number> <operator> <number>\n";
    std::cout << "Usage: calc <operator> <multi number>\n\n";

    std::cout << "Available options:\n";
    std::cout << "   +, add            get the sum of the numbers\n";
    std::cout << "   -, subtract       get the difference of the numbers\n";
    std::cout << "   x, multiply       get the product of the numbers\n";
    std::cout << "   /, divide         get the quotient of the numbers\n";
    std::cout << "   -h, --help        Display this help and exit the program\n";

    std::cout << "\nExamples:\n";
    std::cout << "   calc add 3 2 5 10\n";
    std::cout << "   result: 20\n";
}
