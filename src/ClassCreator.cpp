#include "ClassCreator.hpp"

ClassCreator::ClassCreator(const std::string &className, bool destructor, bool isVirtual, const std::string &filePath)
    : m_className{className}, m_filePath{filePath}, m_upperCaseClassName{className}, m_hasDestructor{destructor}, m_isDestructorVirtual{isVirtual}
{
    SeparateWords(m_upperCaseClassName, '_');

    for (size_t i{0}; i < m_upperCaseClassName.length(); i++)
    {
        m_upperCaseClassName[i] = std::toupper(m_upperCaseClassName[i]);
    }

    m_upperCaseClassName += "_HPP";

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
    
    m_ofs.open(m_filePath + m_className + fileExtension);

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

    m_ofs << "class " << m_className << '\n';
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
