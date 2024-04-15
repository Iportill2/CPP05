/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:31:08 by imontero          #+#    #+#             */
/*   Updated: 2023/12/26 12:31:08 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		Intern & operator =(Intern const &rhs);

		AForm	*makeForm(std::string name, std::string target);

		class UnofficialFormException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form not found");
				}
		};
};

#endif
