#include "Form.hpp"
#include "Bureaucrat.hpp"
//CANONICAL
Form::Form(): Bureaucrat("def_Burocrata",150) ,_signed(false),_grade_to_sign(150),_grade_to_execute(150)
{
	std::cout << "Default Form constructor named " << this->Bureaucrat::getName() << " with range " << this->Bureaucrat::getGrade() << " created" << std::endl;
}
Form::Form(int  signed,int grade_to_sign,int grade_to_execute) : Bureaucrat("Burocrata1",150) ,_signed(false),_grade_to_sign(grade_to_sign),_grade_to_execute(grade_to_execute) 
{
std::cout << "Constructor Form named " << this->Bureaucrat::getName() << " with range " << this->Bureaucrat::getGrade() << " created" << std::endl;
}
Form::Form(const Form & copy)
{
	std::cout <<  "Form copy" << std::endl;
	*this=copy;
}
Form & Form::operator=(Form const & inst)
{
	this->_grade = inst._grade;
	return (*this);
	std::cout <<  "Form operator=" << std::endl;
}
Form::~Form()
{
std::cout << "Destructor Form named " << this->Bureaucrat::getName() << "with range "<< getGrade() << " destroyed!"<< std::endl;
}





//GETTERS
const	std::string Form::getName()
{
	return(this->_name);
}
bool Form::getSigned()
{
	return(this->_signed);
}
int Form::getGradetosign()
{
	return(this->_grade_to_sign);
}
int Form::getGradetoexecute()
{
	return(this->_grade_to_execute);
}




void Form::signForm()
{

}
void Form::beSigned()
{

}




void Form::beSigned(Bureaucrat)
{

}