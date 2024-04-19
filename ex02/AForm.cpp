#include "AForm.hpp"
#include "Bureaucrat.hpp"
/*
\033[0m - Restablecer / color por defecto
\033[30m - Negro
\033[31m - Rojo
\033[32m - Verde
\033[33m - Amarillo
\033[34m - Azul
\033[35m - Magenta
\033[36m - Cian
\033[37m - Blanco
*/

//CANONICAL
AForm::AForm() : _name("Form Name"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{
	if(getGradetosign() < 1  || getGradetoexecute() < 1)
		throw GradeTooHighException();
	else if(getGradetosign() > 150  || getGradetoexecute() > 150)
		throw GradeTooLowException();
	std::cout << "\033[36m" << "Default Form constructor named " << this->getName()  << " created" << "\033[0m"<< std::endl;
	std::cout << "getSigned= " << getSigned() << "getGradetosign= "<< getGradetosign() << "getGradetoexecute= "  << getGradetoexecute() << "\033[0m" << std::endl;
}
AForm::AForm(std::string name,int grade_to_sign,int grade_to_execute) : _name(name),_grade_to_sign(grade_to_sign),_grade_to_execute(grade_to_execute) ,_signed(false)
{
	if(getGradetosign() < 1  || getGradetoexecute() < 1)
		throw GradeTooHighException();
	else if(getGradetosign() > 150  || getGradetoexecute() > 150)
		throw GradeTooLowException();
std::cout  << "\033[35m"<< "Constructor Form named " << this->getName() <<  " created" << "\033[0m" << std::endl;
std::cout << "getSigned=" << getSigned() << " getGradetosign="<< getGradetosign() << " getGradetoexecute=" << getGradetoexecute() << std::endl;

}
AForm::AForm(const AForm & copy)
{
	std::cout <<  "Form copy" << std::endl;
	*this=copy;
}
AForm & AForm::operator=(AForm const & inst)
{
	this->_name = inst._name;
	this->_grade_to_sign = inst._grade_to_sign;
	this->_grade_to_execute = inst._grade_to_execute;
	this->_signed = inst._signed;
	return (*this);
	std::cout <<  "Form operator=" << std::endl;
}
AForm::~AForm()
{
std::cout << "Destructor Form named " << this->getName() <<  " destroyed!"<< std::endl;
}

//SETTERS
void AForm::setName(std::string name)
{
	_name = name;
}
void AForm::setGradetosign(int grade_to_sign)
{
	_grade_to_sign = grade_to_sign;

}
void AForm::setGradetoexecute(int grade_to_execute)
{
	_grade_to_execute = grade_to_execute;
}
void AForm::setSigned(bool signe)
{
	_signed = signe;
}
//GETTERS
const	std::string AForm::getName() const 
{
	return(this->_name);
}
bool AForm::getSigned() const 
{
	return(this->_signed);
}
int AForm::getGradetosign() const
{
	return(this->_grade_to_sign);
}
int AForm::getGradetoexecute() const 
{
	return(this->_grade_to_execute);
}


void AForm::beSigned(Bureaucrat &inst)
{
	this->_signed = true;
	std::cout << "gradetosign=" << getGradetosign() << " gradotoexecute= " << getGradetoexecute() << std::endl;
	std::cout << inst.getName() << " signed Form named " << getName() << std::endl;
}


std::ostream& operator <<(std::ostream &v, const AForm &inst)
{   
	v << "\033[32m" <<  "operator<< ";
	v << "Form name: " << inst.getName();
	v << ", Status(Signed)TRUE=1/FALSE=0: " << inst.getSigned();
	v << ", Sign grade: " << inst.getGradetosign();
	v << ", Execution grade: " << inst.getGradetoexecute() << "\033[0m"  << std::endl;;

	return (v);
}
