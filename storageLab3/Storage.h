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
				delete storage[i];
			}
		}
		storage2[size] = newobj;
		storage = storage2;
		size++;
	}

	void deleteObj(int k) {
		storage[k] = nullptr;
	}


};

