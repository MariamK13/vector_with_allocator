#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include "vector.h"


template <typename T>
Vector<T>::Vector () {
	std::cout << "default ctor" << std::endl;
	m_ptr = nullptr;
	m_size = 0;
	m_cap = 0;
}

template <typename T>
Vector<T>::Vector (size_type size)
{
	std::cout << "param ctor" << std::endl;
	Vector ob;
	m_size = size;
	m_cap = size;
	m_ptr = new value_type[ob.m_cap];
}
	
template <typename T>
Vector<T>::Vector (size_type size, value_type val)
{
	std::cout << "param ctor" << std::endl;
	Vector ob;
	m_size = size;
	m_cap = size;
	m_ptr = new value_type[m_cap];
	for (size_type i = 0; i < m_size; ++i)
	{
		m_ptr[i] = val;
	}
}

template <typename T>
Vector<T>::Vector (const Vector& lhv) 
	: m_size{lhv.m_size}
	, m_cap{lhv.m_cap}
	, m_ptr{new value_type[lhv.m_cap]}
{
	std::cout << "copy ctor" << std::endl;
	for (size_type i = 0; i < m_size; ++i) {
		this->m_ptr[i] = lhv.m_ptr[i];
	}

}

template <typename T>
Vector<T>::Vector (Vector&& rhv) 
	: m_size{rhv.m_size}
	, m_cap{rhv.m_cap}
	, m_ptr{new value_type[rhv.m_cap]}
{
	std::cout << "move ctor" << std::endl;
	rhv.m_ptr = nullptr;
	rhv.m_size = 0;
	rhv.m_cap = 0;

}

template <typename T>
typename Vector<T>::size_type 
Vector<T>::operator[](size_type index) {
	return m_ptr[index];
}

template <typename T>
void 
Vector<T>::realloc (size_type size)
{
		if (m_size > size)
		{
			m_size = size;
		} else if (size > m_cap)
		{
			m_cap = size;
			pointer ptr2 = new value_type[m_cap];
			for (size_type i = 0; i < m_size; ++i)
			{
				ptr2[i] = m_ptr[i];
			}
			for (size_type i = m_size; i < m_cap; ++i) 
			{
				ptr2[i] = 0;
			}
			m_size = size;
			delete [] m_ptr;
			m_ptr = ptr2;
			ptr2 = nullptr;
		} else {
			for (size_type i = m_size; i < size; ++i) 
			{
				m_ptr[i] = 0;
			}
			m_size = size;
		}
}

template <typename T>
void 
Vector<T>::recap() 
	{
		if (m_cap == 0)
		{
			m_cap = 8;
			m_ptr = new value_type[m_cap];
		} else {
			m_cap *= 2;
			pointer ptr2 = new value_type[m_cap];
			for (size_type i = 0; i < m_size; ++i)
			{
				ptr2[i] = m_ptr[i];
			}
			delete [] m_ptr;
			m_ptr = ptr2;
			ptr2 = nullptr;
		}
}

template <typename T>
void 
Vector<T>::push_back(value_type val)
	{
		if (m_ptr == nullptr)
		{
			m_cap = 8;
			m_ptr = new value_type[m_cap];
		}
		if (m_size == m_cap) {
			recap();
		}
			m_ptr[m_size] = val;
			m_size += 1;
}

template <typename T>
void 
Vector<T>::pop_back()
	{
		if (m_size > 0) {
		m_size -= 1;
		}
}

template <typename T>
typename Vector<T>::size_type  
Vector<T>::Vsize()
{
	return m_size;
}

template <typename T>
typename Vector<T>::size_type  
Vector<T>::Vcap ()
{
	return m_cap;
}

template <typename T>
void 
Vector<T>::print()
{
	for (size_type i = 0; i < m_size; ++i)
	{
		std::cout << m_ptr[i] << " ";
	}
}

template <typename T>
void 
Vector<T>::shrink_to_fit()
{
	if (m_size < m_cap)
	{
		pointer ptr2 = new value_type[m_size];
			for (size_type i = 0; i < m_size; ++i) {
				ptr2[i] = m_ptr[i];
			}
			m_cap = m_size;
			delete [] m_ptr;
			m_ptr = ptr2;
			ptr2 = nullptr;
		}
}

template <typename T>
void 
Vector<T>::insert (value_type val, size_type pos)
	{
		if (pos >= m_size)
		{
			std::cout << "no way";
			return;
		}
		size_type i = m_size;
		if (m_size == m_cap)
		{
			recap();
		}
		m_size += 1;
		while (pos != i)
		{
			m_ptr[i] = m_ptr[i - 1];
			--i;
		}
		m_ptr[pos] = val;
}

template <typename T>
void 
Vector<T>::erase (size_type pos)
{
	if (pos > m_size)
	{
		std::cout << "no way";
	} else if (pos == m_size - 1) {
		--m_size;
	} else {
		for (size_type j = pos; j < m_size - 1; ++j)
		{
			m_ptr[j] = m_ptr[j + 1];
		}
		--m_size;
	}
}

template <typename T>
typename Vector<T>::reference
Vector<T>::at (size_type pos)
{
		if (pos >= m_size)
		{
			std::cout << "no way";
		}
		return m_ptr[pos];
}

template <typename T>
void 
Vector<T>::clear ()
{
	m_size = 0;
	m_cap = 0;
	delete [] m_ptr;
	m_ptr = nullptr;
}

template <typename T>
bool 
Vector<T>::empty()
{
	return (m_ptr == nullptr);
}

template <typename T>
Vector<T>::~Vector()
{
		clear();
}

template <typename T>
std::ostream& operator << (std::ostream& out, Vector<T>& ob) {
	for (size_t i = 0; i < ob.Vsize(); ++i) {
		out << ob[i] << " ";
	}
	return out;
}

#endif
