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

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
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