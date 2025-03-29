#pragma once

template<typename T>
class Vector
{
public:
	Vector()
	{
		//allocate 2 elements
		Realloc();
	}
	void Pushback(const T& value)
	{
		if(m_size>=m_capacity)
		{
			Realloc(m_capacity + m_capacity / 2);
		}	
		m_Data[m_size] = value;
		m_size++;
	}
	const T& operator[](size_t index)
	{
		if (index >= m_size)
		{
			//assert
		}
		return m_Data[index];
	}
	T& operator[](size_t index)
	{
		if (index >= m_size)
		{
			//assert
		}
		return m_Data[index];
	}
private:
	void Realloc(size_t newCapacity)
	{
		//1.allocate a new block of memory
		//2. copy/move old elements into new block  
		//3.delete the old block of memory 

		T* newBlock = new T[newCapacity];
		size_t size = m_size;
		if (newCapacity < size)
			size = newCapacity;
		///make sure we arent using the memcpy because it works fine with builtin datatypes,
		//but fails to work with the classes or more complex types ... so we use the for loop.
		for (int i = 0;i < m_size;i++)
		{
			newBlock[i] = m_Data[i];
		}
		delete[] m_Data;
		m_Data = newBlock;
		m_capacity = newCapacity;
		delete[] newBlock;
	}
	T* m_Data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0; ==

};