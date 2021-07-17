#include "MyCheckButton.hpp"

MyCheckButton::MyCheckButton(int x, int y, int width, int height, const char *label, const char *tooltip)
    : Fl_Check_Button{x, y, width, height, label}, m_checked{false}
{
    if (!std::string(tooltip).empty())
    {
        this->tooltip(tooltip);
    }

    auto MyCallback{
        [](Fl_Widget *widget, void *pointer)
        {
            MyCheckButton *me{static_cast<MyCheckButton *>(pointer)};
            me->m_checked = !me->m_checked;
        }
    };

    this->callback(MyCallback, this);
}
