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

/*
 * For each line of the file
    * get symbol and check if symbol is in stockMap
        * if not, add new Stock to stockMap
    * addTrade to stock
 */
void TradesInputter::readTrades2(vector<vector<vector<shared_ptr<StockParser>>>>& stockVec){

    string line;
    string symbol;

    if(inputFile.is_open()){
        while(getline(inputFile, line)){
            // Find index after first comma
            int start = (int)line.find(",");

            long long timeStamp = stoll(line.substr(0, start));

            int i = line[start+1] - 'a';
            int j = line[start+2] - 'a';
            int k = line[start+3] - 'a';

            if(stockVec[i][j][k]==NULL){
                stockVec[i][j][k] = shared_ptr<StockParser> (new StockOpt());
            }

            stockVec[i][j][k]->addTrade(line.substr(start+5, line.size() - (start+5)), timeStamp);
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

