#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
	private:
	std::string 				_target;
	public:
	//CANONICAL
								ShrubberyCreationForm();
								ShrubberyCreationForm(std::string target);
								ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	ShrubberyCreationForm & 	operator=(ShrubberyCreationForm const & inst);
								~ShrubberyCreationForm();

	//GETTER
	std::string					getTarget();

	void 						execute(Bureaucrat const & executor) const;

};
#endif