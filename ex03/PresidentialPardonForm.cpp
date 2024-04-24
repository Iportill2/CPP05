# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Undefined target")
{

}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & inst) : AForm("Presidential PArdon Form", 25, 5),_target(inst._target)
{
    this->_target = inst._target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & inst)
{
    std::cout << "[operator=] Presi" << std::endl;
    if (this != &inst)
    {
        this->_target = inst._target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() 
{

}

std::string PresidentialPardonForm::getTarget() const 
{
    return(_target);
}
void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if( this->getSigned()== false)
	{
		std::cout << executor.getName() <<  " cannot execute " << this->getName() << " because it is not signed." << std::endl;

	}
    else if( executor.getGrade() <= this->getGradetoexecute() && this->getSigned()== true)
	{
        std::cout << executor.getName() <<  " executed " <<  this->getName() << std::endl;
	    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
	else
		throw(GradeTooLowException());
}
