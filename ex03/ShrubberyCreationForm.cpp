/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:40:39 by imontero          #+#    #+#             */
/*   Updated: 2023/12/26 11:40:39 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): 
	AForm("Shrubbery Creation Form", 145, 137),
	_target("Undefined target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("Shrubbery Creation Form", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
	AForm("Presidential Pardon Form", 145, 137),
	_target(src._target)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator =(ShrubberyCreationForm const & rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream outfile((this->_target + "_shrubbery").c_str());
	outfile << "      /\\      " << std::endl;
	outfile << "     /\\*\\     " << std::endl;
	outfile << "    /\\O\\*\\    " << std::endl;
	outfile << "   /*/\\/\\/\\   " << std::endl;
	outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
	outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << std::endl;
	std::cout << "Shrubbery has been created at ";
	std::cout << this->_target << std::endl;

}
