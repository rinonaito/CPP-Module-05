#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string name, const int signGrade, const int execGrade, std::string target);
		AForm(const AForm &form);
		~AForm();
		AForm& operator=(const AForm &form);

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		std::string getTarget() const;
		bool isSigned() const;
		bool beSigned(const Bureaucrat &bureaucrat);
		bool execute(Bureaucrat const & executor) const;
		virtual bool executeCore() const;

		class GradeTooHighException : public std::runtime_error{
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::runtime_error{
			public:
				GradeTooLowException();
		};
		class IsNotSignedException : public std::runtime_error{
			public:
				IsNotSignedException();
		};

	private:
		const std::string name_;
		const int signGrade_;
		const int execGrade_;
		bool isSigned_;
		std::string target_;
		static const int kHighestGrade = 1;
		static const int kLowestGrade = 150;
		AForm();
		bool isValidGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const AForm& form);