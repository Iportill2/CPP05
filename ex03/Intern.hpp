








































/* #ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		Intern & operator =(Intern const &rhs);

		AForm	*makeForm(std::string name, std::string target);

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
 */