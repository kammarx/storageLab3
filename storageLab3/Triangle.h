#pragma once
#include "Item.h"
#include <iostream>
class Triangle :
    public Item
{
protected:
    int a, b, c;
public:
    Triangle();

    Triangle(int a, int b, int c);

    Triangle(const Triangle& tr);

    void showName() override;
};

