/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:54:06 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/23 11:58:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string		brain = "HI THIS IS BRAIN";
	void*			stringPTR = &brain;
	std::string&	stringREF = brain;
	std::cout << &brain << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";
	std::cout << brain << "\n";
	std::cout << *(std::string*)stringPTR << "\n";
	std::cout << stringREF << "\n";
}
