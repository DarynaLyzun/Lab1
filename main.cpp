#include <string>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <vector>
#include "price.hpp"
using namespace std;

int main()
{
    FILE* input_file;
    errno_t err;
    char c;
    vector<string> lines;
    
    if ((err = fopen_s(&input_file, "input.txt", "r")) != 0) 
        fprintf(stderr, "cannot open file '%s': %s\n", "input.txt", strerror(err));
    else 
    {
        string line_buffer = {};
        int comma = 0;

        while((c = fgetc(input_file)) != EOF)
        {
            if (c == ';')
            {
                lines.push_back(line_buffer);
                comma = 0;
                line_buffer = {};
            } 
            else if(c == ',')
                comma++;
            else if (comma > 0)
                line_buffer += c;  
        }

        lines.push_back(line_buffer);

        vector<Price> prices;
        vector<int> quants;

        for (string line : lines)
        {
            char* line_buff = new char[line.size() + 1];
            line_buff[line.size()] = '\0';
            for (int i = 0; i < line.size(); i++)
                line_buff[i] = line[i];
            Price price;
            price.uah = 0;
            price.kop = 0;
            int quant = 0;
            sscanf(line_buff, " %d %*[грн] %d %*[коп] %d", &price.uah, &price.kop, &quant);
            delete[] line_buff;
            prices.push_back(price);
            quants.push_back(quant);
        }

        out(prices, quants);
        
        fclose(input_file);
    }

    return 0;
}