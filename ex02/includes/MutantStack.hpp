/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:54 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/17 15:43:11 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
  public:
    MutantStack() {}
    MutantStack( const MutantStack& original ) : std::stack<T>( original ) {}
    MutantStack& operator=( const MutantStack& original ) {
      if ( this != &original )
        std::stack<T>::operator=( original );
      return *this;
    }
    ~MutantStack() {}

    typedef typename
      std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    typedef typename
      std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    // push_back
    void push_back( const T& t ) { this->push( t ); }

    // back
    T& back() { return this->top(); }
    const T& back() const { return this->top(); }

    // pop_back
    void pop_back() { this->pop(); }
};
