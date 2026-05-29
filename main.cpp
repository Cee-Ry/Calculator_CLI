#include <iostream>
#include <vector>
#include <string>

int sum(std::vector<int> &arg);

int main(int argc, char *argv[]) {
    std::vector<int> nums;
    char cal_operator;
    int index;
    
    for (int i {1}; i < argc; i++) {
        if ((argc % 2) == 0) {
            nums.push_back(std::stoi(argv[i]));
        } else {
            std::cout << argv[i];
        } 
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
