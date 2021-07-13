#include "MyWindow.hpp"

void MyWindow::_SaveButtonCallback()
{
    std::string className{m_classNameInput.value()};

    // If the input text is not empty
    if (className[0])
    {
        CreateClassName(className);

        std::string inheritedClassName{m_inheritanceInput.value()};
        if (m_inheritanceInput.value()[0])
        {
            CreateClassName(inheritedClassName);
        }

        ClassCreator classCreator{
            className, m_destructorCheckButton.IsChecked(), m_virtualDestructorCheckButton.IsChecked(), 
            m_inheritanceInput.value()[0] ? inheritedClassName : ""
        };
    }
}

MyWindow::MyWindow()
    : Fl_Window{800, 600, "FltkClassCreator"},
      m_classNameInput{100, 10, 230, 30, "Class name:"}, 
      m_saveButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y(), 100, 30, "Generate!"},
      m_destructorCheckButton{m_classNameInput.x(), m_classNameInput.y() + 30, 126, 30, "Add a destructor"},
      m_virtualDestructorCheckButton{   
        m_destructorCheckButton.x() + m_destructorCheckButton.w() + 10, m_destructorCheckButton.y(), 108, 30, "Make it virtual"
      },
      m_inheritanceInput{m_classNameInput.x(), m_destructorCheckButton.y() + 30, m_classNameInput.w(), m_classNameInput.h(), "Inherits from:"}
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
