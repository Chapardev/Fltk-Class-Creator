#ifndef CLASS_CREATOR_HPP
#define CLASS_CREATOR_HPP

#include "functions.hpp"

// Class that enables to create files defining classes
class ClassCreator
{
private:
	void _OpenFile(const std::string &fileExtension);

public:
	ClassCreator(const std::pair<std::string, std::string> &classNames, bool destructor, bool isVirtual,
				 const std::string &inheritanceMode, const std::pair<std::string, std::string> &fileExtensions, // header and implementation
				 const std::string &directoryPath);

	void CreateHeaderFile();
	void CreateImplementationFile();

private:
	std::ofstream m_ofs;

	const std::string m_className;
	const std::string m_inheritedClassName;
	
	const std::string m_inheritanceMode;
	
	const std::string m_headerFileExtension;
	const std::string m_implementationFileExtension;

	const std::string m_upperCaseClassName;
	
	const std::string m_directoryPath;

	const bool m_hasDestructor;
	const bool m_isDestructorVirtual;
};

#endif // CLASS_CREATOR_HPP
