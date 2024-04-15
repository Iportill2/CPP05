/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:28:45 by imontero          #+#    #+#             */
/*   Updated: 2023/12/23 18:28:45 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat & copy);
		~Bureaucrat(void);

		Bureaucrat & operator =(Bureaucrat const & rhs);

		std::string		getName(void) const;
		int				getGrade(void) const;
		//void			setGrade(int i);

		void			upGrade(void);
		void			upGrade(int i);
		void			downGrade(void);
		void			downGrade(int i);
		bool			signForm(AForm &inst);
		void			executeForm(AForm const &form);	

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

		class UnsignedFormException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is unsigned");
				}
		};

};

std::ostream &operator<<(std::ostream & o, const Bureaucrat & inst);

#endif
