#include "Bureaucrat.hpp"
#include "Form.hpp"
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
		const int gradeTooHigh = 0;
		PrintWithBlueColor("<< Construct with grade " + toString(gradeTooHigh) + " >>");
		Form tooHigh = Form("tooHigh", gradeTooHigh, gradeTooHigh);
		std::cout << tooHigh << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		const int gradeTooLow = 151;
		PrintWithBlueColor("<< Construct with grade " + toString(151) + " >>");
		Form tooLow = Form("tooLow", gradeTooLow, gradeTooLow);
		std::cout << tooLow << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	const int lowestGrade = 150;
	PrintWithBlueColor("<< Construct with grade " + toString(lowestGrade) + " >>");
	Form withLowestGrade = Form("FormWithLowestGrade", lowestGrade, lowestGrade); 
	std::cout << withLowestGrade << std::endl;
	one->signForm(withLowestGrade);
	std::cout << withLowestGrade << std::endl;

	const int highestGrade = 1;
	PrintWithBlueColor("<< Construct with grade " + toString(highestGrade) + " >>");
	Form withHighestGrade = Form("FormWithHighestGrade", highestGrade, highestGrade); 
	std::cout << withHighestGrade << std::endl;
	one->signForm(withHighestGrade);
	std::cout << withHighestGrade << std::endl;
};