// HashDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "HashDLL.h"

HASHDLL_API HashTables::HashTables() {
	list = new Node*[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = NULL;
	}
	node = new Node("", -1);
}

HASHDLL_API HashTables::HashTables(int size) {
	maxSize = size;
	list = new Node*[maxSize];
	for (int i = 0; i < maxSize; i++) {
		list[i] = NULL;
	}
	node = new Node("", -1);
}	

HASHDLL_API bool HashTables::addItem(string data)
{
	if (count == maxSize) {
		return false;
	}
	count++;
	int key = Hash(data);
	node = new Node(data,key);
	if (list[key] == NULL) { 
		list[key] = node;
		return true;
	}
	else {
		int counter = key;
		while (list[counter] != NULL){ 
			counter++;
			if (counter >= maxSize) {
				counter = 0;
			}
		}
		list[counter] = node;
		return true;
	}
	return false;
}


HASHDLL_API Node* HashTables::getItem(string data){
	int x = Hash(data);
	for (int k = x; k < maxSize; k++) {
		if (list[k] == NULL)
			return NULL;
		if (list[k]->data == data) //checks if shifted
			return list[k];
	}
	return NULL;
}


HASHDLL_API int HashTables::getLength(){
	return maxSize;
}

HASHDLL_API  Node* HashTables::removeItem(string data) {
  int x = Hash(data);
  int i;
  for (i = x; i < maxSize; i++) {
    if (list[i]->data == data) //checks if shifted
      break;
  }
  
  if(list[i]!=nullptr){
	Node* N = list[i];
    delete list[i];
	return N;
  }   
  else
	return nullptr;
}

HASHDLL_API HashTables::~HashTables(){
  for(int i=0; i< maxSize; i++){
    //if(list[i]!=NULL)
      delete list[i];
  }
  delete node;
}

HASHDLL_API int HashTables::Hash(string data){
	int total = 0;
	for (int i = 0; i < data.length(); i++)
		total += data[i];
	return (total % maxSize);
}
