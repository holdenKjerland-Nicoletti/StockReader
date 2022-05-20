#  Quantlab Stock Stream Project

To run executable

    mkdir cmake_build
    cd cmake_build
    cmake ../
    cmake --build .
    ./QuantlabStocks

To view results in output.csv

    cd ../data
Results in "output.csv"

### Project Layout

* libs/
  * Class header and cpp files
* tests/
  * Catch2 tests for each class and main
* data/
  * input.csv
  * output.csv
* main.cpp
  * main function for QuantlabStocks executable

### Pseudocode Strategy
#### Main()
* create ordered_map<char[3], StockParser*> stocksMap
    * used to map a symbol to Stock object in O(1) time

* TradesInputter('input.csv')
* TradesInputter.readTrades

* StocksOutputter
* StocksOutputter.writeStocks()

### Classes
#### Abstract Class (Interface) StockParser
Doing this to follow the Dependency Inversion Principle because TradesInputter and StocksOutputter (high-level class) will rely on a map with Stocks.

  * Virtual Methods
      * parseTrade(line)
      * toString()

#### Class Stock implements StockParser
  * Attributes:
      * symbol (string)
          * 3 character unique identifier for a financial instrument (Stock, future etc.)
      *  maxTimeGap (long long) = 0
          * Time gap = Amount of time that passes between consecutive trades of a symbol.
          * If only 1 trade is in the file then the gap is 0.
          * NOTE: for all time values we must use long long because the number of microseconds in day is greater than the max value of an unsigned integer
      *  lastTradeTime (long long) = -1
          * time of last trade for this stock
          * NOTE: for all time values we must use long long because the number of microseconds in day is greater than the max value of an unsigned integer
      * totalVolumeTraded (int) = 0
          * Sum of the quantity for all trades in a symbol.
      * totalUnitsTraded (int) = 0
          * Total units traded in a symbol.
      * maxTradePrice (int) = 0
          * Max Trade Price
      * weightedAvgPrice (int) = 0
          * Average price per unit traded not per trade.
      
      * Optional (not included):
          * Create a Trade class and include vector<Trade*> list of all trades for stock
  
  * Methods:
      * addTrade(trade)
          * Update values of Stock from new trade
      * weightedAvgPrice()
          * return totalVolumeTraded/totalUnitsTraded
      * toString()
          * return <symbol>,<MaxTimeGap>,<Volume>,<weightedAveragePrice()>,<MaxPrice>

#### Class TradesInputter
* Attributes:
    * string inputFileName
    * ifstream inputFile
  
* Methods:
    * TradesInputter(string inputFileName)
        * open ifstream
    * readTrades(stockMap)
        * get each line in file
            * get symbol (after first comma)
            * if symbol not in stockMap
                * create Stock(symbol)
                * add Stock to stockMap
            * Stock.addTrade(line)
        * close ofstream

#### Class StocksOutputter
* Attributes:
    * string outputFileName = "output.csv"
    * ofstream outputFile
  
* Methods:
    * StocksOutputter()
        * open ofstream
    * writeStocks()
        * for stock in stocksMap
            * write stock.toString()
        * close ofstream

### Resources
* TDD: 
  * https://www.youtube.com/watch?v=N2gTxeIHMP0&ab_channel=CppCon
  * https://www.youtube.com/watch?v=w2CzYK5ZJys&ab_channel=JetBrainsTV
* SOLID strategies:
  * https://www.digitalocean.com/community/conceptual_articles/s-o-l-i-d-the-first-five-principles-of-object-oriented-design
