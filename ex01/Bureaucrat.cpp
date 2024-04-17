#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Undefined_name") , _grade(149)
{
	std::cout << "Default Constructor Burocrata named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) , _grade(grade)
{
	std::cout << "Constructor Burocrata named " << getName() << " with range " << getGrade() << " created!"<< std::endl;
	
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
	std::cout << "Destructor Burocrata named " << getName() << " with range "<< getGrade() << " destroyed!"<< std::endl;
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	//std::cout << "\033[32m" << a << "\033[0m" << std::endl;
	//this->_grade = inst._grade;
	o << "\033[32m" << inst.getName() << ", bureaucrat grade " << inst.getGrade() << "\033[0m"  << std::endl;
	return (o);
	/*
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