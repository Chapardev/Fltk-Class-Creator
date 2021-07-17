#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include "MyInputChoice.hpp"

class MyWindow : public Fl_Window
{
private:
	void _SaveButtonCallback();

public:
	MyWindow();

private:
	Fl_Input m_classNameInput;
	MyCheckButton m_destructorCheckButton;
	MyCheckButton m_virtualDestructorCheckButton;
	Fl_Input m_inheritanceInput;
	MyInputChoice m_inheritanceModeInputChoice;
	MyInputChoice m_headerFileExtensionInputChoice;
	Fl_Button m_saveButton;
};

#endif // MY_WINDOW_HPP
