/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:37:06 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 20:59:00 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mutantstack.hpp"
#include <iostream>
#include <list>

void testWithMutantStack()
{
	std::cout << "=== Testing MutantStack ===" << std::endl;
	MutantStack<int> mstack;

	// Test push
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;  // Should be 17
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;  // Should be 1

	// Push more elements
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Test iterators
	std::cout << "Elements (forward): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Test const iterators
	const MutantStack<int>& constMstack = mstack;
	std::cout << "Elements (const): ";
	for (MutantStack<int>::const_iterator it = constMstack.begin(); it != constMstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Test reverse iteration
	std::cout << "Elements (reverse): ";
	for (MutantStack<int>::iterator it = mstack.end(); it != mstack.begin(); )
		std::cout << *(--it) << " ";
	std::cout << std::endl;

	// Test stack operations still work
	std::cout << "Top element: " << mstack.top() << std::endl;
}

void compareWithList()
{
	std::cout << "\n=== Comparison with std::list ===" << std::endl;
	MutantStack<int> mstack;
	std::list<int> list;

	// Add same elements to both
	mstack.push(1); list.push_back(1);
	mstack.push(2); list.push_back(2);
	mstack.push(3); list.push_back(3);
	mstack.push(4); list.push_back(4);
	mstack.push(5); list.push_back(5);

	// Compare iteration
	std::cout << "MutantStack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\nstd::list:    ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	testWithMutantStack();
	compareWithList();
	return (0);
}
