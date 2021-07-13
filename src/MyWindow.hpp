#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include "ClassCreator.hpp"

class MyWindow : public Fl_Window
{
private:
	void _SaveButtonCallback();
	static void _StaticSaveButtonCallback(Fl_Widget *widget, void *pointer);

	void _DestructorCheckButtonCallback();
	static void _StaticDestructorCheckButtonCallback(Fl_Widget *widget, void *pointer);

public:
	MyWindow();

private:
	Fl_Input m_classNameInput;
	Fl_Button m_saveButton;
	Fl_Check_Button m_destructorCheckButton;
	bool m_checked;
};

#endif // MY_WINDOW_HPP
