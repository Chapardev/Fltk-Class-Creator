#include "MyWindow.hpp"

void MyWindow::_SaveButtonCallback()
{
    std::string className{m_classNameInput.value()};

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

        // If this conditional statement was omitted there would be issues with the files, as an identifier cannot begin with a digit
        if (std::isdigit(className[0]))
        {
            className.insert(0, 1, '_');
        }

        ClassCreator classCreator{className, m_checked};
    }
}

void MyWindow::_StaticSaveButtonCallback(Fl_Widget *widget, void *pointer)
{
    MyWindow *me{static_cast<MyWindow *>(pointer)};
    me->_SaveButtonCallback();
}

void MyWindow::_DestructorCheckButtonCallback()
{
    m_checked = !m_checked;
}

void MyWindow::_StaticDestructorCheckButtonCallback(Fl_Widget *widget, void *pointer)
{
    MyWindow *me{static_cast<MyWindow *>(pointer)};
    me->_DestructorCheckButtonCallback();
}

MyWindow::MyWindow()
    : Fl_Window{800, 600, "FltkClassCreator"},
      m_classNameInput{100, 10, 230, 30, "Class name:"}, 
      m_saveButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y(), 100, 30, "Save!"},
      m_destructorCheckButton{m_classNameInput.x(), m_classNameInput.y() + 30, 126, 30, "Add a destructor"},
      m_checked{false}
{
    m_saveButton.callback(this->_StaticSaveButtonCallback, this);
    m_destructorCheckButton.callback(this->_StaticDestructorCheckButtonCallback, this);

    this->end();
	this->show();
}
