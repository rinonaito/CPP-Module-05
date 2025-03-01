#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
};

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
	:name_(bureaucrat.getName()) {
		this->setGrade(bureaucrat.grade_);
};

Bureaucrat::Bureaucrat(const std::string name)
	: name_(name) {
		this->setGrade(Bureaucrat::kLowestGrade);
};

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: name_(name){
		this->setGrade(grade);
};

Bureaucrat::~Bureaucrat(){
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat){
	this->setGrade(bureaucrat.grade_);
	return *this;
};

void Bureaucrat::signForm(AForm &form) const {
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signs " << form.getName() << std::endl;
};

void Bureaucrat::executeForm(AForm const & form){
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
};

std::string Bureaucrat::getName() const{
	return this->name_;
};

int Bureaucrat::getGrade() const{
	return this->grade_;
};

void Bureaucrat::setGrade(int grade){
	if (grade > Bureaucrat::kLowestGrade){
		throw Bureaucrat::GradeTooLowException();
		return;
	}
	if (grade < Bureaucrat::kHighestGrade){
		throw Bureaucrat::GradeTooHighException();
		return;
	}
	this->grade_ = grade;
};

void Bureaucrat::incrementGrade(){
	this->setGrade(this->getGrade() - 1);
};

void Bureaucrat::decrementGrade(){
	this->setGrade(this->getGrade() + 1);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
};

//Exception class
//GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException() : runtime_error("[ERROR]Grade is too high"){};

//GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException() : runtime_error("[ERROR]Grade is too Low"){};