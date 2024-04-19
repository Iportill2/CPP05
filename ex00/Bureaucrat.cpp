#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Undefined_name") , _grade(150)
{
	std::cout << "Default Constructor named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) , _grade(grade)
{
	std::cout << "Constructor named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
	if(getGrade() < 1 )
		throw GradeTooHighException();
	else if(getGrade() > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	std::cout <<  "copy" << std::endl;
	*this=copy;
}
Bureaucrat & Bureaucrat::operator =(Bureaucrat const & inst)
{
	this->_name = inst._name;
	this->_grade = inst._grade;
	return (*this);
	std::cout <<  "operator=" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor named " << getName() << " with range "<< getGrade() << " destroyed!"<< std::endl;
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	o << "\033[32m" << inst.getName() << ", bureaucrat grade " << inst.getGrade() << "\033[0m"  << std::endl;
	return (o);
}


const std::string Bureaucrat::getName() const
{
	return(_name);
}
int Bureaucrat::getGrade() const
{
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