#pragma once
#include<map>
#include<string>
#include<vector>
#include<functional>
#include"Singleton.h"
#include "const.h"
#include "Object.h"

typedef Object* (*create_object)(void);
class ClassFactory
{
	friend class Singleton<ClassFactory>;
public:
	void register_class(const std::string& className, create_object method);
	Object* create_class(const std::string& className);
private:
	ClassFactory(){}
	~ClassFactory(){}
private:
	std::map<std::string, create_object>m_classMap;
};
class ClassRegister {
public:
	ClassRegister(const std::string& className, create_object method) {
		Singleton<ClassFactory>::instance()->register_class(className, method);
	}
};
#define REGISTER_CLASS(className)       \
	Object*createObject##className()    \
	{                                   \
		Object * obj = new className(); \
		obj->SetName(#className);		\
		return obj;                     \
	}                                   \
	ClassRegister ClassRegister##className(#className,createObject##className)

