# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined target")
{
	_target= "Default target";
	std::cout << "Default ShrubberyCreationForm Constructor that target " << this->_target << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	_target = target;
	std::cout << "Default ShrubberyCreationForm Constructor that target " << this->_target << std::endl;
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
	std::cout << "Destructor ShrubberyCreationForm with target=" << this->_target << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const 
{
	return(_target);
}
void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	//std::cout << "\033[31m" << "executor Grade is=" << executor.getGrade() << "||" << "ShrubberyCreationForm needed executeGrade is=" << this->getGradetoexecute() << "\033[37m" << std::endl;
	
	if( this->getSigned()== false)
		std::cout << executor.getName() <<  " cannot execute " << this->getName() << " because it is not signed." << std::endl;
	else if( executor.getGrade() <= this->getGradetoexecute() && this->getSigned()== true)
	{
		std::cout << executor.getName() <<  " executed " <<  this->getName() << std::endl;

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
		std::cout << this->_target <<  "_shrubbery file has been created " << std::endl;
	}
	else
		throw(GradeTooLowException());
/*
ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.
*/
}
/* std::ostream& operator <<(std::ostream &v, const ShrubberyCreationForm &inst)
{
	v << "\033[36m" <<  "operator<< " << "\033[0m" << std::endl;
	v << "\033[32m"<< "ShrubberyCreationForm name: " << inst.getName();
	v << ", Status(Signed)TRUE=1/FALSE=0: " << inst.getSigned();
	v << ", Sign grade: " << inst.getGradetosign();
	v << ", Execution grade: " << inst.getGradetoexecute() << "\033[0m"  << std::endl;;

	return (v);
} */