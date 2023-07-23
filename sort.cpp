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
#include <chrono>

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

std::vector<int> Sort::mergeSort(std::vector<int> arr) {
    if(arr.size() <= 1) {
        return arr;
    }
    std::vector<int> left(arr.begin(), arr.begin() + arr.size()/2);
    std::vector<int> right(arr.begin() + arr.size()/2, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    arr.clear();
    while(left.size() > 0 && right.size() > 0) {
        if(left[0] <= right[0]) {
            arr.push_back(left[0]);
            left.erase(left.begin());
        } else {
            arr.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    while(left.size() > 0) {
        arr.push_back(left[0]);
        left.erase(left.begin());
    }
    while(right.size() > 0) {
        arr.push_back(right[0]);
        right.erase(right.begin());
    }
    return arr;
}

void Sort::cycleSort(std::vector<int>& arr) {
    for(int cycleStart = 0; cycleStart < arr.size() - 1; ++cycleStart) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        for(int i = cycleStart + 1; i < arr.size(); ++i) {
            if(arr[i] < item) {
                ++pos;
            }
        }
        if(pos == cycleStart) {
            continue;
        }
        while(item == arr[pos]) {
            ++pos;
        }
        std::swap(item, arr[pos]);
        while(pos != cycleStart) {
            pos = cycleStart;
            for(int i = cycleStart + 1; i < arr.size(); ++i) {
                if(arr[i] < item) {
                    ++pos;
                }
            }
            while(item == arr[pos]) {
                ++pos;
            }
            std::swap(item, arr[pos]);
        }
    }
}

int Sort::partition(std::vector<int>& arr, int minIndex, int maxIndex){
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

void Sort::quickSort(std::vector<int>& arr, int minIndex, int maxIndex){
    if (minIndex < maxIndex) {
        int partIndex = partition(arr, minIndex, maxIndex);
        quickSort(arr, minIndex, partIndex - 1);
        quickSort(arr, partIndex + 1, maxIndex);
    }
}

void Sort::print(int alg, std::vector<int> dataSet) {
    std::copy(dataSet.begin(), dataSet.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void Sort::printSort(int alg){
    std::vector<std::vector<int>> dataSets = {this->sorted, this->reversed, this->random, this->partial};
    std::vector<std::string> descriptions = {"Sorted", "Reversed", "Random", "Partial"};

    for(int i = 0; i < dataSets.size(); i++){
        std::vector<int> dataSet = dataSets[i];
        std::string description = descriptions[i];
        std::cout << "Before Sort of " << description << " List" << std::endl;
        print(alg, dataSet);
        switch(alg) {
            case 1:
                dataSet = insertionSort(dataSet);
                break;
            case 2:
                quickSort(dataSet, 0, dataSet.size()-1);
                break;
            case 3:
                dataSet = mergeSort(dataSet);
                break;
            case 4:
                cycleSort(dataSet);
                break;
        }
        std::cout << "After Sort of " << description << " List" << std::endl;
        print(alg, dataSet);
    }
}

void Sort::benchmark(int alg) {
    std::vector<std::vector<int>> dataSets = {this->sorted, this->reversed, this->random, this->partial};
    std::vector<std::string> descriptions = {"Sorted", "Reversed", "Random", "Partial"};

    std::string sortName;

    for(int i = 0; i < dataSets.size(); i++){
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> dataSet = dataSets[i];
        std::string description = descriptions[i];

        switch(alg) {
            case 1:
                sortName = "Insertion Sort";
                dataSet = insertionSort(dataSet);
                break;
            case 2:
                sortName = "Quick Sort";
                quickSort(dataSet, 0, dataSet.size()-1);
                break;
            case 3:
                sortName = "Merge Sort";
                dataSet = mergeSort(dataSet);
                break;
            case 4:
                sortName = "Cycle Sort";
                cycleSort(dataSet);
                break;
        }

        std::cout << "Before " << sortName << " of " << description << " List" << std::endl;
        print(alg, dataSet);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "After " << sortName << " of " << description << " List" << std::endl;
        print(alg, dataSet);
        std::cout << "Time to sort: " << elapsed.count() << " seconds" << std::endl << std::endl;
    }
}
