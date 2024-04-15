/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:26:07 by imontero          #+#    #+#             */
/*   Updated: 2023/12/29 08:23:17 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int  main()
{
	try
	{
		RobotomyRequestForm R("Igor");
		Bureaucrat B("Susana", 42);
		R.beSigned(B);
		B.executeForm(R);	

	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "++++++++++" << std::endl << std::endl;

	try
	{
		Bureaucrat B("Jesus", 100);
		std::cout << B;
		PresidentialPardonForm P("me");
		P.beSigned(B);
		B.executeForm(P);

	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "++++++++++" << std::endl << std::endl;
	std::cout << "The End" << std::endl;
	
	return (0);
}
