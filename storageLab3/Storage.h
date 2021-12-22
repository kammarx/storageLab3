#pragma once
#include "Item.h"
#include <cstdlib>
#include <ctime>

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
		storage = new Item * [size];
		for (int i = 0; i < size; i++)
			storage[i] = nullptr;
	}

	void addObjEnd(Item* newobj) {
		Item** storage2 = new Item*[size + 1];
		if (size != 0) {
			for (int i = 0; i < size; i++) {
				storage2[i] = storage[i];
				
			}
			delete[] storage;
		}
		storage2[size] = newobj;
		size++;
		storage = storage2;
		
	}

	void addObjRandom(Item* newobj,int k) {
		
			Item** storage2 = new Item * [size + 1];
				for (int i = 0; i < k; i++) {
					storage2[i] = storage[i];
				}
				storage2[k] = newobj;
				for (int j = k + 1; j < size+1; j++) {
					storage2[j] = storage[j - 1];
				}
				delete[] storage;
				size = size + 1;
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

	int getCountFilled() {
		int q = 0;
		for (int i = 0; i < size; i++) {
			if (storage[i] != nullptr)
				q++;
		}
		return q;
	}

	bool isObj(int k) {
		if (storage[k] != nullptr)return true;
		else return false;
	}

	void removeObj(int k) {
		if (size > 0 && k<size && size!=1) {
			Item** storage2 = new Item * [size - 1];

			for (int i = 0; i < k; i++) {
				storage2[i] = storage[i];
			}
			
			for (int j = k; j < size - 1; j++) {
				storage2[j] = storage[j + 1];
			}
			delete[] storage;
			size--;
			storage = storage2;
		
		}
		else if (size == 1) {
			storage[0] = nullptr;
			size = 0;
		}

	}

	Item& getPrevObj(int k) {
		if (k > 0) {
			return *(this->storage[k - 1]);
		}
	}

	Item& getNextObj(int k) {
		if (k < size) {
			return *(this->storage[k + 1]);
		}
	}

	void fooNameStorage(int i) {
		if (size != 0 && size > i && storage[i]!=nullptr) {
			storage[i]->fooname();
		}
	}

	void perimeterStorage(int i) {
		if (size != 0 && size > i && storage[i] != nullptr) {
			storage[i]->perimeter();
		}
	}
	


    ~Storage() {
			for (int i = 0; i < size; i++) {
				delete storage[i];
			}
			delete[] storage;
		}






};

