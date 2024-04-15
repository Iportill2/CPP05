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
Bureaucraft::Bureaucraft() : _name("Undefined_name") , _grade(99999)
{
	std::cout << "Default Constructor named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
}

Bureaucraft::Bureaucraft(const std::string name, const int grade) : _name(name) , _grade(grade)
{
	std::cout << "Constructor named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
	
	
	
	if(getGrade() < 1 )
		std::cout << "\033[31m" << "Bureaucrat::GradeTooLowException" << "\033[0m" << std::endl;
	else if(getGrade() > 150)
		std::cout << "\033[31m" << "Bureaucrat::GradeTooHighException" << "\033[0m"<< std::endl;
}
Bureaucraft::Bureaucraft(const Bureaucraft & copy)
{
	std::cout <<  "copy" << std::endl;
	*this=copy;
}
Bureaucraft & Bureaucraft::operator =(Bureaucraft const & inst)
{
	this->_grade = inst._grade;
	return (*this);
	std::cout <<  "operator=" << std::endl;
}
Bureaucraft::~Bureaucraft()
{
	std::cout << "Destructor named " << getName() << "with range "<< getGrade() << " destroyed!"<< std::endl;
}
std::ostream & operator<<(std::ostream & o, Bureaucraft const & inst)
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


const std::string Bureaucraft::getName() const
{
	//std::cout << "getName() " << std::endl;
	return(_name);
}
int Bureaucraft::getGrade() const
{
	//std::cout << "getGrade() " << std::endl;
	return(_grade);
}