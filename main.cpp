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

int main(int argc, char* argv[]){
    std::string file_name(argv[1]); //Get file name.

    std::vector<int> file_data;
    std::ifstream file(file_name);

    std::vector<std::vector<int>> sequence;
    std::string line;

    while (std::getline(file, line)){
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
}
