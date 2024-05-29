#ifndef PVZ_SINGLETON_H
#define PVZ_SINGLETON_H
#include <memory>
template<typename T>
class Singleton {
public:
	static T* instance() {
		if (m_instance == nullptr) {
			m_instance = new T();
		}
		return m_instance;
	}
    static std::shared_ptr<T> instanceSP() {
        if (m_instanceSP == nullptr) {
            m_instanceSP = std::make_shared<T>();
        }
        return m_instanceSP;
    }
private:
	Singleton(){}
	Singleton(const Singleton<T>&);
	~Singleton(){}
private:
	static T* m_instance;
    static std::shared_ptr<T>m_instanceSP;
};
template<typename T>
T* Singleton<T>::m_instance = nullptr;
template<typename T>
std::shared_ptr<T>Singleton<T>::m_instanceSP= nullptr;
#endif