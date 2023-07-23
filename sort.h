#include <iostream>
#include <vector>

class Sort {
    private:
        int size;
        std::vector<int> sorted;
        std::vector<int> reversed;
        std::vector<int> random;
        std::vector<int> partial;
    public:
        Sort();
        Sort(int size, std::vector<int> sorted, std::vector<int> reversed, std::vector<int> random, std::vector<int> partial);
        void benchmark(int alg);
        void print(int alg, std::vector<int> dataSet);
        void printSort(int alg);
        std::vector<int> insertionSort(std::vector<int> arr);
        std::vector<int> mergeSort(std::vector<int> arr);
        void cycleSort(std::vector<int>& arr);
        void quickSort(std::vector<int>& arr, int minIndex, int maxIndex);
        int partition(std::vector<int>& arr, int minIndex, int maxIndex);
        void mergeSort(std::vector<int>& arr, int left, int right);
        void merge(std::vector<int>& arr, int left, int mid, int right);
        void printAndMergeSort(std::string description, std::vector<int>& dataSet);
};
