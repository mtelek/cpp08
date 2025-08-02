/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:36:34 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 18:31:25 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testBasic()
{
	std::cout << "=== Basic Tests ===" << std::endl;
	Span sp(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		// This should throw
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testEdgeCases()
{
	std::cout << "\n=== Edge Cases ===" << std::endl;
	Span sp(1);
	
	sp.addNumber(42);
	
	try {
		// Should throw - not enough numbers
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try {
		// Should throw - not enough numbers
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testLargeDataset()
{
	std::cout << "\n=== Large Dataset Test (10,000 numbers) ===" << std::endl;
	Span sp(10000);
	std::vector<int> numbers;
	
	std::srand(std::time(0));
	while (numbers.size() < 10000)
	{
		int num = std::rand() % 100000;
		if (std::find(numbers.begin(), numbers.end(), num) == numbers.end())
			numbers.push_back(num);
	}
	sp.addNumbers(numbers);
	
	std::cout << "Size: " << sp.size() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	try {
		// Should throw - span is full
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testBulkAdd()
{
	std::cout << "\n=== Bulk Add Test ===" << std::endl;
	Span sp(20);
	std::vector<int> numbers;
	
	for (int i = 0; i < 15; ++i)
		numbers.push_back(i * 2);
	
	sp.addNumbers(numbers);
	
	std::cout << "Size after bulk add: " << sp.size() << std::endl;
	
	// Add 5 more individually
	for (int i = 0; i < 5; ++i)
		sp.addNumber(i * 3);
	
	std::cout << "Final size: " << sp.size() << std::endl;
	std::cout << "Overall capacity: " << sp.capacity() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	try {
		// Should throw - span is full
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testBasic();
	testEdgeCases();
	testLargeDataset();
	testBulkAdd();
	
	return (0);
}
