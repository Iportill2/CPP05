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

	std::cout << "\033[36m" << "Default Form constructor named " << this->getName()  << " created" << "\033[0m"<< std::endl;
	std::cout << "getSigned= " << getSigned() << "getGradetosign= "<< getGradetosign() << "getGradetoexecute= "  << getGradetoexecute() << "\033[0m" << std::endl;
}
Form::Form(std::string name,int grade_to_sign,int grade_to_execute) : _name(name),_grade_to_sign(grade_to_sign),_grade_to_execute(grade_to_execute) ,_signed(false)
{
	if(getGradetosign() < 1  || getGradetoexecute() < 1)
		throw GradeTooHighException();
	else if(getGradetosign() > 150  || getGradetoexecute() > 150)
		throw GradeTooLowException();

//this->_name = this->Bureaucrat::getName();
std::cout  << "\033[35m"<< "Constructor Form named " << this->getName() <<  " created" << "\033[0m" << std::endl;
std::cout << "getSigned=" << getSigned() << " getGradetosign="<< getGradetosign() << " getGradetoexecute=" << getGradetoexecute() << std::endl;

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


void Form::beSigned(Bureaucrat &inst)
{
	std::cout << "This form has been signed by bureaucrat " << inst.getName() << std::endl;
	this->_signed = true;
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