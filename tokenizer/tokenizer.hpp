#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Tokenizer
{

private:
    string text;
    size_t position;
    unordered_map<string, int> tokenToId;
    vector<string> idToToken;

public:
    Tokenizer() : position(0)
    {

        tokenToId["<PAD>"] = 0;
        tokenToId["<UNK>"] = 1;
        tokenToId["<BOS>"] = 2;
        tokenToId["<EOS>"] = 3;

        idToToken =
            {
                "<PAD>",
                "<UNK>",
                "<BOS>",
                "<EOS>"};
    }

    void loadText(const string &dirCorpus);

    void normalizeText(string &textToNormalize);

    void buildVocabulary();

    void tokenization(const string &dirCorpus);

    vector<int> encode(const string &input);
    string decode(const vector<int> &encoded);

    int vocabularySize() const
    {
        return tokenToId.size();
    }

    void printVocabulary() const
    {
        for (size_t i = 0; i < idToToken.size(); i++)
        {
            cout << i << " : " << idToToken[i] << endl;
        }
    }

    void replaceAll(string &str, const string &from, const string &to);

};