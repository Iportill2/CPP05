/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:37:48 by imontero          #+#    #+#             */
/*   Updated: 2023/12/26 12:37:48 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &copy)
{
	(void)copy;
}

Intern::~Intern(void) {}

Intern	&Intern::operator =(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm *ptr;
	int i;
	std::string formList[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (i = 0; i < 3; i++)
		if (name == formList[i])
			break ;

	switch (i)
	{
		case 0:
			ptr = new PresidentialPardonForm(target);
			break ;
		
		case 1:
			ptr = new RobotomyRequestForm(target);
			break ;

		case 2:
			ptr = new ShrubberyCreationForm("target");
			break ;

		default:
			throw (UnofficialFormException());

		std::cout << "Intern creates " << name << " form" << std::endl;
	}
	return (ptr);
}
