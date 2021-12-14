#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Storage.h"
#include "Rectangle.h"
#include "Triangle.h"


void cycle(Storage& st, int q) {
	srand((unsigned int)time(NULL));
       int s = clock();
	for (int i = 0; i < q; i++) {
		int a = rand() % 3;
		int b;
		if (st.getCount() != 0) {
			b = rand() % st.getCount();
		}
		else {
			b = 0;
		}

		int k = rand() % 2;
		switch (a) {
		case 0: {
			if (k == 0)
				st.addObjEnd(new Rectangle);
			else
				st.addObjEnd(new Triangle);

			printf("addObject\n");
			break;
		}
		case 1: {
			st.removeObj(b);
			printf("removeObject\n");
			break;
		}
		case 2: {
			if (st.isObj(b) == true) {
				if (k == 0)st.getObj(b).fooname();
				else st.getObj(b).perimeter();
				printf("\n");
			}
			else printf("No object to call");
			break;
		}
		}
	}
	 int e = clock();//end time
	 int time = e - s;//target time
	printf("\nTime: %d ms\n", time);
	printf("Amount of objects: %d\n", st.getCount());
}

using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	Storage storage(10);
	for (int i = 0; i < storage.getCount(); i++) {
		int r = rand() % 2;
		if (r == 0) {
			storage.setObj(i, new Rectangle());
		}
		else {
			storage.setObj(i, new Triangle());
		}
	}



	cycle(storage, 100);
	printf("\n\n");
	system("pause");
	cycle(storage, 1000);
	printf("\n\n");
	system("pause");
	cycle(storage, 10000);
	
}