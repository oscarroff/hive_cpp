/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:41:55 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/25 17:07:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HARL_H
# define HARL_H

#include <string>

class	Harl {
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	Harl();
	~Harl();
	void	complain( std::string level );
	void	filter( std::string level );
	void	message( int index );
};

#endif
