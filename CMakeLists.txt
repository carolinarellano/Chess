cmake_minimum_required(VERSION 3.22.3)
project(SuperCoolChess C)

set(CMAKE_C_STANDARD 99)

add_executable(SuperCoolChess main.c Structs.h Movements.c Movements.h Files.c Files.h Board.c Board.h Events.c Events.h Assets.c Assets.h Check.c Check.h)

# Dependencies
find_package(raylib 4.0.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()
include_directories(Header)
target_link_libraries(${PROJECT_NAME} raylib)