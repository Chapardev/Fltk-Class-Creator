#ifndef CLASS_CREATOR_HPP
#define CLASS_CREATOR_HPP

#include "functions.hpp"

// Class that enables to create files defining classes
class ClassCreator
{
private:
	void _OpenFile(const std::string &fileExtension);

public:
	ClassCreator(const std::string &className, const bool destructor, const std::string &filePath="");

	void CreateHppFile();
	void CreateCppFile();

private:
	std::ofstream m_ofs;
	const std::string m_className;
	std::string m_filePath;
	std::string m_upperCaseClassName;
	const bool m_hasDestructor;
};

#endif // CLASS_CREATOR_HPP
