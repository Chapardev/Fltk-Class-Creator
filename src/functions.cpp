#include "functions.hpp"

unsigned int GetNumberOfUpperCaseLetters(const std::string &text)
{
    unsigned int result{0};
    for (size_t i{1}; i < text.length(); i++)
    {
        if (std::isupper(text[i]))
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
        for (size_t j{1}; j < text.length(); j++)
        {
            if (std::isupper(text[j]) && text[j-1] != separator)
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
    for (size_t i{0}; i < result.length(); i++)
    {
        if (std::islower(result[i]))
        {
            result[i] = std::toupper(result[i]);
        }
    }
    return result;
}

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

void CreateClassName(std::string &className)
{
    if (std::islower(className[0]))
    {
        className[0] = std::toupper(className[0]);
    }

    for (const auto &c : " &~\"#'{([-|`\\^@)]=}+/*-<>,?;.:!§")
    {
        HandlePunctuation(className, c);
    }

    // If this conditional statement was omitted there would be issues with the files, as an identifier cannot begin with a digit
    if (std::isdigit(className[0]))
    {
        className.insert(0, 1, '_');
    }

    // _myClass will become _MyClass
    for (size_t i{0}; i < className.length(); i++)
    {
        if (className[i-1] == '_' && std::islower(className[i]))
        {
            className[i] = std::toupper(className[i]);
        }
    }
}
