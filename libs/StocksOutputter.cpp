//
// Created by Holden Nicoletti on 5/20/22.
//

#include "StocksOutputter.h"

using namespace std;

StocksOutputter::StocksOutputter(const string fileName):outputFileName(fileName){
    outputFile.open(outputFileName);
}

StocksOutputter::StocksOutputter(){
    outputFile.open(outputFileName);
}

void StocksOutputter::writeStocks(const std::map<std::string, std::shared_ptr<StockParser>>& stockMap){
    if(outputFile.is_open()){
        for(auto stock: stockMap){
            outputFile << stock.second->toString();
        }
        outputFile.close();
    }else{
        cout<<"Failed to Open File"<<endl;
        exit(-1);
    }
}
