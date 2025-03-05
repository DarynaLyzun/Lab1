#pragma once
#include <string>

struct Price
{
    int uah;
    short int kop;
};

Price add(std::vector<Price> prices, std::vector<int> quants);
Price mult(Price prod, int quant);
Price roundto10(Price sum);
void out(std::vector<Price> prices, std::vector<int> quants);