#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45, "DefaultTarget"){};
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy request", 72, 45, target){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form): AForm(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget()){};
RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form){
	AForm::operator=(form);
	return *this;
};

//Makes some drilling noises. Then, informs that <target> has been robotomized
//successfully 50% of the time. Otherwise, informs that the robotomy failed.
bool RobotomyRequestForm::executeCore() const
{
	srand(time(NULL));
	int random = rand();
	if (random % 2 == 0)
	{
		std::cout << "Drrrrrrrrrrrrr" << std::endl;
		std::cout << "... " << this->getTarget() << " has been robotomized successfully." << std::endl;
		return true;
	}
	std::cout << "Failed to robotomize " << this->getTarget() << "..." << std::endl;
	return false;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	os << static_cast<const AForm&>(form);
	return os;
};