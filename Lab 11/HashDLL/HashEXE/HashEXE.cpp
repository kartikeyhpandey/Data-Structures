#include "../HashDLL/HashDLL.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

int main(){
	//create HashTable
	int num_ele;
	cout << "How many elements? : ";
	cin >> num_ele;
	cout << endl;
	HashTables* hashbash = new HashTables(num_ele);

	//user interface
	int choice = 0;
	string temp = "";
	int count = 0;
	int size = 1;
	while (choice != 6) {
		cout << "Enter number to proceed with action\n";
		cout << "1: add item to hash table\n";
		cout << "2: get item from hash table\n";
    cout << "3: delete item from hash table\n";
		cout << "4: get length of hash table\n";
		cout << "5: analyze hash table\n";
		cout << "6: quit\n";
		cin >> choice;
		switch (choice) {
		case 1: //DONE
			cout << "----Adding Item----\n" << "Data to enter, as string: ";
			cin >> temp;
			cout << endl;
			if (hashbash->addItem(temp)) {
				cout << "Items " << temp << " added" << endl;
				count++;
			}
			else {
				cout << "Your hashtable is full" << endl;
				cout << "Items " << temp << " was not added" << endl;
			}
			break;
		case 2: //DONE
			cout << "What item you want to find: " << endl;
			cin >> temp;
      if(hashbash->getItem(temp)!=NULL){
        cout << "Data point: " << hashbash->getItem(temp)->data << "\n";
        cout << "Key: " << hashbash->getItem(temp)->key << "\n";
        cout << endl;
        break;
      }
        cout << "Item not in the hashtable" <<endl;
			break;
      case 3: //DONE
			cout << "What item you want to delete: " << endl;
			cin >> temp;
			if (hashbash->removeItem(temp) != nullptr)
				cout << "Item deleted";
			else
				cout << "Item not in the hashtable";
			cout << endl;
			break;
		case 4: //DONE
			cout << "Length is " << hashbash->getLength() << "\n";
			break;
		case 5:
			cout << "Analysis on hashtables" << endl;

			while (size != 0) {
				cout << "How many random ints? (0 to stop)" << endl;
				cin >> size;

				if (size != 0) {
					cout << "Task 3 analysis" << endl;
					HashTables* baby_hashbash = new HashTables(size*1.50);
					auto t1 = chrono::system_clock::now();
					for (int I = 0; I < size; I++) {
						string randomStr = to_string(rand() % (size * 2) + 1);
						baby_hashbash->addItem(randomStr);
					}
					auto t2 = chrono::system_clock::now();
					cout << "Inserting random integers: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

					delete baby_hashbash;
				}
				if (size != 0) {
					cout << "Task 4 analysis" << endl;
					HashTables* baby_hashbash = new HashTables(size);
					auto t1 = chrono::system_clock::now();
					for (int I = 0; I < size; I++) {
						string randomStr = to_string(rand() % (size * 2) + 1);
						baby_hashbash->addItem(randomStr);
					}
					auto t2 = chrono::system_clock::now();
					cout << "Inserting random integers (100%): " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

					baby_hashbash->~HashTables();

					baby_hashbash = new HashTables(2 * size);
					t1 = chrono::system_clock::now();
					for (int I = 0; I < size; I++) {
						string randomStr = to_string(rand() % (size * 2) + 1);
						baby_hashbash->addItem(randomStr);
					}
					 t2 = chrono::system_clock::now();
					cout << "Inserting random integers (200%): " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

					delete baby_hashbash;

					baby_hashbash = new HashTables(5 * size);
					t1 = chrono::system_clock::now();
					for (int I = 0; I < size; I++) {
						string randomStr = to_string(rand() % (size * 2) + 1);
						baby_hashbash->addItem(randomStr);
					}
					t2 = chrono::system_clock::now();
					cout << "Inserting random integers (500%): " << chrono::duration<double>(t2 - t1).count() << "s" << endl;

					delete baby_hashbash;
				}
			}
			break;
		case 6:
			cout << "You quit, but you're not a quitter" << endl;

		}
	}
	delete hashbash;
	return 0;
};