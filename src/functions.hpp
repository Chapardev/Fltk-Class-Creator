#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "precompiled.hpp"

unsigned int GetNumberOfUpperCaseLetters(const std::string &text);
void SeparateWords(std::string &text, char separator);
std::string ToUpper(const std::string &text);
void HandlePunctuation(std::string &text, char punctuation);

#endif
