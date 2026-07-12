#include "test/test.hpp"

// g++ main.cpp math/*.cpp tokenizer/*.cpp -o m 

int main()
{
    Test test;
    test.testTokenizer();
    test.testMatrix();
    test.testVector();

    return 0;
}