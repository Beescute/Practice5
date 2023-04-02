#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

class clDate {
private:
	Date _clDate;
public:
	//Конструктор с параметрами
	clDate(int, int, int);
	//Конструктор по умолчанию
	clDate() {
		_clDate.day = 1;
		_clDate.month = 1;
		_clDate.year = 1970;
	};
	//Конструктор копирования
	clDate(const clDate& _copy_date) {
		_clDate.day = _copy_date._clDate.day;
		_clDate.month = _copy_date._clDate.month;
		_clDate.year = _copy_date._clDate.year;
	}
	void setDate(int _day, int _month, int _year) {
		_clDate.day = _day;
		_clDate.month = _month;
		_clDate.year = _year;
	}
	//Проверка добавления 5-ти дней к дате
	bool fiveDaysPlus(clDate f_clDate) {
		f_clDate._clDate.day += 5;
		const int MONTHS = 12;
		int countMonth = f_clDate._clDate.month;
		int listMonth[MONTHS];
		for (int i = 0; i < MONTHS; i++) {
			listMonth[i] = i;
		}
		for (int i = 1; i < MONTHS; i + 2) {
			if ((countMonth == i) && (f_clDate._clDate.day <= 31)) {
				cout << f_clDate.getData_day() << " "\
					<< f_clDate.getData_month() << " "\
					<< f_clDate.getData_year() << " " << endl;
				return true;
			}
			if ((countMonth != i) && (f_clDate._clDate.day <= 30)) {
				cout << f_clDate.getData_day() << " "\
					<< f_clDate.getData_month() << " "\
					<< f_clDate.getData_year() << " " << endl;
				return true;
			}
			if ((countMonth != i) && (f_clDate._clDate.day <= 28) && (f_clDate._clDate.year != 2024)) {
				cout << f_clDate.getData_day() << " "\
					<< f_clDate.getData_month() << " "\
					<< f_clDate.getData_year() << " " << endl;
				return true;
			}
			if ((countMonth != i) && (f_clDate._clDate.day <= 29) && (f_clDate._clDate.year == 2024)) {
				cout << f_clDate.getData_day() << " "\
					<< f_clDate.getData_month() << " "\
					<< f_clDate.getData_year() << " " << endl;
				return true;
			}
			else {
				cout << "Неверная дата!" << endl;
				cout << f_clDate.getData_day() - 5 << " "\
					<< f_clDate.getData_month() << " "\
					<< f_clDate.getData_year() << " " << endl;
				return false;
			}
		}

	}
	int getData_day() {
		return _clDate.day;
	}
	int getData_month() {
		return _clDate.month;
	}
	int getData_year() {
		return _clDate.year;
	}
	//Деструктор
	~clDate() {
	}
};


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
	clRecord(string, char, int, float, unsigned int, unsigned int, unsigned int);
	clRecord(Record*);
	clRecord(const char*);
	string getSurName() { return surName; }
	string getIdent() { return ident; }
	unsigned short getYear() { return year; }
	float getSalary() { return salary; }
	clDate getDate() { return date; }
};

clRecord::clRecord() {
	surName = "Atavin";
	ident = "D.A.";
	year = 2005;
	salary = 5088;

}

clRecord::clRecord(string surName, string ident, int year, float salary, clDate date) {
	this->surName = surName;
	this->ident = ident;
	this->year = year;
	this->salary = salary;
	this->date = date;
}
clRecord::clRecord(string surName, char ident, int year, float salary, unsigned int day, unsigned int month, unsigned int yearD) {
	this->surName = surName;
	this->ident = ident;
	this->year = year;
	this->salary = salary;
	this->date = clDate(day, month, yearD);
}
clRecord::clRecord(Record* _record) {
	this->surName = _record->surName;
	this->ident = _record->ident;
	this->year = _record->year;
	this->salary = _record->salary;
	this->date = _record->date;
}
clRecord::clRecord(const char* nameFile) {
	FILE* file;
	char split;
	fopen_s(&file, nameFile, "r");
	fscanf_s(file, "%s", &this->surName, (this->surName).length());
	fscanf_s(file, "%s", &this->ident, (this->ident).length());
	fscanf_s(file, "%d", &this->year);
	fscanf_s(file, "%f", &this->salary);
	fscanf_s(file, "%d", this->date.getData_day());
	fscanf_s(file, "%d", this->date.getData_month());
	fscanf_s(file, "%d", this->date.getData_year());
	fclose(file);
}



char* GetSpacebar(int count) {
	char* msg = new char[count];
	for (int i = 0; i < count; i++)
	{
		msg[i] = ' ';
	}
	msg[count] = '\0';
	return msg;
}

int GetSize(char* msg) {
	int size = 0;
	while (msg[size] != '\0')
		size++;
	return size;
}


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(int day, int month, int year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void Draw(struct Record* records, int num) {
	cout << endl;	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Отдел кадров"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|"; myCentr("Фамилия", 16);
	cout << left << "|"; myCentr("Инициалы", 11);
	cout << left << "|"; myCentr("Год рожд", 10);
	cout << left << "|"; myCentr("Оклад", 10);
	cout << left << " |"; myCentr("Дата приема на работу", 24);
	cout << "|" << endl;

	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');

	for (int i = 0; i < num; i++) {
		cout << left << "|"; cout.width(16); cout << left << records[i].surName;
		cout << left << "|"; cout.width(11); cout << left << records[i].ident;
		cout << left << "|+"; cout.width(10); cout << left << records[i].year;
		std::cout.precision(2);
		cout << left << "|"; cout.width(11); cout << left << fixed << records[i].salary;
		cout << left << "|";
		printDate(records[i].date.getData_day(), records[i].date.getData_month(), records[i].date.getData_year(), 26);
		cout << "|" << endl;
	}
	cout.width(79); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78);  cout << left << "|Примечание: оклад установлен по состоянию на 1 января 2000 года"; cout << "|" << endl;
	cout.width(79); cout.fill('-'); cout << "-" << endl;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[3];
	const int num = 3;

	records[0] = { "Иванов", "И.И.", 1975, 517.50, {01,02,2010} };
	records[1] = { "Петренко", "П.П.", 1956, 219.10, {02,03,2020} };
	records[2] = { "Панковский", "М.С.", 1967, 300.10, {12,12,2012} };

	cout << endl << "---Практика 5: классы и объекты---" << endl;
	const int SIZE = 3;
	class clDate listDates[SIZE];
	for (int i = 0; i < SIZE; i++) {
		listDates[i].setDate(records[i].date.getData_day(), records[i].date.getData_month(), records[i].date.getData_year());
	}
	cout << "Даты из структуры Record:" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << \
			listDates[i].getData_day() << " " <<
			listDates[i].getData_month() << " " <<
			listDates[i].getData_year() << " " << endl;
	}
	class clDate* dynamicClDate = new clDate;
	delete dynamicClDate;

	//Добавление 5-ти ко дню даты и проверка 
	clDate copied_Date;
	clDate copy_Date = copied_Date;
	copy_Date.setDate(26, 04, 2023);
	if (copy_Date.fiveDaysPlus(copy_Date));
	clRecord cl_Record("Иванов", "И.И.", 1975, 517.50, { 01,02,2010 });
	return 0;
}