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

std::string SeparateWords(const std::string &text, char separator)
{
    std::string result{text};
    unsigned int numberOfUpperCaseLetters{GetNumberOfUpperCaseLetters(text)};

    // I have to use two loops because when you insert a character in the string, its length increases
    for (size_t i{0}; i < numberOfUpperCaseLetters; i++)
    {
        for (size_t j{1}; j < result.length(); j++)
        {
            if (std::isupper(result[j]) && result[j-1] != separator)
            {
                result.insert(j, 1, separator);
                break;
            }
        }
    }

    return result;
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

std::string HandlePunctuation(const std::string &text, const std::string &punctuations)
{
    std::string result{text};
    for (const auto &p : punctuations)
    {
        while (result.find(p) != std::string::npos)
        {
            size_t pos{result.find(p)};
            if (pos + 1 < result.size() && std::islower(result[pos+1]))
            {
                result[pos+1] = std::toupper(result[pos+1]);
            }
            result.erase(std::find(result.begin(), result.end(), p));
        }
    }
    return result;
}

std::string CreateClassName(const std::string &className)
{
    std::string result{className};
    if (std::islower(result[0]))
    {
        result[0] = std::toupper(result[0]);
    }

    result = HandlePunctuation(result, " &~\"#'{([-|`\\^@)]=}+/*-<>,?;.:!§");

    // If this conditional statement was omitted there would be issues with the files, as an identifier cannot begin with a digit
    if (std::isdigit(result[0]))
    {
        result.insert(0, 1, '_');
    }

    for (size_t i{0}; i < result.length(); i++)
    {
        if (result[i-1] == '_' && std::islower(result[i]))
        {
            result[i] = std::toupper(result[i]);
        }
    }

    return result;
}
