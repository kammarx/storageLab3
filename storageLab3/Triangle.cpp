#include "Triangle.h"
#include <iostream>
Triangle::Triangle() {
	this->a = 1;
	this->b = 1;
	this->c = 1;
}

Triangle::Triangle(int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;
}


Triangle::Triangle(const Triangle& tr) {
	a = tr.a;
	b = tr.b;
	c = tr.c;
}

void Triangle::showName(){
	std::cout << "Triangle";
};