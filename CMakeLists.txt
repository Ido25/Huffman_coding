cmake_minimum_required(VERSION 3.17)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Huffman main.cpp Heap.h Heap.cpp Tree.h Tree.cpp SearchTree.h SearchTree.cpp)