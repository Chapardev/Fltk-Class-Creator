#include "MyWindow.hpp"

void MyWindow::_SaveButtonCallback()
{
    // If the input text is not empty
    if (m_classNameInput.value()[0])
    {
        const std::string className{CreateClassName(m_classNameInput.value())};
        const std::string inheritedClassName{m_inheritanceInput.value()[0] ? CreateClassName(m_inheritanceInput.value()) : ""};

        std::string inheritanceMode{m_inheritanceModeInputChoice.value()};
        if (!((inheritanceMode == "public") || (inheritanceMode == "protected") || (inheritanceMode == "private")))
        {
            inheritanceMode = "public";
        }

        const char *directoryPath{fl_dir_chooser("Select folder to generate files", "")};

        if (directoryPath)
        {
            ClassCreator classCreator{
                className, m_destructorCheckButton.IsChecked(), m_virtualDestructorCheckButton.IsChecked(), inheritedClassName, inheritanceMode,
                directoryPath
            };
        }
    }
}

MyWindow::MyWindow()
    : Fl_Window{800, 600, "FltkClassCreator"},
      m_classNameInput{100, 10, 230, 30, "Class name:"}, 
      m_destructorCheckButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y(), 126, 30, "Add a destructor"},
      m_virtualDestructorCheckButton{   
        m_destructorCheckButton.x() + m_destructorCheckButton.w() + 10, m_destructorCheckButton.y(), 108, 30, "Make it virtual"
      },
      m_inheritanceInput{
          m_classNameInput.x(), m_classNameInput.y() + m_classNameInput.h() + 10, m_classNameInput.w(), m_classNameInput.h(), "Inherits from:"
      },
      m_inheritanceModeInputChoice{m_inheritanceInput.x() + m_inheritanceInput.w() + 10, m_inheritanceInput.y(), 100, 30},
      m_saveButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y() + 200, 100, 30, "Generate!"}
{
    m_virtualDestructorCheckButton.tooltip("Works only if the destructor box is checked");

    m_inheritanceModeInputChoice.value("public");
    m_inheritanceModeInputChoice.add("public");
    m_inheritanceModeInputChoice.add("protected");
    m_inheritanceModeInputChoice.add("private");

    auto ButtonCallBack{
        [](Fl_Widget *widget, void *pointer)
        {
            MyWindow *me{static_cast<MyWindow *>(pointer)};
            me->_SaveButtonCallback();
        }
    };

    m_saveButton.callback(ButtonCallBack, this);

    this->end();
    this->show();
}
