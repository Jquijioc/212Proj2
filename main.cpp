#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <random>
#include <iterator>
#include "algo.h"

int main() {
    SortAlgo sortAlgo;

    std::vector<int> sorted;
    std::vector<int> reversed;
    std::vector<int> random;
    std::vector<int> partial;

    std::vector<int> data = {25,10,5,30,13,7};

    //pushes user input into 4 arrays
    for(int i = 0; i < data.size(); i++) {
        sorted.push_back(data[i]);
        reversed.push_back(data[data.size() - 1 - i]);
        random.push_back(data[i]);
        partial.push_back(data[i]);
    }
    //shuffles smallRandom
    std::random_shuffle(random.begin(), random.end());
    //partially sorts smallPartial
    int offset = partial.size()/2;
    std::partial_sort (partial.begin(), partial.begin() + offset, partial.end(), SortAlgo::check);


    //BENCHMARK
    std::clock_t start;
    double duration;

    start = std::clock();

    //sortAlgo.printAndInsertionSort("Sorted", sorted);
    //sortAlgo.printAndInsertionSort("Reversed", reversed);
    //sortAlgo.printAndInsertionSort("Random", random);
    sortAlgo.printAndInsertionSort("Partially Sorted", partial);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Benchmark: "<< duration << std::endl;
}
