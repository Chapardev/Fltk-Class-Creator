#include "ClassCreator.hpp"

ClassCreator::ClassCreator(const std::pair<std::string, std::string> &classNames, bool destructor, bool isVirtual,
                           const std::string &inheritanceMode, const std::pair<std::string, std::string> &fileExtensions, 
                           const std::string &directoryPath)
    : m_className{classNames.first}, m_inheritedClassName{classNames.second},
      m_inheritanceMode{inheritanceMode},
      m_headerFileExtension{'.' + fileExtensions.first}, m_implementationFileExtension{'.' + fileExtensions.second},
      m_upperCaseClassName{boost::to_upper_copy(SeparateWords(m_className, '_')) + '_' + boost::to_upper_copy(fileExtensions.first)},
      m_directoryPath{directoryPath}, m_hasDestructor{destructor}, m_isDestructorVirtual{isVirtual}
{
    this->CreateHeaderFile();
    this->CreateImplementationFile();
}

void ClassCreator::_OpenFile(const std::string &fileExtension)
{
    if (m_ofs.is_open())
    {
        m_ofs.close();
        m_ofs.clear();
    }
    
    m_ofs.open(m_directoryPath + m_className + fileExtension);

    if (!m_ofs.is_open())
    {
        throw std::string("Unable to open " + m_directoryPath + m_className + fileExtension + " file.");
    }
}

void ClassCreator::CreateHeaderFile()
{
    this->_OpenFile(m_headerFileExtension);

    m_ofs << "#ifndef " << m_upperCaseClassName << '\n';
    m_ofs << "#define " << m_upperCaseClassName << '\n';

    if (!m_inheritedClassName.empty())
    {
        m_ofs << "\n#include \"" << m_inheritedClassName << m_headerFileExtension << "\"\n";
    }

    m_ofs << "\nclass " << m_className;
    if (!m_inheritedClassName.empty())
    {
        m_ofs << " : " << m_inheritanceMode << ' ' << m_inheritedClassName;
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

void ClassCreator::CreateImplementationFile()
{
    this->_OpenFile(m_implementationFileExtension);
    
    m_ofs << "#include \"" << m_className << m_headerFileExtension << "\"\n\n";

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
