# 212 Project
Project Members: Summer Lizarda, Jonathan Ok, Amer al Sayari

## Summary of the Project
```
**Sorting Algorithms**
^^^

**_Implement the following algorithms_**

- `insertion sort`
- `mergesort`
- `quicksort`
- 1 additional algorithm not present in class

**_Benchmark all algorithms recording their runtime_**

- use different sequence sizes
- use different types of sequences:
  - sorted, reversed, random, partially sorted
```

# HOW TO COMPILE/INSTRUCTIONS TO USE PROJECT

## Instructions

```
Other IDES may be used, however CLion is Preferred

Follow These Steps:

1. Download the files sort.h, sort.cpp, main.cpp from our Github Repository
2. Open preferred IDE
3. Create your own data set or use one of our data sets provided
4. Use the CLA provided below
5. Follow the prompt instructions  

NOTE: To open your own data set, it must follow the format below:

Sorted 1 2 3 4 5 6 7 8 9 10
Reversed 10 9 8 7 6 5 4 3 2 1
Random 7 3 10 8 2 1 5 9 4 6
Partial 1 2 3 4 5 10 8 7 9 6

```

## Command Line Arguments
```
Use the following CLA Arguments

g++ sort.cpp main.cpp -o test && ./test

```

    
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

//struct KeyedInt {
    int value;
    std::string key;
};

class Sort {
    private:
        //std::vector<KeyedInt> sorted;
        //std::vector<KeyedInt> reversed; 
        //std::vector<KeyedInt> random; 
        //std::vector<KeyedInt> partial;
        //int size; //The dataset's size.
    public:
        //Sort constructors, default and parameterized.
        //Sort();
        //Sort(int size, std::vector<KeyedInt> sorted, std::vector<KeyedInt> reversed, std::vector<KeyedInt> random, std::vector<KeyedInt> partial);

        //void mainMenu(std::string file_name);
        //void analyzeMenu(std::string file_name);
        //void displayMenu(std::string file_name);
        //void inputMenu(); //The user can input custom data to test against sorting algorithms.
        //void fileMenu(); //The user can input a file name to select as their custom data.
        //void outputFile(const std::string& file_name);

        //void analyzeSort(int alg);
        //void displaySort(int alg, int sort_type);
        //void print(int alg, std::vector<KeyedInt> dataSet, bool displaySteps);

        //std::vector<KeyedInt> insertionSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        //void quickSort(std::vector<KeyedInt>& arr, int minIndex, int maxIndex, bool displaySteps = false);
        //int partition(std::vector<KeyedInt>& arr, int low, int high, bool displaySteps);
        //std::vector<KeyedInt> mergeSort(std::vector<KeyedInt> arr, bool displaySteps = false);
        //std::vector<KeyedInt> merge(std::vector<KeyedInt> left, std::vector<KeyedInt> right, bool displaySteps);
        //std::vector<KeyedInt> cycleSort(std::vector<KeyedInt> arr, bool displaySteps = false);
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
    //this.partial = partial

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
        i//nput = get user input as a string
        // Check

//sort displayMenu(file_name):
   // while true:
        //Display the display menu options
        //print "Select the type of data set for the sorting display:"
        //print "1. Sorted"
        //print "2. Reversed"
        //print "3. Random"
        //print "4. Partial"
        //print "5. Back"
        //print "0. Quit"
        //print ""

        //Get user input
        //input = get user input as a string

        //Check user choice and perform the corresponding action
        //if input is "0":
            //abort the program
        //else if input is "5":
            //break from the loop
        //else if input is "1" or input is "2" or input is "3" or input is "4":
            //sortMethod = parse input as an integer
            //displaySort(sortMethod)
        //else:
            //print "Unrecognized command: " + input

//sort outputFile(file_name):
    //outputFile = create a new output file with the name file_name
    //Output the datasets to the file

//sort inputMenu(file_name):
    //Get the size of the custom dataset from the user
    //Get the custom dataset from the user
    //for i = 1 to size:
        //num = parse next integer from user input
        //key = convert i to its corresponding alphabetical character (a -> 1, b -> 2, ...)
        //temp = create a new KeyedInt object with value=num and key=key
        //add temp to customData
    // Initialize the datasets with the custom data

    //Sort the datasets accordingly
    //Display the datasets

    //Ask if the user wants to output the datasets to a file
    //if outputChoice is "Y" or outputChoice is "y":
      //output to file

//sort fileMenu(file_name):
    //print "Enter the name of the text file to read data from: "
    //file_name = get user input as a string
    //file = open the file with the name file_name
    //sequence = an empty vector
    //while there are lines left in the file:
        //line = read the next line from the file
        //str = create a new stringstream with the content of the line
        //seq = an empty vector
        //dec = read the next string from the stringstream
        //key = 'a'
        //while there are more numbers to read from the stringstream:
            //num = read the next integer from the stringstream
            //temp = create a new KeyedInt object with value=num and key=key
            //add temp to the seq vector
            //increment the key to the next character
        //add seq to the sequence vector
    // Display the datasets

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

//sort displaySort(alg, sort_type):
    //while true:
        //print "Select the sorting algorithm to run on the " + sorted/reversed/etc. + " data set."
        //print "1: Insertion Sort"
        //print "2: Quick Sort"
        //print "3: Merge Sort"
        //print "4: Cycle Sort"
        //print "5. Back"
        //print "0. Quit"
        //print ""

        //input = read the user's input

        //if input is "0":
            //abort the program
        //else if input is "5":
            //break
        //else if input is "1" or input is "2" or input is "3" or input is "4":
            //sortMethod = convert input to an integer

            //dataSet = get the dataset from dataSets at index alg-1
            //description = get the description from descriptions at index alg-1

            // Perform the selected sorting algorithm
            //switch sortMethod:
                //case 1:
                    //dataSet = call insertionSort method on dataSet with displaySteps=true
                //case 2:
                    //call quickSort method on dataSet with minIndex=0, maxIndex=the size of dataSet - 1, and displaySteps=true
                //case 3:
                    //dataSet = call mergeSort method on dataSet with displaySteps=true
                //case 4:
                    //dataSet = call cycleSort method on dataSet with displaySteps=true
        //else:
            //print "Unrecognized command: " + input

//sort print(alg, dataSet, displaySteps):
    // Print the original values
    //for each item in dataSet:
        //print item.value + " "
    //print ""

    //if displaySteps is false:
        //Print the keyed values
        //for each item in dataSet:
            //print item.value + item.key + " "
        //print ""

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
