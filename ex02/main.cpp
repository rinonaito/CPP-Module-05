#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

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

	if (argc!= 3){
		std::cout << "Usage: ./bureaucrat <name> <grade>" << std::endl;
		return 1;
	}

	std::string name = argv[1];
	int grade;
	Bureaucrat* one;
	try
	{
		grade = std::stoi(argv[2]);
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
		ShrubberyCreationForm shrubberyCreationForm = ShrubberyCreationForm("target");
		std::cout << shrubberyCreationForm << std::endl;
		one->signForm(shrubberyCreationForm);
		shrubberyCreationForm.execute(*one); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};