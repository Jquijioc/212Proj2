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
## sort.h

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

//sort analyzeSort
    //dataSets = an array containing sorted, reversed, random, and partial datasets
    //descriptions = an array containing descriptions of the datasets
    //for i = 0 to the length of dataSets - 1:
        //start = get the current time using chrono library

        //dataSet = get the dataset from dataSets at index i
        //description = get the description from descriptions at index i

        //Perform the selected sorting algorithm
        //switch case:
            //case 1 Insertion Sort:
                //name = "Insertion Sort"
                //print "Before " + name + " of " + description + " List"
                //call print method with alg=alg, dataSet=dataSet, and displaySteps=false
                //dataSet = call insertionSort method on dataSet with displaySteps=false
            //case 2 Quick Sort:
                //name = "Quick Sort"
                //print "Before " + name + " of " + description + " List"
                //call print method with alg=alg, dataSet=dataSet, and displaySteps=false
                //call quickSort method on dataSet with minIndex=0, maxIndex=the size of dataSet - 1, and displaySteps=false
            //case 3 Merge Sort:
                //name = "Merge Sort"
                //print "Before " + name + " of " + description + " List"
                //call print method with alg=alg, dataSet=dataSet, and displaySteps=false
                //dataSet = call mergeSort method on dataSet with displaySteps=false
            //case 4 Cycle Sort:
                //name = "Cycle Sort"
                //print "Before " + name + " of " + description + " List"
                //call print method with alg=alg, dataSet=dataSet, and displaySteps=false
                //dataSet = call cycleSort method on dataSet with displaySteps=false

        //end = get the current time using chrono library
        //elapsed = calculate the difference between end and start

        //Display the sorted dataset and elapsed time
        //print "After " + name + " of " + description + " List"
        //call print method with alg=alg, dataSet=dataSet, and displaySteps=false
        //print "Time to sort: " + elapsed + " seconds"

//sort insertionSort
    insert insertion sort code..

//sort quickSort
    insert quick sort code..

//sort partition
    insert partition helper code..

//sort mergeSort
    insert merge sort code..

//sort merge
  insert merge helper code..

//sort cycleSort
    insert cycle sort code..

```
