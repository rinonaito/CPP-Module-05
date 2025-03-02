#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::kName = "presidential pardon";
const int PresidentialPardonForm::kSignGrade = 25;
const int PresidentialPardonForm::kExecGrade= 5;

PresidentialPardonForm::PresidentialPardonForm() : AForm(PresidentialPardonForm::kName, PresidentialPardonForm::kSignGrade, PresidentialPardonForm::kExecGrade, "DefaultTarget"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(PresidentialPardonForm::kName, PresidentialPardonForm::kSignGrade, PresidentialPardonForm::kExecGrade, target){};

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