#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include "myallocator.h"

template <typename T, typename MyAllocator>
class Vector {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;
	Vector ();
	Vector (size_type size);
	Vector (size_type size, value_type val = 0);
	Vector (const Vector& lhv);
	Vector (Vector&& rhv);
	size_type operator[](size_type index);
	void realloc (size_type size);
	void reserve();
	void push_back(value_type val);
	void pop_back();
	size_type Vsize();
	size_type Vcap();
	void print();
	void shrink_to_fit();
	void insert(value_type val, size_type pos);
	void erase(size_type pos);
	reference at(size_type pos);
	void clear();
	bool empty();
	~Vector();
private: 
	size_type m_size;
	size_type m_cap;
	pointer m_ptr;
};

template <typename T, typename MyAllocator>
std::ostream& operator << (std::ostream& out, Vector<T, MyAllocator>& ob);

#include "vector.hpp"

#endif

