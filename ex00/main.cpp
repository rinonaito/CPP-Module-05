#include "Bureaucrat.hpp"
#include <cstdlib>

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
		grade = std::atoi(argv[2]);
		one = new Bureaucrat(name, grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << *one << std::endl;

	std::cout << "<< Increment grade until Highest >>" << std::endl;
	while (1) {
		try {
			one->incrementGrade();
			std::cout << *one << std::endl;
		} catch (std::exception &e){
			std::cerr << e.what() << std::endl;
			break;
		}
	}
	std::cout << "<< Decrement grade until Lowest >>" << std::endl;
	while (1) {
		try {
			one->decrementGrade();
			std::cout << *one << std::endl;
		} catch (std::exception &e){
			std::cerr << e.what() << std::endl;
			break;
		}
	}
};
