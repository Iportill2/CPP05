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

	/* 							PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm & 	operator=(PresidentialPardonForm const & rhs); */

								~PresidentialPardonForm();

	//GETTER
	std::string					getTarget();

	void 						execute(Bureaucrat const &executor) const;

};
#endif
/*
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;
	
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);

		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

		~PresidentialPardonForm(void);


		std::string	getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;

};

#endif
*/
