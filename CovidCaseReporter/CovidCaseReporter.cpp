#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include<iterator>
#include <string>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <vector>
#pragma warning(disable : 4996).
using namespace std;
enum VaccinatedStatus { Vaccinated = 1, Partial = 2, NonVaccinated = 3 };
enum Programe { CS = 1, SE = 2, IT = 3, CE = 4 };
enum TeacherRank { Lecturer = 1, Proffesor = 2 };
enum Variant { Delta = 1, OmiCron = 2, Alpha = 3 };
enum Condition { Critical, Stable };
enum Vaccine { Pfizer, Moderna, Sinopharm, SinoVac, Spuntik, CanSino, AsteraZenica, PakVak };
enum PersonIdentification { STU, TCH };

class Helper {
public:
	static bool HasDigit(const std::string& str)
	{
		return std::all_of(str.begin(), str.end(), ::isdigit);
	}
	static bool HasLetters(const std::string& str)
	{
		return std::all_of(str.begin(), str.end(), ::isalpha);
	}

	static char* GetCurrentDate() {
		auto start = std::chrono::system_clock::now();
		auto end = std::chrono::system_clock::now();
		time_t end_time = std::chrono::system_clock::to_time_t(end);
		return ctime(&end_time);
	}

	static bool checkFileExists(char* name) {
		ifstream ifile;
		ifile.open(name);
		if (ifile) {
			return true;
		}
		else {
			return false;
		}
	}
};

class CovidCases {

public:
	CovidCases() {
		TestTaken = Helper::GetCurrentDate();
		CovidVariant = Variant::Alpha;
		HealthState = Condition::Stable;
		IsPositive = true;
	}
	CovidCases(Variant var, Condition cond, int isPos, string date) {
		setCovidVariant(var);
		setHealthState(cond);
		setIsPositiveForFile(isPos);
		setTestTaken(date);
	}
private:
	string TestTaken;
	Variant CovidVariant;
	Condition HealthState;
	bool IsPositive;
public:
	Variant getCovidVariant() {
		return CovidVariant;
	}
	Condition getHealthState() {
		return HealthState;
	}
	string getTestTakenDate() {
		return TestTaken;
	}
	bool getIsPositive() {
		return IsPositive;
	}
	bool setCovidVariant(Variant variant) {
		if (variant < 1 || variant > 3) {
			cout << "\t\t\tInvalid Covid variant";
			return false;
		}
		CovidVariant = variant;
		return true;
	}
	bool setHealthState(Condition state) {
		if (state < 1 || state > 2) {
			cout << "\t\t\tInvalid Health State";
			return false;
		}
		HealthState = state;
		return true;
	}
	bool setIsPositive(string positive) {
		if (positive.length() != 1) {
			cout << "\t\t\tPlease enter valid result!";
			return false;
		}
		else if (positive == "Y" && positive != "y" && positive != "N" && positive != "n") {
			cout << "\t\t\tPlease enter valid gender such lie 'Y N or y n'";
			return false;
		}
		else {
			IsPositive = true;
			return true;
		}
	}
	void setTestTaken(string testTaken) {
		TestTaken = testTaken;
	}
	void setIsPositiveForFile(int positive) {
		if (positive == 1) {
			IsPositive = true;
		}
		else {
			IsPositive = false;
		}
	}
};

