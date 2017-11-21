/*
 * EMBJ_ImplementStackUsingArray.cpp
 *
 *  Created on: Sep 2, 2017
 *      Author: JoanneY1
 */

#define INTI_CAP 100

template <class T>
class MyStack
{
public:
	MyStack()
	{
		capacity = DEAULT_MAXCAP;
		size = 0;
		array = new T[capacity];
	}

	~MyStack()
	{
		delete []array;
	}

	bool push(T value)
	{
		checkSize();
		array[size++] = value;
	}

	T pop()
	{
		return array[--size];
	}

	T top()
	{
		return array[size-1];
	}

	int getSize()
	{
		return size;
	}

	bool empty()
	{
		return size == 0;
	}

private:
	void checkSize()
	{
		if(size+1 < capacity) return;
		T * temp = new T[capacity*2 + 1]; // if capacity is 0 then we need to allocate at least one more
		memcpy(temp, array, size);
		delete []array;
		array = temp;
	}

	T array[];
	int capacity;
	int size;
	const static int DEAULT_MAXCAP = 100;

};


