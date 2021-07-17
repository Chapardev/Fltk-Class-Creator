#ifndef MY_CHECK_BUTTON_HPP
#define MY_CHECK_BUTTON_HPP

#include "ClassCreator.hpp"

// Check button that updates each time it is checked or not
class MyCheckButton : public Fl_Check_Button

{
public:
	// Text parameters must be const char * because if you use std::string, there will be strange issues at runtime
	MyCheckButton(int x, int y, int width, int height, const char *label, const char *tooltip="");
	bool IsChecked() const { return m_checked; }

private:
	bool m_checked;
};

#endif // MY_CHECK_BUTTON_HPP
