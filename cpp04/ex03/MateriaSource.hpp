/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:09 by thblack-          #+#    #+#             */
/*   Updated: 2026/05/08 11:22:10 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class	MateriaSource : IMateriaSource {
private:
	AMateria*	_skills[4] = {};
public:
	MateriaSource();
	MateriaSource( const MateriaSource& other);
	MateriaSource&	operator=( const MateriaSource& other );
	~MateriaSource();
	void		learnMateria(AMateria *m) override;
	AMateria*	createMateria(std::string const &type) override;
};
