//
// Created by Holden Nicoletti on 5/20/22.
//
#include <catch2/catch.hpp>
#include "libs/Stock.h"
#include <map>
#include <memory>

using namespace std;

TEST_CASE("Test Stock Class Functionality"){

    // Creation with symbol
    Stock stock("aed");
    REQUIRE( stock.getSymbol() == "aed" );

    // checking init values
    auto vals = stock.getValues();
    REQUIRE( vals[0] == -1 );
    for(int i = 1; i< 5; i++){
        REQUIRE( vals[i] == 0 );
    }

    // made parseTrade() private
//    // checking trade parsing
//    vals = stock.parseTrade("51300003387,aed,96,208");
//    REQUIRE( vals[0] == 51300003387 );
//    REQUIRE( vals[1] == 96 );
//    REQUIRE( vals[2] == 208 );

    // checking add trade
    stock.addTrade("51300003387,aed,96,208");
    vals = stock.getValues();
    REQUIRE( vals[0] == 51300003387 ); // lastTradeTime
    REQUIRE( vals[1] == 0 ); // maxTimeGap
    REQUIRE( vals[2] ==  19968 ); // totalVolumeTraded
    REQUIRE( vals[3] ==  96 ); // totalUnitsTraded
    REQUIRE( vals[4] ==  208 ); // maxTradePrice


    // checking adding 2nd trade
    stock.addTrade("71300003498,aed,50,300");
    vals = stock.getValues();
    REQUIRE( vals[0] == 71300003498 ); // lastTradeTime
    REQUIRE( vals[1] == 20000000111 ); // maxTimeGap
    REQUIRE( vals[2] == 34968 ); // totalVolumeTraded
    REQUIRE( vals[3] ==  146 ); // totalUnitsTraded
    REQUIRE( vals[4] ==  300 ); // maxTradePrice

    // checking adding 3rd trade (not max time gap or max trade price)
    stock.addTrade("71300003499,aed,100,100");
    vals = stock.getValues();
    REQUIRE( vals[0] == 71300003499 ); // lastTradeTime
    REQUIRE( vals[1] == 20000000111 ); // maxTimeGap
    REQUIRE( vals[2] == 44968 ); // totalVolumeTraded
    REQUIRE( vals[3] ==  246 ); // totalUnitsTraded
    REQUIRE( vals[4] ==  300 ); // maxTradePrice

    // moving to private method
//    // checking weightedAvgPrice()
//    REQUIRE( stock.weightedAvgPrice() == 182 );

    // checking toStringMethod
    REQUIRE( stock.toString() == "aed,20000000111,44968,182,300\n" );

    // testing StockParser interface for symbol map
    map<string, shared_ptr<StockParser>> stockMap;
    stockMap["aed"] = (shared_ptr<StockParser>) (new Stock(stock));
    stockMap["abc"] = shared_ptr<StockParser>(new Stock("abc"));
    stockMap["abc"]->addTrade("51305914640,abc,217,50");
    int i = 0;
    for(auto s: stockMap){
        if(i){
            REQUIRE(s.second->toString() == "aed,20000000111,44968,182,300\n" );
        }else{
            REQUIRE(s.second->toString() == "abc,0,10850,50,50\n" );
        }
        i++;
    }
}
