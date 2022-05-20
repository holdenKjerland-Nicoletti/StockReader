//
// Created by Holden Nicoletti on 5/20/22.
//

#ifndef TRADESINPUTTER_H
#define TRADESINPUTTER_H


#include <string>
#include <fstream>
#include <map>

#include "Stock.h"

#define SYMBOL_SIZE 3

class TradesInputter {
    const std::string inputFileName;
    std::ifstream inputFile;

public:
    TradesInputter(const std::string);
    void readTrades(std::map<std::string, std::shared_ptr<StockParser>>&);
};

std::string getSymbol(const std::string& line);


#endif //TRADESINPUTTER_H
