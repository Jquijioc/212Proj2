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
    printAndInsertionSort("Sorted", sorted);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort sorted vector: " << duration << " seconds" << std::endl;


    start = std::clock();
    printAndInsertionSort("Reversed", reversed);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort reversed vector: " << duration << " seconds" << std::endl;


    start = std::clock();
    printAndInsertionSort("Random", random);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort random vector: " << duration << " seconds" << std::endl;


    start = std::clock();
    printAndInsertionSort("Partial", partial);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to sort partially sorted vector: " << duration << " seconds" << std::endl;

}

std::vector<int> Sort::insertionSort(std::vector<int> dataSet) {
    for (int i = 1; i < dataSet.size(); i++) {
        int key = dataSet[i];
        int j = i - 1;
        while (j >= 0 && dataSet[j] > key) {
            dataSet[j + 1] = dataSet[j];
            j = j - 1;
        }
        dataSet[j + 1] = key;
    }
    return dataSet;
}

void Sort::printAndInsertionSort(std::string description, std::vector<int> dataSet) {
    std::cout << "Current " << description << " List" << std::endl;
    std::copy(dataSet.begin(), dataSet.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "After Insertion Sort" << std::endl;
    std::vector<int> sorted = insertionSort(dataSet);
    std::copy(sorted.begin(), sorted.end(), std::ostream_iterator<int>(std::cout, " "));
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
void sort::cycleSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int cycleStart = 0; cycleStart < n - 1; ++cycleStart) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        
        // Find the position where we put the element 'item'
        for (int i = cycleStart + 1; i < n; ++i) {
            if (arr[i] < item) {
                ++pos;
            }
        }
        
        // If the item is already in the correct position, skip this cycle
        if (pos == cycleStart) {
            continue;
        }
        
        // Otherwise, put the item to its correct position
        while (item == arr[pos]) {
            ++pos;
        }
        std::swap(item, arr[pos]);
        
        // Rotate the rest of the cycle
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; ++i) {
                if (arr[i] < item) {
                    ++pos;
                }
            }
            while (item == arr[pos]) {
                ++pos;
            }
            std::swap(item, arr[pos]);
        }
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
