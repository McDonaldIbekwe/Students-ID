#include <iostream>
#include <map>
#include <format>
#include <algorithm>
#include <vector>

class Student {
public:
	Student(const std::string& name, int id, double grade)
		: mName{ name }, mId{ id }, mGrade{ grade }
	{
	}
	void printStudent() const
	{
		std::cout << std::format("{}: {}\n{}: {}\n{}: {}\n",
			"Name", mName, "Id", mId, "Grade", mGrade
		);
	}
	double GetGrade() const 
	{
		return mGrade;
	}
private:
	std::string mName;
	int mId;
	double mGrade;
};

int main()
{
	std::vector<Student> students{
		Student{"Michael Cook", 119, 4.79},
		Student{"Liam Ferguson", 134, 4.58},
		Student{"Timothy Jonathan", 152, 4.96}
	};
	auto comp = [](const Student& lhs, const Student& rhs) {
		return lhs.GetGrade() > rhs.GetGrade();
	};
	std::sort(students.begin(), students.end(), comp);
	for(const auto& student: students) {
		student.printStudent();
		std::cout << "==========================================\n";
	}
}