#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();
		Intern& operator=(const Intern& intern);

		struct FormFactory {
			std::string name;
			AForm* (*create)(std::string);
		};

		class FormNotFoundException : public std::runtime_error{
			public:
				FormNotFoundException();
		};
		
		static AForm* creatPresidentialPardon(std::string target);
		static AForm* creatRobotomyRequest(std::string target);
		static AForm* creatShrubberyCreation(std::string target);
		AForm* makeForm(std::string name, std::string target);
		static const FormFactory form_factory_list_[3];
};