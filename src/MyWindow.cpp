#include "MyWindow.hpp"

void MyWindow::_SaveButtonCallback()
{
    std::string className(m_classNameInput.value());

    // If the input text is not empty
    if (className[0])
    {
        if (std::islower(className[0]))
        {
            className[0] = std::toupper(className[0]);
        }

        for (const auto &c : " &~\"#'{([-|`_\\^@)]=}+/*-<>,?;.:!§")
        {
            HandlePunctuation(className, c);
        }

        ClassCreator classCreator(className);
    }
}

void MyWindow::_StaticSaveButtonCallback(Fl_Widget *widget, void *pointer)
{
    MyWindow *me = static_cast<MyWindow *>(pointer);
    me->_SaveButtonCallback();
}

MyWindow::MyWindow()
    : Fl_Window(800, 600, "FltkClassCreator"),
      m_classNameInput(100, 10, 230, 30, "Class name:"), 
      m_saveButton(m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y(), 100, 30, "Save!")
{
    m_saveButton.callback(this->_StaticSaveButtonCallback, this);

    this->end();
	this->show();
}
