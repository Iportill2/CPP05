#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
