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
        void benchmark();
        void print(int alg);
        void printSort(int alg);
        static bool check (int i, int j);
        std::vector<int> insertionSort(std::vector<int> arr);
        void cycleSort(std::vector<int>& arr);
        void printAndInsertionSort(std::string description, std::vector<int> dataSet);
        void quickSort(std::vector<int> arr, int minIndex, int maxIndex);
        int partition(std::vector<int> arr, int minIndex, int maxIndex);
};
