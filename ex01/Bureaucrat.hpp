#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP
# include <iostream>


class Bureaucraft
{
	private:
		std::string _name;
		int _grade;
	public:
	//CANONICAL//
		Bureaucraft();
		Bureaucraft(const std::string name, const int grade);
		Bureaucraft(const Bureaucraft & copy);
		Bureaucraft & operator =(Bureaucraft const & inst);
		~Bureaucraft();
		friend std::ostream & operator<<(std::ostream & o, Bureaucraft const & inst2);


		const std::string getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid grade. Must be under 1");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid grade. Must be above 150");
				}
		};
};
//std::ostream &operator<<(std::ostream & o, const Bureaucraft & inst);
#endif

/*
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Undefined"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat & Bureaucrat::operator =(Bureaucrat const & rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::upGrade(void)
{
	if (this->_grade - 1 < 1)
		throw(GradeTooHighException());
	else if (this->_grade - 1 > 150)
		throw (GradeTooLowException());
	this->_grade--;
}

void		Bureaucrat::upGrade(int i)
{
	if (this->_grade - i < 1)
		throw (GradeTooHighException());
	else if (this->_grade - i > 150)
		throw (GradeTooLowException());
	this->_grade -= i;
}

void		Bureaucrat::downGrade(void)
{
	if (this->_grade + 1  > 150)
		throw(GradeTooLowException());
	else if (this->_grade  + 1 < 1)
		throw (GradeTooHighException());
	this->_grade++;
}

void		Bureaucrat::downGrade(int i)
{
	if (this->_grade + i < 1)
		throw (GradeTooHighException());
	else if (this->_grade + i > 150)
		throw (GradeTooLowException());
	this->_grade += i;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	o << inst.getName() << ", bureaucrat grade: " << inst.getGrade();
	return (o);
}


*/