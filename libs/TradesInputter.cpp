//
// Created by Holden Nicoletti on 5/20/22.
//

#include "TradesInputter.h"

#include <iostream>
#include <memory>

using namespace std;

TradesInputter::TradesInputter(const string fileName):inputFileName(fileName)
{
    inputFile.open(inputFileName);
}

/*
 * For each line of the file
    * get symbol and check if symbol is in stockMap
        * if not, add new Stock to stockMap
    * addTrade to stock
 */
void TradesInputter::readTrades(map<string, shared_ptr<StockParser>>& stockMap){

    string line;
    string symbol;

    if(inputFile.is_open()){
        while(getline(inputFile, line)){
            symbol = getSymbol(line);

            if(stockMap.find(symbol) == end(stockMap)){
                stockMap[symbol] = shared_ptr<StockParser> (new Stock(symbol));
            }

            stockMap[symbol]->addTrade(line);
        }
    }else{
        cout<<"Failed to Open File"<<endl;
        exit(-1);
    }
}

string getSymbol(const string& line){
    int start = (int)line.find(",") + 1;
    return line.substr(start, SYMBOL_SIZE);
}
