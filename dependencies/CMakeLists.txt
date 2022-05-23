include(FetchContent)

# https://www.youtube.com/watch?v=w2CzYK5ZJys&ab_channel=JetBrainsTV
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.4)


# https://stackoverflow.com/questions/55376111/how-to-build-and-link-google-benchmark-using-cmake-in-windows
# https://stackoverflow.com/a/64853449
#FetchContent_Declare(googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG v1.10.x)
#
#FetchContent_Declare(benchmark
#        GIT_REPOSITORY https://github.com/google/benchmark.git
#        GIT_TAG master)

FetchContent_MakeAvailable(
        Catch2
)