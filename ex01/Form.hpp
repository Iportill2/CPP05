#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
	private:
	bool	_signed;
	int		_grade_to_sign;
	int 	_grade_to_execute;
	public:
	const std::string _name;
	//CANONICAL
	Form();
	Form(const std::string name,const int grade,int signed,int grade_to_sign,int grade_to_execute);	
	Form(const Form & copy);
	Form & operator=(Form const & inst);
	~Form();




	//GETTERS
	const	std::string getName();
	bool	getSigned();
	int		getGradetosign();
	int		getGradetoexecute();

	void signForm();
	void beSigned();
};
std::ostream &operator<<(std::ostream & o, const Form & inst);
#endif