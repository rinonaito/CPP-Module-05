#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "DefaultTarget"){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137, target){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget()){};

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form){
	AForm::operator=(form);
	return *this;
};

//Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
bool ShrubberyCreationForm::executeCore() const
{
	try
	{
		std::ofstream file(this->getTarget() + "_shrubbery");
		file << getAsciiTree();
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

void buildTree(std::stringstream &ss, const std::string &directory, const std::string &prefix) {
	DIR *dir = opendir(directory.c_str());
	if (!dir)
		return;
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
    std::string name = entry->d_name;
		if (name == "." || name == "..")
			continue;
		std::string path = directory + "/" + name;
		struct stat st;
		if (stat(path.c_str(), &st) == 0 && S_ISDIR(st.st_mode)) {
		    ss << prefix << "├── " << name << std::endl;
		    buildTree(ss, path, prefix + "│   ");
		} else {
		    ss << prefix << "├── " << name << std::endl;
		}
	}
	closedir(dir);
}

std::string ShrubberyCreationForm::getAsciiTree() const
{
	char currentDir[1024];
    if (getcwd(currentDir, sizeof(currentDir)) != NULL) {
        std::stringstream ss;
        ss << currentDir << "/" << std::endl;
        buildTree(ss, currentDir, "");
        return ss.str();
    } else {
        return "Error: Unable to get current directory!";
    }
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form){
	os << static_cast<const AForm&>(form);
	return os;
}
