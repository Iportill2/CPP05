#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Form a(false,138,128);
	Form b = a;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
}