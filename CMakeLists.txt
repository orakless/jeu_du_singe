cmake_minimum_required(VERSION 3.24)
project(singe)

set(CMAKE_CXX_STANDARD 11)

add_executable(singe main.cpp src/hstring.cpp src/hstring.h src/types_const.h src/tree.cpp src/tree.h src/text_file.cpp src/text_file.h src/file.cpp src/file.h src/node.cpp src/node.h src/range.cpp src/range.h tests/test_file.cpp tests/tests.h tests/test_tree.cpp tests/test_hstring.cpp src/player.cpp src/player.h src/pile.cpp src/pile.h src/pNode.cpp src/pNode.h src/game.cpp src/game.h)
add_compile_options(-Wall -Wextra -Wpedantic -Werrors)