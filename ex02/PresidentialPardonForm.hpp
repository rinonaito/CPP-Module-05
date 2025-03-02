#pragma once 
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &form);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &form);
		static const std::string kName;
		static const int kSignGrade;
		static const int kExecGrade;

	private:
		PresidentialPardonForm();
		bool executeCore() const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);