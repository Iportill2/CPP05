/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:18:31 by imontero          #+#    #+#             */
/*   Updated: 2023/12/25 19:18:31 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): 
	AForm("Presidential Pardon Form", 25, 5),
	_target("Undefined target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm("Presidential Pardon Form", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
	AForm("Presidential PArdon Form", 25, 5),
	_target(src._target)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm & PresidentialPardonForm::operator =(PresidentialPardonForm const & rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << this->_target;
	std::cout << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}
