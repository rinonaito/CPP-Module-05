#include "AForm.hpp"

AForm::AForm()
	: name_("defaultName"), signGrade_(AForm::kLowestGrade), execGrade_(AForm::kLowestGrade), isSigned_(false){
};

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target)
	: name_(name), signGrade_(signGrade), execGrade_(execGrade), isSigned_(false), target_(target){
		isValidGrade(signGrade);
		isValidGrade(execGrade);
};

AForm::AForm(const AForm &form): name_(form.getName()), signGrade_(form.getSignGrade()), execGrade_(form.getExecGrade()), isSigned_() {
}

AForm::~AForm(){}

AForm& AForm::operator=(const AForm &form){
	this->isSigned_ = form.isSigned_;
	this->target_ = form.target_;
	return *this;
}

std::string AForm::getName() const{
	return this->name_;
}
int AForm::getSignGrade() const{
	return this->signGrade_;
}
int AForm::getExecGrade() const{
	return this->execGrade_;
}
bool AForm::isSigned() const{
	return this->isSigned_;
}
std::string AForm::getTarget() const{
	return this->target_;
}
bool AForm::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->getSignGrade()){
		throw AForm::GradeTooLowException();
		return false;
	}
	this->isSigned_ = true;
	return true;
}

bool AForm::isValidGrade(int grade) {
	if (grade < AForm::kHighestGrade)
		throw AForm::GradeTooHighException();
	if (grade > AForm::kLowestGrade)
		throw AForm::GradeTooLowException();
	return true;
}

bool AForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned()){
		throw AForm::IsNotSignedException();
		return false;
	}
	if (executor.getGrade() > this->getExecGrade()){
		throw AForm::GradeTooLowException();
		return false;
	}
	return executeCore();
}

bool AForm::executeCore() const
{
	return true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
os << form.getName() << ", sign grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade() << ", target " << form.getTarget() << ". ";
if (form.isSigned()) {
	os << "Is signed.";
} else {
	os << "Is NOT sigend.";
}
return os;
};

//Exception class
//GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException() : runtime_error("[ERROR]Grade is too high"){};

//GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException() : runtime_error("[ERROR]Grade is too Low"){};

//IsNotSignedException
AForm::IsNotSignedException::IsNotSignedException() : runtime_error("[ERROR]Form is NOT signed"){};