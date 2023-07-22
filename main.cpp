#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <random>
#include <iterator>

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
    std::partial_sort (partial.begin(), partial.begin() + offset, partial.end(), check);


    printAndInsertionSort("Sorted", sorted);
    printAndInsertionSort("Reversed", reversed);
    printAndInsertionSort("Random", random);
    printAndInsertionSort("Partially Sorted", partial);

    std::clock_t start;
    double duration;

    start = std::clock();

    /* Your algorithm here */

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Benchmark: "<< duration << std::endl;
}
