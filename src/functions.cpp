#include "functions.hpp"

unsigned int GetNumberOfUpperCaseLetters(const std::string &text)
{
    unsigned int result{0};
    for (size_t i{0}; i < text.length(); i++)
    {
        if (std::isupper(text[i]) && i > 0)
        {
            result++;
        }
    }
    return result;
}

void SeparateWords(std::string &text, char separator)
{
    unsigned int numberOfUpperCaseLetters{GetNumberOfUpperCaseLetters(text)};

    // I have to use two loops because when you insert a character in the string, its length increases
    for (size_t i{0}; i < numberOfUpperCaseLetters; i++)
    {
        for (size_t j{0}; j < text.length(); j++)
        {
            if (std::isupper(text[j]) && j > 0 && text[j-1] != separator)
            {
                text.insert(j, 1, separator);
                break;
            }
        }
    }
}

std::string ToUpper(const std::string &text)
{
    std::string result{text};
    for (size_t i{0}; i < text.length(); i++)
    {
        result[i] = std::toupper(text[i]);
    }
    return result;
}

// Deletes a punctuation from the text and replace the next letter by its capital
void HandlePunctuation(std::string &text, char punctuation)
{
    while (text.find(punctuation) != std::string::npos)
    {
        size_t pos{text.find(punctuation)};
        if (pos + 1 < text.size() && std::islower(text[pos+1]))
        {
            text[pos+1] = std::toupper(text[pos+1]);
        }
        text.erase(std::find(text.begin(), text.end(), punctuation));
    }
}
