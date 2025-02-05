#include "Bureaucrat.hpp"

int	main(int argc, char **argv){

	if (argc!= 3){
		std::cout << "Usage: ./bureaucrat <name> <grade>" << std::endl;
		return 1;
	}

	std::string name = argv[1];
	int grade = std::stoi(argv[2]);
	Bureaucrat* one = new Bureaucrat(name, grade);
	one->decrementGrade();
	std::cout << *one << std::endl;

	std::cout << "<< Increment grade until Highest >>" << std::endl;
	while (1) {
		try {
			one->incrementGrade();
			std::cout << *one << std::endl;
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
			break;
		}
	}
	std::cout << "<< Decrement grade until Lowest >>" << std::endl;
	while (1) {
		try {
			one->decrementGrade();
			std::cout << *one << std::endl;
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
			break;
		}
	}
};
