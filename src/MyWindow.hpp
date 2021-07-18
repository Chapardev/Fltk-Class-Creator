#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include "MyButton.hpp"

class MyWindow : public Fl_Window
{
private:
	void _PathSelectionButtonCallback();
	void _GenerateButtonCallback();

public:
	MyWindow();

private:
	Fl_Input m_classNameInput;

	MyCheckButton m_destructorCheckButton;
	MyCheckButton m_virtualDestructorCheckButton;

	Fl_Input m_inheritanceInput;
	MyInputChoice m_inheritanceModeInputChoice;

	MyInputChoice m_headerFileExtensionInputChoice;
	MyInputChoice m_implementationFileExtensionInputChoice;

	Fl_Input m_pathSelectionInput;
	MyButton m_pathSelectionButton;

	MyButton m_generateButton;
};

#endif // MY_WINDOW_HPP
