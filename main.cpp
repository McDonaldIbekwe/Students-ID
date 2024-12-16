#include <iostream>
#include <map>
#include <format>

class Student {
public:
	Student(const std::string& name, int id)
		: mName{ name }, mId{ id }
	{
	}
	bool operator<(const Student& other) const
	{
		return mId < other.mId;
	}
	void printStudent() const
	{
		std::cout << std::format("{}: {}\n{}: {}\n", "Name", mName, "Id", mId);
	}
private:
	std::string mName;
	int mId;
};

int main()
{
	std::map<Student, double> students{
		{Student{"Michael Cook", 119}, 4.79},
		{Student{"Liam Ferguson", 134}, 4.58},
		{Student{"Timothy Jonathan", 152}, 4.96}
	};
	for (const auto& [student, grade] : students) {
		student.printStudent();
		std::cout << "Grade: " << grade << '\n';
		std::cout << "==========================================\n";
	}
}