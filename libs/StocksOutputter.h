//
// Created by Holden Nicoletti on 5/20/22.
//

#ifndef STOCKSOUTPUTTER_H
#define STOCKSOUTPUTTER_H


#include <string>
#include <fstream>
#include <map>

#include "Stock.h"

class StocksOutputter {
    std::string outputFileName = "data/output.csv";
    std::ofstream outputFile;

public:

    StocksOutputter();
    StocksOutputter(const std::string);
    void writeStocks(const std::map<std::string, std::shared_ptr<StockParser>>&);
};


#endif //STOCKSOUTPUTTER_H
