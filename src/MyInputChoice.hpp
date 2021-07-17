#ifndef MY_INPUT_CHOICE_HPP
#define MY_INPUT_CHOICE_HPP

#include "MyCheckButton.hpp"

class MyInputChoice : public Fl_Input_Choice
{
public:
	MyInputChoice(int x, int y, int width, int height, const std::array<std::string, 3> &items);

	// Returns a correct value: if the input value is not part of the items, the default one is returned
	std::string GetValue() const
	{
		return std::any_of(m_items.begin(), m_items.end(), [=](auto s){ return std::string(this->value()) == s; }) ? this->value() : m_items[0];
	}

private:
	std::array<std::string, 3> m_items;
};

#endif // MY_INPUT_CHOICE_HPP
