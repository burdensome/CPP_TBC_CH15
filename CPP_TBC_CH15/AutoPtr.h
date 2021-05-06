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
	AutoPtr(T *ptr = nullptr)
		: m_ptr(ptr)
	{}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	AutoPtr& operator = (AutoPtr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;
	}

	// return값에 reference가 있을 떄
	// 이건 강의가 아닌 내 스스로의 잡담이다.
	// 레퍼런스를 리턴한다는 것은 내부의 사라지지 않는 값 그러니까 주소값을 가지고
	// 있는 값을 리턴하는 것으로 함수 내에서도 휘발성이 아닌 것이다.
	// 이와 마찬가지로 포인터를 리턴하는 것은 레퍼런스와는 다르게
	// 주소값을 가지고 있는 L-value라고 해야하나? 암튼 그 주소값을 리턴하는 것
	// 레퍼런스 리턴이나 포인터 리턴이나 사라지지 않는 값을 리턴하는 것이다!
	// 이상 혼자만의 생각 잡담이었다.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};