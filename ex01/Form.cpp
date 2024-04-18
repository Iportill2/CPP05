#include "Form.hpp"
#include "Bureaucrat.hpp"
//CANONICAL
Form::Form(): Bureaucrat("def_Burocrata",150) ,_signed(false),_grade_to_sign(150),_grade_to_execute(150)
{
	if(getGrade() < 1 )
		throw GradeTooHighException();
	else if(getGrade() > 150)
		throw GradeTooLowException();

	std::cout << "Default Form constructor named " << this->Bureaucrat::getName() << " with range " << this->Bureaucrat::getGrade() << " created" << std::endl;
	std::cout << "getSigned= " << getSigned() << "getGradetosign= "<< getGradetosign() << "getGradetoexecute= " << getGradetoexecute() << std::endl;
}
Form::Form(bool  Signed,int grade_to_sign,int grade_to_execute) : Bureaucrat("Burocrata1",150) ,_signed(Signed),_grade_to_sign(grade_to_sign),_grade_to_execute(grade_to_execute) 
{
	if(getGradetosign() < 1  || getGradetoexecute() < 1)
		throw GradeTooHighException();
	else if(getGradetosign() > 150  || getGradetoexecute() > 150)
		throw GradeTooLowException();

this->_name = this->Bureaucrat::getName();
std::cout << "Constructor Form named " << this->Bureaucrat::getName() << " with range " << this->Bureaucrat::getGrade() << " created" << std::endl;
std::cout << "getSigned=" << getSigned() << " getGradetosign="<< getGradetosign() << " getGradetoexecute=" << getGradetoexecute() << std::endl;

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
std::cout << "Destructor Form named " << this->Bureaucrat::getName() << " with range "<< getGrade() << " destroyed!"<< std::endl;
}


void Form::setName(std::string name)
{
	_name = name;
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




void Form::signForm(Bureaucrat &inst)
{
 (void)&inst;
}
void Form::beSigned()
{

}




void Form::beSigned(Bureaucrat)
{

}

std::ostream& operator <<(std::ostream &v, const Form &inst)
{
	v << "Form name: " << inst.getName();
	v << ", Status(Signed)TRUE=1/FALSE=0: " << inst.getSigned();
	v << ", Sign grade: " << inst.getGradetosign();
	v << ", Execution grade: " << inst.getGradetoexecute();
	return (v);
}

/*
#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_sigStatus;
		int const			_signGrade;
		int const			_execGrade;
		
	public:
		Form(void);
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form & copy);
		~Form(void);

		Form & operator =(Form const & rhs);

		std::string const	getName(void) const;
		bool				getSigStatus(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		void				beSigned(Bureaucrat &inst);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
};

std::ostream& operator<<(std::ostream &o, const Form &inst);


#endif
*/