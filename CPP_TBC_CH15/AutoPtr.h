#pragma once

#include <iostream>

//XX std::auto_ptr<int>; // c++98, c++11, c++17 �� ���������� �̻��
//�ڿ� �ٸ� ����Ʈ�������� ���ο� ���� ��� ����

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

	// return���� reference�� ���� ��
	// �̰� ���ǰ� �ƴ� �� �������� ����̴�.
	// ���۷����� �����Ѵٴ� ���� ������ ������� �ʴ� �� �׷��ϱ� �ּҰ��� ������
	// �ִ� ���� �����ϴ� ������ �Լ� �������� �ֹ߼��� �ƴ� ���̴�.
	// �̿� ���������� �����͸� �����ϴ� ���� ���۷����ʹ� �ٸ���
	// �ּҰ��� ������ �ִ� L-value��� �ؾ��ϳ�? ��ư �� �ּҰ��� �����ϴ� ��
	// ���۷��� �����̳� ������ �����̳� ������� �ʴ� ���� �����ϴ� ���̴�!
	// �̻� ȥ�ڸ��� ���� ����̾���.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};