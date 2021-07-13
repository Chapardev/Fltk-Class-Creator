#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include "MyCheckButton.hpp"

class MyWindow : public Fl_Window
{
private:
	void _SaveButtonCallback();

public:
	MyWindow();

private:
	Fl_Input m_classNameInput;
	Fl_Button m_saveButton;
	MyCheckButton m_destructorCheckButton;
	MyCheckButton m_virtualDestructorCheckButton;
};

#endif // MY_WINDOW_HPP
