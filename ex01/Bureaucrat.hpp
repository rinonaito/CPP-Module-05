#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class	Bureaucrat{

	public:
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const int grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &bureaucrat);

		void signForm(Form &form) const;

		std::string getName() const;
		int getGrade() const;
		void setGrade(int grade);
		void incrementGrade();
		void decrementGrade();

	private:
		const std::string name_;
		int grade_;
		static const int kHighestGrade = 1;
		static const int kLowestGrade = 150;

		Bureaucrat();

		class GradeTooHighException : public std::runtime_error{
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::runtime_error{
			public:
				GradeTooLowException();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
