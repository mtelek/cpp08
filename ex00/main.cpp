/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:52:56 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 17:32:19 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void testWithVector()
{
	std::cout << "=== Testing with vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	try {
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found value 20 at position: " << std::distance(vec.begin(), it) << std::endl;
		
		it = easyfind(vec, 50); // This should throw
		std::cout << "Found value 50 at position: " << std::distance(vec.begin(), it) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testWithList()
{
	std::cout << "\n=== Testing with list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	try {
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "Found value 3 in list" << std::endl;
		
		it = easyfind(lst, 5); // This should throw
		std::cout << "Found value 5 in list" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testWithDeque()
{
	std::cout << "\n=== Testing with deque ===" << std::endl;
	std::deque<int> dq;
	dq.push_back(100);
	dq.push_back(200);
	dq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(dq, 200);
		std::cout << "Found value 200 at position: " << std::distance(dq.begin(), it) << std::endl;
		
		it = easyfind(dq, 400); // This should throw
		std::cout << "Found value 400 at position: " << std::distance(dq.begin(), it) << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testWithConstContainer()
{
	std::cout << "\n=== Testing with const container ===" << std::endl;
	const int arr[] = {1, 2, 3};
	const std::vector<int> constVec(arr, arr + sizeof(arr)/sizeof(arr[0]));

	try {
		std::vector<int>::const_iterator it = easyfind(constVec, 2);
		std::cout << "Found value 2 in const vector" << std::endl;
		
		it = easyfind(constVec, 4); // This should throw
		std::cout << "Found value 4 in const vector" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	testWithVector();
	testWithList();
	testWithDeque();
	testWithConstContainer();
	
	return (0);
}
