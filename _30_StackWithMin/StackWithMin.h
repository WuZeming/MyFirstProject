#pragma once
#include<stack>
#include<assert.h>

template< typename T>
class StackWithMin
{
public:
	StackWithMin() {}
	virtual ~StackWithMin() {}

	void pop();
	void push(const T& element);
	const T& top() const;
	const T& min()const;
	size_t size() const;
	bool empty() const;

private:
	std::stack<T> m_data;
	std::stack<T> m_min;
};




template<typename T>
void StackWithMin<T>::pop()
{
	assert(!m_data.empty() && !m_min.empty());

	m_data.pop();
	m_min.pop();
}

template<typename T>
void StackWithMin<T>::push(const T& element)
{
	m_data.push(element);
	if (m_min.empty()||m_min.top()>element)
	{
		m_min.push(element);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template<typename T>
const T& StackWithMin<T>::top() const
{
	assert(!m_data.empty());
	return m_data.top();
}

template<typename T>
size_t StackWithMin<T>::size() const
{
	return m_data.size();
}

template<typename T>
bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template<typename T>
const T& StackWithMin<T>::min() const
{
	assert(!m_min.empty());
	return m_min.top();
}
