/*

#include "Rectangle.h"

Rectangle::Rectangle(float length, float width)
{
	// Set width and length
	setWidth(width);
	setLength(length);
}

float Rectangle::perimeter() const
{
	// Calculate perimeter and return
	return 2.0f * (m_length + m_width);
}

float Rectangle::area() const
{
	// Calculate area and return
	return m_length * m_width;
}

void Rectangle::setWidth(float width)
{
	// Set width to member width
	m_width = width;
	
	// If the number is not in the domain {0<x<20} set it to 1
	if (!(0 < m_width && m_width < 20))
	{
		m_width = 1;
	}
}

void Rectangle::setLength(float length)
{
	// Set length to member length
	m_length = length;

	// If the number is not in the domain {0<x<20} set it to 1
	if (!(0 < m_length && m_length < 20))
	{
		m_length = 1;
	}
}

float Rectangle::getWidth()
{
	// Return width
	return m_width;
}

float Rectangle::getLength()
{
	// Return length
	return m_length;
}

*/