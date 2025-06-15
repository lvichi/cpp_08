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
#include <vector>
#include <list>
#include "easyfind.hpp"


int main( int argc, char** argv )
{
  ( void )argc;
  ( void )argv;

  // Vector
  std::vector<int> vectorNumbers;
  vectorNumbers.push_back(1);
  vectorNumbers.push_back(5);
  vectorNumbers.push_back(6);

  std::vector<int>::iterator vectorResult;

  for ( int searchNumber = 0; searchNumber < 10; searchNumber++ ) {
    try {
      vectorResult = easyfind( vectorNumbers, searchNumber );
      std::cout << "Found " << searchNumber
                << " in the vector container." << std::endl;
    } catch ( std::exception& e ) {
      std::cout << e.what() << " value: " << searchNumber << std::endl;
    }
  }

  std::cout << std::endl;

  // List
  std::list<int> listNumbers;
  listNumbers.push_back(4);
  listNumbers.push_back(8);
  listNumbers.push_back(9);

  std::list<int>::iterator listResult;

  for ( int searchNumber = 0; searchNumber < 10; searchNumber++ ) {
    try {
      listResult = easyfind( listNumbers, searchNumber );
      std::cout << "Found " << searchNumber
                << " in the list container." << std::endl;
    } catch ( std::exception& e ) {
      std::cout << e.what() << " value: " << searchNumber << std::endl;
    }
  }

  return 0;
}
