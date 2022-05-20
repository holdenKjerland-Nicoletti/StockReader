//
// Created by Holden Nicoletti on 5/20/22.
//
#include <catch2/catch.hpp>
#include "libs/TradesInputter.h"
#include <map>
#include <string>

using namespace std;

TEST_CASE("Test TradesInputter Creation"){
    {
        // check creation opens file and sets fileName
        TradesInputter tradesInputter("../../data/input0.csv");

        // Passed, setting to private
        //    REQUIRE(tradesInputter.inputFileName == "../../data/input2.csv");
        //    REQUIRE(tradesInputter.inputFile.is_open());

        // checking getting symbol correctly
        REQUIRE(getSymbol("51305882461,ada,140,154") == "ada");

        map<string, std::shared_ptr<StockParser>> stockMap;

        // 1 trade: check stock is added to stockMap, and trade is succesully parsed
        tradesInputter.readTrades(stockMap);
        REQUIRE(stockMap["aed"]->toString() == "aed,0,19968,208,208\n");

        // Checking file is closed after reading, inputFile moved to private
//        REQUIRE(!tradesInputter.inputFile.is_open());
    }
    {
        // check creation opens file and sets fileName
        TradesInputter tradesInputter("../../data/input1.csv");
        map<string, std::shared_ptr<StockParser>> stockMap;

        // 1 trade: check stock is added to stockMap, and trade is succesully parsed
        tradesInputter.readTrades(stockMap);
        REQUIRE(stockMap["aed"]->toString() == "aed,20000000111,44968,182,300\n");
        REQUIRE(stockMap["abc"]->toString() == "abc,35094085359,21700,50,50\n");
        REQUIRE(stockMap["zzz"]->toString() == "zzz,0,10000,100,100\n" );
    }
}