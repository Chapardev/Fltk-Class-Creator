#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "precompiled.hpp"

// Counts the number of capital letters (ignores the first character)
unsigned int GetNumberOfUpperCaseLetters(const std::string &text);

// Separates words (which begins with a capital letter) in a string with a certain character
void SeparateWords(std::string &text, char separator);

// Returns a string with upper characters
std::string ToUpper(const std::string &text);

// Deletes a punctuation from the text and replace the next letter by its capital one
void HandlePunctuation(std::string &text, char punctuation);

// Modifies a string to apply class naming conventions (PascalCase and no punctuations)
void CreateClassName(std::string &className);

#endif
