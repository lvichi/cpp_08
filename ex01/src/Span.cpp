/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:31:03 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/15 22:31:03 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"


// Span( unsigned int maxSize );
Span::Span( unsigned int maxSize )
{
  _maxSize = maxSize;
  _numbers.reserve( _maxSize );
}


// Span( const Span& original );
Span::Span( const Span& original )
{
  _maxSize = original._maxSize;
  _numbers = original._numbers;
}


// Span& operator=( const Span& original );
Span& Span::operator=( const Span& original )
{
  if ( this != &original ) {
    _maxSize = original._maxSize;
    _numbers = original._numbers;
  }
  return *this;
}


// ~Span();
Span::~Span() {}


// void addNumber( const int number );
void Span::addNumber( const int number )
{
  if ( _numbers.size() >= _maxSize )
    throw Span::FullException();
  _numbers.push_back( number );
}


// int shortestSpan();
int Span::shortestSpan()
{
  if ( _numbers.size() < 2 )
    throw NotEnoughNumbersException();

  std::vector<int> sorted = _numbers;
  std::sort(sorted.begin(), sorted.end());

  int minSpan = sorted[1] - sorted[0];

  for ( unsigned int i = 2; i < sorted.size(); i++ ) {
    if ( ( sorted[i] - sorted[i - 1] ) < minSpan )
      minSpan = ( sorted[i] - sorted[i - 1] );
  }

  return minSpan;
}


// int longestSpan();
int Span::longestSpan()
{
  if ( _numbers.size() < 2 )
    throw NotEnoughNumbersException();

  int minValue = *std::min_element( _numbers.begin(), _numbers.end() );
  int maxValue = *std::max_element( _numbers.begin(), _numbers.end() );

  return maxValue - minValue;
}


// Class FullException { const char* what() const throw(); }
const char* Span::FullException::what() const throw()
{
  return "It already has the maximum amount of numbers.";
}


// Class NotEnoughNumbersException { const char* what() const throw(); }
const char* Span::NotEnoughNumbersException::what() const throw()
{
  return "Not enough numbers to calculate a span.";
}


// Class RangeTooLargeException { const char* what() const throw(); }
const char* Span::RangeTooLargeException::what() const throw()
{
  return "Not enough space for the range.";
}