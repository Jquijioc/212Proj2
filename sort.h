#include <iostream>
#include <vector>
#include <string>

struct KeyedInt {
    int value;
    std::string key;
};

class Sort {
    private:
        int size;
        std::vector<KeyedInt> sorted;
        std::vector<KeyedInt> reversed;
        std::vector<KeyedInt> random;
        std::vector<KeyedInt> partial;
    public:
        //Sort constructors.
        Sort();
        Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial);
        //Helper methods
        void benchmark(int alg);
        void print(int alg, std::vector<KeyedInt> dataSet);
        void printSort(int alg);
        void menu(std::string file_name);
        //Sorting methods.
        std::vector<KeyedInt> insertionSort(std::vector<KeyedInt> arr);
        std::vector<KeyedInt> mergeSort(std::vector<KeyedInt> arr);
        std::vector<KeyedInt> cycleSort(std::vector<KeyedInt> arr);
        void quickSort(std::vector<KeyedInt>& arr, int minIndex, int maxIndex);
        int partition(std::vector<KeyedInt>& arr, int minIndex, int maxIndex);
};
