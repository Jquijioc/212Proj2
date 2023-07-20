#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>

void insertionSort(std::vector<int> arr) {
    for (int i = 1; i < algo.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

    std::vector<int> smallSorted;
    std::vector<int> smallReversed;
    std::vector<int> smallRandom;
    std::vector<int> smallPartial;
    std::vector<int> bigSorted;
    std::vector<int> bigReversed;
    std::vector<int> bigRandom;
    std::vector<int> bigPartial;

    std::vector<int> data = {25,10,5,30,13,7};

    for(int i = 0; i < data.size(); i++) {
        smallSorted.push_back(data[i]);
        smallReversed.push_back(data[data.size() - 1 - i]);
        smallRandom.push_back(data[i]);
        smallPartial.push_back(data[i]);
    }

    insertionSort(smallSorted);
    for(int i = 0; i < smallSorted.size(); i++) {
        std::cout << smallSorted[i] << " ";
    }
    std::cout << std::endl;

    insertionSort(smallReversed);
    for(int i = 0; i < smallReversed.size(); i++) {
        std::cout << smallReversed[i] << " ";
    }
    std::cout << std::endl;

    std::random_shuffle(smallRandom.begin(), smallRandom.end());
    insertionSort(smallRandom);
    for(int i = 0; i < smallRandom.size(); i++) {
        std::cout << smallRandom[i] << " ";
    }
    std::cout << std::endl;

    int offset = smallPartial.size()/2;
    std::partial_sort (smallPartial.begin(), smallPartial.begin()+ offset, smallPartial.end(), check);
    for(int i = 0; i < smallPartial.size(); i++) {
        std::cout << smallPartial[i] << " ";
    }
    std::cout << std::endl;

    insertionSort(smallPartial);
    for(int i = 0; i < smallPartial.size(); i++) {
        std::cout << smallPartial[i] << " ";
    }

    std::clock_t start;
    double duration;

    start = std::clock();

    /* Your algorithm here */

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Benchmark: "<< duration << std::endl;
}
