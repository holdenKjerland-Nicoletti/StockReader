include(FetchContent)

# https://www.youtube.com/watch?v=w2CzYK5ZJys&ab_channel=JetBrainsTV
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.4)
FetchContent_MakeAvailable(Catch2)