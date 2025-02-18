#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &form);
		~Form();
		Form& operator=(const Form &form);

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		bool beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::runtime_error{
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::runtime_error{
			public:
				GradeTooLowException();
		};

	private:
		const std::string name_;
		const int signGrade_;
		const int execGrade_;
		bool isSigned_;
		static const int kHighestGrade = 1;
		static const int kLowestGrade = 150;
		Form();
		bool isValidGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& form);