
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

class L Sort {
public:
	vector<int> VectorGenerator(int n);
	vector<int> BubbleSort(vector<int> v);
	vector<int> InsertionSort(vector<int> v);
	vector<int> MergeSort(vector<int> v);
	vector<int> QuickSort(vector<int> v);
	vector<int> RadixSort(vector<int> v);
private:
	vector<int> vec;
};