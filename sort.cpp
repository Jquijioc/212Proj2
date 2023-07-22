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

void Sort::benchmark() {
    std::clock_t start;
    double duration;

    start = std::clock();
    insertionSort(sorted);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort sorted vector: " << duration << " seconds" << std::endl;
    printAndInsertionSort("Sorted", sorted);

    start = std::clock();
    insertionSort(reversed);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort reversed vector: " << duration << " seconds" << std::endl;
    printAndInsertionSort("Reversed", reversed);

    start = std::clock();
    insertionSort(random);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort random vector: " << duration << " seconds" << std::endl;
    printAndInsertionSort("Random", random);

    start = std::clock();
    insertionSort(partial);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort partially sorted vector: " << duration << " seconds" << std::endl;
    printAndInsertionSort("Partial", partial);
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
