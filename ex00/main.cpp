#include "Bureaucrat.hpp"
int main()
{
	try
	{	
		//BUREAUCRAT
		Bureaucrat a;//default Bureaucrat constructor
		std::cout << a << std::endl;
		std::cout << "************************" << std::endl;

		Bureaucrat b("pepe",44);//Bureaucrat constructor
		std::cout << b << std::endl;
		std::cout << "************************" << std::endl;
	
		Bureaucrat c(b);//COPY  constructor Bureaucrat 
		std::cout << c << std::endl;
		std::cout << "************************" << std::endl;

		a = c;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << "************************" << std::endl;

		a.upGrade();
		b.upGrade(2);
		c.downGrade();
		a.downGrade(3);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << "************************" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

