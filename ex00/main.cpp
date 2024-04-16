#include "Bureaucrat.hpp"

int  main()
{
	try
	{
		//Bureaucrat b;
		Bureaucrat a("Pepe Funcionario", 2);
		std::cout << a << std::endl;
		a.upGrade();
		std::cout << a << std::endl;
		//a.upGrade();
		//std::cout << a << std::endl;

		//std::cout << b << std::endl;
		//b.downGrade();
		//std::cout << b << std::endl;
	}
	catch(std::exception& z)
	{
		std::cerr << "Exception: " << z.what() << std::endl;
	}

	std::cout << std::endl << "**************" << std::endl << std::endl;

	try
	{
		Bureaucrat paco;
		std::cout << paco << std::endl;
		paco.upGrade(5);
		std::cout << paco << std::endl;
		paco.upGrade();
		std::cout << paco << std::endl;
		paco.downGrade();
		std::cout << paco << std::endl;
		paco.downGrade(10);
		std::cout << paco << std::endl;
	}
	catch(std::exception& x)
	{
		std::cerr << "Exception: " << x.what() << std::endl;
	}
	
	std::cout << std::endl << "*************" << std::endl << std::endl;
	std::cout << "Program Finished!" << std::endl;
	
	return (0);
}