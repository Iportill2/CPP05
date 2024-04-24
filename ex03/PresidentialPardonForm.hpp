#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
	private:
	std::string 				_target;
	public:
	//CANONICAL
								PresidentialPardonForm();
								PresidentialPardonForm(std::string target);
								PresidentialPardonForm(PresidentialPardonForm const & copy);
	PresidentialPardonForm & 	operator=(PresidentialPardonForm const &  inst);
								~PresidentialPardonForm();
	//GETTER
	std::string					getTarget() const ;

	void 						execute(Bureaucrat const &executor) const;

};
#endif

