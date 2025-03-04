#pragma once
#include <string>

struct Price
{
    int uah;
    short int kop;
};

int add(std::vector<Price> prices, std::vector<int> quants);
int mult(Price prod, int quant);
int roun(int sum);
void out(int sum);