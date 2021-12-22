/*

#include "DoubleSubscriptedArray.h"

DoubleSubscriptedArray::DoubleSubscriptedArray(int x_size, int y_size)
	:m_sizeX(x_size),
	 m_sizeY(y_size)
{
	m_arrPtr = new int[x_size * y_size];
}

bool DoubleSubscriptedArray::operator==(DoubleSubscriptedArray& other) const
{
	if (other.getSizeX() != m_sizeX && other.getSizeY() != m_sizeY)
	{
		return false;
	}
	
	for (int i = 0; i != other.getSizeX() * other.getSizeY(); i++)
	{
		if (other.m_arrPtr[i] != m_arrPtr[i])
		{
			return false;
		}
	}

	return true;
}

bool DoubleSubscriptedArray::operator!=(DoubleSubscriptedArray& other) const
{
	if (other.getSizeX() != m_sizeX && other.getSizeY() != m_sizeY)
	{
		return true;
	}

	for (int i = 0; i != other.getSizeX() * other.getSizeY(); i++)
	{
		if (other.m_arrPtr[i] != m_arrPtr[i])
		{
			return true;
		}
	}

	return false;
}

DoubleSubscriptedArray DoubleSubscriptedArray::operator=(DoubleSubscriptedArray& other) const
{
	for (int i = 0; i != other.getSizeX() * other.getSizeY(); i++)
	{
		m_arrPtr[i] = other.m_arrPtr[i];
	}

	return *this;
}

std::ostream& operator<<(std::ostream& stream, DoubleSubscriptedArray& other)
{
	for (int x = 0; x != other.getSizeX(); x++)
	{
		for (int y = 0; y != other.getSizeY(); y++)
		{
			stream << other(y, x) << " ";
		}
		stream << std::endl;
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, DoubleSubscriptedArray& other)
{
	for (int i = 0; i != other.getSizeX() * other.getSizeY(); i++)
	{
		stream >> other.m_arrPtr[i];
	}

	return stream;
}

int DoubleSubscriptedArray::getSizeX()
{
	return m_sizeX;
}

int DoubleSubscriptedArray::getSizeY()
{
	return m_sizeY;
}

int DoubleSubscriptedArray::operator()(int x, int y)
{
	return m_arrPtr[x + y * m_sizeY];
}

int& DoubleSubscriptedArray::operator()(int x, int y) const
{
	return m_arrPtr[x + y * m_sizeY];
}
*/