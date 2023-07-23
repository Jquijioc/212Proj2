#include "sort.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <ctime>
#include <stdlib.h>
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

void Sort::mainMenu(std::string file_name) {
    std::string input;
    while(true) {
        std::cout << "Input an integer:\n";
        std::cout << "1. Analyze sort.\n";
        std::cout << "2. Display sort.\n";
        std::cout << "0. Quit.\n";
        std::cout << "\n";

        getline(std::cin, input);
        if (input == "0") {
            break;
        } else if (input == "1") {
            displaySubMenu(file_name);
        } else if (input == "2") {
            displaySortMenu(file_name);
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }
}

void Sort::displaySubMenu(std::string file_name) {
    std::string input;
    while(true) {
        std::cout << "Input an integer to sort " << file_name << " via algorithm:" << std::endl;
        std::cout << "1: Insertion Sort" << std::endl;
        std::cout << "2: Quick Sort" << std::endl;
        std::cout << "3: Merge Sort" << std::endl;
        std::cout << "4: Cycle Sort" << std::endl;
        std::cout << "5: Back" << std::endl;
        std::cout << "0: Quit" << std::endl;
        std::cout << std::endl;

        getline(std::cin, input);
        if (input == "0") {
            abort();
        } else if (input == "5"){
            break;
        } else if (input == "1" || input == "2" || input == "3" || input == "4") {
            int sortMethod = std::stoi(input);
            benchmark(sortMethod);
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }
}

void Sort::displaySortMenu(std::string file_name) {
    std::string input;
    while(true) {
        std::cout << "Select the type of data set for the sorting display:" << std::endl;
        std::cout << "1. Sorted" << std::endl;
        std::cout << "2. Reversed" << std::endl;
        std::cout << "3. Random" << std::endl;
        std::cout << "4. Partial" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "\n";

        getline(std::cin, input);
        if (input == "0") {
            abort();
        } else if (input == "5"){
            break;
        } else if (input == "1" || input == "2" || input == "3" || input == "4") {
            int sortMethod = std::stoi(input);
            displaySort(sortMethod, std::stoi(input));
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }
}

void Sort::displaySort(int alg, int sort_type) {
    std::vector<std::vector<KeyedInt>> dataSets = {this->sorted, this->reversed, this->random, this->partial};
    std::vector<std::string> descriptions = {"Sorted", "Reversed", "Random", "Partial"};
    std::string input;
    while(true) {
        std::cout << "Select the sorting algorithm to run on the " << descriptions[alg-1] <<" data set."<< std::endl;
        std::cout << "1: Insertion Sort" << std::endl;
        std::cout << "2: Quick Sort" << std::endl;
        std::cout << "3: Merge Sort" << std::endl;
        std::cout << "4: Cycle Sort" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "\n";

        getline(std::cin, input);
        if (input == "0") {
            abort();
        } else if (input == "5"){
            break;
        } else if (input == "1" || input == "2" || input == "3" || input == "4") {
            int sortMethod = std::stoi(input);
            std::vector<KeyedInt> dataSet = dataSets[alg-1];
            std::string description = descriptions[alg-1];
            switch (sortMethod) {
                case 1:
                    dataSet = insertionSort(dataSet, true);
                    break;
                case 2:
                    quickSort(dataSet, 0, dataSet.size() - 1, true);
                    break;
                case 3:
                    dataSet = mergeSort(dataSet, true);
                    break;
                case 4:
                    dataSet = cycleSort(dataSet, true);
                    break;
            }
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }
}

void Sort::print(int alg, std::vector<KeyedInt> dataSet, bool displaySteps) {
    // Print the original values.
    std::cout << "Value: ";
    for (const auto& item : dataSet) {
        std::cout << item.value << " ";
    }
    std::cout << std::endl;
    if(!displaySteps){
        // Print the keyed values.
        std::cout << "Key: ";
        for (const auto& item : dataSet) {
            std::cout << item.value << item.key << " ";
        }
        std::cout << std::endl;
    }
}

void Sort::printSort(int alg) {
    std::vector<std::vector<KeyedInt>> dataSets = {this->sorted, this->reversed, this->random, this->partial};
    std::vector<std::string> descriptions = {"Sorted", "Reversed", "Random", "Partial"};

    for (int i = 0; i < dataSets.size(); i++) {
        std::vector<KeyedInt> dataSet = dataSets[i];
        std::string description = descriptions[i];
        std::cout << "Before Sort of " << description << " List" << std::endl;
        print(alg, dataSet, false);
        switch (alg) {
            case 1:
                dataSet = insertionSort(dataSet, false);
                break;
            case 2:
                quickSort(dataSet, 0, dataSet.size() - 1, false);
                break;
            case 3:
                dataSet = mergeSort(dataSet, false);
                break;
            case 4:
                dataSet = cycleSort(dataSet, false);
                break;
        }
        std::cout << "After Sort of " << description << " List" << std::endl;
        print(alg, dataSet, false);
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
                print(alg, dataSet, false);
                dataSet = insertionSort(dataSet, false);
                break;
            case 2:
                name = "Quick Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet, false);
                quickSort(dataSet, 0, dataSet.size() - 1, false);
                break;
            case 3:
                name = "Merge Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet, false);
                dataSet = mergeSort(dataSet, false);
                break;
            case 4:
                name = "Cycle Sort";
                std::cout << "Before " << name << " of " << description << " List" << std::endl;
                print(alg, dataSet, false);
                dataSet = cycleSort(dataSet, false);
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "After " << name << " of " << description << " List" << std::endl;
        print(alg, dataSet, false);
        std::cout << "Time to sort: " << elapsed.count() << " seconds" << std::endl << std::endl;
    }
}

std::vector<KeyedInt> Sort::insertionSort(std::vector<KeyedInt> arr, bool displaySteps) {
    for (int i = 1; i < arr.size(); i++) {
        KeyedInt key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].value > key.value) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        if (displaySteps) {
            std::cout << "Step " << i << ": ";
            print(1, arr, displaySteps); //Insertion Sort
        }
    }
    return arr;
}


void Sort::quickSort(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps) {
    if (low < high) {
        int pivot = partition(arr, low, high, displaySteps);

        quickSort(arr, low, pivot - 1, displaySteps);
        quickSort(arr, pivot + 1, high, displaySteps);

        if (displaySteps) {
            std::cout << "Step " << pivot << ", Pivot: " << arr[pivot].value << " : ";
            print(2, arr, displaySteps); //Quick Sort
        }
    }
}

int Sort::partition(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps) {
    KeyedInt pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value < pivot.value) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

std::vector<KeyedInt> Sort::mergeSort(std::vector<KeyedInt> arr, bool displaySteps) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;

        std::vector<KeyedInt> left(arr.begin(), arr.begin() + mid);
        std::vector<KeyedInt> right(arr.begin() + mid, arr.end());

        left = mergeSort(left, displaySteps);
        right = mergeSort(right, displaySteps);

        arr = merge(left, right, displaySteps);

        if (displaySteps) {
            std::cout << "Left: ";
            print(3, left, displaySteps); //Merge Sort

            std::cout << "Right: ";
            print(3, right, displaySteps);

            std::cout << "Merged: ";
            print(3, arr, displaySteps);
        }
    }
    return arr;
}

