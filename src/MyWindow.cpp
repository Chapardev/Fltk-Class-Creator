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

        ClassCreator classCreator{className, m_destructorCheckButton.IsChecked(), m_virtualDestructorCheckButton.IsChecked()};
    }
}

MyWindow::MyWindow()
    : Fl_Window{800, 600, "FltkClassCreator"},
      m_classNameInput{100, 10, 230, 30, "Class name:"}, 
      m_saveButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y(), 100, 30, "Generate!"},
      m_destructorCheckButton{m_classNameInput.x(), m_classNameInput.y() + 30, 126, 30, "Add a destructor"},
      m_virtualDestructorCheckButton{   
        m_destructorCheckButton.x() + m_destructorCheckButton.w(), m_destructorCheckButton.y(), 100, 30, "Make it virtual"
      }
{
    auto ButtonCallBack{
        [](Fl_Widget *widget, void *pointer)
        {
            MyWindow *me{static_cast<MyWindow *>(pointer)};
            me->_SaveButtonCallback();
        }
    };

    m_saveButton.callback(ButtonCallBack, this);

    // m_virtualDestructorCheckButton.deactivate();
    m_virtualDestructorCheckButton.tooltip("Works only if the destructor box is checked");

    this->end();
	this->show();
}