class Person
{

public:Person() {
	Department = "Computer Science";
	IsAlive = true;
	VaccineStatus = NonVaccinated;
}

private:
	string Name;
	string Cnic;
	string Address;
	string Mobile;
	string Department;
	string Gender;
	bool IsAlive;
	int Age;
	VaccinatedStatus VaccineStatus;
	Programe Program;
	vector<CovidCases> ListOfCovidCases;

public:
	string getName() {
		return Name;
	}
	string getCnic() {
		return Cnic;
	}
	string getAddress() {
		return Address;
	}
	string getMobile() {
		return Mobile;
	}
	string getDepartment() {
		return Department;
	}
	string getGender() {
		return Gender;
	}
	bool getIsAlive() {
		return IsAlive;
	}
	int getAge() {
		return Age;
	}
	void setCovidHistory(vector<CovidCases> list) {
		ListOfCovidCases = list;
	}
	VaccinatedStatus getVaccinatedStatus() {
		return VaccineStatus;
	}
	Programe getProgram() {
		return Program;
	}
	bool setName(string name) {
		int length = name.length();
		if (length < 2 || length > 30) {
			cout << "\t\t\tName shall be between 2 and 30 Letters";
			return false;
		}
		else if (Helper::HasDigit(name)) {
			cout << "\t\t\tName shall not contain digits";
			return false;
		}
		else {
			Name = name;
			return true;
		}
	}
	bool setCnic(string cnic) {
		int length = cnic.length();
		if (length != 13) {
			cout << "\t\t\tCNIC shall contain 13 digits";
			return false;
		}
		else if (Helper::HasLetters(cnic)) {
			cout << "\t\t\tCnic shall not contain letters";
			return false;
		}
		else {
			Cnic = cnic;
			return true;
		}
	}
	bool setAddress(string address) {
		int length = address.length();
		if (length < 1) {
			cout << "\t\t\tPlease enter something for address";
			return false;
		}
		else {
			Address = address;
			return true;
		}
	}
	bool setMobile(string mobile) {
		int length = mobile.length();
		if (length != 11) {
			cout << "\t\t\tMobile shall contain 11 digits";
			return false;
		}
		else if (Helper::HasLetters(mobile)) {
			cout << "\t\t\tMobile shall not contain letters";
			return false;
		}
		else {
			Mobile = mobile;
			return true;
		}
	}
	bool setGender(string gender) {
		if (gender.length() != 1) {
			cout << "\t\t\tPlease enter valid gender!";
			return false;
		}
		if (gender == "M" && gender != "m" && gender != "F" && gender != "f") {
			cout << "\t\t\tPlease enter valid gender such lie 'M F or m f'";
			return false;
		}
		else {
			Gender = gender;
			return true;
		}
	}
	bool setIsAlive(string alive) {
		if (alive.length() != 1) {
			cout << "\t\t\tPlease enter valid death status!";
			return false;
		}
		if (alive == "Y" && alive != "y" && alive != "N" && alive != "n") {
			cout << "\t\t\tPlease enter valid gender death status such lie 'Y N or y n'";
			return false;
		}
		else {
			IsAlive = false;
			return true;
		}
	}
	bool setAge(int age) {
		if (age < 15 || age > 80) {
			cout << "\t\t\tInvalid age, it shall be between 15 to 80";
			return false;
		}
		else {
			Age = age;
		}
	}
	bool setVaccineStatus(VaccinatedStatus status) {
		if (status < 0 || status > 3) {
			cout << "\t\t\tInvalid Vaccine Status";
			return false;
		}
		VaccineStatus = status;
		return true;
	}
	bool setProgram(Programe program) {
		if (program < 0 || program > 4) {
			cout << "\t\t\tInvalid Programe";
			return false;
		}
		Program = program;
		return true;
	}
	vector<CovidCases> getCovidHistory() {
		return ListOfCovidCases;
	}
	bool addCovidCase(CovidCases covidCase) {
		ListOfCovidCases.push_back(covidCase);
		return true;
	}
};

class Student : public Person {

private:
	string SapId;
	int Semester;

public:
	Student() {
		SapId = "";
		Semester = 1;
	}
	string getStudentId() {
		return SapId;
	}
	int getSemester() {
		return Semester;
	}
	bool setSapId(string sapId) {
		if (sapId.length() < 1) {
			cout << "\t\t\tPlease enter something for sap id";
			return false;
		}
		else {
			SapId = sapId;
		}
	}
	bool setSemester(int semester) {
		if (semester < 0 || semester > 8) {
			cout << "\t\t\tSemester shall be between 1 and 8";
			return false;
		}
		else {
			Semester = semester;
		}
	}
};

class Teacher :public Person {

public:
	Teacher() {
		TeacherId = "";
		Rank = TeacherRank::Lecturer;
	}
private:
	string TeacherId;
	TeacherRank Rank;

public:
	string getTeacherId() {
		return TeacherId;
	}
	TeacherRank getRank() {
		return Rank;
	}
	bool setTeacherId(string teacherId) {
		if (teacherId.length() < 1) {
			cout << "\t\t\tPlease enter something for teacher id";
			return false;
		}
		else {
			TeacherId = teacherId;
			return true;
		}
	}
	bool setRank(TeacherRank rank) {
		if (rank < 0 || rank > 2) {
			cout << "\t\t\tInvalid Rank";
			return false;
		}
		Rank = rank;
		return true;
	}
};

long sleepTime = 5000;
char personFileName[200] = "persons.txt";
char covidHistory[200] = "covidHistory.txt";

int ShowMenu();
void SeeActiveCasesByPrograme();
void SeeHistoryOfPerson();
void UpdateCovidCase();
void SeeActiveCases();
void ReportCovidCase();
void WriteStudentToPersonFile(Student* student);
void WriteTeacherToPersonFile(Teacher* teacher);
void main();
bool CheckIfAlreadyExists(string id, int st);
void WriteCovidHistoryFile(CovidCases* covidCase, string id, int st);
void ClearCovidCaseScreenInError();
void ClearCovidCaseScreenInErrorForUpdate();
void ClearCovidCaseScreenInErrorForSearch();
Student* CreateStudent();
Teacher* CreateTeacher();
Student* UpdateStudent();
Teacher* UpdateTeacher();
Student* GetStudentById(string id);
Teacher* GetTeacherById(string id);
void UpdateStudentToFile(Student* student);
void UpdateTeacherToFile(Teacher* teacher);
vector<CovidCases> GetCovidCasesById(string id, int studentOrTeacher);
void SearchTeacher();
void SearchStudent();
vector<Student> GetActiveCasesStudent();
vector<Teacher> GetActiveTeacherCases();
string getProgrameValue(Programe d);
string getGenderValue(string gender);
string getTeacherRankValue(TeacherRank rank);
string getCovidVariantValue(Variant va);
string getHealthStateValue(Condition co);

