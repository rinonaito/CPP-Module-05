#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
};

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
	:name_(bureaucrat.getName()), grade_(bureaucrat.getGrade()) {
};

Bureaucrat::Bureaucrat(const std::string name)
	: name_(name) {
};

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: name_(name), grade_(grade){
};

Bureaucrat::~Bureaucrat(){
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat){
	this->grade_ = bureaucrat.grade_;
	return *this;
};

std::string Bureaucrat::getName() const{
	return this->name_;
};

int Bureaucrat::getGrade() const{
	return this->grade_;
};

void Bureaucrat::incrementGrade(){
	if (this->grade_ < Bureaucrat::kHighestGrade)
		throw GradeTooHighException();
	this->grade_--;
};

void Bureaucrat::decrementGrade(){
	if (this->grade_ > Bureaucrat::kLowestGrade)
		throw GradeTooLowException();
	this->grade_++;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
};


//Excetion class
//GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException() : runtime_error("Grade is too high"){};

//GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException() : runtime_error("Grade is too Low"){};