std::vector<KeyedInt> Sort::merge(std::vector<KeyedInt> left, std::vector<KeyedInt> right, bool displaySteps) {
    std::vector<KeyedInt> result;
    while (!left.empty() && !right.empty()) {
        if (left.front().value <= right.front().value) {
            result.push_back(left.front());
            left.erase(left.begin());
        } else {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (!left.empty()) {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty()) {
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

std::vector<KeyedInt> Sort::cycleSort(std::vector<KeyedInt> arr, bool displaySteps) {
    for (int cycle_start = 0; cycle_start <= arr.size() - 2; cycle_start++) {
        KeyedInt item = arr[cycle_start];

        int pos = cycle_start;
        for (int i = cycle_start + 1; i < arr.size(); i++) {
            if (arr[i].value < item.value) {
                pos++;
            }
        }

        if (pos == cycle_start) {
            continue;
        }

        while (item.value == arr[pos].value) {
            pos += 1;
        }

        if (item.value != arr[pos].value) {
            std::swap(item, arr[pos]);
        }

        while (pos != cycle_start) {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < arr.size(); i++) {
                if (arr[i].value < item.value) {
                    pos += 1;
                }
            }

            while (item.value == arr[pos].value) {
                pos += 1;
            }

            if (item.value != arr[pos].value) {
                std::swap(item, arr[pos]);
            }
        }

        if (displaySteps) {
            std::cout << "Step " << cycle_start << ": ";
            print(4, arr, displaySteps); //Cycle Sort
        }
    }
    return arr;
}
