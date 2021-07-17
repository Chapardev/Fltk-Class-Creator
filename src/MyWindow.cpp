#include "MyWindow.hpp"

void MyWindow::_SaveButtonCallback()
{
    // If the input text is not empty
    if (m_classNameInput.value()[0])
    {
        const char *directoryPath{fl_dir_chooser("Select folder to generate files", "")};

        if (directoryPath)
        {
            ClassCreator classCreator{
                {CreateClassName(m_classNameInput.value()), m_inheritanceInput.value()[0] ? CreateClassName(m_inheritanceInput.value()) : ""},
                m_destructorCheckButton.IsChecked(), m_virtualDestructorCheckButton.IsChecked(),
                m_inheritanceModeInputChoice.GetValue(), {m_headerFileExtensionInputChoice.GetValue(), 
                m_implementationFileExtensionInputChoice.GetValue()}, directoryPath
            };
        }
    }
}

MyWindow::MyWindow()
    : Fl_Window{800, 600, "FltkClassCreator"},
      m_classNameInput{100, 10, 230, 30, "Class name:"}, 
      m_destructorCheckButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y(), 126, 30, "Add a destructor"},
      m_virtualDestructorCheckButton{   
        m_destructorCheckButton.x() + m_destructorCheckButton.w() + 10, m_destructorCheckButton.y(), 108, 30, "Make it virtual",
        "Works only if the destructor box is checked"
      },
      m_inheritanceInput{
          m_classNameInput.x(), m_classNameInput.y() + m_classNameInput.h() + 10, m_classNameInput.w(), m_classNameInput.h(), "Inherits from:"
      },
      m_inheritanceModeInputChoice{
          m_inheritanceInput.x() + m_inheritanceInput.w() + 10, m_inheritanceInput.y(), 100, 30, 
          {"public", "protected", "private"}
      },
      m_headerFileExtensionInputChoice{
          m_inheritanceModeInputChoice.x() + m_inheritanceModeInputChoice.w() + 10, 
          m_inheritanceModeInputChoice.y(), 
          m_inheritanceModeInputChoice.w(), m_inheritanceModeInputChoice.h(),
          {"hpp", "h", "hh"}
      },
      m_implementationFileExtensionInputChoice{
          m_headerFileExtensionInputChoice.x() + m_headerFileExtensionInputChoice.w() + 10, 
          m_headerFileExtensionInputChoice.y(), 
          m_headerFileExtensionInputChoice.w(), m_headerFileExtensionInputChoice.h(),
          {"cpp", "cc", "cxx"}
      },
      m_saveButton{m_classNameInput.x() + m_classNameInput.w() + 10, m_classNameInput.y() + 200, 100, 30, "Generate!"}
{
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
