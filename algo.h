class SortAlgo {
    public:
    void insertionSort(std::vector<int>& arr);
    void printAndInsertionSort(std::string description, std::vector<int>& dataSet);
    void quickSort(std::vector<int> arr, int minIndex, int maxIndex);
    static bool check (int i, int j);
    int partition(std::vector<int> arr, int minIndex, int maxIndex);
};
