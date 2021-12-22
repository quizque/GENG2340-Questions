/*

#pragma once

#include <iostream>

class DoubleSubscriptedArray
{
	friend std::ostream& operator<<(std::ostream& stream, DoubleSubscriptedArray& other);
	friend std::istream& operator>>(std::istream& stream, DoubleSubscriptedArray& other);

public:
	explicit DoubleSubscriptedArray(int x_size = 1, int y_size = 1);

	bool operator==(DoubleSubscriptedArray &other) const;
	bool operator!=(DoubleSubscriptedArray &other) const;

	DoubleSubscriptedArray operator=(DoubleSubscriptedArray& other) const;

	int getSizeX();
	int getSizeY();

	int operator()(int x, int y);
	int &operator()(int x, int y) const;

private:

	int *m_arrPtr;
	int m_sizeX;
	int m_sizeY;

};

*/