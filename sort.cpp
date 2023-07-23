#include <iostream>
#include <vector>
#include <string>

struct KeyedInt {
    int value;
    std::string key;
};

class Sort {
    private:
        std::vector<KeyedInt> sorted;
        std::vector<KeyedInt> reversed;
        std::vector<KeyedInt> random;
        std::vector<KeyedInt> partial;
        int size;
    public:
        //Sort constructors.
        Sort();
        Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial);
        //Helper methods
        void benchmark(int alg);
        void print(int alg, std::vector<KeyedInt> dataSet, bool displaySteps);
        void printArray(const std::vector<KeyedInt>& arr);
        void printSort(int alg);
        //Menu methods.
        void mainMenu(std::string file_name);
        void displaySubMenu(std::string file_name);
        void displaySortMenu(std::string file_name);
        void displaySort(int alg, int sort_type);
        //Sorting methods.
        std::vector<KeyedInt> insertionSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        void quickSort(std::vector<KeyedInt>& arr, int minIndex, int maxIndex, bool displaySteps = false);
        int partition(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps);
        std::vector<KeyedInt> mergeSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        std::vector<KeyedInt> merge(std::vector<KeyedInt> left, std::vector<KeyedInt> right, bool displaySteps);
        std::vector<KeyedInt> cycleSort(std::vector<KeyedInt> arr, bool displaySteps = false);
    };
