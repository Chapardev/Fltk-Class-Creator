#ifndef CLASS_CREATOR_HPP
#define CLASS_CREATOR_HPP

#include "functions.hpp"

// Class that enables to create files defining classes
class ClassCreator
{
private:
	void _OpenFile(const std::string &fileExtension);

public:
	ClassCreator(const std::string &className, bool destructor, bool isVirtual, const std::string &inheritedClass);

	void CreateHppFile();
	void CreateCppFile();

private:
	std::ofstream m_ofs;
	const std::string m_className;
	const std::string m_inheritedClassName;
	std::string m_upperCaseClassName;

	const bool m_hasDestructor;
	const bool m_isDestructorVirtual;
};

#endif // CLASS_CREATOR_HPP
