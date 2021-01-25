include(FetchContent)

cmake_minimum_required(VERSION 3.5)

project(tr-holidays LANGUAGES CXX)

FetchContent_Declare( date_src
  GIT_REPOSITORY https://github.com/HowardHinnant/date.git
  GIT_TAG        v3.0.0  # adjust tag/branch/commit as needed
)
FetchContent_MakeAvailable(date_src)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tr-holidays main.cpp)
target_link_libraries (tr-holidays PRIVATE date::date)
