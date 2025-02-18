#include "Form.hpp"

Form::Form()
	: name_("defaultName"), signGrade_(Form::kLowestGrade), execGrade_(Form::kLowestGrade), isSigned_(false){
};

Form::Form(std::string name, int signGrade, int execGrade)
	: name_(name), signGrade_(signGrade), execGrade_(execGrade), isSigned_(false){
		isValidGrade(signGrade);
		isValidGrade(execGrade);
};

Form::Form(const Form &form): name_(form.getName()), signGrade_(form.getSignGrade()), execGrade_(form.getExecGrade()), isSigned_() {
}

Form::~Form(){}

Form& Form::operator=(const Form &form){
	this->isSigned_ = form.isSigned_;
	return *this;
}

std::string Form::getName() const{
	return this->name_;
}
int Form::getSignGrade() const{
	return this->signGrade_;
}
int Form::getExecGrade() const{
	return this->execGrade_;
}
bool Form::isSigned() const{
	return this->isSigned_;
}
bool Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->getSignGrade()){
		throw Form::GradeTooLowException();
		return false;
	}
	this->isSigned_ = true;
	return true;
}

bool Form::isValidGrade(int grade) {
	if (grade < Form::kHighestGrade)
		throw Form::GradeTooHighException();
	if (grade > Form::kLowestGrade)
		throw Form::GradeTooLowException();
	return true;
}

std::ostream& operator<<(std::ostream& os, const Form& form){
os << form.getName() << ", sign grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade() << ". ";
if (form.isSigned()) {
	os << "Is signed.";
} else {
	os << "Is NOT sigend.";
}
return os;
};

//Exception class
//GradeTooHighException
Form::GradeTooHighException::GradeTooHighException() : runtime_error("Grade is too high"){};

//GradeTooLowException
Form::GradeTooLowException::GradeTooLowException() : runtime_error("Grade is too Low"){};