#include "Bureaucrat.hpp"
/*
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat & copy);
		~Bureaucrat(void);

		Bureaucrat & operator =(Bureaucrat const & rhs);

		std::string		getName(void) const;
		int				getGrade(void) const;

		void			upGrade(void);
		void			upGrade(int i);
		void			downGrade(void);
		void			downGrade(int i);	

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



std::ostream &operator<<(std::ostream & o, const Bureaucrat & inst);

#endif
*/
Bureaucrat::Bureaucrat() : _name("Undefined_name") , _grade(150)
{
	std::cout << "Default Constructor named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) , _grade(grade)
{
	std::cout << "Constructor named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
	
	
	
	if(getGrade() < 1 )
		throw GradeTooHighException();
	//std::cout << "\033[31m" << "Bureaucrat::GradeTooLowException" << "\033[0m" << std::endl;
	else if(getGrade() > 150)
		throw GradeTooLowException();
	//std::cout << "\033[31m" << "Bureaucrat::GradeTooHighException" << "\033[0m"<< std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	std::cout <<  "copy" << std::endl;
	*this=copy;
}
Bureaucrat & Bureaucrat::operator =(Bureaucrat const & inst)
{
	this->_grade = inst._grade;
	return (*this);
	std::cout <<  "operator=" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor named " << getName() << "with range "<< getGrade() << " destroyed!"<< std::endl;
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	//std::cout << "\033[32m" << a << "\033[0m" << std::endl;
	o << "\033[32m" << inst.getName() << ", bureaucrat grade " << inst.getGrade() << "\033[0m"  << std::endl;
	return (o);
	/*
	this->_grade = inst._grade;
	std::cout << this->getName() << ",, bureaucrat grade " << this->getGrade() << std::endl;
	return (*this);
	*/
	//std::cout <<  "operator=" << std::endl;
}


const std::string Bureaucrat::getName() const
{
	//std::cout << "getName() " << std::endl;
	return(_name);
}
int Bureaucrat::getGrade() const
{
	//std::cout << "getGrade() " << std::endl;
	return(_grade);
}

void Bureaucrat::upGrade(void)
{
	if (this->_grade - 1 < 1)
		throw(GradeTooHighException());
	else if (this->_grade - 1 > 150)
		throw (GradeTooLowException());
	this->_grade--;
}
void Bureaucrat::upGrade(int i)
{
	if (this->_grade - i < 1)
		throw (GradeTooHighException());
	else if (this->_grade - i > 150)
		throw (GradeTooLowException());
	this->_grade = this->_grade - i;
}
void Bureaucrat::downGrade(void)
{
	if(this->_grade + 1 > 150)
		throw (GradeTooLowException());
	else if(this->_grade + 1 < 1)
		throw (GradeTooHighException());
	this->_grade++;

}
void Bureaucrat::downGrade(int i)
{
	if(this->_grade + i > 150)
		throw (GradeTooLowException());
	else if(this->_grade + i < 1)
		throw (GradeTooHighException());
	this->_grade = this->_grade + i ;
}