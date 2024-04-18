#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP
# include <iostream>
# include "Form.hpp"

//class exception;
class Form;
class Bureaucrat
{
	protected:
		std::string _name;
		int _grade;
	public:
	//CANONICAL//
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat & copy);
		Bureaucrat & operator =(Bureaucrat const & inst);
		~Bureaucrat();
		//friend std::ostream & operator<<(std::ostream & o, Bureaucraft const & inst2);
		
		bool	signForm(Form &inst);


		const std::string getName() const;
		int getGrade() const;

		void			upGrade(void);
		void			upGrade(int i);
		void			downGrade(void);
		void			downGrade(int i);

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
std::ostream &operator<<(std::ostream & o, const Bureaucrat & inst);
#endif

/*
#include "Form.hpp"

Form::Form(void): 
	_name("Undefined"),
	_sigStatus(false), 
	_signGrade(150),
	_execGrade(150)
{
}

Form::Form(std::string name, int signGrade, int executeGrade):
	_name(name),
	_sigStatus(false),
	_signGrade(signGrade),
	_execGrade(executeGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (GradeTooHighException());
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (GradeTooLowException());
}

Form::Form (const Form & copy):
	_name(copy._name),
	_sigStatus(copy._sigStatus),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
	*this = copy;
}

Form::~Form(void)
{
}

Form &Form::operator =(Form const &rhs)
{
	this->_sigStatus = rhs._sigStatus;
	return (*this);
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSigStatus(void) const
{
	return (this->_sigStatus);
}

int					Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int					Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void				Form::beSigned(Bureaucrat &inst)
{
	if (inst.signForm(*this))
	{
		std::cout << "This form has been signed by bureaucrat " << inst.getName() << std::endl;
		this->_sigStatus = true;
	}
	
}


std::ostream& operator <<(std::ostream &o, const Form &inst)
{
	o << "Form name: " << inst.getName();
	o << ", Status: " << inst.getSigStatus();
	o << ", Sign grade: " << inst.getSignGrade();
	o << ", Execution grade: " << inst.getExecGrade();
	return (o);
}

*/