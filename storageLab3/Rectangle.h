#pragma once
#include "Item.h"
class Rectangle :
    public Item
{
protected:
    int a;
    int b;
public:
    Rectangle();

    Rectangle(int a, int b);

    Rectangle(const Rectangle& rec);

    void showName() override;
};

