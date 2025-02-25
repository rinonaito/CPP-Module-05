#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "DefaultTarget"){};
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45, target){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form): AForm(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget()){};
RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form){
	AForm::operator=(form);
	return *this;
};

bool RobotomyRequestForm::executeCore() const
{
	return true;
	//Makes some drilling noises. Then, informs that <target> has been robotomized
	//successfully 50% of the time. Otherwise, informs that the robotomy failed.
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);