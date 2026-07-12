#include "../tokenizer/tokenizer.hpp"
#include "../math/math.hpp"
#include <iostream>
#include <vector>

class Test
{
    private:
        Tokenizer tokenizer;
        Matrix matrix;
        Vector vector;

    public:
        Test() : tokenizer(), matrix(2, 2), vector(2) {}

        void testTokenizer()
        {
            tokenizer.tokenization("test/test_corpus.txt");
            string testInput = "Prueba de tokenizacion y decodificacion.";
            std::vector<int> encoded = tokenizer.encode(testInput);
            for (int id : encoded)
            {
                std::cout << id << " ";
            }
            std::cout << std::endl;
            std::cout << "Decoded: " << tokenizer.decode(encoded) << std::endl;

            std::cout << "tamaño del vocabulario: " << tokenizer.vocabularySize() << std::endl;
            std::cout << "Vocabulario: " << std::endl;
            tokenizer.printVocabulary();

        }

        void testMatrix()
        {
            matrix.fill(1.0);
            Matrix result = matrix + matrix;
            std::cout << "Matrix addition result: " << std::endl;
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    std::cout << result(i, j) << " ";
                }
                std::cout << std::endl;
            }
        }

        void testVector()
        {
            vector[0] = 1.0;
            vector[1] = 2.0;
            Vector result = vector * 2.0;
            std::cout << "Vector scalar multiplication result: ";
            for (int i = 0; i < result.getSize(); ++i)
            {
                std::cout << result[i] << " ";
            }
            std::cout << std::endl;
        }

        void runTests()
        {
            testTokenizer();
            testMatrix();
            testVector();
        }
};

