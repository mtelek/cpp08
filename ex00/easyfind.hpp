/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:53:24 by mtelek            #+#    #+#             */
/*   Updated: 2025/08/02 17:21:39 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>

template <typename Container>
typename Container::iterator easyfind(Container &container, int element)
{
	typename Container::iterator it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw std::runtime_error("Element not found in container");
	else
		return (it);
}

template <typename Container>
typename Container::const_iterator easyfind(const Container &container, int element)
{
	typename Container::const_iterator it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw std::runtime_error("Element not found in container");
	else
		return (it);
}

#endif
