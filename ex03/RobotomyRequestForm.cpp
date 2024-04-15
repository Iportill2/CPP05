/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:24:11 by imontero          #+#    #+#             */
/*   Updated: 2023/12/26 11:24:11 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): 
	AForm("Robotomy Request Form", 72, 45),
	_target("Undefined target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("Robotomy Request Form", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
	AForm("Robotomy Request Form", 72, 45),
	_target(src._target)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm & RobotomyRequestForm::operator =(RobotomyRequestForm const & rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;

	std::cout << "BrrrrrzzzzzzzzzZZZzzZZZzzzzzzz" << std::endl;
	//generates a random number between 0 and 1

	srand(time(NULL));
	int i = rand() % 2;
	if (i)
	{
		std::cout << this->_target;
		std::cout << " has been robotomized." << std::endl;
	}
	else
	{
		std::cout << this->_target;
		std::cout << " robotomization failed." << std::endl;
	}
}
