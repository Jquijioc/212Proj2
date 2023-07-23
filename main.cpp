#include "sort.h"
#include <iostream>
#include <vector>
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
        std::string dec;
        str >> dec;
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

    sort.mainMenu(file_name);

    return 0;
}