int ShowMenu() {
	int feature = 0;
	cout << "\n\n\t\t Please Select an Item From Menu: ";
	cout << "\n\n\t\t 1. Report Covid Case: ";
	cout << "\n\n\t\t 2. Update Covid Case: ";
	cout << "\n\n\t\t 3. See History of Person: ";
	cout << "\n\n\t\t 4. See Active Cases: ";
	cout << "\n\n\t\t    Please Select Your Input: ";
	cin >> feature;

	if (feature > 0 && feature < 5) {
		return feature;
	}
	else {
		return 0;
	}
}

void ClearCovidCaseScreenInError() {
	_sleep(sleepTime);
	system("cls");
	ReportCovidCase();
}
void ClearCovidCaseScreenInErrorForUpdate() {
	_sleep(sleepTime);
	system("cls");
	UpdateCovidCase();
}
void ClearCovidCaseScreenInErrorForSearch() {
	_sleep(sleepTime);
	system("cls");
	UpdateCovidCase();
}

Student* CreateStudent() {
	string id, name, cnic, mobile, address, gender, positive;
	int semester, age, program, status, variant, healthStatus;

	CovidCases covidCase;
	Student* student = new Student();
	cout << "\n\t\t 1. Please Enter SAP Id: ";
	cin >> id;
	if (student->setSapId(id) == false) {
		ClearCovidCaseScreenInError();
	}
	if (CheckIfAlreadyExists(student->getStudentId(), STU) == true) {
		cout << "\n\t\t\tPerson Already Exists";
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 2. Please Enter Name: ";
	cin >> name;
	if (student->setName(name) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 3. Please Enter Covid Variant: ";
	cout << "\n\t\t\t For Delta Hit 1: ";
	cout << "\n\t\t\t For Omicorn 2: ";
	cout << "\n\t\t\t For Alpha/Other Hit 3: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> variant;
	if (covidCase.setCovidVariant(Variant(variant)) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 4. Please Enter Patient Condition: ";
	cout << "\n\t\t\t For Critical 1: ";
	cout << "\n\t\t\t For Stable 2: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> healthStatus;
	if (covidCase.setHealthState(Condition(healthStatus)) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 5. Please Enter Semester: ";
	cin >> semester;
	if (student->setSemester(semester) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 6. Please Enter CNIC: ";
	cin >> cnic;
	if (student->setCnic(cnic) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 7. Please Enter Mobile: ";
	cin >> mobile;
	if (student->setMobile(mobile) == false) {
		ClearCovidCaseScreenInError();
	}

	cout << "\n\t\t 8. Please Enter Age: ";
	cin >> age;
	if (student->setAge(age) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 9. Please Enter Gender please enter 'M or m' for a male and for female 'F or f': ";
	cin >> gender;
	if (student->setGender(gender) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 10. Please Enter Address: ";
	cin >> address;
	if (student->setAddress(address) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 11. Please Enter Programe: ";
	cout << "\n\t\t\t For Computer Science Hit 1: ";
	cout << "\n\t\t\t For Software Engineering Hit 2: ";
	cout << "\n\t\t\t For Information Technology Hit 3: ";
	cout << "\n\t\t\t For Computer Engineering Hit 4: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> program;
	if (student->setProgram(Programe(program)) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 12. Please Vaccine Status: ";
	cout << "\n\t\t\t For Vaccinated Hit 1: ";
	cout << "\n\t\t\t For Partialy Vaccinated Hit 2: ";
	cout << "\n\t\t\t For Non Vaccinated Hit 3: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> status;
	if (student->setVaccineStatus(VaccinatedStatus(status)) == false) {
		ClearCovidCaseScreenInError();
	}
	student->addCovidCase(covidCase);
	return student;
}
Teacher* CreateTeacher() {
	string id, name, cnic, mobile, address, gender, positive;
	int semester, age, program, status, variant, healthStatus;

	CovidCases covidCase;
	Teacher* teacher = new Teacher();
	cout << "\n\n\t\t 1. Please Enter Teacher Id: ";
	cin >> id;
	if (teacher->setTeacherId(id) == false) {
		ClearCovidCaseScreenInError();
	}
	if (CheckIfAlreadyExists(teacher->getTeacherId(), TCH) == true) {
		cout << "\n\t\t\tPerson Already Exists";
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 2. Please Enter Name: ";
	cin >> name;
	if (teacher->setName(name) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 3. Is Case Positive? enter 'Y or y' for a yes and 'N or n' for no: ";
	cin >> positive;
	if (covidCase.setIsPositive(positive) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 4. Please Enter Covid Variant: ";
	cout << "\n\t\t\t For Delta Hit 1: ";
	cout << "\n\t\t\t For Omicorn 2: ";
	cout << "\n\t\t\t For Alpha/Other Hit 3: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> variant;
	if (covidCase.setCovidVariant(Variant(variant)) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 5. Please Enter Patient Condition: ";
	cout << "\n\t\t\t For Critical 1: ";
	cout << "\n\t\t\t For Stable 2: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> healthStatus;
	if (covidCase.setHealthState(Condition(healthStatus)) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 3. Please Enter Rank: ";
	cout << "\n\t\t\t For Lecturer Hit 1: ";
	cout << "\n\t\t\t For Proffesor Vaccinated Hit 2: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> status;
	if (teacher->setRank(TeacherRank(status)) == false) {
		ClearCovidCaseScreenInError();
	}

	cout << "\n\t\t 4. Please Enter CNIC: ";
	cin >> cnic;
	if (teacher->setCnic(cnic) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 5. Please Enter Mobile: ";
	cin >> mobile;
	if (teacher->setMobile(mobile) == false) {
		ClearCovidCaseScreenInError();
	}

	cout << "\n\t\t 6. Please Enter Age: ";
	cin >> age;
	if (teacher->setAge(age) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 7. Please Enter Gender please enter 'M or m' for a male and for female 'F or f': ";
	cin >> gender;
	if (teacher->setGender(gender) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 8. Please Enter Address: ";
	cin >> address;
	if (teacher->setAddress(address) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 9. Please Enter Programe: ";
	cout << "\n\t\t\t For Computer Science Hit 1: ";
	cout << "\n\t\t\t For Software Engineering Hit 2: ";
	cout << "\n\t\t\t For Information Technology Hit 3: ";
	cout << "\n\t\t\t For Computer Engineering Hit 4: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> program;
	if (teacher->setProgram(Programe(program)) == false) {
		ClearCovidCaseScreenInError();
	}
	cout << "\n\t\t 10. Please Vaccine Status: ";
	cout << "\n\t\t\t For Vaccinated Hit 1: ";
	cout << "\n\t\t\t For Partialy Vaccinated Hit 2: ";
	cout << "\n\t\t\t For Non Vaccinated Hit 3: ";
	cout << "\n\t\t\t Please Select Your Input: ";
	cin >> status;
	if (teacher->setVaccineStatus(VaccinatedStatus(status)) == false) {
		ClearCovidCaseScreenInError();
	}

	teacher->addCovidCase(covidCase);
	return teacher;
}
Student* UpdateStudent() {
	string id, isAlive, positive;

	CovidCases* covidCase = new CovidCases();
	Student* student = new Student();
	cout << "\n\t\t 1. Please Enter SAP Id: ";
	cin >> id;
	if (student->setSapId(id) == false) {
		ClearCovidCaseScreenInError();
	}
	Student* existingStudent = GetStudentById(student->getStudentId());
	if (existingStudent->getStudentId().length() < 1) {
		cout << "\n\t\t\tPerson doesn't exists! try again in few seconds!";
		ClearCovidCaseScreenInErrorForUpdate();
	}
	cout << "\n\t\t 2. Is " << existingStudent->getName() << " Dead enter 'Y or y' for a yes and 'N or n' for no: : ";
	cin >> isAlive;
	if (existingStudent->setIsAlive(isAlive) == false) {
		ClearCovidCaseScreenInErrorForUpdate();
	}

	cout << "\n\t\t 3. Is Case Positive? enter 'Y or y' for a yes and 'N or n' for no: ";
	cin >> positive;
	if (covidCase->setIsPositive(positive) == false) {
		ClearCovidCaseScreenInErrorForUpdate();
	}

	existingStudent->setIsAlive(covidCase->getIsPositive() ? "Y" : "N");
	return existingStudent;
}
Teacher* UpdateTeacher() {
	string id, isAlive, positive;

	CovidCases* covidCase = new CovidCases();
	Teacher* teacher = new Teacher();
	cout << "\n\n\t\t 1. Please Enter Teacher Id: ";
	cin >> id;
	if (teacher->setTeacherId(id) == false) {
		ClearCovidCaseScreenInError();
	}
	Teacher* existingTeacher = GetTeacherById(teacher->getTeacherId());
	if (existingTeacher->getTeacherId().length() < 1) {
		cout << "\n\t\t\tPerson doesn't exists! try again in few seconds!";
		ClearCovidCaseScreenInErrorForUpdate();
	}
	cout << "\n\t\t 2. Is " << existingTeacher->getName() << " Dead enter 'Y or y' for a yes and 'N or n' for no: : ";
	cin >> isAlive;
	if (existingTeacher->setIsAlive(isAlive) == false) {
		ClearCovidCaseScreenInErrorForUpdate();
	}

	cout << "\n\t\t 3. Is Case Positive? enter 'Y or y' for a yes and 'N or n' for no: ";
	cin >> positive;
	if (covidCase->setIsPositive(positive) == false) {
		ClearCovidCaseScreenInErrorForUpdate();
	}

	return existingTeacher;
}
string getProgrameValue(Programe d) {
	switch (d)
	{
	case CS:
		return "Computer Science";
		break;
	case SE:
		return "Software Engineering";
		break;
	case IT:
		return "Information Technology";
		break;
	case CE:
		return "Computer Engineering";
		break;
	default:
		return "Computer Science";
		break;
	}
}
string getGenderValue(string gen) {
	if (gen == "f" || gen == "F") {
		return "Female";
	}
	else {
		return "Male";
	}
}
string getTeacherRankValue(TeacherRank rank) {
	switch (rank)
	{
	case Lecturer:
		return "Lecturer";
		break;
	case Proffesor:
		return "Proffesor";
		break;
	default:
		return "Proffesor";
		break;
	}
}
string getCovidVariantValue(Variant var) {
	switch (var)
	{
	case Delta:
		return "Delta Variant";
		break;
	case OmiCron:
		return "OmiCron Variant";
		break;
	case Alpha:
		return "Alpha Variant";
		break;
	default:
		return "Alpha Variant";
		break;
	}
}
string getHealthStateValue(Condition cond) {
	switch (cond)
	{
	case Critical:
		return "Critical";
		break;
	case Stable:
		return "Stable";
		break;
	default:
		return "Stable";
		break;
	}
}

void SearchTeacher() {
	system("cls");
	string id;
	Teacher* teacher = new Teacher();
	cout << "\n\t\t 1. Please Enter Teacher Id: ";
	cin >> id;
	if (teacher->setTeacherId(id) == false) {
		ClearCovidCaseScreenInErrorForSearch();
	}
	Teacher* existingTeacher = GetTeacherById(teacher->getTeacherId());
	if (existingTeacher->getTeacherId().length() < 1) {
		cout << "\n\t\t\tPerson doesn't exists! try again in few seconds!";
		ClearCovidCaseScreenInErrorForSearch();
	}
	cout << "\n\t\t\tName: " << existingTeacher->getName();
	cout << "\n\t\t\tCNIC: " << existingTeacher->getCnic();
	cout << "\n\t\t\tMobile: " << existingTeacher->getMobile();
	cout << "\n\t\t\tGender: " << getGenderValue(existingTeacher->getGender());
	cout << "\n\t\t\tAge: " << existingTeacher->getAge();
	cout << "\n\t\t\tSemester: " << getTeacherRankValue(existingTeacher->getRank());
	cout << "\n\t\t\tPrograme: " << getProgrameValue(existingTeacher->getProgram());
	cout << "\n\t\t\tDepartment: " << existingTeacher->getDepartment();
	cout << "\n\t\t\tAddress: " << existingTeacher->getAddress();
	cout << "\n\t\t\t-------------------------------------";
	cout << "\n\t\t\tCovid History";
	vector<CovidCases> cases = GetCovidCasesById(existingTeacher->getTeacherId(), PersonIdentification::TCH);
	for (size_t i = 0; i < sizeof(cases); ++i)
	{
		cout << "\n\t\t\tRecord Number: " << i + 1;
		cout << "\n\t\t\tCovid Variant: " << getCovidVariantValue(cases[i].getCovidVariant());
		cout << "\n\t\t\tHealth: " << getHealthStateValue(cases[i].getHealthState());
		//cout << "\n\t\t\tTest Date: " << getDate(cases[i].getTestTakenDate());
		cout << "\n\t\t\t-------------------------------------";
	}
}
void SearchStudent() {
	system("cls");
	string id;
	Student* student = new Student();
	cout << "\n\t\t 1. Please Enter SAP Id: ";
	cin >> id;
	if (student->setSapId(id) == false) {
		ClearCovidCaseScreenInErrorForSearch();
	}
	Student* existingStudent = GetStudentById(student->getStudentId());
	if (existingStudent->getStudentId().length() < 1) {
		cout << "\n\t\t\tPerson doesn't exists! try again in few seconds!";
		ClearCovidCaseScreenInErrorForSearch();
	}
	cout << "\n\t\t\tName: " << existingStudent->getName();
	cout << "\n\t\t\tCNIC: " << existingStudent->getCnic();
	cout << "\n\t\t\tMobile: " << existingStudent->getMobile();
	cout << "\n\t\t\tGender: " << getGenderValue(existingStudent->getGender());
	cout << "\n\t\t\tAge: " << existingStudent->getAge();
	cout << "\n\t\t\tSemester: " << existingStudent->getSemester();
	cout << "\n\t\t\tPrograme: " << getProgrameValue(existingStudent->getProgram());
	cout << "\n\t\t\tDepartment: " << existingStudent->getDepartment();
	cout << "\n\t\t\tAddress: " << existingStudent->getAddress();
	cout << "\n\t\t\t-------------------------------------";
	cout << "\n\t\t\tCovid History";
	vector<CovidCases> cases = GetCovidCasesById(existingStudent->getStudentId(), PersonIdentification::STU);
	for (size_t i = 0; i < sizeof(cases); i++)
	{
		cout << "\n\t\t\Record Number: " << i + 1;
		cout << "\n\t\t\tTest Date: " << cases[i].getTestTakenDate();
		cout << "\n\t\t\tCovid Variant: " << getCovidVariantValue(cases[i].getCovidVariant());
		cout << "\n\t\t\tHealth: " << getHealthStateValue(cases[i].getHealthState());
		//cout << "\n\t\t\tTest Date: " << getDate(cases[i].getTestTakenDate());
		cout << "\n\t\t\t-------------------------------------";
	}
}

void ReportCovidCase() {
	system("cls");
	int person = 0;
	cout << "\n\n\t\t\t Welcome to Covid Case Tracker/Reporter";
	cout << "\n\n\t\t Please Select Option Below to Add: ";
	cout << "\n\n\t\t 1. Is it Student: ";
	cout << "\n\n\t\t 2. Is it Teacher: ";
	cout << "\n\n\t\t 3. Return to Main Menu: ";
	cout << "\n\n\t\t    Please Select Your Input: ";
	cin >> person;
	if (person > 0 && person < 4) {
		system("cls");
		if (person == 1)
		{
			Student* student = CreateStudent();
			WriteStudentToPersonFile(student);
			vector<CovidCases> covid = student->getCovidHistory();
			WriteCovidHistoryFile(&covid.at(0), student->getStudentId(), STU);
			main();
		}
		else if (person == 2) {
			Teacher* teacher = CreateTeacher();
			WriteTeacherToPersonFile(teacher);
			vector<CovidCases> covid = teacher->getCovidHistory();
			WriteCovidHistoryFile(&covid.at(0), teacher->getTeacherId(), TCH);
			main();
		}
		else if (person == 3) {
			main();
		}
	}
	else {
		system("cls");
		ReportCovidCase();
	}

}
void UpdateCovidCase() {
	system("cls");
	int person = 0;
	cout << "\n\n\t\t\t Welcome to Covid Case Tracker/Reporter";
	cout << "\n\n\t\t Please Select Option Below to Update: ";
	cout << "\n\n\t\t 1. Is it Student: ";
	cout << "\n\n\t\t 2. Is it Teacher: ";
	cout << "\n\n\t\t 3. Return to Main Menu: ";
	cout << "\n\n\t\t    Please Select Your Input: ";
	cin >> person;
	if (person > 0 && person < 4) {
		system("cls");
		if (person == 1)
		{
			Student* student = UpdateStudent();
			UpdateStudentToFile(student);
			/*CovidCases* covid = student->getCovidHistory();
			WriteCovidHistoryFile(covid, student->getStudentId(), STU);*/
			main();
		}
		else if (person == 2) {
			Teacher* teacher = UpdateTeacher();
			UpdateTeacherToFile(teacher);
			/*WriteTeacherToPersonFile(teacher);
			CovidCases* covid = teacher->getCovidHistory();
			WriteCovidHistoryFile(covid, teacher->getTeacherId(), TCH);*/
			main();
		}
		else if (person == 3) {
			main();
		}
	}
	else {
		system("cls");
		UpdateCovidCase();
	}

}

void SeeHistoryOfPerson() {
	system("cls");
	int person = 0;
	cout << "\n\n\t\t\t Welcome to Covid Case Tracker/Reporter";
	cout << "\n\n\t\t Please Select Option Below to Update: ";
	cout << "\n\n\t\t 1. Is it Student: ";
	cout << "\n\n\t\t 2. Is it Teacher: ";
	cout << "\n\n\t\t 3. Return to Main Menu: ";
	cout << "\n\n\t\t    Please Select Your Input: ";
	cin >> person;
	if (person > 0 && person < 4) {
		system("cls");
		if (person == 1)
		{
			SearchStudent();
		}
		else if (person == 2) {
			SearchTeacher();
		}
		else if (person == 3) {
			main();
		}
	}
	else {
		system("cls");
		UpdateCovidCase();
	}
}
void SeeActiveCases() {
	system("cls");
	cout << "\n\n\t\t\t Welcome to Covid Case Tracker/Reporter";
	cout << "\n\n\t\t Here is the list of Active Cases: ";
	cout << "\n\n\t\t Student Lists: ";
	vector<Student> students = GetActiveCasesStudent();
	vector<Student>::iterator ptrS;
	if (sizeof(students) > 0) {
		for (ptrS = students.begin(); ptrS < students.end(); ptrS++)
		{
			cout << "\n\t\t\tName: " << ptrS->getName();
			cout << "\n\t\t\tCNIC: " << ptrS->getCnic();
			cout << "\n\t\t\tMobile: " << ptrS->getMobile();
			cout << "\n\t\t\tGender: " << getGenderValue(ptrS->getGender());
			cout << "\n\t\t\tAge: " << ptrS->getAge();
			cout << "\n\t\t\tSemester: " << ptrS->getSemester();
			cout << "\n\t\t\tPrograme: " << getProgrameValue(ptrS->getProgram());
			cout << "\n\t\t\tDepartment: " << ptrS->getDepartment();
			cout << "\n\t\t\tAddress: " << ptrS->getAddress();
			cout << "\n\t\t\t-----------------";
		}
	}
	else {
		cout << "\n\n\t\t No Student Records Found: ";
	}
	cout << "\n\n\t\t ------------------------------------------------------------------: ";
	cout << "\n\n\t\t Teacher Lists: ";
	vector<Teacher> teachers = GetActiveTeacherCases();
	if (sizeof(teachers) > 0) {
		vector<Teacher>::iterator ptr;
		for (ptr = teachers.begin(); ptr < teachers.end(); ptr++)
		{
			cout << "\n\t\t\tName: " << ptr->getName();
			cout << "\n\t\t\tCNIC: " << ptr->getCnic();
			cout << "\n\t\t\tMobile: " << ptr->getMobile();
			cout << "\n\t\t\tGender: " << getGenderValue(ptr->getGender());
			cout << "\n\t\t\tAge: " << ptr->getAge();
			cout << "\n\t\t\tSemester: " << getTeacherRankValue(ptr->getRank());
			cout << "\n\t\t\tPrograme: " << getProgrameValue(ptr->getProgram());
			cout << "\n\t\t\tDepartment: " << ptr->getDepartment();
			cout << "\n\t\t\tAddress: " << ptr->getAddress();
			cout << "\n\t\t\t-----------------";
		}
	}
	else {
		cout << "\n\n\t\t No Teacher Records Found: ";
	}
}
void SeeActiveCasesByPrograme() {

}

void WriteStudentToPersonFile(Student* student) {
	ofstream outfile(personFileName, std::ios_base::app | std::ios_base::out);
	outfile << student->getStudentId() + ","
		<< student->getName() + ","
		<< to_string(student->getSemester()) + ","
		<< student->getCnic() + ","
		<< student->getMobile() + ","
		<< to_string(student->getAge()) + ","
		<< student->getGender() + ","
		<< student->getAddress() + ","
		<< to_string(student->getProgram()) + ","
		<< to_string(student->getVaccinatedStatus()) + ","
		<< to_string(PersonIdentification::STU) + ","
		<< to_string(student->getIsAlive())
		<< std::endl;

	outfile.close();
}
void WriteCovidHistoryFile(CovidCases* covidCase, string id, int st) {
	ofstream outfile(covidHistory, std::ios_base::app | std::ios_base::out);
	outfile << id + ","
		<< to_string(st) + ","
		<< to_string(covidCase->getIsPositive()) + ","
		<< to_string(covidCase->getCovidVariant()) + ","
		<< to_string(covidCase->getHealthState()) + ","
		<< covidCase->getTestTakenDate();

	outfile.close();
}
void WriteTeacherToPersonFile(Teacher* teacher) {
	ofstream outfile(personFileName, std::ios_base::app | std::ios_base::out);
	outfile << teacher->getTeacherId() + ","
		<< teacher->getName() + ","
		<< to_string(teacher->getRank()) + ","
		<< teacher->getCnic() + ","
		<< teacher->getMobile() + ","
		<< to_string(teacher->getAge()) + ","
		<< teacher->getGender() + ","
		<< teacher->getAddress() + ","
		<< to_string(teacher->getProgram()) + ","
		<< to_string(teacher->getVaccinatedStatus()) + ","
		<< to_string(PersonIdentification::TCH) + ","
		<< to_string(teacher->getIsAlive())
		<< std::endl;

	outfile.close();
}
bool CheckIfAlreadyExists(string id, int studentOrTeacher) {
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[0] == id && values[10] == to_string(studentOrTeacher)) {
					return true;
				}
			}
		}
	}
	return false;
}
void UpdateStudentToFile(Student* updatedStudent) {
	vector<Student> students;
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				Student* std = new Student();
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[10] == to_string(PersonIdentification::STU)) {
					std->setSapId(values[0]);
					std->setName(values[1]);
					std->setSemester(stoi(values[2]));
					std->setCnic(values[3]);
					std->setMobile(values[4]);
					std->setAge(stoi(values[5]));
					std->setGender(values[6]);
					std->setAddress(values[7]);
					std->setProgram(Programe(stoi(values[8])));
					std->setVaccineStatus(VaccinatedStatus(stoi(values[9])));
					std->setIsAlive(values[11]);
					students.push_back(*std);
				}

			}
			infile.close();
		}
	}

	ofstream ofs;
	ofs.open(personFileName, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].getStudentId() == updatedStudent->getStudentId()) {
			WriteStudentToPersonFile(updatedStudent);
		}
		else {
			Student st = students[i];
			WriteStudentToPersonFile(&st);
		}
	}
}
void UpdateTeacherToFile(Teacher* updatedTeacher) {
	vector<Teacher> teachers;
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				Teacher* teacher = new Teacher();
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[10] == to_string(PersonIdentification::TCH)) {
					teacher->setTeacherId(values[0]);
					teacher->setName(values[1]);
					teacher->setRank(TeacherRank(stoi(values[2])));
					teacher->setCnic(values[3]);
					teacher->setMobile(values[4]);
					teacher->setAge(stoi(values[5]));
					teacher->setGender(values[6]);
					teacher->setAddress(values[7]);
					teacher->setProgram(Programe(stoi(values[8])));
					teacher->setVaccineStatus(VaccinatedStatus(stoi(values[9])));
					teacher->setIsAlive(values[11]);
					teachers.push_back(*teacher);
				}

			}
			infile.close();
		}
	}

	ofstream ofs;
	ofs.open(personFileName, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].getTeacherId() == updatedTeacher->getTeacherId()) {
			WriteTeacherToPersonFile(updatedTeacher);
		}
		else {
			Teacher st = teachers[i];
			WriteTeacherToPersonFile(&st);
		}
	}
}
Student* GetStudentById(string id) {
	Student* std = new Student();
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[0] == id && values[10] == to_string(PersonIdentification::STU)) {
					std->setSapId(values[0]);
					std->setName(values[1]);
					std->setSemester(stoi(values[2]));
					std->setCnic(values[3]);
					std->setMobile(values[4]);
					std->setAge(stoi(values[5]));
					std->setGender(values[6]);
					std->setAddress(values[7]);
					std->setProgram(Programe(stoi(values[8])));
					std->setVaccineStatus(VaccinatedStatus(stoi(values[9])));
					std->setIsAlive(values[11]);
					vector<CovidCases> arrayOfCovidCases = GetCovidCasesById(std->getStudentId(), PersonIdentification::STU);
					std->setCovidHistory(arrayOfCovidCases);
					return std;
				}
			}
		}
	}
	return std;
}
Teacher* GetTeacherById(string id) {
	Teacher* teacher = new Teacher();
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[0] == id && values[10] == to_string(PersonIdentification::TCH)) {
					teacher->setTeacherId(values[0]);
					teacher->setName(values[1]);
					teacher->setRank(TeacherRank(stoi(values[2])));
					teacher->setCnic(values[3]);
					teacher->setMobile(values[4]);
					teacher->setAge(stoi(values[5]));
					teacher->setGender(values[6]);
					teacher->setAddress(values[7]);
					teacher->setProgram(Programe(stoi(values[8])));
					teacher->setVaccineStatus(VaccinatedStatus(stoi(values[9])));
					teacher->setIsAlive(values[11]);
					vector<CovidCases> arrayOfCovidCases = GetCovidCasesById(teacher->getTeacherId(), PersonIdentification::TCH);
					teacher->setCovidHistory(arrayOfCovidCases);
					return teacher;
				}
			}
		}
	}
	return teacher;
}
vector<CovidCases> GetCovidCasesById(string id, int studentOrTeacher) {
	vector<CovidCases> listOfCovidCases;
	if (Helper::checkFileExists(covidHistory)) {
		ifstream infile(covidHistory);
		if (infile.is_open()) {
			string line;
			int index = 0;
			while (getline(infile, line)) {
				string values[6];
				stringstream d(line);
				int i = 0;

				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[0] == id && values[1] == to_string(PersonIdentification(studentOrTeacher))) {
					CovidCases* singleCase = new CovidCases(Variant(stoi(values[3])), Condition(stoi(values[4])), stoi(values[2]), values[5].c_str());
					listOfCovidCases.push_back(*singleCase);
					index++;
				}
			}
		}
	}
	return listOfCovidCases;
}

