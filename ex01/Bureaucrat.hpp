#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP
# include <iostream>

class exception;

class Bureaucrat
{
	protected:
		std::string _name;
		int _grade;
	public:
	//CANONICAL//
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat & copy);
		Bureaucrat & operator =(Bureaucrat const & inst);
		~Bureaucrat();
		//friend std::ostream & operator<<(std::ostream & o, Bureaucraft const & inst2);


		const std::string getName() const;
		int getGrade() const;

		void			upGrade(void);
		void			upGrade(int i);
		void			downGrade(void);
		void			downGrade(int i);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid grade. Must be over 0");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid grade. Must be under 150");
				}
		};
};
std::ostream &operator<<(std::ostream & o, const Bureaucrat & inst);
#endif

