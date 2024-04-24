#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern Constructor" << std::endl;
}

Intern::Intern(const Intern & copy)
{
	std::cout << "[Intern Copy]" << std::endl;
	*this=copy;
}

Intern &Intern::operator =(Intern const &inst)
{
	std::cout << "[operator=] Intern" << std::endl;
	(void)inst;
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}



AForm *Intern::makeForm(std::string nameform, std::string targetform)
{

	AForm *ptr;
	int i = 0;
	std::string formArray[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	while(i < 3)
	{
		if(nameform == formArray[i])
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		ptr = new PresidentialPardonForm(targetform);
		break;
	case 1:
		ptr = new RobotomyRequestForm(targetform);
		break;	
	case 2:
		ptr = new ShrubberyCreationForm(targetform);
		break;
	default:
		throw (UnofficialFormException());
	}
	std::cout << "Intern create " << formArray[i] << "Form" << std::endl; 
	return(ptr);
}
