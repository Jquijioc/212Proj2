#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>

void insertionSort(std::vector<int> algo) {
    for (int i = 1; i < algo.size(); i++) {
        int key = algo[i];
        int j = i - 1;
        while (j >= 0 && algo[j] > key) {
            algo[j + 1] = algo[j];
            j = j - 1;
        }
        algo[j + 1] = key;
    }
}

int main() {
    std::clock_t start;
    double duration;

    start = std::clock();

    /* Your algorithm here */

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Benchmark: "<< duration << std::endl;
}
