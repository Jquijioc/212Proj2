# 212 Project
Project Members: Summer Lizarda, Jonathan Ok, Amer al Sayari

## Summary of the Project

The premise of this project was to implement a C++ application capable of running and analyzing several sorting algorithms. The application can benchmark different sorting algorithms by runtime at a granular scale, check different algorithms' stability via a character key structure, demonstrate the step-by-step processes of sorting algorithms, and read in and output custom user data sequences as text files.

The application can read in up to a four-line text file made up of datasets in the order of fully sorted, reversed, randomly sorted, and partially sorted. The user can choose from a console output menu whether to produce a custom dataset and write it to a file or read in an outside file, which we've provided. The user can interact with the menu from there to step through an algorithm or benchmark it with the dataset.

The project required our program to implement the following sorting algorithms and a custom algorithm, which are as follows:

```
- `insertion sort`
- `mergesort`
- `quicksort`
- `cyclesort
```

The project required our program to benchmark the algorithms on several different sequence types, which are as follows:

```
- use different sequence sizes
- use different types of sequences:
  - sorted, reversed, random, partially sorted
```

# Instructions on Input & Compilation

## File Structure

Our program benchmarks sorting algorithms with four different sequence types: fully sorted, reversed, randomly sorted, and partially sorted. The user can choose to input their own dataset of a custom size into the program for it to sort, reverse, randomize, and partially sort automatically, or the user can write a file themself for the program to read in. The program accepts a four-line text file as such, with each line beginning with the sequence type and input in the order:

```
Sorted 1 2 3 4 5 6 7 8 9 10 
Reversed 10 9 8 7 6 5 4 3 2 1 
Random 9 2 10 3 1 6 8 4 5 7 
Partial 1 2 3 4 5 10 8 9 7 6 
```

## Command Line Arguments

The program's command line execution follow the form of:

```
g++ sort.cpp main.cpp -o test && ./test
```

## Runtime Instructions

Other IDES may be used, however the code was originally written and tested with CLion. The program can be run and operated per these steps:

1. Download the files sort.h, sort.cpp, main.cpp from our Github repository.
2. Open your preferred IDE.
3. Enter the CLA command provided into your console.
4. Before you operate, you must select a dataset of sequences. You may create your own data set or use one of our data sets provided, please follow instructions closely.
5. If you want to use a specific custom data set, i.e. the ones we've provided or a custom-made one:
   5a. Create a four-line text file.
   5b. Label each line with [Sorted, Reversed, Random, Partial] in that order.
   5c. Input your integers on each line sorted, reversed, randomized, and partially sorted separated by single white spaces.
   5d. In the program main menu, input 2 for 2. Input File Data.
   5e. Enter the name of your .txt file.
   5f. The program will read in and display the file contents, saving the datasets.
7. If you want to create a program-made custom data set:
   7a. In the program main menu, input 1 for 1. Input custom data.
   7b. Input the size of your desired data set.
   7c. Input your integers in any order up to the size you set.
   7d. The program will fully sort, reverse, randomly sort, and partially sort your data and display it for you, saving the datasets.  
12. You may now use our Analyze Sort and Display Sort feature.
13. If you want to use Analyze Sort:
   13a. Input 3 for 3. Analyze Sort.
   13b. Input an integer for the sorting algorithm you'd like to run.
   13c. The program will display the original sequence, the sorted sequence, and the sequences with letter keys to check algorithm stability with duplicates in datasets.
14. If you want to use Display Sort:
   14a. Input 4 for 4. Display Sort.
   14b. Select the data type you want to sort: sorted, reversed, randomized, and partially sorted.
   14c. Select the sorting algorithm you want to run on the data type: insertion sort, quick sort, merge sort, and cycle sort.
   14d. The program will display the original sequence, each intermediate step of the sorting algorithm sequence as it sorts, and the final sorted sequence.
15. If you ever want to quit, you can input 0. Quit. If you want to backstep in the menu, you can input 5. Back. to go back.

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
