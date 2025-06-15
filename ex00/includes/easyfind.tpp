/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:58:18 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/15 21:33:02 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename T::iterator easyfind( T& container, int value )
{
  typename T::iterator searchResult;
  searchResult = std::find( container.begin(), container.end(), value );

  if ( searchResult == container.end() )
    throw ::NotFoundException();

  return searchResult;
}


const char* NotFoundException::what() const throw()
{
  return "Value not found.";
}
