find_package(benchmark REQUIRED)

set(BENCHMARK_OUT "benchmark_results.txt")
set(BENCHMARK_OUT_FORMAT console)

add_executable(benchmark_tests read_stocks.cpp)
target_link_libraries(benchmark_tests StoreLib benchmark::benchmark)