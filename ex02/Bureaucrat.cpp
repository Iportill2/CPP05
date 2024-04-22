#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Undefined_name") , _grade(145)
{
	if(getGrade() < 1 )
		throw GradeTooHighException();
	else if(getGrade() > 150)
		throw GradeTooLowException();
	std::cout << "\033[33m" << "Default Constructor Burocrata named " << getName() << " with range " << getGrade() << " created!"<< "\033[0m"<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) , _grade(grade)
{
	
	if(getGrade() < 1 )
		throw GradeTooHighException();
	else if(getGrade() > 150)
		throw GradeTooLowException();
	std::cout << "\033[31m" << "Constructor Burocrata named " << getName() << " with range " << getGrade() << " created!"<< "\033[0m" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	std::cout <<  "copy" << std::endl;
	*this=copy;
}
Bureaucrat & Bureaucrat::operator =(Bureaucrat const & inst)
{
	this->_grade = inst._grade;
	this->_name = inst._name;
	//std::cout <<  "operator=" << std::endl;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Burocrata named " << getName() << " with range "<< getGrade() << " destroyed!"<< std::endl;
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{

	o << "\033[32m" << "operator<< " << "Bureaucrat Name: "<< inst.getName() << " and, bureaucrat grade " << inst.getGrade() << "\033[0m"  << std::endl;
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

bool	Bureaucrat::signForm(AForm &inst)
{
	if(inst.getSigned() == true)
	{
		std::cout << "Bureaucrat " << this->_name;
		std::cout << " couldn’t sign form " << inst.getName(); 
		std::cout << " because it's already signed." << std::endl;
		return(false);
	}
	else if(this->_grade > inst.getGradetosign())
	{
		std::cout << "bureaucrat " << this->_name;
		std::cout << " couldn’t sign form " << inst.getName(); 
		std::cout << " because he or she has not enough grade." << std::endl;
		std::cout << "NAME =" << inst.getName() << " GRADE=" << this->getGrade() << std::endl;
		throw (GradeTooLowException());
		return(false);
	}	
	else
	{
		inst.beSigned(*this);
		return(true);
	}
}