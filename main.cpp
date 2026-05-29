#include <iostream>
#include <vector>
#include <string>
using str = std::string;

double sum(std::vector<double> &arg);
double difference(std::vector<double> &arg);
double product(std::vector<double> &arg);
double quotient(std::vector<double> &arg);
void help();

int main(int argc, char *argv[]) {
    std::vector<double> nums;
    char cal_operator;
    std::string invalid_arg;
    bool operator_set {};

    for (int i = 1; i < argc; i++) {
        if (str(argv[i]) == "+" || str(argv[i]) == "add") { 
            if (operator_set) {
                std::cout << "calc: " << argv[i] << ": Invalid Argument\n";
                std::cout << "Invalid Argument: try '--help' to learn more\n";
                return 1;
            }
            cal_operator = '+';
            operator_set = true;
        } else if (str(argv[i]) == "-" || str(argv[i]) == "subtract") {
            if (operator_set) {
                std::cout << "calc: " << argv[i] << ": Invalid Argument\n";
                std::cout << "Invalid Argument: try '--help' to learn more\n";
                return 1;
            }
            cal_operator = '-';
            operator_set = true;
        } else if (str(argv[i]) == "x" || str(argv[i]) == "multiply") {
            if (operator_set) {
                std::cout << "calc: " << argv[i] << ": Invalid Argument\n";
                std::cout << "Invalid Argument: try '--help' to learn more\n";
                return 1;
            }
            cal_operator = 'x';
            operator_set = true;
        } else if (str(argv[i]) == "/" || str(argv[i]) == "divide") {
            if (operator_set) {
                std::cout << "calc: " << argv[i] << ": Invalid Argument\n";
                std::cout << "Invalid Argument: try '--help' to learn more\n";
                return 1;
            }
            cal_operator = '/';
            operator_set = true;
        } else if (str(argv[i]) == "--help" || str(argv[i]) == "-h") {
            help();
            return 0;
        } else {
            try {
                nums.push_back(std::stod(argv[i]));
            } catch (...) {
                invalid_arg = argv[i];
                std::cout << "calc: " << invalid_arg << ": Invalid Argument\n";
                std::cout << "Invalid Argument: try '--help' to learn more\n";
                return 1;
            }
        }
    }

    switch (cal_operator) {
        case '+':
            std::cout << "Result: " << sum(nums) << '\n';
            break;

        case '-':
            std::cout << "Result: " << difference(nums) << '\n';
            break;

        case 'x':
            std::cout << "Result: " << product(nums) << '\n';
            break;

        case '/':
            std::cout << "Result: " << quotient(nums) << '\n';
            break;
            
        default:
            std::cout << "Invalid Argument: try '--help' to learn more\n";
            break;
    }

    return 0;
}

double sum(std::vector<double> &arg) {
    double adding {};
    for (int i {}; i < arg.size(); i++) {
        adding += arg[i];
    }

    return adding;
}

double difference(std::vector<double> &arg) {
    double result {};
    result = arg[0];
    for (int i {1}; i < arg.size(); i++) {
        result -= arg[i];
    }

    return result;
}

double product(std::vector<double> &arg) {
    double result {};
    result = arg[0];
    for (int i {1}; i < arg.size(); i++) {
        result *= arg[i];
    }

    return result;
}

double quotient(std::vector<double> &arg) {
    double result {};
    result = arg[0];
    for (int i {1}; i < arg.size(); i++) {
        result /= arg[i];
        if (arg[i] == 0) {
            std::cout << "Invalid Argument: division by zero\n";
            std::cout << "Invalid Argument: try '--help' to learn more\n";
            exit(1);
        }
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
    std::cout << "   calc add 3 2 5 10 ||\n";
    std::cout << "   calc - 4 5 ||\n";
    std::cout << "   calc 4 multiply 5 ||\n";
    std::cout << "   calc 4 / 5 \n";
    std::cout << "   result: 20\n";
}
