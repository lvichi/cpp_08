/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:58:18 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/15 21:33:02 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind( T& container, int value);


class NotFoundException : public std::exception
{
  const char* what() const throw();
};


#include "easyfind.tpp"
