#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
	std::string _name;
	int		_grade_to_sign;
	int 	_grade_to_execute;
	bool	_signed;
	public:
	//CANONICAL
	Form();
	Form(std::string name,int grade_to_sign,int grade_to_execute);	
	Form(const Form & copy);
	Form & operator=(Form const & inst);
	~Form();

	void setName(std::string name);
	void setGradetosign(int grade_to_sign);
	void setGradetoexecute(int grade_to_execute);
	void setSigned(bool signe);
	//GETTERS
	const	std::string getName() const ;
	int		getGradetosign()const ;
	int		getGradetoexecute()const ;
	bool	getSigned() const ;

	void	beSigned(Bureaucrat &inst);

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