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
	{}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	autoptr(autoptr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	autoptr& operator = (autoptr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};