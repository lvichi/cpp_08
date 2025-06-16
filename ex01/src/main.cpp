/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:39:22 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/15 14:39:22 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "Span.hpp"
#define LARGE_TEST_NUMBERS 10000


int main( int argc, char** argv )
{
  ( void )argc;
  ( void )argv;


  // BASIC TEST

  Span basicTestNumbers( 5 );

  // Try with 0 numbers added
  std::cout << "Try shortest span with no number added:" << std::endl;
  try {
    std::cout << "Shortest Span: " << basicTestNumbers.shortestSpan()
              << std::endl;
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  basicTestNumbers.addNumber( 1 );

  // Try with 1 numbers added
  std::cout << "Try longest span with one number added:" << std::endl;
  try {
    std::cout << "Longest Span: " << basicTestNumbers.longestSpan()
              << std::endl;
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  basicTestNumbers.addNumber( 5 );
  basicTestNumbers.addNumber( 10 );
  basicTestNumbers.addNumber( 12 );
  basicTestNumbers.addNumber( 20 );

  // Try to add more number it can hold
  std::cout << "Try with more numbers it supports:" << std::endl;
  try {
    basicTestNumbers.addNumber( 35 );
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // Basic Test Shortest Span
  std::cout << "Shortest Span: " << basicTestNumbers.shortestSpan() << std::endl;

  // Basic Test Longest Span
  std::cout << "Longest Span: " << basicTestNumbers.longestSpan() << std::endl;
  std::cout << std::endl;


  // SMALL ARRAY TEST

  int smallArray[10] = { -3, 0, 5, 6, -4, 15, -2, 8, 2, 11 };

  Span smallArrayTestNumbers( 10 );

  // smallArrayTestNumbers.addNumber( 3 ); // Uncomment to overflow addrange()

  try {
    smallArrayTestNumbers.addRange( &smallArray[0], &smallArray[10] );
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Small Array Test Shortest Span
  try {
    std::cout << "Shortest Span: " << smallArrayTestNumbers.shortestSpan() << std::endl;
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Small Array Test Longest Span
  try {
    std::cout << "Longest Span: " << smallArrayTestNumbers.longestSpan() << std::endl;
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  std::cout << std::endl;


  // LARGE VECTOR TEST
  Span largeTestNumbers( LARGE_TEST_NUMBERS );

  std::vector<int> randomNumbers;
  randomNumbers.reserve( LARGE_TEST_NUMBERS );

  srand( time(NULL) );
  int randomNumber = 0;

  std::cout << "Generating " << LARGE_TEST_NUMBERS << " random numbers : "
            << std::endl;
  for ( int i = 0; i < LARGE_TEST_NUMBERS; i++ ) {
    randomNumber = (-99999999999) + rand() % (99999999999 - (-99999999999) + 1);
    // std::cout << randomNumber << "  ";       // uncomment to see the random numbers
    randomNumbers.push_back( randomNumber );
  }
  std::cout << std::endl;

  try {
    largeTestNumbers.addRange( randomNumbers.begin(), randomNumbers.end() );
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Large Vector Test Shortest Span
  try {
    std::cout << "Shortest Span: " << largeTestNumbers.shortestSpan() << std::endl;
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // Large Vector Test Longest Span
  try {
    std::cout << "Longest Span: " << largeTestNumbers.longestSpan() << std::endl;
  } catch ( std::exception& e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
