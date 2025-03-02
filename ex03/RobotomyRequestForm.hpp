#pragma once 
#include "AForm.hpp"
#include <cstdlib> 

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &form);
		static const std::string kName;
		static const int kSignGrade;
		static const int kExecGrade;

	private:
		RobotomyRequestForm();
		bool executeCore() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);