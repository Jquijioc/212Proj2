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


    std::cout << "Input an integer to sort " << file_name << " via algorithm:" << std::endl;
    std::cout << "1: Insertion Sort" << std::endl;
    std::cout << "2: Quick Sort" << std::endl;
    std::cout << "3: Merge Sort" << std::endl;
    std::cout << "4: Cycle Sort" << std::endl;
    std::cout << "0: Quit" << std::endl;


    while(getline(std::cin, input) && input != "0"){
        if(input == "0"){
            break;
        } else if (input == "1"){
            int sortMethod = std::stoi(input);
            sort.benchmark(sortMethod);
        } else if(input == "2"){
            int sortMethod = std::stoi(input);
            sort.benchmark(sortMethod);
        } else if(input == "3"){
            int sortMethod = std::stoi(input);
            sort.benchmark(sortMethod);
        } else if(input == "4") {
            int sortMethod = std::stoi(input);
            sort.benchmark(sortMethod);
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
            continue;
        }
    }
    return 0;
}
