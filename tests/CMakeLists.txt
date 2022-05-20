add_executable(tests main.cpp inputTests.cpp stockTests.cpp)
target_link_libraries(tests StoreLib Catch2::Catch2)