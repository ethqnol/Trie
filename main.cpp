#include <iostream>
#include "trie.h"

int main(){

    Trie test;

    test.insert("hello");
    std::cout << test.search("hello") << std::endl;
}