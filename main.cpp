#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <random>

bool check (int i,int j) {
    return (i < j);
}

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
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
    const int dataSize = 10000;
// data sets:
// Sorted Integer Set
//small
    int smallSorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//big
    int bigSorted[dataSize];
    for (int i = 0; i < dataSize; ++i) {
        bigSorted[i] = i + 1;
    }

// Reversed Integer Set
//small
    int smallReversed[] = {10,9,8,7,6,5,4,3,2,1};
//big
    int bigReversed[dataSize];
    for (int i = 0; i < dataSize; ++i) {
        bigReversed[i] = dataSize - i;
    }

// Random Integer Set
//small
    int smallRandom[] = {9, 4, 1, 8, 2, 7, 5, 10, 3, 6};
//big
    int bigRandom[dataSize];
    srand(time(0));
    for (int i = 0; i < dataSize; ++i) {
        bigRandom[i] = rand() % 10000 + 1;
    }

// Partially Sorted Integer Set
//small
    int smallPartial[] = {5, 1, 4, 3, 2, 6, 7, 8, 9, 10};
//big
    int bigPartial[dataSize];
    for (int i = 0; i < dataSize; ++i) {
        if (i < dataSize / 2) {
            // First half: Partially sorted (every 5th element is sorted)
            if (i % 5 == 0) {
                bigPartial[i] = i + 1;
            } else {
                bigPartial[i] = rand() % 10000 + 1;
            }
        } else {
            // Second half: Sorted in ascending order
            bigPartial[i] = i + 1;
        }
    }
    //delete
    for (int i = 0; i < dataSize; ++i) {
        std::cout<< bigRandom[i] << std::endl;
    }

    int smallSorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int smallReversed[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int smallRandom[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int smallPartial[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


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
