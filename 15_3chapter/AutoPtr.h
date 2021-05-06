#pragma once

#include <iostream>

//XX std::auto_ptr<int>; // c++98, c++11, c++17 이 마지막으로 미사용
//뒤에 다른 스마트포인터의 새로운 것을 배울 예정

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr(T* ptr = nullptr)
		: m_ptr(ptr)
	{
		std::cout << "AutoPtr default constructorr " << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor " << std::endl;

		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor " << std::endl;
		
		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	AutoPtr& operator=(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment " << std::endl;
		if (&a == this)
			return *this;

		if (m_ptr != nullptr) delete m_ptr;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator=(const AutoPtr& a) = delete;

	//AutoPtr(AutoPtr&& a)
	//	: m_ptr(a.m_ptr)
	//{
	//	a.m_ptr = nullptr; // really necessary?

	//	std::cout << "AutoPtr move constructor" << std::endl;
	//}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};