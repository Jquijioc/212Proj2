#include "sort.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <random>
#include <iterator>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    std::string file_name(argv[1]); //Get file name.

    std::vector<int> file_data;
    std::ifstream file(file_name);

    std::vector <std::vector<int>> sequence;
    std::string line;

    while (std::getline(file, line)) {
        int i = 0;
        std::stringstream str(line);
        std::vector<int> seq;
        int num;
        while (str >> num) {
            seq.push_back(num);
        }
        sequence.push_back(seq);

    }

    Sort sort(sequence[0].size(), sequence[0], sequence[1], sequence[2], sequence[3]);

    std::string input;

    std::cout << "Input an integer to sort via algorithm:" << std::endl;
    std::cout << "1: Insertion Sort" << std::endl;
    std::cout << "2: Quick Sort" << std::endl;
    std::cout << "3: Merge Sort" << std::endl;
    std::cout << "4: Cycle Sort" << std::endl;
    std::cout << "5: Quit" << std::endl;

    while(getline(std::cin, input) && input != "5"){
        if(input == "5"){
            break;
        } else if (input == "1"){
            std::cout << "INSERTION SORT HERE" << std::endl;
        } else if (input == "2"){
            std::cout << "QUICK SORT HERE" << std::endl;
        } else if (input == "3"){
            std::cout << "MERGE SORT HERE" << std::endl;
        } else if(input == "4"){
            std::cout << "CYCLE SORT HERE" << std::endl;
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }

    return 0;
}
