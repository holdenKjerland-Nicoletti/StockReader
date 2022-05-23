//
// Created by Holden Nicoletti on 5/23/22.
//

#ifndef QUANTLABSTOCKS_STOCKOPT_H
#define QUANTLABSTOCKS_STOCKOPT_H

#include "Stock.h"


class StockOpt: public StockParser {
    long long lastTradeTime = -1;
    long long maxTimeGap = 0;
    int totalVolumeTraded = 0;
    int totalUnitsTraded = 0;
    int maxTradePrice = 0;

    std::vector<int> parseTrade(const std::string&);
//    int weightedAvgPrice();
public:
    StockOpt();
//    std::string getSymbol();
    std::vector<long long> getValues();
    void addTrade(const std::string&){};
    void addTrade(const std::string&, long long);
    const std::string toString(){return "";};
};


#endif //QUANTLABSTOCKS_STOCKOPT_H
