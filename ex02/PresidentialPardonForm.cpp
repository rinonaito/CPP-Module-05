#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "DefaultTarget"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5, target){};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget()){};

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form){
	AForm::operator=(form);
	return *this;
};

bool PresidentialPardonForm::executeCore() const
{
	return true;
	//Informs that <target> has been pardoned by Zaphod Beeblebrox.
}