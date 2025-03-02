#include "Intern.hpp"

 const Intern::FormFactory Intern::form_factory_list_[3] = {
	{"presidential pardon", creatPresidentialPardon},
	{"robotomy request", creatRobotomyRequest},
	{"shrubbery creation", creatShrubberyCreation}
};

Intern::Intern(){};
Intern::Intern(const Intern& intern){
	(void)intern;
};
Intern::~Intern(){};
Intern& Intern::operator=(const Intern& intern){
	(void)intern;
	return *this;
};

AForm* Intern::creatPresidentialPardon(std::string target){
	return new PresidentialPardonForm(target);
};

AForm* Intern::creatRobotomyRequest(std::string target){
	return new RobotomyRequestForm(target);
};

AForm* Intern::creatShrubberyCreation(std::string target){
	return new ShrubberyCreationForm(target);
};

AForm* Intern::makeForm(std::string name, std::string target){
	std::cout << ShrubberyCreationForm::kName << std::endl;
	unsigned long array_size = sizeof(form_factory_list_) / sizeof(form_factory_list_[0]); 
	for (unsigned long i = 0; i < array_size; i++)
	{
		if (form_factory_list_[i].name == name) {
			return form_factory_list_[i].create(target);
		}
	}
	throw FormNotFoundException();
};

Intern::FormNotFoundException::FormNotFoundException() : runtime_error("[ERROR]form with the matching name not found."){};