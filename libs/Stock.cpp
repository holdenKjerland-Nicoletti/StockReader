//
// Created by Holden Nicoletti on 5/20/22.
//

#include "Stock.h"

#include <sstream>

using namespace std;

Stock::Stock(const string& s):symbol(s)
{
}

string Stock::getSymbol(){
    return symbol;
}

vector<long long> Stock::getValues(){
    return {lastTradeTime, maxTimeGap, totalVolumeTraded, totalUnitsTraded, maxTradePrice};
}

vector<long long> Stock::parseTrade(const string& trade){
    vector<long long> data(3);
    stringstream ss(trade);
    string s;

    // get timestamp
    getline(ss, s, ',');
    data[0] = stoll(s);

    // skip symbol (already have it
    getline(ss, s, ',');

    // get quantity
    getline(ss, s, ',');
    data[1] = stoll(s);

    // get price
    getline(ss, s);
    data[2] = stoll(s);

    return data;
}

void Stock::addTrade(const string& trade){
    vector<long long> data = parseTrade(trade);

    // check if current time gap is greater than current maxTimeGap
    if((lastTradeTime > 0) && ((data[0] - lastTradeTime) > maxTimeGap)){
        maxTimeGap = data[0] - lastTradeTime;
    }

    //check if current price is greater than maxTradePrice
    if(data[2] > maxTradePrice){
        maxTradePrice = (int)data[2];
    }

    // increment other variables
    lastTradeTime = data[0];
    totalVolumeTraded += (int)data[1]*(int)data[2];
    totalUnitsTraded += (int)data[1];
}

int Stock::weightedAvgPrice(){
    if(totalUnitsTraded) {
        return (int)(totalVolumeTraded/totalUnitsTraded);
    }
    cout<<"No Units Traded";
    return 0;
}

const string Stock::toString(){
    return symbol+","+to_string(maxTimeGap)+","+to_string(totalVolumeTraded)+","+to_string(weightedAvgPrice())+","+to_string(maxTradePrice)+"\n";
}