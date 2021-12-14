#include "Rectangle.h"
#include <iostream>
Rectangle::Rectangle() {
	this->a = 1;
	this->b = 1;
}

Rectangle::Rectangle(int a, int b) {
	this->a = a;
	this->b = b;
}


Rectangle::Rectangle(const Rectangle& tr) {
	a = tr.a;
	b = tr.b;
}

void Rectangle::fooname() {
	std::cout << "It's rectangle";
};

void Rectangle::perimeter() {
	int per = (a + b) * 2;
	printf("Perimter of the rectangular : %d",per);

}