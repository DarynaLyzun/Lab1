#pragma once

struct Price
{
    int uah;
    short int kop;
};

void add(Price &sum, Price price, int qnt);
void mult(Price &prod, int quant);
void roundto10(Price &sum);
void out(Price sum);

void parseFile(const char*);