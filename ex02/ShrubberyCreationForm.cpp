# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined target")
{

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & inst) : AForm("ShrubberyCreationForm", 145, 137),_target(inst._target)
{
    this->_target = inst._target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & inst)
{
    if (this != &inst)
    {
        this->_target = inst._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << "Destructor ShrubberyCreationForm with target=" << this->getTarget() << std::endl;
}
std::string ShrubberyCreationForm::getTarget() const 
{
	return(_target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::cout << "\033[31m" << "executor Grade is=" << executor.getGrade() << "||" << "ShrubberyCreationForm needed executeGrade is=" << this->getGradetoexecute() << "\033[37m" << std::endl;
	
	if( this->getSigned()== false)
	{
		std::cout << executor.getName() <<  " cannot execute " << this->getName() << " because it is not signed." << std::endl;

	}
	else if( executor.getGrade() <= this->getGradetoexecute() && this->getSigned()== true)
	{
		std::cout << executor.getName() <<  " executed " <<  this->getTarget() << std::endl;

		std::cout << this->_target;
		std::ofstream outfile((this->_target + "_shrubbery").c_str());
		outfile << "      /\\      " << std::endl;
		outfile << "     /\\*\\     " << std::endl;
		outfile << "    /\\O\\*\\    " << std::endl;
		outfile << "   /*/\\/\\/\\   " << std::endl;
		outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
		outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		outfile << "      ||      " << std::endl;
		outfile << "      ||      " << std::endl;
		outfile << "      ||      " << std::endl;
		outfile << std::endl;
		std::cout << "Shrubbery has been created at ";
		std::cout << this->_target << std::endl;
	}
	else
		throw(GradeTooLowException());

}