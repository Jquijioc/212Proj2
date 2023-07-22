#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <random>

bool check (int i,int j) {
    return (i < j);
}


void insertionSort(std::vector<int>& dataSet) {
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

void printAndInsertionSort(std::string description, std::vector<int>& dataSet) {
    std::cout << "Current " << description << " List" << std::endl;
    std::copy(dataSet.begin(), dataSet.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "After Insertion Sort" << std::endl;
    insertionSort(dataSet);
    std::copy(dataSet.begin(), dataSet.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n" << std::endl;
}

int partition(std::vector<int> arr, int minIndex, int maxIndex){
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

void quickSort(std::vector<int> arr, int minIndex, int maxIndex){
    if (minIndex < maxIndex) {
        int partIndex = partition(arr, minIndex, maxIndex);
        quickSort(arr, minIndex, partIndex - 1);
        quickSort(arr, partIndex + 1, maxIndex);
    }
}

int main() {
    //- use different sequence sizes
    //- use different types of sequences:
    //- sorted, reversed, random, partially sorted
    std::vector<int> smallSorted;
    std::vector<int> smallReversed;
    std::vector<int> smallRandom;
    std::vector<int> smallPartial;
    std::vector<int> bigSorted;
    std::vector<int> bigReversed;
    std::vector<int> bigRandom;
    std::vector<int> bigPartial;

    std::vector<int> data = {25,10,5,30,13,7};

    //pushes user input into 4 arrays
    for(int i = 0; i < data.size(); i++) {
        smallSorted.push_back(data[i]);
        smallReversed.push_back(data[data.size() - 1 - i]);
        smallRandom.push_back(data[i]);
        smallPartial.push_back(data[i]);
    }
    //shuffles smallRandom
    std::random_shuffle(smallRandom.begin(), smallRandom.end());
    //partially sorts smallPartial
    int offset = smallPartial.size()/2;
    std::partial_sort (smallPartial.begin(), smallPartial.begin() + offset, smallPartial.end(), check);


    printAndInsertionSort("Sorted", smallSorted);
    printAndInsertionSort("Reversed", smallReversed);
    printAndInsertionSort("Random", smallRandom);
    printAndInsertionSort("Partially Sorted", smallPartial);

    std::clock_t start;
    double duration;

    start = std::clock();

    /* Your algorithm here */

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Benchmark: "<< duration << std::endl;
}
