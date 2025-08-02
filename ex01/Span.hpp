/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:37:28 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 18:25:20 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _size;

	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		void addNumbers(std::vector<int> &numbers);

		unsigned int size() const;
		unsigned int capacity() const;
};

#endif
