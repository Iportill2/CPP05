#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
	private:
	bool	_signed;
	int		_grade_to_sign;
	int 	_grade_to_execute;
	public:
	const std::string _name;
	//CANONICAL
	Form();
	Form(int  signed,int grade_to_sign,int grade_to_execute);	
	Form(const Form & copy);
	Form & operator=(Form const & inst);
	~Form();


	//GETTERS
	const	std::string getName();
	bool	getSigned();
	int		getGradetosign();
	int		getGradetoexecute();

	void 	signForm();
	void	beSigned();

	void	beSigned(Bureaucrat);
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
std::ostream &operator<<(std::ostream & o, const Form & inst);
#endif