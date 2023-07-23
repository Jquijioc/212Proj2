# 212 Project
Project Members: Summer Lizarda, Jonathan Ok, Amer al Sayari

## Summary of the Project

The premise of this project is to build a codebase to evaluate sorting algorithms using data sets of different sizes.
1. Individual: returns individual deliverable name and grade
2. Category: returns all grades from category and category total
3. Course:
   * all grades in their respective categories and course overall
   * only category totals and course overall
   * only course overall
    
# Pseudocode

## main.cpp

``` 

# Include necessary headers
#include "sort.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

//function main(argc, argv):
    //get file_name = argv[1]
    //file = open_file(file_name)

    //vector of vectors = []

    //Read each line from the input file and process the datasets
    //for each line in file:
        //Create a stringstream to read data from the line
        //str = stringstream(line)
        //seq = []

        //Read the dataset label (dec) and discard it for now
        //dec = str.read_next_string()

        //Read numbers from the stringstream and create KeyedInt objects
        //key = 'a'
        //while str.has_next():
            //num = str.read_next_integer()
            //temp = create_keyed_int(num, key)
            //seq.push_back(temp)
            //key = increment_key(key)
        //Add the dataset to the sequence vector
    //Close file

    //Create a Sort object and initialize it with the datasets
    //Sort(sequence[0].size(), sequence[0], sequence[1], sequence[2], sequence[3])

    //Display the main menu to  interact with sorting algorithms
    //sort.mainMenu(file_name)

    return 0

```
## sort.cpp

```
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
        int size; //The dataset's size.
    public:
        //Sort constructors, default and parameterized.
        Sort();
        Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial);

        void mainMenu(std::string file_name);
        void analyzeMenu(std::string file_name);
        void displayMenu(std::string file_name);
        void inputMenu(); //The user can input custom data to test against sorting algorithms.
        void fileMenu(); //The user can input a file name to select as their custom data.
        void outputFile(const std::string& file_name);

        void analyzeSort(int alg);
        void displaySort(int alg, int sort_type);
        void print(int alg, std::vector<KeyedInt> dataSet, bool displaySteps);

        std::vector<KeyedInt> insertionSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        void quickSort(std::vector<KeyedInt>& arr, int minIndex, int maxIndex, bool displaySteps = false);
        int partition(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps);
        std::vector<KeyedInt> mergeSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        std::vector<KeyedInt> merge(std::vector<KeyedInt> left, std::vector<KeyedInt> right, bool displaySteps);
        std::vector<KeyedInt> cycleSort(std::vector<KeyedInt> arr, bool displaySteps = false);
    };

```

## sort.cpp

```

#include "sort.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>


//sort object constructor
    //this.size = size
    //this.sorted = sorted
    //this.reversed = reversed
    //this.random = random
    t//his.partial = partial

// Define methods for Sort class
//sort mainMenu(file_name):
    //while true:
        //Display the main menu options
        //print "Input an integer:"
        //print "1. Analyze sort."
        //print "2. Display sort."
        //print "3. Input custom data."
        //print "4. Input file data."
        //print "0. Quit."
        // Get user input
        input = get user input as a string
        // Check

```
