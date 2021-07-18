#include "MyButton.hpp"

MyButton::MyButton(int x, int y, int width, int height, const char *label, Fl_Callback *callback, void *pointer)
    : Fl_Button{x, y, width, height, label}
{
    this->callback(callback, pointer);
}
