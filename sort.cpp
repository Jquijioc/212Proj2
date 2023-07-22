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

Sort::Sort(){
    int size = 0;
    this->sorted = {};
    this->reversed = {};
    this->random = {};
    this->partial = {} ;
}

Sort::Sort(int size, std::vector<int> sorted, std::vector<int> reversed, std::vector<int> random, std::vector<int> partial){
    this->size = size;
    this->sorted = sorted;
    this->reversed = reversed;
    this->random = random;
    this->partial = partial;
}

bool Sort::check (int i, int j) {
    return (i < j);
}

void Sort::benchmark(){
    std::clock_t start;
    double duration;
    start = std::clock();

    //sort.printAndInsertionSort("Sorted", sorted);
    //sort.printAndInsertionSort("Reversed", reversed);
    //sort.printAndInsertionSort("Random", random);
    //sort.printAndInsertionSort("Partially Sorted", partial);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<" Benchmark: "<< duration << std::endl;
}

void Sort::insertionSort(std::vector<int>& dataSet) {
    for (int i = 1; i < dataSet.size(); i++) {
        int key = dataSet[i];
        int j = i - 1;
        while (j >= 0 && dataSet[j] > key) {
            dataSet[j + 1] = dataSet[j];
            j = j - 1;
        }
        dataSet[j + 1] = key;
    }
}

void Sort::printAndInsertionSort(std::string description, std::vector<int>& dataSet) {
    std::cout << "Current " << description << " List" << std::endl;
    std::copy(dataSet.begin(), dataSet.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "After Insertion Sort" << std::endl;
    insertionSort(dataSet);
    std::copy(dataSet.begin(), dataSet.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n" << std::endl;
}

int Sort::partition(std::vector<int> arr, int minIndex, int maxIndex){
    int pivot = arr[maxIndex];
    int i = (minIndex - 1);

    for (int j = minIndex; j <= maxIndex - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[maxIndex]);
    return (i + 1);
}

void Sort::quickSort(std::vector<int> arr, int minIndex, int maxIndex){
    if (minIndex < maxIndex) {
        int partIndex = partition(arr, minIndex, maxIndex);
        quickSort(arr, minIndex, partIndex - 1);
        quickSort(arr, partIndex + 1, maxIndex);
    }
}

void Sort::print(int alg){
    for (int i = 0; i < this->size; i++){
        std::cout << this->sorted[i] << ' ';
    }
    for (int i = 0; i < this->size; i++){
        std::cout << this->reversed[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < this->size; i++){
        std::cout << this->random[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < this->size; i++){
        std::cout << this->partial[i] << ' ';
    }
    std::cout << std::endl;
}

void Sort::printSort(int alg){
    switch(alg) {
        case 1:
            print(alg);
            break;
        case 2:
            print(alg);
            break;
        case 3:
            print(alg);
            break;
        case 4:
            print(alg);
            break;
    }
    std::cout << std::endl;
}
