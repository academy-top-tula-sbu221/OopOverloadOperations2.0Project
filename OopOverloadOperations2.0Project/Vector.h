#pragma once
#include <iostream>

class Vector
{
	int size;
	int* array;
public:
	Vector(int size = 0)
		: size{ size }, array{ new int[size] {} } 
	{
		std::cout << this << " vector create\n";
	}

	Vector(const Vector& v) : size{ v.size }, array{ new int[size] }
	{
		std::cout << this << " vector copy create\n";
		for (int i = 0; i < size; i++)
			array[i] = v.array[i];
	}

	~Vector() 
	{ 
		std::cout << this << " vector destroy\n";
		delete[] array; 
	}

	/*int GetItem(int index) { return array[index]; }
	void SetItem(int index, int value) { array[index] = value; }*/

	int& operator[](int index) { return array[index]; }
	
	int Size() { return size; }
};

