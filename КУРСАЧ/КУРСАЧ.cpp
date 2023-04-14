#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <C:/Users/katko/Desktop/KURSACH/КУРСАЧ/Header1.h>

using namespace std;

struct Date {
	unsigned short int Day;
	unsigned short int Month;
	unsigned short int Year;

    int GetDay() {
        return this->Day;
    }

    void SetDay(unsigned short int day) {
        this->Day = day;
    }

    int GetMonth() {
        return this->Month;
    }

    void SetMonth(unsigned short int month) {
        this->Month = month;
    }

    int GetYear() {
        return this->Year;
    }

    void SetYear(unsigned short int year) {
        this->Year = year;
    }
};

struct Subject {
	char Name[100];
	int Mark;

    char* GetName() {
        return this->Name;
    }

    void SetName(char name[]) {
        strcpy_s(this->Name, name);
    }

    int GetMark() {
        return this->Mark;
    }

    void SetMark(int mark) {
        this->Mark = mark;
    }
};

struct Session {
	int Semester;
	Subject Subjects[10];
	int SubjectsCount;

    int GetSemester() {
        return this->Semester;
    }

    void SetSemester(int semester) {
        this->Semester = semester;
    }

    int GetSubjectsCount() {
        return this->SubjectsCount;
    }

    void SetSubjectsCount(int subjectsCount) {
        this->SubjectsCount = subjectsCount;
    }

};

class Student {
public:
	char Surname[100];
	char Name[100];
	char Patronymic[100];
	Date BirthdayData;
	unsigned short int AdmissionYear;
	char Faculty[100];
	char Department[10];
	char Group[15];
	char RecordBook[10];
	bool Sex;
	Session StudentSession[9];
	int SessionCount;

    char* GetSurname() {
        return this->Surname;
    }

    void SetSurname(char* surname) {
        strcpy_s(this->Surname, surname);
    }

    char* GetName() {
        return this->Name;
    }

    void SetName(char* name) {
        strcpy_s(this->Name, name);
    }

    char* GetPatronymic() {
        return this->Patronymic;
    }

    void SetPatronymic(char* patronymic) {
        strcpy_s(this->Patronymic, patronymic);
    }

    unsigned short int GetAdmissionYear() {
        return this->AdmissionYear;
    }

    void SetAdmissionYear(int admissionYear) {
        this->AdmissionYear = admissionYear;
    }

    char* GetFaculty() {
        return this->Faculty;
    }

    void SetFaculty(char* faculty) {
        strcpy_s(this->Faculty, faculty);
    }

    char* GetDepartment() {
        return this->Department;
    }

    void SetDepartment(char* department) {
        strcpy_s(this->Department, department);
    }

    char* GetGroup() {
        return this->Group;
    }

    void SetGroup(char* group) {
        strcpy_s(this->Group, group);
    }

    char* GetRecordBook() {
        return this->RecordBook;
    }

    void SetRecordBook(char* recordBook) {
        strcpy_s(this->RecordBook, recordBook);
    }

    bool GetSex() {
        return this->Sex;
    }

    void SetSex(bool sex) {
        this->Sex = sex;
    }

    int GetSessionCount() {
        return this->SessionCount;
    }

    void SetSessionCount(int sessionCount) {
        this->SessionCount = sessionCount;
    }
};



const char* path = "C:/Users/katko/Desktop/KURSACH/MyFile.bin";

List<Student> ReadData() {
	ifstream file(path, ios::binary);
	Student student;
    List<Student> students;
	for (int i = 0;
		file.read((char*)&student, sizeof(student)); i++) {
		students.add(student);
	}
	file.close();
	return students;
}

void AddStudent(List <Student> students) {
	ofstream file(path, ios::binary | ios::app);
	for (auto& student : students) {
		file.write((char*)&student, sizeof(student));
	}
	file.close();
}

void EditStudent(List <Student> students) {
	remove(path);
	AddStudent(students);
}

void DeleteStudent(int studentId) {
    List <Student> students = ReadData();
	students.remove(studentId);
	remove(path);
	AddStudent(students);
}

int main()
{}