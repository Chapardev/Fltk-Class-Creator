#include "MyInputChoice.hpp"

MyInputChoice::MyInputChoice(int x, int y, int width, int height, const std::array<std::string, 3> &items)
    : Fl_Input_Choice{x, y, width, height}, m_items{items}
{
    // Sets the default value
    this->value(items[0].c_str());

    for (const auto &item : m_items)
    {
        this->add(item.c_str());
    }
}
