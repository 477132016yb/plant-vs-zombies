#include "ClassFactory.h"

void ClassFactory::register_class(const std::string& className, create_object method)
{
	m_classMap[className] = method;
}

Object* ClassFactory::create_class(const std::string& className)
{
	auto it = m_classMap.find(className);
	if ( it!= m_classMap.end()) {
		return it->second();
	}
	return nullptr;
}