vector<Student> GetActiveCasesStudent() {
	vector<Student> students;
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				Student* std = new Student();
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[11] == "1" && values[10] == to_string(PersonIdentification::STU)) {
					std->setSapId(values[0]);
					std->setName(values[1]);
					std->setSemester(stoi(values[2]));
					std->setCnic(values[3]);
					std->setMobile(values[4]);
					std->setAge(stoi(values[5]));
					std->setGender(values[6]);
					std->setAddress(values[7]);
					std->setProgram(Programe(stoi(values[8])));
					std->setVaccineStatus(VaccinatedStatus(stoi(values[9])));
					std->setIsAlive(values[11]);
					students.push_back(*std);
				}

			}
			infile.close();
		}
	}
	return students;
}

vector<Teacher> GetActiveTeacherCases() {
	vector<Teacher> teachers;
	if (Helper::checkFileExists(personFileName)) {
		ifstream infile(personFileName);
		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				string values[12];
				stringstream d(line);
				int i = 0;
				Teacher* teacher = new Teacher();
				while (d.good())
				{
					string a;
					getline(d, a, ',');
					values[i] = a;
					i++;
				}
				if (values[11] == "1" && values[10] == to_string(PersonIdentification::TCH)) {
					teacher->setTeacherId(values[0]);
					teacher->setName(values[1]);
					teacher->setRank(TeacherRank(stoi(values[2])));
					teacher->setCnic(values[3]);
					teacher->setMobile(values[4]);
					teacher->setAge(stoi(values[5]));
					teacher->setGender(values[6]);
					teacher->setAddress(values[7]);
					teacher->setProgram(Programe(stoi(values[8])));
					teacher->setVaccineStatus(VaccinatedStatus(stoi(values[9])));
					teacher->setIsAlive(values[11]);
					teachers.push_back(*teacher);
				}

			}
			infile.close();
		}
		return teachers;
	}
}

void main()
{
	system("cls");
	int feature = ShowMenu();
	if (feature != 0) {
		system("cls");
		switch (feature)
		{
		case 1:
			ReportCovidCase();
			break;
		case 2:
			UpdateCovidCase();
			break;
		case 3:
			SeeHistoryOfPerson();
			break;
		case 4:
			SeeActiveCases();
			break;
		case 5:
			SeeActiveCasesByPrograme();
			break;
		default:
			break;
		}
	}
	else {
		system("cls");
		main();
	}
}