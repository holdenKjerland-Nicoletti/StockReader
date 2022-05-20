#  Quantlab Stock Stream Project

## Objects

<!--### Class Trade-->
<!--1. Single Responsibility Principle: Responsible for storing trade data from input line-->
<!--2. Open Closed Principle: If format of each line changed, you can simply overwrite Constructor-->
<!--3. Liskov Substitution Principle: N/A-->
<!--4. Interface Segregation Principle: -->
<!--5. Dependency Inversion Principle-->
<!--    * Attributes:-->
<!--        * int timeStamp-->
<!--            * value indicating the microseconds since midnight.-->
<!--        * int quantity-->
<!--            * Amount traded-->
<!--        * int price-->
<!--            * Price of the trade for that financial instrument.-->
<!--        -->
<!--        * Optional (not included):-->
<!--            * char[3] symbol-->
<!--                * 3 character unique identifier for a financial instrument (Stock, future etc.)-->
<!--                * Not needed because Stock has symbol-->
<!--                -->
<!--        * Methods:-->
<!--            * Trade(line)-->
<!--                * Split line by commas into <TimeStamp>,<Symbol>,<Quantity>,<Price> accordingly-->
<!--                * Set Trade values-->
### Abstract Class (Interface) StockParser
Doing this so as to follow Dependency Inversion Principle because TradesInputter and StocksOutputter (high-level class) will rely on an abstraction and not a concretion

    * Virtual Methods
        * parseTrade(line)
        * toString()

### Class Stock implements StockParser
    * Attributes:
        * char[3] symbol
            * 3 character unique identifier for a financial instrument (Stock, future etc.)
        * int maxTimeGap = 0
            * Time gap = Amount of time that passes between consecutive trades of a symbol.
            * If only 1 trade is in the file then the gap is 0.
        * int lastTradeTime
            * time of last trade for this stock
        * int totalVolumeTraded = 0
            * Sum of the quantity for all trades in a symbol.
        * int totalUnitsTraded = 0
            * Total units traded in a symbol.
        * int maxTradePrice
            * Max Trade Price
        * int weightedAvgPrice
            * Average price per unit traded not per trade.
        
        * Optional (not included):
            * vector<Trade*> list of all trades for stock
    
    * Methods:
        * void parseTrade(line)
            * parseValues of line
            * check maxTimeGap, maxTradePrice
            * increase totalVolumeTraded
            * update lastTradeTime
        * int weightedAvgPrice()
            * return totalVolumeTraded/totalUnitsTraded
        * toString()
            * return <symbol>,<MaxTimeGap>,<Volume>,<weightedAveragePrice()>,<MaxPrice>

### Class TradesInputter
    * Attributes:
        * string inputFileName
        * ifstream inputFile
    
    * Methods:
        * TradesInputter(string inputFileName)
            * open ifstream
        * readTrades()
            * get each line in file
                * get symbol (after first comma)
                * if symbol not in stockMap
                    * create Stock(symbol)
                    * add Stock to stockMap
                * Stock.parseTrade(line)
            * close ofstream

### Class StocksOutputter
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

## Strategy
* main
    * ordered_map<char[3], StockParser*> stocksMap
        * used to map a symbol to Stock object in O(1) time

    * TradesInputter('input.csv')
    * TradesInputter.readTrades

    * StocksOutputter
    * StocksOutputter.writeStocks()

    * TODO: Testing
