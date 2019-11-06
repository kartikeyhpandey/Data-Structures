#include "PQueue.h"
#include "Heap.h"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
  // PQueue
  PQueue queue;
  cout << "Analysis on queues" << endl;

  //500 random numbers Vector
  vector<int> vec500;
  for(int i=0; i<500; i++){
    vec500.push_back(rand() % (1000)+1);
  }
  
  //1000 random numbers Vector
  vector<int> vec1000;
  for(int i=0; i<1000; i++){
    vec1000.push_back(rand() % (2000)+1);
  }
  
  //2000 random numbers Vector
  vector<int> vec2000;
  for(int i=0; i<2000; i++){
    vec2000.push_back(rand() % (4000)+1);
  }
  
  //5000 random numbers Vector
  vector<int> vec5000;
  for(int i=0; i<5000; i++){
    vec5000.push_back(rand() % (10000)+1);
  }
  
  // 500
  auto t1 = chrono::system_clock::now();
  int size = 500;
  for(int i = 0; i < size; i++) {
    queue.insert(vec500[i]);
	}
	auto t2 = chrono::system_clock::now();
	cout << "Inserting 500 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 500
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
    queue.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 500 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // 1000
  t1 = chrono::system_clock::now();
  size = 1000;
  for(int i = 0; i < size; i++) {
    queue.insert(vec1000[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 1000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 1000
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
    queue.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 1000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // 2000
  t1 = chrono::system_clock::now();
  size = 2000;
  for(int i = 0; i < size; i++) {
    queue.insert(vec2000[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 2000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 2000
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
    queue.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 2000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // 5000
  t1 = chrono::system_clock::now();
  size = 5000;
  for(int i = 0; i < size; i++) {
    queue.insert(vec5000[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 5000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 5000
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
    queue.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 5000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // HEAPS
  Heap heapC;
  cout << "Analysis on heaps" << endl;
  // 500
  t1 = chrono::system_clock::now();
  size = 500;
  for(int i = 0; i < size; i++) {
    heapC.insert(vec500[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 500 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 500
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
	  heapC.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 500 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // 1000
  t1 = chrono::system_clock::now();
  size = 1000;
  for(int i = 0; i < size; i++) {
    heapC.insert(vec1000[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 1000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 1000
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
	  heapC.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 1000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // 2000
  t1 = chrono::system_clock::now();
  size = 2000;
  for(int i = 0; i < size; i++) {
    heapC.insert(vec2000[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 2000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 2000
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
	  heapC.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 2000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // 5000
  t1 = chrono::system_clock::now();
  size = 5000;
  for(int i = 0; i < size; i++) {
    heapC.insert(vec5000[i]);
	}
	t2 = chrono::system_clock::now();
	cout << "Inserting 5000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

  // remove 5000
  t1 = chrono::system_clock::now();
  for(int i = 0; i < size; i++) {
	  heapC.remove();
	}
	t2 = chrono::system_clock::now();
	cout << "Removing 5000 random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;


  return 0;
}
