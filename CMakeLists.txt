cmake_minimum_required(VERSION 3.17)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Huffman main.cpp MinimumHeap.h MinimumHeap.cpp BinaryTree.h BinaryTree.cpp SearchTree.h SearchTree.cpp Pair.h Pair.cpp configs.h Huffman.cpp Huffman.h TreeNode.cpp TreeNode.h)