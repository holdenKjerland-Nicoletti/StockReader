#include <iostream>
#include "libs/TradesInputter.h"
#include "libs/StocksOutputter.h"

using namespace std;

int main() {
    // Maps symbol to Stock
    map<string, shared_ptr<StockParser>> stockMap;

    TradesInputter tradesInputter = TradesInputter("../data/input.csv");
    tradesInputter.readTrades(stockMap);

    StocksOutputter stockOutputter = StocksOutputter("../data/output.csv");
    stockOutputter.writeStocks(stockMap);
    return 0;
}
