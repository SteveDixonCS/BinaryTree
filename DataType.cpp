#include "DataType.h"
#include <cstddef>
#include <iostream>

DataType::DataType() {
	value = NULL;
}


void DataType::print()
{
	std::cout<<DataType::value;
}

void DataType::initialize(int number)
{
	value = number;
	//std::cout<<"initialized with value: "<<value<<std::endl;
}

int DataType::getValue()const
{
	return value;
}

void DataType::setValue(int value)
{
	DataType::value = value;
}

Comparison DataType::compareTo(DataType &item)
{
	if(value > item.value)
	{
		return GREATER;
	}
	else if(value < item.value)
	{
		return LESS;
	}
	else
		return EQUAL;
}

