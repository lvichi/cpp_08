/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:54 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/17 15:41:04 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "MutantStack.hpp"
#define TEST_NUMBERS 10
#define RANDOM_MIN -99
#define RANDOM_MAX 99


void subjectTest();
template <typename T> void runAllTests();
template <typename T> void testEmptyContainer( T& container );
template <typename T> void fillContainer( T& container );
template <typename T> void testIterate( T& container );
template <typename T> void testReverse( T& container );


int main( int argc, char** argv )
{
  ( void )argc;

  std::string containerType = ( argv[1] ) ? argv[1] : "MutantStack";

  if (containerType == "MutantStack" || containerType == "mutant" ) {
    std::cout << "--Running tests for MutantStack container--\n";
    ::subjectTest();
    ::runAllTests< ::MutantStack<int> >();
  }
  else if ( containerType == "vector" ) {
    std::cout << "--Running tests for vector container--\n";
    ::runAllTests< std::vector<int> >();
  }
  else if ( containerType == "list" ) {
    std::cout << "--Running tests for list container--\n";
    ::runAllTests< std::list<int> >();
  }
  else
    return ( std::cout << "Invalid container. [ mutant, vector, list ]\n", 1);

  return 0;
}


void subjectTest( )
{
  std::cout << "\n  [Test] Subject test ::" << std::endl;

  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}


template <typename T>
void runAllTests()
{
  T container;

  ::testEmptyContainer( container );
  ::fillContainer( container );
  ::testIterate( container );
  ::testReverse( container );

  std::cout << std::endl;
}


template <typename T>
void testEmptyContainer( T& container )
{
  std::cout << "\n  [Test] Empty container ::" << std::endl;
  std::cout << "    - Size on creation: "
            << container.size() << std::endl;

  if (container.begin() == container.end())
    std::cout << "    - begin() == end(): OK" << std::endl;
  else
    std::cout << "    - begin() == end(): FAILED" << std::endl;
}


template <typename T>
void fillContainer( T& container )
{
  int randomNumber = 0;
  int min = RANDOM_MIN;
  int max = RANDOM_MAX;

  std::cout << "\n  [Test] Fill container ::" << std::endl;

  srand( time(NULL) );

  for ( int i = 0; i < TEST_NUMBERS; i++ ) {
    randomNumber = min + rand() % ( max - min + 1 );
    container.push_back( randomNumber );
    std::cout << "    - added : " << randomNumber << std::endl;
  }
}


template <typename T>
void testIterate( T& container )
{
  std::cout << "\n  [Test] Iteration ::" << std::endl;

  std::cout << "    - Size : "
            << container.size() << std::endl;
  std::cout << "    - Back element: "
            << container.back() << std::endl;

  container.pop_back();

  std::cout << "    - Popped one element. New size: "
            << container.size() << std::endl;
  std::cout << "    - New back element: "
            << container.back() << std::endl;

  // Foward iteration
  typename T::iterator it = container.begin();
  typename T::iterator ite = container.end();
  ++it;
  --it;
  std::cout << "    - Fowarding iterating through remaining elements: ";
  while ( it != ite ) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;

  // Reverse iteration
  typename T::reverse_iterator rit = container.rbegin();
  typename T::reverse_iterator rite = container.rend();
  ++rit;
  --rit;
  std::cout << "    - Reverse iterating through remaining elements: ";
  while ( rit != rite ) {
    std::cout << *rit << " ";
    ++rit;
  }
  std::cout << std::endl;
}


template <typename T>
void testReverse( T& container )
{
  std::cout << "\n  [Test] Reversing container ::" << std::endl;

  typename T::iterator it = container.begin();
  typename T::iterator ite = container.end();

  std::reverse( it, ite );

  std::cout << "    - Reversed: ";
  while ( it != ite ) {
    std::cout << *it << " ";
    ++it;
  }
}
