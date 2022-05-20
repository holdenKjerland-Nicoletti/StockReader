add_executable(tests main.cpp inputTests.cpp)
target_link_libraries(tests StoreLib Catch2::Catch2)