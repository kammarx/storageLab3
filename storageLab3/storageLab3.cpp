#include <iostream>
#include <ctime>
#include "Item.h"
#include "Storage.h"
#include "Rectangle.h"
#include "Triangle.h"


void cycle(Storage& st, int q) {
	unsigned int s = clock();
	for (int i = 0; i < q; i++) {
		int a = rand() % 5;
		int b;
		if (st.getCount() != 0) {
			b = rand() % st.getCount();
		}
		else {
			b = 0;
		}

		int k = rand() % 2;
		switch (a) {
		case 0:
			if (k == 0)
				st.addObj(new Rectangle);
			else
				st.addObj(new Triangle);

			printf("addObject\n");
			break;
		case 1:
			st.removeObj(b);
			printf("removeObject\n");
			break;
		case 2:
			if (k == 0)st.getObj(b).fooname();
			else st.getObj(b).perimeter();
			printf("\n");
		}
	}
	unsigned int e = clock();//end time
	unsigned int time = e - s;//target time
	printf("\nTime: %d ms\n", time);
	printf("Amount of objects: %d\n", st.getCount());
}

using namespace std;
int main()
{
	srand(time(nullptr));
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
	cout << endl << endl;
	
}