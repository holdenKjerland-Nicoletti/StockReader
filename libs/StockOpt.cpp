//
// Created by Holden Nicoletti on 5/23/22.
//

#include "StockOpt.h"

#include <sstream>

using namespace std;

StockOpt::StockOpt()
{
}

//__attribute__((always_inline)) // did not improve performance
__attribute__((hot)) // very slight performance improvement
vector<int> StockOpt::parseTrade(const string& trade){
    vector<int> data(3);
    stringstream ss(trade);
    string s;

    // get quantity
    getline(ss, s, ',');
    data[1] = stoi(s);

    // get price
    getline(ss, s);
    data[2] = stoi(s);

    return data;
}

void StockOpt::addTrade(const string& trade, long long t){

    vector<int> data = parseTrade(trade);

    // check if current time gap is greater than current maxTimeGap
    if((lastTradeTime > 0) && ((t - lastTradeTime) > maxTimeGap)){
        maxTimeGap = t - lastTradeTime;
    }

    //check if current price is greater than maxTradePrice
    if(data[1] > maxTradePrice){
        maxTradePrice = data[1];
    }

    // increment other variables
    lastTradeTime = t;
    totalVolumeTraded += data[0]*data[1];
    totalUnitsTraded += data[0];
}
