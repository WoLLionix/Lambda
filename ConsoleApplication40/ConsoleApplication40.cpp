#include <iostream>
#include <vector>
#include <algorithm>

class Student 
{
public:
    Student(const std::string& firstName, const std::string& lastName, double averageScore) : firstName(firstName), lastName(lastName), averageScore(averageScore) {}

    std::string getFirstName() const 
    {
        return firstName;
    }

    std::string getLastName() const 
    {
        return lastName;
    }

    double getAverageScore() const 
    {
        return averageScore;
    }

private:
    std::string firstName;
    std::string lastName;
    double averageScore;
};

int main() 
{
    system("chcp 1251 > null");
    std::vector<Student> students;

    students.push_back(Student("Назар", "Бабюк", 76.8));
    students.push_back(Student("Антон", "Архипенко", 89.2));
    students.push_back(Student("Віктор", "Іванов", 77.8));
    students.push_back(Student("Аліса", "Ліненко", 92.1));

    // Пошук студента з найвищим балом за допомогою std::max_element()
    auto highestScoringStudent = std::max_element(students.begin(), students.end(), 
        [](const Student& a, const Student& b) 
        {
            return a.getAverageScore() < b.getAverageScore();
        });

    // Виведення імені студента з найвищим балом
    if (highestScoringStudent != students.end()) 
    {
        std::cout << "Студент з найвищим балом: " << highestScoringStudent->getFirstName() << " " << highestScoringStudent->getLastName() << std::endl;
    }
    else 
    {
        std::cout << "Список студентів порожній." << std::endl;
    }

    return 0;
}