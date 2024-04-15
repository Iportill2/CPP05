/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:41:02 by imontero          #+#    #+#             */
/*   Updated: 2023/12/24 16:41:02 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): 
	_name("Undefined"),
	_sigStatus(false), 
	_signGrade(150),
	_execGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade):
	_name(name),
	_sigStatus(false),
	_signGrade(signGrade),
	_execGrade(executeGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (GradeTooLowException());
}

AForm::AForm (const AForm & copy):
	_name(copy._name),
	_sigStatus(copy._sigStatus),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
	*this = copy;
}

AForm::~AForm(void)
{
}

AForm &AForm::operator =(AForm const &rhs)
{
	this->_sigStatus = rhs._sigStatus;
	return (*this);
}

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

bool				AForm::getSigStatus(void) const
{
	return (this->_sigStatus);
}

int					AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int					AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void				AForm::beSigned(Bureaucrat &inst)
{
	if (inst.signForm(*this))
	{
		std::cout << "This form has been signed by bureaucrat " << inst.getName() << std::endl;
		this->_sigStatus = true;
	}
	
}


std::ostream& operator <<(std::ostream &o, const AForm &inst)
{
	o << "Form name: " << inst.getName();
	o << ", Status: " << inst.getSigStatus();
	o << ", Sign grade: " << inst.getSignGrade();
	o << ", Execution grade: " << inst.getExecGrade();
	return (o);
}

