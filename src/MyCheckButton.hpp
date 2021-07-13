#ifndef MY_CHECK_BUTTON_HPP
#define MY_CHECK_BUTTON_HPP

#include "ClassCreator.hpp"

class MyCheckButton : public Fl_Check_Button
{
public:
	MyCheckButton(int x, int y, int width, int height, const char *label);
	
	inline bool IsChecked() const { return m_checked; }

private:
	bool m_checked;
};

#endif // MY_CHECK_BUTTON_HPP
