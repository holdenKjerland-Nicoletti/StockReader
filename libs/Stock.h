//
// Created by Holden Nicoletti on 5/20/22.
//

#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <vector>

/*
Implementing Interface for stock in order to follow Dependency Inversion Principle,
 so TradesInputter and StocksOuputter can depend on an abstraction when passing
 stockMap as a parameter
*/
class StockParser{
public:
    virtual void addTrade(const std::string&) = 0;
    virtual const std::string toString() = 0;
};

class Stock: public StockParser {
    std::string symbol;
    long long lastTradeTime = -1;
    long long maxTimeGap = 0;
    int totalVolumeTraded = 0;
    int totalUnitsTraded = 0;
    int maxTradePrice = 0;

    std::vector<long long> parseTrade(const std::string&);
    int weightedAvgPrice();
public:
    Stock(const std::string&);
    std::string getSymbol();
    std::vector<long long> getValues();
    void addTrade(const std::string&);
    const std::string toString();
};


#endif //STOCK_H
