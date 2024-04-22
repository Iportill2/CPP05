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
    std::cout << executor.getName() <<  " executed " <<  this->getTarget() << std::endl;
	std::cout << this->_target;
	std::cout << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
