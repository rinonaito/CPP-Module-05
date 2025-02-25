#pragma once 
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &form);

	private:
		RobotomyRequestForm();
		bool executeCore() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);