#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
		Intern intern = Intern();

		PrintWithBlueColor("<< ShruberryCreationForm >>");
		AForm* shrubberyCreation = intern.makeForm(ShrubberyCreationForm::kName, target);
		one->signForm(*shrubberyCreation);
		one->executeForm(*shrubberyCreation);

		PrintWithBlueColor("<< RobotomyRequestForm >>");
		AForm* robotomyRequest = intern.makeForm(RobotomyRequestForm::kName, target);
		one->signForm(*robotomyRequest);
		one->executeForm(*robotomyRequest);

		PrintWithBlueColor("<< PresidentialPardonForm >>");
		AForm* presidentialPardon = intern.makeForm(PresidentialPardonForm::kName, target);
		one->signForm(*presidentialPardon);
		one->executeForm(*presidentialPardon);

		PrintWithBlueColor("<< WrongForm >>");
		AForm* wrongForm = intern.makeForm("wrong form name", target);
		one->signForm(*wrongForm);
		one->executeForm(*wrongForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};
