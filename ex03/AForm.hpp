#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# define SC_SIGN 145	//ShrubberyCreationForm SIGN
# define SC_EXEC 137	//ShrubberyCreationForm EXEC

# define RR_SIGN 72		//RobotomyRequestForm SIGN
# define RR_EXEC 45		//RobotomyRequestForm EXEC

# define PP_SIGN 25		//PresidentialPardonForm SIGN
# define PP_EXEC 5		//PresidentialPardonForm EXEC
class Bureaucrat;

class AForm 
{
	private:
	std::string _name;
	int			_grade_to_sign;
	int 		_grade_to_execute;
	bool		_signed;
	public:
	//CANONICAL
				AForm();
				AForm(std::string name,int grade_to_sign,int grade_to_execute);	
				AForm(const AForm & copy);
				AForm & operator=(AForm const & inst);
	virtual 	~AForm();
	//SETTERS
	void 		setName(std::string name);
	void 		setGradetosign(int grade_to_sign);
	void 		setGradetoexecute(int grade_to_execute);
	void 		setSigned(bool signe);
	//GETTERS
	const	std::string getName() const ;
	int			getGradetosign()const ;
	int			getGradetoexecute()const ;
	bool		getSigned() const ;

	void		beSigned(Bureaucrat &inst);

	virtual void 	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Invalid grade. Must be over 0");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Invalid grade. Must be under 150");
			}
	};
};
std::ostream& operator <<(std::ostream &v, const AForm &inst) ;
#endif

