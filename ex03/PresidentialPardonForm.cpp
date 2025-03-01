#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5, "DefaultTarget"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("presidential pardon", 25, 5, target){};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget()){};

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form){
	AForm::operator=(form);
	return *this;
};

//Informs that <target> has been pardoned by Zaphod Beeblebrox.
bool PresidentialPardonForm::executeCore() const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return true;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	os << static_cast<const AForm&>(form);
	return os;
};