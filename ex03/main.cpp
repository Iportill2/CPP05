/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:26:07 by imontero          #+#    #+#             */
/*   Updated: 2024/04/23 19:08:21 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int  main()
{
	try
	{
		//AForm z;

		//BUREAUCRAT
		//operator <<
		Bureaucrat a;//default Bureaucrat constructor
		Bureaucrat b("pepe",5);//Bureaucrat constructor
		Bureaucrat c(b);//COPY  constructor Bureaucrat
		std::cout << c ;
		a = c;//operator =
		//a.downGrade();//
		PresidentialPardonForm A;
		PresidentialPardonForm B("juancar");
		PresidentialPardonForm C(B);
		B = C;
		std::cout << B ;
		a.signForm(B);
		std::cout << B ;
		B.execute(a);

		RobotomyRequestForm E;
		RobotomyRequestForm F("Johnny5");
		RobotomyRequestForm G(F);
		F = G;
		std::cout << F ;
		a.signForm(F);
		std::cout << F ;
		F.execute(a);

		ShrubberyCreationForm X;
		ShrubberyCreationForm Y("Groot");
		ShrubberyCreationForm Z(Y);
		Y = Z;
		std::cout << Y ;
		a.signForm(Y);
		std::cout << Y ;
		Y.execute(a);

		std::cout << std::endl;

		
		Intern internRodolfo;
		AForm* rrf;

		rrf = internRodolfo.makeForm("robotomy request", "Potxolo");
		std::cout << rrf->getName() << std::endl;
		delete rrf;//
		
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	//system("leaks At_least_this_beats_cofee_making");
	return (0);
}
