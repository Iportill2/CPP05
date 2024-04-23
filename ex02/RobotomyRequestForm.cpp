# include "RobotomyRequestForm.hpp"
# include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Undefined target")
{

}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & inst) : AForm("RobotomyRequestForm", 72, 45),_target(inst._target)
{
    this->_target = inst._target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & inst)
{
    if (this != &inst)
    {
        this->_target = inst._target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;



	if( this->getSigned()== false)
	{
		std::cout << executor.getName() <<  " cannot execute " << this->getName() << " because it is not signed." << std::endl;
	}
    else if( executor.getGrade() <= this->getGradetoexecute() && this->getSigned()== true)
	{
		std::cout << this->_target << " Makes some drilling noises" << std::endl;
		//generates a random number between 0 and 1
		srand(time(NULL));
		int i = rand() % 2;
		if (i)
		{
			std::cout << this->_target;
			std::cout << " has been robotomized." << std::endl;
		}
		else
		{
			std::cout << this->_target;
			std::cout << "´s robotomization failed." << std::endl;
		}
    }
	else
		throw(GradeTooLowException());
}