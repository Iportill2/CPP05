#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
	private:
	std::string 				_target;
	public:
	//CANONICAL
								RobotomyRequestForm();
								RobotomyRequestForm(std::string target);
								RobotomyRequestForm(RobotomyRequestForm const & copy);
	RobotomyRequestForm & 		operator=(RobotomyRequestForm const & inst);
								~RobotomyRequestForm();

	//GETTER
	std::string					getTarget();

	void 						execute(Bureaucrat const & executor) const;

};
#endif
