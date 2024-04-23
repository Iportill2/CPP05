#include "Form.hpp"
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
Form::Form() : _name("Form Name"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{
	if(getGradetosign() < 1  || getGradetoexecute() < 1)
		throw GradeTooHighException();
	else if(getGradetosign() > 150  || getGradetoexecute() > 150)
		throw GradeTooLowException();
/*
 	std::cout << "\033[36m" << "Default Form constructor named " << this->getName()  << " created" << "\033[0m"<< std::endl;
	std::cout << "getSigned= " << getSigned() << "getGradetosign= "<< getGradetosign() << "getGradetoexecute= "  << getGradetoexecute() << "\033[0m" << std::endl; 
*/
}
Form::Form(std::string name,int grade_to_sign,int grade_to_execute) : _name(name),_grade_to_sign(grade_to_sign),_grade_to_execute(grade_to_execute) ,_signed(false)
{
	if(getGradetosign() < 1  || getGradetoexecute() < 1)
		throw GradeTooHighException();
	else if(getGradetosign() > 150  || getGradetoexecute() > 150)
		throw GradeTooLowException();
/*
std::cout  << "\033[35m"<< "Constructor Form named " << this->getName() <<  " created" << "\033[0m" << std::endl;
std::cout << "getSigned=" << getSigned() << " getGradetosign="<< getGradetosign() << " getGradetoexecute=" << getGradetoexecute() << std::endl; 
*/

}
Form::Form(const Form & copy)
{
	std::cout <<  "Form copy" << std::endl;
	*this=copy;
}
Form & Form::operator=(Form const & inst)
{
	this->_name = inst._name;
	this->_grade_to_sign = inst._grade_to_sign;
	this->_grade_to_execute = inst._grade_to_execute;
	this->_signed = inst._signed;
	return (*this);
	std::cout <<  "Form operator=" << std::endl;
}
Form::~Form()
{
std::cout << "Destructor Form named " << this->getName() <<  " destroyed!"<< std::endl;
}

//SETTERS
void Form::setName(std::string name)
{
	_name = name;
}
void Form::setGradetosign(int grade_to_sign)
{
	_grade_to_sign = grade_to_sign;

}
void Form::setGradetoexecute(int grade_to_execute)
{
	_grade_to_execute = grade_to_execute;
}
void Form::setSigned(bool signe)
{
	_signed = signe;
}
//GETTERS
const	std::string Form::getName() const 
{
	return(this->_name);
}
bool Form::getSigned() const 
{
	return(this->_signed);
}
int Form::getGradetosign() const
{
	return(this->_grade_to_sign);
}
int Form::getGradetoexecute() const 
{
	return(this->_grade_to_execute);
}


void Form::beSigned(Bureaucrat &inst)
{
	this->_signed = true;
	std::cout << "gradetosign=" << getGradetosign() << " gradotoexecute= " << getGradetoexecute() << std::endl;
	std::cout << inst.getName() << " signed Form named " << getName() << std::endl;
}


std::ostream& operator <<(std::ostream &v, const Form &inst)
{   
	v << "\033[32m" <<  "operator<< " << std::endl ;
	v << "Form name: " << inst.getName();
	v << ", Status(Signed)TRUE=1/FALSE=0: " << inst.getSigned();
	v << ", Sign grade: " << inst.getGradetosign();
	v << ", Execution grade: " << inst.getGradetoexecute() << "\033[0m"  << std::endl;;

	return (v);
}
