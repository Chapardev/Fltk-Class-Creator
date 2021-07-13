#include "ClassCreator.hpp"

ClassCreator::ClassCreator(const std::string &className, bool destructor, bool isVirtual,  const std::string &inheritedClass)
    : m_className{className}, m_inheritedClassName{inheritedClass}, 
      m_upperCaseClassName{ToUpper(SeparateWords(m_className, '_')) + "_HPP"}, 
      m_hasDestructor{destructor}, m_isDestructorVirtual{isVirtual}
{
    this->CreateHppFile();
    this->CreateCppFile();
}

void ClassCreator::_OpenFile(const std::string &fileExtension)
{
    if (m_ofs.is_open())
    {
        m_ofs.close();
        m_ofs.clear();
    }
    
    m_ofs.open(m_className + fileExtension);

    if (!m_ofs.is_open())
    {
        throw std::string("Unable to open " + m_className + fileExtension + " file.");
    }
}

void ClassCreator::CreateHppFile()
{
    this->_OpenFile(".hpp");

    m_ofs << "#ifndef " << m_upperCaseClassName << '\n';
    m_ofs << "#define " << m_upperCaseClassName << "\n\n";

    m_ofs << "class " << m_className;
    if (!m_inheritedClassName.empty())
    {
        m_ofs << " : public " << m_inheritedClassName;
    }
    m_ofs << '\n';

    m_ofs << "{\n";
    m_ofs << "public:\n";
    m_ofs << "\t" << m_className << "();\n";

    if (m_hasDestructor)
    {
        m_ofs << '\t';
        if (m_isDestructorVirtual)
        {
            m_ofs << "virtual ";
        }
        m_ofs << '~' << m_className << "();\n";
    }

    m_ofs << '\n';
    m_ofs << "private:\n\t\n";
    m_ofs << "};\n\n";

    m_ofs << "#endif // " << m_upperCaseClassName << '\n';
}

void ClassCreator::CreateCppFile()
{
    this->_OpenFile(".cpp");
    
    m_ofs << "#include \"" << m_className << ".hpp\"\n\n";

    m_ofs << m_className << "::" << m_className << "()\n";
    m_ofs << "{\n\t\n";
    m_ofs << "}\n";

    if (m_hasDestructor)
    {
        m_ofs << '\n';
        m_ofs << m_className << "::~" << m_className << "()\n";
        m_ofs << "{\n\t\n";
        m_ofs << "}\n";
    }
}
