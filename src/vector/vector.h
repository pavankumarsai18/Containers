#ifndef VECTOR_H
#define VECTOR_H

#define STARTSIZE 16
#include <iostream>
#include <initializer_list>

namespace cop4530{
	template<typename T>
	class Vector{
	private:
		T* arr;
		int size;
		int curSize;
		int maxSize;

		int nearestPower(int size);
	public:
		Vector();
		Vector(T value, int size);
		Vector(const Vector && v);
		const Vector& operator=(const Vector&& v);
		void push_back(T val);
		int findElement(T val);
		void deleteElement(T val);
		void clear();
		~Vector();

	}
};