#ifndef MY_BUTTON_HPP
#define MY_BUTTON_HPP

#include "MyInputChoice.hpp"

class MyButton : public Fl_Button
{
public:
	MyButton(int x, int y, int width, int height, const char *label, Fl_Callback *callback, void *pointer);
};

#endif // MY_BUTTON_HPP
