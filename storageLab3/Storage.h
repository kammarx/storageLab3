#pragma once
#include "Item.h"
class Storage
{
private:
	int size;
	Item** storage;
public:
	Storage() {
		size = 0;
	}

	Storage(int s) {
		size = s;
		storage = new Item*[size];
	}

	void addObj(Item* newobj) {
		Item** storage2 = new Item*[size + 1];
		if (size != 0) {
			for (int i = 0; i < size; i++) {
				storage2[i] = storage[i];
				
			}
		}
		storage2[size] = newobj;
		size++;
		delete[] storage;
		storage = storage2;
		
	}

	void deleteObj(int k) {
		storage[k] = nullptr;
	}

	Item& getObj(int k) {
		return *storage[k];
	}

	Item& getObjDel(int k) {
		Item* temp = storage[k];
		storage[k] = nullptr;
		return *temp;
	}

	void setObj(int i, Item* newobj) {
		storage[i] = newobj;
	}

	int getCount() {
		return size;
	}

	void removeObj(int k) {
		if (size != 0 && k<size) {
			Item** storage2 = new Item * [size - 1];

			for (int i = 0; i < k; i++) {
				storage2[i] = storage[i];
			}
			delete storage[k];
			for (int j = k; j < size - 1; j++) {
				storage2[j] = storage[j + 1];
			}
			delete[] storage;
			size--;
			storage = storage2;
		}

	}
	
	
	
	
		~Storage() {
			for (int i = 0; i < size; i++) {
				delete storage[i];
			}
			delete[] storage;
		}






};

