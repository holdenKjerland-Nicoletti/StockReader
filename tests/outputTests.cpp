//
// Created by Holden Nicoletti on 5/20/22.
//
#include <catch2/catch.hpp>
#include "libs/StocksOutputter.h"
#include "libs/Stock.h"

using namespace std;

TEST_CASE("Test StocksOutputter"){
    // Test Creation
    StocksOutputter stocksOutputter = StocksOutputter("../testdata/output.csv");

    // making attributes private
//    REQUIRE(stocksOutputter.outputFileName == "../../testdata/output.csv");
//    REQUIRE(stocksOutputter.outputFile.is_open());
//    stocksOutputter.outputFile.write("test", 4);

    map<string, std::shared_ptr<StockParser>> stockMap;

    Stock stock("aed");
    stock.addTrade("51300003387,aed,96,208");
    stock.addTrade("71300003498,aed,50,300");
    stock.addTrade("71300003499,aed,100,100");
    stockMap["aed"] = (shared_ptr<StockParser>) (new Stock(stock));
    stockMap["abc"] = shared_ptr<StockParser>(new Stock("abc"));
    stockMap["abc"]->addTrade("51305914640,abc,217,50");


    // Manually checking file to match test from stockTests.cpp
    stocksOutputter.writeStocks(stockMap);

    // making ouputfile private
//    REQUIRE(!stocksOutputter.outputFile.is_open());
}