#include <iostream> 
#include <string.h>
#include <string>
#include <windows.h> 
#include <stdio.h>

using namespace std;


class clDate {
private:
	unsigned short day;
	unsigned short month;
	unsigned short year;
public:
	clDate();
	clDate(unsigned short, unsigned short, unsigned short);
	clDate(const clDate&);

	void setDate(unsigned short day, unsigned short month, unsigned short year);
	bool checkDate(unsigned short);
	int checkDaysInMonth();
	void plusFiveDays(unsigned short);

	unsigned short getDate_day() { return day; }
	unsigned short getDate_month() {return month; }
	unsigned short getDate_year() { return year; }
	//Деструктор
	~clDate() {
	}
};
//Конструктор по умолчанию
clDate::clDate() {
	day = 1;
	month = 1;
	year = 1970;
};
//Конструктор копирования
clDate::clDate(const clDate& copy_date) {
	this->day = copy_date.day;
	this->month = copy_date.month;
	this->year = copy_date.year;
}
clDate::clDate(unsigned short day, unsigned short month, unsigned short year) {
	this->day = day;
	this->month = month;
	this->year = year;
}
int clDate::checkDaysInMonth() {
	//Проверка високосного года
	if (month == 2) {
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	//Проверка месяцев с 30 днями
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	//Оставшиеся месяцы с 31 днем
	return 31;
}

bool clDate::checkDate(unsigned short fiveDays) {
	unsigned short fday = day + fiveDays;
	return fday <= checkDaysInMonth();
}

void clDate::plusFiveDays(unsigned short fiveDays = 5) {
	if (checkDate(fiveDays)) {
		day += fiveDays;
	}
}

struct Record
{
	char surName[17];
	char ident[12];
	int year;
	float salary;
	clDate date;
};

class clRecord {
	string surName;
private:
	string ident;
protected:
	int year;
	clDate date;
public:
	float salary;

	clRecord();
	clRecord(string, string, int, float, clDate);
	clRecord(string, string, int, float, unsigned short, unsigned short, unsigned short);
	clRecord(const char*);
	clRecord(Record*);

	string getSurName() {return surName;}
	string getIdent() {return ident; }
	int getYear() { return year; }
	float getSalary() { return salary; }
	clDate getDate() { return date; }
	clRecord(const clRecord&);

};
clRecord::clRecord() {
	surName = "Surname";
	ident = "S.S.";
	year = 1970;
	salary = 0;
}

clRecord::clRecord(string surName, string ident, int year, float salary, clDate date) {
	this->surName = surName;
	this->ident = ident;
	this->year = year;
	this->salary = salary;
	this->date = date;
}

clRecord::clRecord(string surName, string ident, int year, float salary, unsigned short dday, unsigned short dmonth, unsigned short dyear) {
	this->surName = surName;
	this->ident = ident;
	this->year = year;
	this->salary = salary;
	this->date = clDate(dday, dmonth, dyear);
}

clRecord::clRecord(Record* cRecord) {
	this->surName = cRecord->surName;
	this->ident = cRecord->ident;
	this->year = cRecord->year;
	this->salary = cRecord->salary;
	this->date = cRecord->date;
}


clRecord::clRecord (const clRecord& cRecord) {
	this->surName = cRecord.surName;
	this->ident = cRecord.ident;
	this->year = cRecord.year;
	this->salary = cRecord.salary;
	this->date = cRecord.date;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "---Практика 5: классы и объекты---" << endl;

	clRecord Record1("Static surname", "Static ident", 2000, 100.50, 07, 04, 2023);
	class clRecord* dynamicClRecord = new clRecord;
	delete dynamicClRecord;

	class clRecord records[3];
	records[0] = clRecord("Иванов", "И.И.", 1975, 517.50, 01, 02, 2010);
	records[1] = clRecord("Петренко", "П.П.", 1956, 219.10, 02, 03, 2020);
	records[2] = clRecord("Панковский", "М.С.", 1967, 300.10, 12, 12, 2012);
	const int SIZE = 3;
	class clDate listDates[SIZE];
	cout << "Даты из классов clRecord:" << endl;
	for (int i = 0; i < SIZE; i++){
		listDates[i] = records[i].getDate();
	}
	for (int i = 0; i < SIZE; i++) {
		cout << "Record[" << i << "]: "\
			 << listDates[i].getDate_day() << " " \
			 << listDates[i].getDate_month() << " " \
			 << listDates[i].getDate_year() << endl;
	}
	//Конструктор по умолчанию
	clDate date1();
	//Конструктор с параметрами
	clDate date2(07, 04, 2023);
	cout << "Date2: " \
		<< date2.getDate_day() << " " \
		<< date2.getDate_month() << " " \
		<< date2.getDate_year() << endl;
	//Добавление 5ти дней 
	date2.plusFiveDays();
	cout << "Date2 после прибавления: " \
		<< date2.getDate_day() << " " \
		<< date2.getDate_month() << " " \
		<< date2.getDate_year() << endl;
	//Копирование даты
	clDate date3(date2);
	cout << "Date3: " \
		<< date3.getDate_day() << " " \
		<< date3.getDate_month() << " " \
		<< date3.getDate_year() << endl;
	//Создание динамической даты
	class clDate* dynamicClDate = new clDate;
	delete dynamicClDate;

	return 0;
}