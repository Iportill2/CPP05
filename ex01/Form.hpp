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
	std::string _name;
	public:
	//CANONICAL
	Form();
	Form(bool Signed,int grade_to_sign,int grade_to_execute);	
	Form(const Form & copy);
	Form & operator=(Form const & inst);
	~Form();

	void setName(std::string name);
	//GETTERS
	const	std::string getName() const ;
	bool	getSigned() const ;
	int		getGradetosign()const ;
	int		getGradetoexecute()const ;

	void 	signForm(Bureaucrat &inst);
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
std::ostream& operator <<(std::ostream &v, const Form &inst) ;
#endif