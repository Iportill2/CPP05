/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:26:07 by imontero          #+#    #+#             */
/*   Updated: 2024/04/24 12:43:42 by iportill         ###   ########.fr       */
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
		AForm *x;
		(void)x;

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
		//ROBOT
		RobotomyRequestForm E;
		RobotomyRequestForm F("Johnny5");
		RobotomyRequestForm G(F);
		F = G;
		std::cout << F ;
		a.signForm(F);
		std::cout << F ;
		F.execute(a);
		//SHRUBBERY
		ShrubberyCreationForm X;
		ShrubberyCreationForm Y("Groot");
		ShrubberyCreationForm Z(Y);
		Y = Z;
		std::cout << Y ;
		a.signForm(Y);
		std::cout << Y ;
		Y.execute(a);

		std::cout << std::endl;

		//INTERN
		Intern i1;
		AForm* a1;
		
		Intern i2;
		AForm* a2;
		
/* 		RobotomyRequestForm b;
		PresidentialPardonForm c;
		c = b; */
		
		
/* 		a1 = new RobotomyRequestForm();
		a2 = new PresidentialPardonForm(); */

		//cambiar nombre del makeform por uno no valido
		a1 = i1.makeForm("robotomy request", "Lucas");
		a2 = i2.makeForm("presidential pardon", "mario");
		std::cout << "///////////////////////////"<< std::endl;
		std::cout << "a1->getName:"<< a1->getName() << std::endl;
		std::cout << "a2->getName:"<< a2->getName() << std::endl;
		
		delete a2;//
		a2 = a1;
		std::cout << "***************************"<< std::endl;
		std::cout << "a1->getName:"<< a1->getName() << std::endl;
		std::cout << "a2->getName:"<< a2->getName() << std::endl;
		std::cout << "***************************"<< std::endl;
		delete a1;//
		
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	//system("leaks At_least_this_beats_cofee_making");
	return (0);
}
