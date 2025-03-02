#pragma once 
#include "AForm.hpp"
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <sys/stat.h>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &form);
		~ShrubberyCreationForm();
		static const std::string kName;
		static const int kSignGrade;
		static const int kExecGrade;

	private:
		ShrubberyCreationForm();
		bool executeCore() const;
		std::string getAsciiTree() const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);