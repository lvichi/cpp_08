/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:58:18 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/15 21:33:02 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <vector>
#include <exception>
#include <algorithm>


class Span
{
  private:
    unsigned int     _maxSize;
    std::vector<int> _numbers;

  public:
    Span( unsigned int maxSize );
    Span( const Span& original );
    Span& operator=( const Span& original );
    ~Span();

    void addNumber( const int number );
    int shortestSpan();
    int longestSpan();

    template <typename InputIterator>
    void addRange( InputIterator first, InputIterator last )
    {
      if ( ( _numbers.size() + std::distance( first, last ) ) > _maxSize )
        throw RangeTooLargeException();

      _numbers.insert( _numbers.end(), first, last );
    }

    class FullException : public std::exception
    {
      const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception
    {
      const char* what() const throw();
    };

    class RangeTooLargeException : public std::exception
    {
      const char* what() const throw();
    };
};
