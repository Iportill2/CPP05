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
	std::cout << this->_target;

	std::cout << "Makes some drilling noises" << std::endl;
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
		std::cout << " robotomization failed." << std::endl;
	}

}