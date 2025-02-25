#pragma once 
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &form);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &form);

	private:
		PresidentialPardonForm();
		bool executeCore() const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);