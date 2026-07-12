#include "tokenizer.hpp"

void Tokenizer::replaceAll(string &str, const string &from, const string &to)
{
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != string::npos)
    {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}

void Tokenizer::normalizeText(string &textToNormalize)
{
    replaceAll(text, "á", "a");
    replaceAll(text, "é", "e");
    replaceAll(text, "í", "i");
    replaceAll(text, "ó", "o");
    replaceAll(text, "ú", "u");
    replaceAll(text, "Á", "a");
    replaceAll(text, "É", "e");
    replaceAll(text, "Í", "i");
    replaceAll(text, "Ó", "o");
    replaceAll(text, "Ú", "u");
    replaceAll(text, "ü", "u");
    replaceAll(text, "Ü", "u");
    replaceAll(text, "ñ", "n");
    replaceAll(text, "Ñ", "n");

    for (char &c : textToNormalize)
    {
        if (isalnum(c))
        {
            c = tolower(c);
        }
        else if (!isspace(c))
        {
            c = ' ';
        }
    }
}

void Tokenizer::buildVocabulary()
{
    istringstream stream(text);
    string token;

    while (stream >> token)
    {
        if (tokenToId.find(token) == tokenToId.end())
        {
            int id = tokenToId.size();
            tokenToId[token] = id;
            idToToken.push_back(token);
        }
    }
}

void Tokenizer::loadText(const string &dirCorpus)
{
    text.clear();
    ifstream file(dirCorpus);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << dirCorpus << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        text += line + " ";
    }

    file.close();
}

vector<int> Tokenizer::encode(const string &input)
{
    vector<int> encoded;
    string normalizedInput = input;
    normalizeText(normalizedInput);
    istringstream stream(normalizedInput);
    string token;

    while (stream >> token)
    {
        if (tokenToId.find(token) != tokenToId.end())
        {
            encoded.push_back(tokenToId[token]);
        }
        else
        {
            encoded.push_back(tokenToId["<UNK>"]);
        }
    }

    return encoded;
}

string Tokenizer::decode(const vector<int> &encoded)
{
    string decoded;
    for (int id : encoded)
    {
        if (id >= 0 && id < idToToken.size())
        {
            decoded += idToToken[id] + " ";
        }
        else
        {
            decoded += "<UNK> ";
        }
    }
    return decoded;
}

void Tokenizer::tokenization(const string &dirCorpus)
{
    loadText(dirCorpus);
    normalizeText(text);
    buildVocabulary();
}