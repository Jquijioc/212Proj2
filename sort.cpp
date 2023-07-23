#include "sort.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include <iterator>
#include <fstream>
#include <sstream>
#include <chrono>

Sort::Sort() {
    int size = 0;
    this->sorted = {};
    this->reversed = {};
    this->random = {};
    this->partial = {};
}

Sort::Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial) {
    this->size = size;
    this->sorted = sorted;
    this->reversed = reversed;
    this->random = random;
    this->partial = partial;
}

void Sort::print(int alg, std::vector<KeyedInt> dataSet) {
    // Print the original values.
    std::cout << "Value: ";
    for (const auto& item : dataSet) {
        std::cout << item.value << " ";
    }
    std::cout << std::endl;
    // Print the keyed values.
    std::cout << "Key: ";
    for (const auto& item : dataSet) {
        std::cout << item.value << item.key << " ";
    }
    std::cout << std::endl;
}

void Sort::printSort(int alg) {
    std::vector<std::vector<KeyedInt>> dataSets = {this->sorted, this->reversed, this->random, this->partial};
    std::vector<std::string> descriptions = {"Sorted", "Reversed", "Random", "Partial"};

    for (int i = 0; i < dataSets.size(); i++) {
        std::vector<KeyedInt> dataSet = dataSets[i];
        std::string description = descriptions[i];
        std::cout << "Before Sort of " << description << " List" << std::endl;
        print(alg, dataSet);
        switch (alg) {
            case 1:
                dataSet = insertionSort(dataSet);
                break;
            case 2:
                quickSort(dataSet, 0, dataSet.size() - 1);
                break;
            case 3:
                dataSet = mergeSort(dataSet);
                break;
            case 4:
                dataSet = cycleSort(dataSet);
                break;
        }
        std::cout << "After Sort of " << description << " List" << std::endl;
        print(alg, dataSet);
    }
}

void Sort::benchmark(int alg) {
    std::vector<std::vector<KeyedInt>> dataSets = {this->sorted, this->reversed, this->random, this->partial};
    std::vector<std::string> descriptions = {"Sorted", "Reversed", "Random", "Partial"};

    std::string name;

    for (int i = 0; i < dataSets.size(); i++) {
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<KeyedInt> dataSet = dataSets[i];
        std::string description = descriptions[i];

        switch (alg) {
            case 1:
                name = "Insertion Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet);
                dataSet = insertionSort(dataSet);
                break;
            case 2:
                name = "Quick Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet);
                quickSort(dataSet, 0, dataSet.size() - 1);
                break;
            case 3:
                name = "Merge Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet);
                dataSet = mergeSort(dataSet);
                break;
            case 4:
                name = "Cycle Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet);
                dataSet = cycleSort(dataSet);
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "After " << name << " of " << description << " List" << std::endl;
        print(alg, dataSet);
        std::cout << "Time to sort: " << elapsed.count() << " seconds" << std::endl << std::endl;
    }
}

void Sort::menu(std::string file_name) {
    std::cout << "Input an integer to sort " << file_name << " via algorithm:" << std::endl;
    std::cout << "1: Insertion Sort" << std::endl;
    std::cout << "2: Quick Sort" << std::endl;
    std::cout << "3: Merge Sort" << std::endl;
    std::cout << "4: Cycle Sort" << std::endl;
    std::cout << "0: Quit" << std::endl;
    std::cout << std::endl;
}

std::vector<KeyedInt> Sort::insertionSort(std::vector<KeyedInt> arr) {
    for (int i = 1; i < arr.size(); i++) {
        KeyedInt key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].value > key.value) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

std::vector<KeyedInt> Sort::mergeSort(std::vector<KeyedInt> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    std::vector<KeyedInt> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<KeyedInt> right(arr.begin() + arr.size() / 2, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    arr.clear();
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].value <= right[j].value) {
            arr.push_back(left[i]);
            i++;
        } else {
            arr.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        arr.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        arr.push_back(right[j]);
        j++;
    }
    return arr;
}

std::vector<KeyedInt> Sort::cycleSort(std::vector<KeyedInt> arr) {
    for (int cycleStart = 0; cycleStart < arr.size() - 1; ++cycleStart) {
        KeyedInt item = arr[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < arr.size(); ++i) {
            if (arr[i].value < item.value) {
                ++pos;
            }
        }
        if (pos == cycleStart) {
            continue;
        }
        while (item.value == arr[pos].value) {
            ++pos;
        }
        std::swap(item, arr[pos]);
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < arr.size(); ++i) {
                if (arr[i].value < item.value) {
                    ++pos;
                }
            }
            while (item.value == arr[pos].value) {
                ++pos;
            }
            std::swap(item, arr[pos]);
        }
    }
    return arr;
}

void Sort::quickSort(std::vector<KeyedInt>& arr, int minIndex, int maxIndex) {
    if (minIndex < maxIndex) {
        int partIndex = partition(arr, minIndex, maxIndex);
        quickSort(arr, minIndex, partIndex - 1);
        quickSort(arr, partIndex + 1, maxIndex);
    }
}

int Sort::partition(std::vector<KeyedInt>& arr, int minIndex, int maxIndex) {
    int pivot = arr[maxIndex].value;
    int i = minIndex - 1;

    for (int j = minIndex; j <= maxIndex - 1; j++) {
        if (arr[j].value < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[maxIndex]);
    return (i + 1);
}
