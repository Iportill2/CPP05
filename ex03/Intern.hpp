#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		//CANONICAL //4
		Intern();
		Intern(const Intern & copy);
		Intern & operator =(Intern const &inst);
		~Intern();


		AForm *makeForm(std::string nameform, std::string targetform);

		class UnofficialFormException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form not found");
				}
		};
};
#endif
