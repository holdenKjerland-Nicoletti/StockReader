//
// Created by Holden Nicoletti on 5/20/22.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <stdio.h>

#include "libs/TradesInputter.h"
#include "libs/StocksOutputter.h"

using namespace std;

TEST_CASE("Testing Main function"){
    // Maps symbol to Stock
    map<string, shared_ptr<StockParser>> stockMap;
    REQUIRE(stockMap.empty());

    TradesInputter tradesInputter = TradesInputter("../testdata/input1.csv");
    tradesInputter.readTrades(stockMap);
    REQUIRE(stockMap["aed"]->toString() == "aed,20000000111,44968,182,300\n");
    REQUIRE(stockMap["abc"]->toString() == "abc,35094085359,21700,50,50\n");
    REQUIRE(stockMap["zzz"]->toString() == "zzz,0,10000,100,100\n" );

    // testing even if file does not exist
    remove("../testdata/output.csv");

    StocksOutputter stockOutputter = StocksOutputter("../testdata/output.csv");
    stockOutputter.writeStocks(stockMap);
    ifstream outputTest;
    outputTest.open("../testdata/output.csv", ios::in);
    string line;
    getline(outputTest, line);
    REQUIRE(line == "abc,35094085359,21700,50,50");
    getline(outputTest, line);
    REQUIRE(line == "aed,20000000111,44968,182,300");
    getline(outputTest, line);
    REQUIRE(line == "zzz,0,10000,100,100");
}