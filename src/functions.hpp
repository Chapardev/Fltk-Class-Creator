#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "precompiled.hpp"

// Counts the number of capital letters
unsigned int GetNumberOfUpperCaseLetters(const std::string &text);

// Separates words (which begins with a capital letter) in a string with a certain character
std::string SeparateWords(const std::string &text, char separator);

// Returns a string with upper characters
std::string ToUpper(const std::string &text);

// Deletes punctuations from the text and replace the next letters by their capital one
std::string HandlePunctuation(const std::string &text, const std::string &punctuations);

// Modifies a string to apply class naming conventions (PascalCase and no punctuations)
std::string CreateClassName(const std::string &className);

#endif
