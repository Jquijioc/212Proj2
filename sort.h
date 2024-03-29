#include <iostream>
#include <vector>
#include <string>

//When read into the program, values are transposed into a keyedInt struct and assigned a letter key to keep track of original object locations after sorting to measure stability.
struct KeyedInt {
    int value;
    std::string key;
};

class Sort {
    private:
        std::vector<KeyedInt> sorted; //A fully-sorted dataset.
        std::vector<KeyedInt> reversed; //A reversed dataset.
        std::vector<KeyedInt> random; //A randomly sorted dataset.
        std::vector<KeyedInt> partial; //A partially sorted dataset.
        int size; //The dataset's size.
    public:
        //Sort constructors, default and parameterized.
        Sort();
        Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial);

        //Menu methods.
        void mainMenu(); //The main menu pop-up.
        void analyzeMenu(); //A menu to select the algorithm type to analyze.
        void benchmarkMenu(int sort_type); //The menu for benchmarking (time testing, stability testing) an algorithm.
        void displayMenu(); //The menu for displaying the steps of a sorting algorithm.
        void inputMenu(); //The user can input custom data to test against sorting algorithms.
        void fileMenu(); //The user can input a file name to select as their custom data.
        void outputFile(const std::string& file_name);

        //Display/analysis methods.
        void analyzeSort(int alg, bool key); //The method that outputs the sort analysis, either stability with key comparisons or time with the chrono c++ library.
        void displaySort(int alg, int sort_type); //The method that calls the sorting algorithms with display steps set to true.
        void print(std::vector<KeyedInt> dataSet, bool displaySteps); //The method that prints a dataset.
        bool checkStable(const std::vector<KeyedInt>& dataSet);

        //Sorting methods with their helper methods.
        std::vector<KeyedInt> insertionSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        void quickSort(std::vector<KeyedInt>& arr, int minIndex, int maxIndex, bool displaySteps = false);
        int partition(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps);
        std::vector<KeyedInt> mergeSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        std::vector<KeyedInt> merge(std::vector<KeyedInt> left, std::vector<KeyedInt> right, bool displaySteps);
        std::vector<KeyedInt> cycleSort(std::vector<KeyedInt> arr, bool displaySteps = false);
};
