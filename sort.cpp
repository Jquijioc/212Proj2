#include "sort.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>

//A default constructor with empty data sets.
Sort::Sort() {
    int size = 0;
    this->sorted = {};
    this->reversed = {};
    this->random = {};
    this->partial = {};
}

//A parameterized constructor to initialize the Sort object with provided data sets.
Sort::Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial) {
    this->size = size;
    this->sorted = sorted;
    this->reversed = reversed;
    this->random = random;
    this->partial = partial;
}

//A method to display the main menu and interact with the sorting algorithms, allowing a user to either view a sorting algorithm step-by-step or analyze its time and stability with benchmarks.
void Sort::mainMenu(std::string file_name) {
    std::string input;
    while (true) {
        std::cout << "Input an integer:\n";
        std::cout << "1. Analyze sort.\n";
        std::cout << "2. Display sort.\n";
        std::cout << "3. Input custom data.\n";
        std::cout << "4. Input file data.\n";
        std::cout << "0. Quit.\n";
        std::cout << "\n";

        getline(std::cin, input);
        if (input == "0") {
            break;
        } else if (input == "1") {
            analyzeMenu(file_name);
        } else if (input == "2") {
            displayMenu(file_name);
        } else if (input == "3") {
            inputMenu();
        } else if (input == "4") {
            fileMenu();
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }
}

//A method to display the analysis menu for benchmarking and stability testing of sorting algorithms.
void Sort::analyzeMenu(std::string file_name) {
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
            analyzeSort(sortMethod);
        } else {
            std::cout << "Unrecognized command: " << input << std::endl;
        }
    }
}

//A method to display the display menu for viewing how an algorithm sorts a dataset iteratively.
void Sort::displayMenu(std::string file_name) {
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

void Sort::inputMenu() {
    std::cout << "Enter the size of the custom dataset: ";
    std::cin >> this->size;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter " << size << " space-separated sorted integers for a custom dataset: ";

    std::vector <KeyedInt> customData;
    for (int i = 0; i < size; i++) {
        int num;
        std::cin >> num;
        KeyedInt temp = {num, std::string(1, 'a' + i)}; // Assign keys as 'a', 'b', 'c', ...
        customData.push_back(temp);
    }

    //Clear the input buffer to avoid any remaining newline characters.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    this->sorted = customData;
    this->random = customData;
    this->partial = customData;
    this->reversed = customData;

    //Randomly shuffle the 'random' dataset.
    std::random_shuffle(random.begin(), random.end());

    //Sort the 'partial' dataset partially (e.g., half of the data in ascending order).
    std::sort(partial.begin(), partial.begin() + size / 2, [](const KeyedInt &a, const KeyedInt &b) {
        return a.value < b.value;
    });

    //Reverse the 'reversed' dataset.
    std::reverse(reversed.begin(), reversed.end());

    //Display the datasets.
    std::cout << "Sorted: ";
    print(0, sorted, true);
    std::cout << "Reversed: ";
    print(0, reversed, true);
    std::cout << "Random: ";
    print(0, random, true);
    std::cout << "Partial: ";
    print(0, partial, true);

    // Ask if the user wants to output the datasets to a file.
    std::cout << "Do you want to output the datasets to a file? (Y/N): ";
    std::string outputChoice;
    getline(std::cin, outputChoice);
    if (outputChoice == "Y" || outputChoice == "y") {
        std::cout << "Enter the name of the output file: ";
        std::string outputFileName;
        getline(std::cin, outputFileName);
        outputFile(outputFileName);
    }
}

void Sort::fileMenu() {
    std::cout << "Enter the name of the text file to read data from: ";
    std::string file_name;
    getline(std::cin, file_name);
    std::ifstream file(file_name);

    if (!file) {
        std::cout << "Error: Unable to open the file " << file_name << std::endl;
        return;
    }

    std::vector<std::vector<KeyedInt>> sequence;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream str(line);
        std::vector<KeyedInt> seq;
        std::string dec;
        str >> dec;
        int num;
        char key = 'a';
        while (str >> num) {
            KeyedInt temp = {num, std::string(1, key)};
            seq.push_back(temp);
            key++;
        }

        sequence.push_back(seq);
    }

    if (sequence.size() != 4) {
        std::cout << "Error: The file should contain four datasets." << std::endl;
        return;
    }

    this->sorted = sequence[0];
    this->reversed = sequence[1];
    this->random = sequence[2];
    this->partial = sequence[3];

    std::cout << "Sorted ";
    print(0, sorted, true);
    std::cout << "Reversed ";
    print(0, reversed, true);
    std::cout << "Random ";
    print(0, random, true);
    std::cout << "Partial ";
    print(0, partial, true);
}

void Sort::outputFile(const std::string& file_name) {
    std::ofstream outputFile(file_name);

    if (!outputFile) {
        std::cout << "Error: Unable to open the file " << file_name << " for writing." << std::endl;
        return;
    }

    // Output the datasets to the file.
    outputFile << "Sorted ";
    for (const auto& item : sorted) {
        outputFile << item.value << " ";
    }
    outputFile << std::endl;

    outputFile << "Reversed ";
    for (const auto& item : reversed) {
        outputFile << item.value << " ";
    }
    outputFile << std::endl;

    outputFile << "Random ";
    for (const auto& item : random) {
        outputFile << item.value << " ";
    }
    outputFile << std::endl;

    outputFile << "Partial ";
    for (const auto& item : partial) {
        outputFile << item.value << " ";
    }
    outputFile << std::endl;

    std::cout << "The data was written to the file " << file_name << " successfully." << std::endl;
}

//A method that uses the chrono library for granular time outputs along with key displays for stability to benchmark sorting algorithms.
void Sort::analyzeSort(int alg) {
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

//A method for displaying the step-by-step process of sorts. This method lets the user choose which sorting algorithm to run on a selected dataset.
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

//The print method prints all the values of a dataset separated by white spaces (and if displaySteps is on, it prints keys as well).
void Sort::print(int alg, std::vector<KeyedInt> dataSet, bool displaySteps) {
    // Print the original values.
    std::cout << "Value: ";
    for (const auto& item : dataSet) {
        std::cout << item.value << " ";
    }
    std::cout << std::endl;
    if(!displaySteps){ //If the user is in the analysis mode, display steps is false and keys are printed along with values.
        // Print the keyed values.
        std::cout << "Key: ";
        for (const auto& item : dataSet) {
            std::cout << item.value << item.key << " ";
        }
        std::cout << std::endl;
    }
}

//A basic insertion sort implementation.
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

//A basic quick sort implementation.
void Sort::quickSort(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps) {
    if (low < high) {
        int pivot = partition(arr, low, high, displaySteps);
        quickSort(arr, low, pivot - 1, displaySteps);
        if (displaySteps) {
            std::cout << "Pivot Point " << pivot << ": Pivot Value: " << arr[pivot].value << " : ";
            print(2, arr, displaySteps); //Quick Sort
        }

        quickSort(arr, pivot + 1, high, displaySteps);
    }
}

//A partition helper method for the quick sort implementation.
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

//A basic merge sort implementation.
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

//A merge helper method for the merge sort implementation.
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

//A basic cycle sort implementation.
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
