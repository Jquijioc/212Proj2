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

    std::ifstream file(file_name);

    std::vector <std::vector<KeyedInt>> sequence;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream str(line);
        std::vector<KeyedInt> seq;
        int num;
        char key = 'a';
        while (str >> num) {
            KeyedInt temp = {num, std::string(1, key)};
            seq.push_back(temp);
            key++;
        }
        sequence.push_back(seq);
    }

    Sort sort(sequence[0].size(), sequence[0], sequence[1], sequence[2], sequence[3]);

    std::string input;

    sort.menu(file_name);

    while(getline(std::cin, input) && input != "0"){
        std::cout << std::endl;
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
        sort.menu(file_name);
    }

    return 0;
}
