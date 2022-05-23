//
// Created by Holden Nicoletti on 5/22/22.
//

#include <benchmark/benchmark.h>

#include "libs/TradesInputter.h"

using namespace std;

static void BM_read_input(benchmark::State& state) {

    map<string, shared_ptr<StockParser>> stockMap;
    TradesInputter tradesInputter = TradesInputter("../../data/input.csv");

    for (auto _ : state)
        // Maps symbol to Stock
        tradesInputter.readTrades(stockMap);
}
// Register the function as a benchmark
BENCHMARK(BM_read_input);

static void BM_read_input2(benchmark::State& state) {

    vector<vector<vector<shared_ptr<StockParser>>>> stockVec(26, vector<vector<shared_ptr<StockParser>>>(26, vector<shared_ptr<StockParser>>(26, NULL)));
    TradesInputter tradesInputter = TradesInputter("../../data/input.csv");

    for (auto _ : state) {
        // Maps symbol to Stock
        tradesInputter.readTrades2(stockVec);

    }
}
// Register the function as a benchmark
BENCHMARK(BM_read_input2);

BENCHMARK_MAIN();