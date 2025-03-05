#pragma once

struct Price
{
    int uah;
    short int kop;
};

Price add(Price sum, Price price, int qnt);
Price mult(Price prod, int quant);
Price roundto10(Price sum);
void out(Price sum);

void parseFile(const char*);