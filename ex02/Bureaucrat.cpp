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
	if(this->_name.empty())
		this->_name = "NoName";
	if(getGrade() < 1 )
		throw GradeTooHighException();
	else if(getGrade() > 150)
		throw GradeTooLowException();
	std::cout << "\033[31m" << "Constructor Burocrata named " << getName() << " with range " << getGrade() << " created!"<< "\033[0m" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	*this = copy;//operator =
	std::cout <<  "[Bureaucrat copy] "   << " Bureaucrat OG: " << copy._name << " Bureaucrat Copy: " << this->_name << std::endl;
}
Bureaucrat & Bureaucrat::operator =(Bureaucrat const & inst)
{
	std::cout << "[Bureaucrat::operator =] " <<  "OG:"  << inst._name << " Dest:" << this->_name  << std::endl;
	this->_grade = inst._grade;
	this->_name = inst._name;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Burocrata named " << this->getName() << " with range "<< this->getGrade() << " destroyed!"<< std::endl;
}


//GETTERS
const std::string Bureaucrat::getName() const
{
	return(_name);
}
int Bureaucrat::getGrade() const
{
	return(_grade);
}
//SETTERS
void Bureaucrat::upGrade(void)
{
	std::cout << "void Bureaucrat::upGrade(void)" << std::endl;
	if (this->_grade - 1 < 1)
		throw(GradeTooHighException());
	else if (this->_grade - 1 > 150)
		throw (GradeTooLowException());
	this->_grade--;
}
void Bureaucrat::upGrade(int i)
{
	std::cout << "void Bureaucrat::upGrade(int i)" << std::endl;
	if (this->_grade - i < 1)
		throw (GradeTooHighException());
	else if (this->_grade - i > 150)
		throw (GradeTooLowException());
	this->_grade = this->_grade - i;
}
void Bureaucrat::downGrade(void)
{
	std::cout << "void Bureaucrat::downGrade(void)" << std::endl;
	if(this->_grade + 1 > 150)
		throw (GradeTooLowException());
	else if(this->_grade + 1 < 1)
		throw (GradeTooHighException());
	this->_grade++;

}
void Bureaucrat::downGrade(int i)
{
	std::cout << "void Bureaucrat::downGrade(int i)" << std::endl;
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
std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	o << "\033[36m" << "operator<< " << "\033[32m"<< "Bureaucrat Name: "<< inst.getName() << " and, bureaucrat grade " << inst.getGrade() << "\033[0m"  << std::endl;
		return (o);
}