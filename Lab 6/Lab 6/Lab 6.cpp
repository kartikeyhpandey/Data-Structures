// Lab 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
typedef std::chrono::high_resolution_clock Clock;

vector<int> VectorGenerator(int n) {
	srand(time(NULL));
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		vec.push_back(rand() % ((2 * n) + 1));
	}
	return vec;
}

vector<int> BubbleSort(vector<int> vec) {
	vector<int> sorted = vec;
	int size = sorted.size();
	int temp;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < (size - i); j++) {
			if (sorted[j] > sorted[j + 1]) {
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}
	return sorted;
}

vector<int> InsertionSort(vector<int> vec) {
	vector<int> sorted = vec;
	int size = sorted.size();
	int j, a;

	for (int i = 0; i < size; i++) {
		a = sorted[i];

		j = i - 1;
		while (j >= 0 && sorted[j] > a) {
			sorted[j + 1] = sorted[j];
			j = j + 1;
		}
		sorted[j + 1] = a;
	}
	return sorted;
}

vector<int> merge(vector<int> left, vector<int> right) {
	int len_left = 0, len_right = 0;
	vector<int> results;
	while (len_left < left.size() && len_right < right.size())
		if (left[len_left] < right[len_right])
			results.push_back(left[len_left++]);
		else
			results.push_back(right[len_right++]);
	while (len_left < left.size()) results.push_back(left[len_left++]);
	while (len_right < right.size()) results.push_back(right[len_right++]);
	return results;
}

vector<int> MergeSort(vector<int> vec) {
	if (vec.size() <= 1)
		return vec;
	int len = vec.size() / 2;
	vector<int> left(vec.begin(), vec.begin() + len);
	vector<int> right(vec.begin() + len, vec.end());
	return merge(MergeSort(left), MergeSort(right));
}

int partition(vector<int>& vec, int left, int right) {
	int pivotIndex = left + (right - left) / 2;
	int pivotValue = vec[pivotIndex];
	int i = left, j = right;
	int temp;
	while (i <= j) {
		while (vec[i] < pivotValue) {
			i++;
		}
		while (vec[j] > pivotValue) {
			j--;
		}
		if (i <= j) {
			temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			i++;
			j--;
		}
	}
	return i;
}


void QuickSort(vector<int> & vec, int left, int right) {
	if (left < right) {
		int pivotIndex = partition(vec, left, right);
		QuickSort(vec, left, pivotIndex - 1);
		QuickSort(vec, pivotIndex, right);
	}
}
/*
vector<int> RadixSort(vector<string> vec) {

}
*/
int main()
{
	vector<int> vec = VectorGenerator(10);
	cout << "Unsorted Vector: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << endl;

	auto t1 = Clock::now();
	vector<int> vecBS = BubbleSort(vec);
	auto t2 = Clock::now();
	cout << "Sorted Vector: ";
	for (int i = 0; i < vecBS.size(); i++) {
		cout << vecBS[i] << " ";
	}
	cout << endl;
	cout << "Bubble Sort: Time Taken-" << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << endl;

	auto t3 = Clock::now();
	vector<int> vecIS = BubbleSort(vec);
	auto t4 = Clock::now();
	cout << "Sorted Vector: ";
	for (int i = 0; i < vecIS.size(); i++) {
		cout << vecIS[i] << " ";
	}
	cout << endl;
	cout << "Insertion Sort: Time Taken-" << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << endl;
	cout << endl;

	auto t5 = Clock::now();
	vector<int> vecMS = MergeSort(vec);
	auto t6 = Clock::now();
	cout << "Sorted Vector: ";
	for (int i = 0; i < vecMS.size(); i++) {
		cout << vecMS[i] << " ";
	}
	cout << endl;
	cout << "Merge Sort: Time Taken-" << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << endl;
	cout << endl;

	vector<int> vecQS = vec;
	auto t7 = Clock::now();
	QuickSort(vecQS, 0, vecQS.size()-1);
	auto t8 = Clock::now();
	cout << "Sorted Vector: ";
	for (int i = 0; i < vecQS.size(); i++) {
		cout << vecQS[i] << " ";
	}
	cout << endl;
	cout << "Quick Sort: Time Taken-" << std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << endl;
	cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file