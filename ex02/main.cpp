#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
	try
	{	
		//BUREAUCRAT
		//operator <<
		Bureaucrat a;//default Bureaucrat constructor
		std::cout << a << std::endl;
		std::cout << "************************" << std::endl;

		Bureaucrat b("pepe",44);//Bureaucrat constructor
		std::cout << b << std::endl;
		std::cout << "************************" << std::endl;
	
		Bureaucrat c(b);//COPY  constructor Bureaucrat 
		std::cout << c << std::endl;
		std::cout << "************************" << std::endl;

		a = c;//operator =
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << "************************" << std::endl;

		a.upGrade();
		std::cout << a << std::endl;
		b.upGrade(2);
		c.downGrade();
		a.downGrade(3);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << "************************" << std::endl;

	/* 	PresidentialPardonForm A("presiPardFormJose");
		A.execute(a);
		RobotomyRequestForm B ("RobotFormIban");
		B.execute(a); */
		ShrubberyCreationForm C ("ShrumForm Cami");
		C.execute(a);

		//FORM
		/* AForm A;//default Bureaucrat constructor
		std::cout << A << std::endl;
		std::cout << "************************" << std::endl;

		AForm B("Documento1",45,45);//Bureaucrat constructor
		std::cout << B << std::endl;
		std::cout << "************************" << std::endl;
	
		AForm C(B);//COPY  constructor Bureaucrat 
		std::cout << C << std::endl;
		std::cout << "************************" << std::endl;

		A = C;//operator=
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << "************************" << std::endl;

		std::cout << A << std::endl;
		std::cout << a << std::endl;
		a.upGrade();//
		a.signForm(A);
		std::cout << A << std::endl;
		std::cout << a << std::endl;
		a.upGrade();
		a.signForm(A);
		std::cout << A << std::endl;
		std::cout << a << std::endl;
		std::cout << "+++++++++++++++++++++++++" << std::endl; */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
