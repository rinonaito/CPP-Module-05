#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void PrintWithBlueColor(std::string message)
{
	const std::string kBulue = "\033[36m";
	const std::string kReset = "\033[0m";
	std::cout << kBulue << message << kReset << std::endl; 
}

std::string toString(int num)
{
	std::ostringstream oss;
	oss << num;
	return oss.str();
}

int	main(int argc, char **argv){

	if (argc!= 4){
		std::cout << "Usage: ./bureaucrat <name> <grade> <target>" << std::endl;
		return 1;
	}

	std::string name = argv[1];
	std::string  target = argv[3];
	int grade;
	Bureaucrat* one;
	try
	{
		grade = std::atoi(argv[2]);
		one = new Bureaucrat(name, grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << *one << std::endl;

	try
	{
		ShrubberyCreationForm shrubberyCreationForm = ShrubberyCreationForm(target);
		std::cout << shrubberyCreationForm << std::endl;
		one->signForm(shrubberyCreationForm);
		one->executeForm(shrubberyCreationForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		RobotomyRequestForm robotomyRequestForm = RobotomyRequestForm(target);
		std::cout << robotomyRequestForm << std::endl;
		one->signForm(robotomyRequestForm);
		one->executeForm(robotomyRequestForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		PresidentialPardonForm presidentialPardonForm = PresidentialPardonForm(target);
		std::cout << presidentialPardonForm<< std::endl;
		one->signForm(presidentialPardonForm);
		one->executeForm(presidentialPardonForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};
