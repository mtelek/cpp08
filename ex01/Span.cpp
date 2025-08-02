/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:37:23 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 18:25:45 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _numbers(), _size(N) {}

Span::Span(const Span& other) : _numbers(other._numbers), _size(other._size) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_size = other._size;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _size)
		throw std::overflow_error("Span is full");
	_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>& numbers)
{
	if (_numbers.size() + numbers.size() > _size)
		throw std::overflow_error("Adding these numbers would exceed Span capacity");
	_numbers.insert(_numbers.end(), numbers.begin(), numbers.end());
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	
	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span");
	
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}

unsigned int Span::size() const
{
	return (_numbers.size());
}

unsigned int Span::capacity() const
{
	return (_size);
}
