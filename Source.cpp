#include<iostream>
#include<iomanip>
#include<string>

class date {
protected:
	int day;
	int month;
	int year;
public:
	date() :day(0), month(0), year(0) {}
	date(int a, int b, int c) :day(a), month(b), year(c) {}
	void setdate(int a, int b, int c) {
		if ((a < 0) or (a > 31) or (b < 0) or (b > 12) or (c < 0) or (c > 2019)) {
			std::cout << "Nemojlyva data";
			exit(1);
		}
		day = a;
		month = b;
		year = c;
	}
	void getdate() {
		std::cout << "Den': ";
		while (true) {
			std::cin >> day;
			if (std::cin.good() and (day > 0) and (day < 32)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Misyac': ";
		while (true) {
			std::cin >> month;
			if (std::cin.good() and (month > 0) and (month < 13)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Rik: ";
		while (true) {
			std::cin >> year;
			if (std::cin.good() and (year > 0) and (year < 2020)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
	}
	void showdate() {
		char ch = '/';
		std::cout << std::setw(2) << day << ch << std::setw(2) << month << ch << std::setw(4) << year;
	}
	void adddate(date *&arr, int &size) {
		date *newarr = new date[size + 1];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		newarr[size].getdate();
		size++;
		delete[] arr;
		arr = newarr;
	}
	bool operator <(date d1) {
		return (((year < d1.year) | ((year == d1.year) & (month < d1.month)) | ((year == d1.year)&(month == d1.month) & (day < d1.day)))) ? true : false;
	}
	bool operator >(date d1) {
		return (((year > d1.year) | ((year == d1.year) & (month > d1.month)) | ((year == d1.year)&(month == d1.month) & (day > d1.day)))) ? true : false;
	}
};
class address {
protected:
	int build;
	std::string street;
	std::string city;
public:
	address() :build(0) {}
	address(int a, std::string b, std::string c) :build(a), street(b), city(c) {};
	void setaddress(int a, std::string b, std::string c) {
		build = a;
		street = b;
		city = c;
	}
	void getaddress() {
		std::cout << "Budynok: ";
		while (true) {
			std::cin >> build;
			if (std::cin.good() and (build > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Vulycya: ";
		std::cin >> street;
		std::cout << "Misto: ";
		std::cin >> city;
	}
	friend std::ostream& operator<<(std::ostream &s, address &a);
	void showaddress() {
		std::cout << std::setw(5) << build << std::setw(15) << street << std::setw(15) << city;
	}
};
std::ostream& operator<<(std::ostream &s, address &a) {
	s << a.city << ", " << a.street << " " << a.build;
	return s;
}
class goods :public date {
private:
	int id;
	std::string name;
	date rdate;
	int amount;
	int price;
public:
	goods() :id(0) {};
	void setgoods(int a, std::string b, date c, int d, int f) {
		id = a;
		name = b;
		rdate = c;
		amount = d;
		price = f;
	}
	bool checkid(goods* arr, int size, int id) {
		int k = 0;
		for (int i = 0; i < size; i++) {
			if (id == arr[i].id) {
				k++;
			}
		}
		if (k != 0) {
			return false;
		}
		else {
			return true;
		}
	}
	void setdate(int a, int b, int c) {
		if ((a < 0) or (a > 31) or (b < 0) or (b > 12) or (c < 0) or (c > 2019)) {
			std::cout << "Nemojlyva data";
			exit(1);
		}
		day = a;
		month = b;
		year = c;
	}
	void getgoods() {
		std::cout << "Kod: ";
		while (true) {
			std::cin >> id;
			if (std::cin.good() and (id > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Nazva: ";
		std::cin >> name;
		std::cout << "Kil'kist': ";
		while (true) {
			std::cin >> amount;
			if (std::cin.good() and (amount > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Cina zakupky: ";
		while (true) {
			std::cin >> price;
			if (std::cin.good() and (price >= 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Data otrymannya: ";
		rdate.getdate();
	}
	void showgoods() {
		std::cout << std::setw(3) << id;
		std::cout << std::setw(15) << name;
		std::cout << "  ";
		rdate.showdate();
		std::cout << std::setw(10) << amount;
		std::cout << std::setw(13) << price;
	}
	int retid() {
		return this->id;
	}
	date retdate() {
		return this->rdate;
	}
	int retamount() {
		return this->amount;
	}
	int retprice() {
		return this->price;
	}
};
class provider :public address {
private:
	int id;
	std::string name;
	address paddress;
	std::string telephone;
public:
	provider() :id(0) {}
	void setprovider(int a, std::string b, address c, std::string d) {
		if (a < 0) {
			std::cout << "Nastupnogo razu vvod'te korektni dani";
			exit(1);
		};
		id = a;
		name = b;
		paddress = c;
		telephone = d;
	}
	void getprovider() {
		std::cout << "Kod: ";
		while (true) {
			std::cin >> id;
			if (std::cin.good() and (id > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Nazva: ";
		std::cin >> name;
		std::cout << "Adresa: ";
		paddress.getaddress();
		std::cout << "Telefon: ";
		std::cin >> telephone;
	}
	void showprovider() {
		std::cout << std::setw(3) << id;
		std::cout << std::setw(15) << name;
		std::cout << std::setw(12) << telephone;
		std::cout << std::setw(14) << paddress;
	}
	int retid() {
		return this->id;
	}
};
class sales :public date {
private:
	int id;
	int gid;
	date sdate;
	int amount;
	int price;
public:
	sales() {}
	sales(int a, int b, date c, int d, int f) :id(a), gid(b), sdate(c), amount(d), price(f) {}
	void setsales(int a, int b, date c, int d, int f) {
		if ((a <= 0) or (b <= 0) or (d <= 0) or (f <= 0)) {
			std::cout << "Nastupnogo razu vvod'te korektni dani";
			exit(1);
		}
		id = a;
		gid = b;
		sdate = c;
		amount = d;
		price = f;
	}
	void getsales() {
		std::cout << "Kod: ";
		while (true) {
			std::cin >> id;
			if (std::cin.good() and (id > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Kod tovaru: ";
		while (true) {
			std::cin >> gid;
			if (std::cin.good() and (gid > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Data prodaju: ";
		sdate.getdate();
		std::cout << "Kil'kist' prodanogo: ";
		while (true) {
			std::cin >> amount;
			if (std::cin.good() and (amount > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Rozdribna cina: ";
		while (true) {
			std::cin >> price;
			if (std::cin.good() and (price > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
	}
	void showsales() {
		std::cout << std::setw(3) << id;
		std::cout << std::setw(10) << gid;
		std::cout << "  ";
		sdate.showdate();
		std::cout << std::setw(10) << amount;
		std::cout << std::setw(15) << price;
	}
	int retid() {
		return this->id;
	}
	int retgid() {
		return this->gid;
	}
	date retsdate() {
		return this->sdate;
	}
	int retamount() {
		return this->amount;
	}
	int retprice() {
		return this->price;
	}
};
class pcong {
private:
	int id;
	int gid;
	int pid;
public:
	pcong() {}
	pcong(int a, int b, int c) :id(a), gid(b), pid(c) {}
	void setcon(int a, int b, int c) {
		id = c;
		gid = a;
		pid = b;
	}
	void getcon() {
		std::cout << "Kod: ";
		while (true) {
			std::cin >> id;
			if (std::cin.good() and (id > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Kod tovaru: ";
		while (true) {
			std::cin >> gid;
			if (std::cin.good() and (gid > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		std::cout << "Kod postachal'nyka: ";
		while (true) {
			std::cin >> pid;
			if (std::cin.good() and (pid > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
	}
	void showcon() {
		std::cout << std::setw(5) << id;
		std::cout << std::setw(5) << gid;
		std::cout << std::setw(20) << pid;
	}
	int retid() {
		return this->id;
	}
	int retgid() {
		return this->gid;
	}
	int retpid() {
		return this->pid;
	}
};
void addgoods(goods *&arr, int &size) {
	goods* newarr = new goods[size + 1];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	newarr[size].getgoods();
	size++;
	delete[] arr;
	arr = newarr;
}
void addprovider(provider *&arr, int &size) {
	provider* newarr = new provider[size + 1];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	newarr[size].getprovider();
	size++;
	delete[] arr;
	arr = newarr;
}
void addsales(sales *&arr, int &size) {
	sales* newarr = new sales[size + 1];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	newarr[size].getsales();
	size++;
	delete[] arr;
	arr = newarr;
}
void addcon(pcong *&arr, int &size) {
	pcong* newarr = new pcong[size + 1];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	newarr[size].getcon();
	size++;
	delete[] arr;
	arr = newarr;
}
void deletegoods(goods *&arr, int &size, int id) {
	int k = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].retid() == id) {
			k = i;
			count++;
		}
	}
	if (count != 0) {
		goods *newarr = new goods[size];
		for (int i = 0; i < k; i++) {
			newarr[i] = arr[i];
		}
		for (int i = k + 1; i < size; i++) {
			newarr[i - 1] = arr[i];
		}
		size--;
		delete[] arr;
		arr = newarr;
	}
	else {
		std::cout << "Takogo zapysu ne znaideno" << std::endl;
	}
}
void deleteprovider(provider *&arr, int &size, int id) {
	int k = 0; int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].retid() == id) {
			k = i;
			count++;
		}
	}
	if (count != 0) {
		provider *newarr = new provider[size];
		for (int i = 0; i < k; i++) {
			newarr[i] = arr[i];
		}
		for (int i = k + 1; i < size; i++) {
			newarr[i - 1] = arr[i];
		}
		size--;
		delete[] arr;
		arr = newarr;
	}
	else {
		std::cout << "Takogo zapysu ne znaideno" << std::endl;
	}
}
void deletesales(sales *&arr, int &size, int id) {
	int k = 0; int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].retid() == id) {
			k = i;
			count++;
		}
	}
	if (count != 0) {
		sales *newarr = new sales[size];
		for (int i = 0; i < k; i++) {
			newarr[i] = arr[i];
		}
		for (int i = k + 1; i < size; i++) {
			newarr[i - 1] = arr[i];
		}
		size--;
		delete[] arr;
		arr = newarr;
	}
	else {
		std::cout << "Takogo zapysu ne znaideno" << std::endl;
	}
}
void deleteconallgid(pcong *&arr, int &size, int id) {
	int k = 0; int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].retgid() == id) {
			count++;
		}
	}
	if (count != 0) {
		for (int j = 1; j <= count; j++) {
			for (int i = 0; i < size; i++) {
				if (arr[i].retgid() == id) {
					k = i;
				}
			}
			pcong *newarr = new pcong[size];
			for (int i = 0; i < k; i++) {
				newarr[i] = arr[i];
			}
			for (int i = k + 1; i < size; i++) {
				newarr[i - 1] = arr[i];
			}
			size--;
			delete[] arr;
			arr = newarr;
		}
	}
	else {
		std::cout << "Takogo zapysu ne znaideno" << std::endl;
	}
}
void deleteconallpid(pcong *&arr, int &size, int id) {
	int k = 0; int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].retpid() == id) {
			count++;
		}
	}
	if (count != 0) {
		for (int j = 1; j <= count; j++) {
			for (int i = 0; i < size; i++) {
				if (arr[i].retpid() == id) {
					k = i;
				}
			}
			pcong *newarr = new pcong[size];
			for (int i = 0; i < k; i++) {
				newarr[i] = arr[i];
			}
			for (int i = k + 1; i < size; i++) {
				newarr[i - 1] = arr[i];
			}
			size--;
			delete[] arr;
			arr = newarr;
		}
	}
	else {
		std::cout << "Takogo zapysu ne znaideno" << std::endl;
	}
}
void deletecon(pcong* arr, int& size, int id) {
	int k = 0; int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].retid() == id) {
			k = i;
			count++;
		}
	}
	if (count != 0) {
		pcong *newarr = new pcong[size];
		for (int i = 0; i < k; i++) {
			newarr[i] = arr[i];
		}
		for (int i = k + 1; i < size; i++) {
			newarr[i - 1] = arr[i];
		}
		size--;
		delete[] arr;
		arr = newarr;
	}
	else {
		std::cout << "Takogo zapysu ne znaideno" << std::endl;
	}

}
void deleteconquest(pcong* arr, int &size) {
	int a, gid, pid, b, id;
	std::cout << "1-Vsi z pevnym id" << std::endl;
	std::cout << "9-Vyhid" << std::endl;
	while (true) {
		std::cin >> a;
		if (std::cin.good() and (a > 0)) {
			std::cin.ignore(10, '\n');
			break;
		}
		std::cin.clear();
		std::cout << "Vvedit' korektni dani\n";
		std::cin.ignore(10, '\n');
	}
	switch (a) {

	case 1: {
		std::cout << "1-Vydalennya po KODU TOVARU\n";
		std::cout << "2-Vydalennya po KODU POSTACHZl'NYKA\n";
		std::cout << "9-Vyhid" << std::endl;
		while (true) {
			std::cin >> b;
			if (std::cin.good() and (b > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		switch (b) {
		case 1: {
			std::cout << "Vvedit' KOD TOVARU: ";
			while (true) {
				std::cin >> gid;
				if (std::cin.good() and (gid > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			deleteconallgid(arr, size, gid);
			break;
		}
		case 2: {
			std::cout << "Vvedit' KOD POSTACHAL'NYKA: ";
			while (true) {
				std::cin >> pid;
				if (std::cin.good() and (pid > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			deleteconallpid(arr, size, pid);
			break;
		}
		case 9: {
			exit(1);
			break;
		}
		default:std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
			break;
		}
		break;
	}
	}
}
void showtitels(int a) {
	switch (a) {
	case 1: {
		std::cout << std::setw(3) << "KOD";
		std::cout << std::setw(15) << "NAZVA";
		std::cout << std::setw(10) << "DATA";
		std::cout << std::setw(13) << "KIL'KIST'";
		std::cout << std::setw(15) << "CINA ZAKUPKY";
		std::cout << std::endl;
		break;
	}
	case 2: {
		std::cout << std::setw(3) << "KOD";
		std::cout << std::setw(15) << "NAZVA";
		std::cout << std::setw(13) << "TELEFON";
		std::cout << std::setw(15) << "ADRESA";
		std::cout << std::endl;
		break;
	}
	case 3: {
		std::cout << std::setw(3) << "KOD";
		std::cout << std::setw(12) << "KOD TOVARU";
		std::cout << std::setw(8) << "DATA";
		std::cout << std::setw(20) << "KIL'KIST' V KG";
		std::cout << std::setw(15) << "ROZDRIBNA CINA";
		std::cout << std::endl;
		break;
	}
	case 4: {
		std::cout << std::setw(2) << "KOD";
		std::cout << std::setw(15) << "KOD TOVARU";
		std::cout << std::setw(20) << "ÊOD POSTACHAL'NYKA";
		std::cout << std::endl;
		break;
	}
	}
}
void goodssortidup(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retid() > arr[j + 1].retid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortiddown(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retid() < arr[j + 1].retid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortpriceup(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retprice() > arr[j + 1].retprice()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortpricedown(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retprice() < arr[j + 1].retprice()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortamountup(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retamount() > arr[j + 1].retamount()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortamountdown(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retamount() < arr[j + 1].retamount()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortdateup(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retdate() > arr[j + 1].retdate()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void goodssortdatedown(goods* arr, int size) {
	goods d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retdate() < arr[j + 1].retdate()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void providersortidup(provider* arr, int size) {
	provider d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retid() > arr[j + 1].retid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void providersortiddown(provider* arr, int size) {
	provider d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retid() < arr[j + 1].retid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortidup(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retid() > arr[j + 1].retid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortiddown(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retid() < arr[j + 1].retid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortgidup(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retgid() > arr[j + 1].retgid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortgiddown(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retgid() < arr[j + 1].retgid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortdateup(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retsdate() > arr[j + 1].retsdate()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortdatedown(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retsdate() < arr[j + 1].retsdate()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortamountup(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retamount() > arr[j + 1].retamount()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}

void salessortamountdown(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retamount() < arr[j + 1].retamount()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortpriceup(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retprice() > arr[j + 1].retprice()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void salessortpricedown(sales* arr, int size) {
	sales d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retprice() < arr[j + 1].retprice()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void consortgidup(pcong* arr, int size) {
	pcong d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retgid() > arr[j + 1].retgid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void consortgiddown(pcong* arr, int size) {
	pcong d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retgid() < arr[j + 1].retgid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void consortpidup(pcong* arr, int size) {
	pcong d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retpid() > arr[j + 1].retpid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
void consortpiddown(pcong* arr, int size) {
	pcong d;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j].retpid() < arr[j + 1].retpid()) {
				d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "russian");
	const int rdatesize = 15;
	const int goodssize = 15;
	const int paddresssize = 15;
	const int provsize = 15;
	const int sdatesize = 18;
	const int salessize = 18;
	const int consize = 26;
	int gsize = goodssize;
	int psize = provsize;
	int ssize = salessize;
	int csize = consize;
	date* rdatearr = new date[rdatesize];
	rdatearr[0].setdate(1, 10, 2019);
	rdatearr[1].setdate(5, 10, 2019);
	rdatearr[2].setdate(5, 10, 2019);
	rdatearr[3].setdate(1, 10, 2019);
	rdatearr[4].setdate(2, 10, 2019);
	rdatearr[5].setdate(2, 10, 2019);
	rdatearr[6].setdate(10, 10, 2019);
	rdatearr[7].setdate(10, 10, 2019);
	rdatearr[8].setdate(20, 10, 2019);
	rdatearr[9].setdate(22, 10, 2019);
	rdatearr[10].setdate(22, 10, 2019);
	rdatearr[11].setdate(22, 10, 2019);
	rdatearr[12].setdate(17, 10, 2019);
	rdatearr[13].setdate(17, 10, 2019);
	rdatearr[14].setdate(18, 10, 2019);


	goods* goodsarr = new goods[goodssize];
	goodsarr[0].setgoods(1, "grechka", rdatearr[0], 50, 10);
	goodsarr[1].setgoods(2, "rys", rdatearr[1], 20, 10);
	goodsarr[2].setgoods(3, "rijky", rdatearr[2], 30, 7);
	goodsarr[3].setgoods(4, "yabluka", rdatearr[3], 30, 5);
	goodsarr[4].setgoods(5, "banany", rdatearr[4], 50, 15);
	goodsarr[5].setgoods(6, "mandaryny", rdatearr[5], 20, 15);
	goodsarr[6].setgoods(7, "morkva", rdatearr[6], 45, 4);
	goodsarr[7].setgoods(8, "kartoplya", rdatearr[7], 100, 6);
	goodsarr[8].setgoods(9, "lymony", rdatearr[8], 10, 20);
	goodsarr[9].setgoods(10, "syr", rdatearr[9], 10, 100);
	goodsarr[10].setgoods(11, "kovbasa", rdatearr[10], 20, 80);
	goodsarr[11].setgoods(12, "sardel'ky", rdatearr[11], 25, 45);
	goodsarr[12].setgoods(13, "cukor", rdatearr[12], 70, 8);
	goodsarr[13].setgoods(14, "boroshno", rdatearr[13], 115, 10);
	goodsarr[14].setgoods(15, "maslo", rdatearr[14], 35, 75);
	address* paddressarr = new address[paddresssize];
	paddressarr[0].setaddress(35, "Lisova", "Rivne");
	paddressarr[1].setaddress(40, "Naukova", "L'viv");
	paddressarr[2].setaddress(113, "Bankova", "Luc'k");
	paddressarr[3].setaddress(72, "Rynkova", "Rivne");
	paddressarr[4].setaddress(83, "Syhivs'ka", "L'viv");
	paddressarr[5].setaddress(44, "L'vivs'ka", "Luc'k");
	paddressarr[6].setaddress(101, "Sheptyc'kogo", "Mykolaiv");
	paddressarr[7].setaddress(55, "Myrna", "Chervonograd");
	paddressarr[8].setaddress(88, "Pivnichna", "Luc'k");
	paddressarr[9].setaddress(11, "Vygovs'kogo", "L'viv");
	paddressarr[10].setaddress(125, "Zahidna", "Mykolaiv");
	paddressarr[11].setaddress(331, "Vygovs'kogo", "L'viv");
	paddressarr[12].setaddress(22, "Syaivo", "Rivne");
	paddressarr[13].setaddress(33, "Shevchenka", "L'viv");
	paddressarr[14].setaddress(59, "Sheptyc'kogo", "Mykolaiv");
	provider* provarr = new provider[provsize];
	provarr[0].setprovider(1, "Smereka", paddressarr[0], "0674504746");
	provarr[1].setprovider(2, "Frutini", paddressarr[1], "0976301122");
	provarr[2].setprovider(3, "Namynajlo", paddressarr[2], "0509304311");
	provarr[3].setprovider(4, "Yablun'ka", paddressarr[3], "0954441205");
	provarr[4].setprovider(5, "Molochar", paddressarr[4], "0635430315");
	provarr[5].setprovider(6, "Myasko", paddressarr[5], "0974931179");
	provarr[6].setprovider(7, "Fruktove", paddressarr[6], "0975412297");
	provarr[7].setprovider(8, "Vershky", paddressarr[7], "0672228345");
	provarr[8].setprovider(9, "Cytryna", paddressarr[8], "0959415536");
	provarr[9].setprovider(10, "Zlakove", paddressarr[9], "0974136613");
	provarr[10].setprovider(11, "Ovocheve", paddressarr[10], "0505554112");
	provarr[11].setprovider(12, "Rebercya", paddressarr[11], "0979235545");
	provarr[12].setprovider(13, "Smakolyk", paddressarr[12], "0671116699");
	provarr[13].setprovider(14, "Ukrains'ke", paddressarr[13], "0953334499");
	provarr[14].setprovider(15, "Jytnycya", paddressarr[14], "0670672211");

	date* sdatearr = new date[sdatesize];
	sdatearr[0].setdate(15, 10, 2019);
	sdatearr[1].setdate(10, 10, 2019);
	sdatearr[2].setdate(23, 10, 2019);
	sdatearr[3].setdate(3, 10, 2019);
	sdatearr[4].setdate(12, 10, 2019);
	sdatearr[5].setdate(18, 10, 2019);
	sdatearr[6].setdate(25, 10, 2019);
	sdatearr[7].setdate(7, 10, 2019);
	sdatearr[8].setdate(25, 10, 2019);
	sdatearr[9].setdate(3, 10, 2019);
	sdatearr[10].setdate(20, 10, 2019);
	sdatearr[11].setdate(20, 10, 2019);
	sdatearr[12].setdate(13, 10, 2019);
	sdatearr[13].setdate(15, 10, 2019);
	sdatearr[14].setdate(7, 10, 2019);
	sdatearr[15].setdate(23, 10, 2019);
	sdatearr[16].setdate(10, 10, 2019);
	sdatearr[17].setdate(21, 10, 2019);
	sales* salesarr = new sales[salessize];
	salesarr[0].setsales(1, 1, sdatearr[0], 3, 20);
	salesarr[1].setsales(2, 6, sdatearr[1], 1, 31);
	salesarr[2].setsales(3, 10, sdatearr[2], 1, 202);
	salesarr[3].setsales(4, 4, sdatearr[3], 3, 10);
	salesarr[4].setsales(5, 7, sdatearr[4], 1, 8);
	salesarr[5].setsales(6, 1, sdatearr[5], 2, 20);
	salesarr[6].setsales(7, 11, sdatearr[6], 2, 160);
	salesarr[7].setsales(8, 3, sdatearr[7], 5, 15);
	salesarr[8].setsales(9, 9, sdatearr[8], 2, 40);
	salesarr[9].setsales(10, 5, sdatearr[9], 2, 30);
	salesarr[10].setsales(11, 13, sdatearr[10], 10, 16);
	salesarr[11].setsales(12, 14, sdatearr[11], 50, 20);
	salesarr[12].setsales(13, 8, sdatearr[12], 25, 12);
	salesarr[13].setsales(14, 3, sdatearr[13], 10, 15);
	salesarr[14].setsales(15, 5, sdatearr[14], 3, 30);
	salesarr[15].setsales(16, 12, sdatearr[15], 1, 90);
	salesarr[16].setsales(17, 6, sdatearr[16], 2, 31);
	salesarr[17].setsales(18, 8, sdatearr[17], 50, 12);

	pcong* conarr = new pcong[consize];
	conarr[0].setcon(1, 15, 1);
	conarr[1].setcon(1, 10, 2);
	conarr[2].setcon(3, 10, 3);
	conarr[3].setcon(5, 2, 4);
	conarr[4].setcon(4, 4, 5);
	conarr[5].setcon(4, 4, 6);
	conarr[6].setcon(2, 14, 7);
	conarr[7].setcon(2, 10, 8);
	conarr[8].setcon(5, 7, 9);
	conarr[9].setcon(15, 8, 10);
	conarr[10].setcon(11, 12, 11);
	conarr[11].setcon(11, 6, 12);
	conarr[12].setcon(12, 6, 13);
	conarr[13].setcon(7, 11, 14);
	conarr[14].setcon(8, 11, 15);
	conarr[15].setcon(8, 1, 16);
	conarr[16].setcon(10, 8, 17);
	conarr[17].setcon(9, 9, 18);
	conarr[18].setcon(13, 3, 19);
	conarr[19].setcon(13, 13, 20);
	conarr[20].setcon(14, 13, 21);
	conarr[21].setcon(6, 1, 22);
	conarr[22].setcon(6, 2, 23);
	conarr[23].setcon(15, 5, 24);
	conarr[24].setcon(7, 14, 25);
	conarr[25].setcon(14, 15, 26);
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u,
		v, w, x, y, z, count, aa, bb, cc, dd, ff, ee, gg, hh, ii, jj, kk,
		ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz;
menu: while (true) {
	std::cout << "1-Podyvytys' vsi tablyci" << std::endl;
	std::cout << "2-Redagyvannya tablyc''" << std::endl;
	std::cout << "3-Zapyt" << std::endl;
	std::cout << "4-Sortuvannya" << std::endl;
	std::cout << "9-Vyhid" << std::endl;
	while (true) {
		std::cin >> a;
		if (std::cin.good() and (a > 0)) {
			std::cin.ignore(10, '\n');
			break;
		}
		std::cin.clear();
		std::cout << "Vvedit' korektni dani\n";
		std::cin.ignore(10, '\n');
	}
	switch (a) {
	case 1: {
		std::cout << "Tablycya TOVARY" << std::endl;
		showtitels(1);
		for (int i = 0; i < gsize; i++) {
			goodsarr[i].showgoods();
			std::cout << std::endl;
		}
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << "Tablycya POSTACHL'NYKY" << std::endl;
		showtitels(2);
		for (int i = 0; i < psize; i++) {
			provarr[i].showprovider();
			std::cout << std::endl;
		}
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << "Tablycya PRODAJI" << std::endl;
		showtitels(3);
		for (int i = 0; i < ssize; i++) {
			salesarr[i].showsales();
			std::cout << std::endl;
		}
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << "Tablycya ZVIAZOK" << std::endl;
		showtitels(4);
		for (int i = 0; i < csize; i++) {
			conarr[i].showcon();
			std::cout << std::endl;
		}
		break;
	}
	case 2: {
		std::cout << "Vyberit' tablyc'u" << std::endl;
		std::cout << "1-TOVARY" << std::endl;
		std::cout << "2-POSTACHAL'NYKY" << std::endl;
		std::cout << "3-PRODAJI" << std::endl;
		std::cout << "4-ZVIAZOK" << std::endl;
		std::cout << "9-VYHID" << std::endl;
		while (true) {
			std::cin >> b;
			if (std::cin.good() and (b > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		switch (b) {
		case 1: {
			std::cout << "1-Dodaty zapys" << std::endl;
			std::cout << "2-Vydalyty zapys" << std::endl;
			std::cout << "9-Vyhid" << std::endl;
			while (true) {
				std::cin >> e;
				if (std::cin.good() and (e > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (e) {
			case 1: {
				addgoods(goodsarr, gsize);
				break;
			}
			case 2: {
				std::cout << "Vvedit KOD zapysu" << std::endl;
				while (true) {
					std::cin >> i;
					if (std::cin.good() and (i > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				deletegoods(goodsarr, gsize, i);
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default:std::cout << "Takoi funkcii ne peredbacheno\n";
			}
			break;
		}
		case 2: {
			std::cout << "1-Dodaty zapys" << std::endl;
			std::cout << "2-Vydalyty zapys" << std::endl;
			std::cout << "9-Vyhid" << std::endl;
			while (true) {
				std::cin >> f;
				if (std::cin.good() and (f > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (f) {
			case 1: {
				addprovider(provarr, psize);
				break;
			}
			case 2: {
				std::cout << "Vvedit KOD zapysu" << std::endl;
				while (true) {
					std::cin >> j;
					if (std::cin.good() and (j > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				deleteprovider(provarr, psize, j);
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default: std::cout << "Takoi funkcii ne peredbacheno\n";
				break;
			}
			break;
		}
		case 3: {
			std::cout << "1-Dodaty zapys" << std::endl;
			std::cout << "2-Vydalyty zapys" << std::endl;
			std::cout << "9-Vyhid" << std::endl;
			while (true) {
				std::cin >> g;
				if (std::cin.good() and (g > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (g) {
			case 1: {
				addsales(salesarr, ssize);
				break;
			}
			case 2: {
				std::cout << "Vvedit KOD zapysu" << std::endl;
				while (true) {
					std::cin >> k;
					if (std::cin.good() and (i > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				deletesales(salesarr, ssize, k);
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default: std::cout << "Takoi funkcii ne peredbacheno\n";
				break;
			}
			break;
		}
		case 4: {
			std::cout << "1-Dodaty zapys" << std::endl;
			std::cout << "2-Vydalyty zapys" << std::endl;
			std::cout << "9-Vyhid" << std::endl;
			while (true) {
				std::cin >> h;
				if (std::cin.good() and (h > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (h) {
			case 1: {
				addcon(conarr, csize);
				break;
			}
			case 2: {
				deleteconquest(conarr, csize);
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default: std::cout << "Takoi funkcii ne peredbacheno\n";
				break;
			}
			break;
		}
		case 9: {
			exit(1);
			break;
		}
		default: std::cout << "Takoi funkcii ne peredbacheno" << std::endl;
		}
		break;
	}
	case 3: {
		std::cout << "Vyberit' tablyc'u" << std::endl;
		std::cout << "1-TOVARY" << std::endl;
		std::cout << "2-POSTACHAL'NYKY" << std::endl;
		std::cout << "3-PRODAJI" << std::endl;
		std::cout << "4-ZVIAZOK" << std::endl;
		std::cout << "9-VYHID" << std::endl;
		while (true) {
			std::cin >> c;
			if (std::cin.good() and (c > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		switch (c) {
		case 1: {
			std::cout << "Vyberit' kryterii(1) zapytu" << std::endl;
			std::cout << "1-KOD" << std::endl;
			std::cout << "2-KIl'KIST'" << std::endl;
			std::cout << "3-CINA ZAKUPKY" << std::endl;
			std::cout << "9-VYHID" << std::endl;
			while (true) {
				std::cin >> m;
				if (std::cin.good() and (m > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (m) {
			case 1: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> q;
					if (std::cin.good() and (q > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> r;
					if (std::cin.good() and (r >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (q) {
				case 1: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retid() > r) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retid() < r) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retid() >= r) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retid() <= r) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retid() == r) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retid() != r) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 2: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> s;
					if (std::cin.good() and (s > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> t;
					if (std::cin.good() and (t >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (s) {
				case 1: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retamount() > t) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retamount() < t) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retamount() >= t) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retamount() <= t) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retamount() == t) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retamount() != t) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 3: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> u;
					if (std::cin.good() and (u > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> v;
					if (std::cin.good() and (v >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (u) {
				case 1: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retprice() > v) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retprice() < v) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retprice() >= v) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retprice() <= v) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retprice() == v) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(1);
					for (int i = 0; i < gsize; i++) {
						if (goodsarr[i].retprice() != v) {
							count++;
							goodsarr[i].showgoods();
							std::cout << std::endl;
						}
					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default:std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
				break;
			}
			break;
		}
		case 2: {
			std::cout << "Vyberit' kryterii(1) zapytu" << std::endl;
			std::cout << "1-KOD" << std::endl;
			std::cout << "9-VYHID" << std::endl;
			while (true) {
				std::cin >> n;
				if (std::cin.good() and (n > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (n) {
			case 1: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> w;
					if (std::cin.good() and (w > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> x;
					if (std::cin.good() and (x >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (w) {
				case 1: {
					count = 0;
					showtitels(2);
					for (int i = 0; i < psize; i++) {
						if (provarr[i].retid() > x) {
							count++;
							provarr[i].showprovider();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(2);
					for (int i = 0; i < psize; i++) {
						if (provarr[i].retid() < x) {
							count++;
							provarr[i].showprovider();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(2);
					for (int i = 0; i < psize; i++) {
						if (provarr[i].retid() >= x) {
							count++;
							provarr[i].showprovider();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					showtitels(2);
					for (int i = 0; i < psize; i++) {
						if (provarr[i].retid() <= x) {
							count++;
							provarr[i].showprovider();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(2);
					for (int i = 0; i < psize; i++) {
						if (provarr[i].retid() == x) {
							count++;
							provarr[i].showprovider();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(2);
					for (int i = 0; i < psize; i++) {
						if (provarr[i].retid() != x) {
							count++;
							provarr[i].showprovider();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case 3: {
			std::cout << "Vyberit' kryterii(1) zapytu" << std::endl;
			std::cout << "1-KOD PRODAJU" << std::endl;
			std::cout << "2-KOD TOVARU" << std::endl;
			std::cout << "3-KIL'KIST' PRODANOGO" << std::endl;
			std::cout << "4-ROZDRIBNA CINA" << std::endl;
			std::cout << "9-VYHID" << std::endl;
			while (true) {
				std::cin >> o;
				if (std::cin.good() and (o > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (o) {
			case 1: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> y;
					if (std::cin.good() and (y > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> z;
					if (std::cin.good() and (z >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (y) {
				case 1: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retid() > z) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retid() < z) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retid() >= z) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retid() <= z) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retid() == z) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retid() != z) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 2: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> aa;
					if (std::cin.good() and (aa > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> bb;
					if (std::cin.good() and (bb >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (aa) {
				case 1: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retgid() > bb) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retgid() < bb) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retgid() >= bb) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retgid() <= bb) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retgid() == bb) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retgid() != bb) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 3: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> cc;
					if (std::cin.good() and (cc > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> dd;
					if (std::cin.good() and (dd >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (cc) {
				case 1: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retamount() > dd) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retamount() < dd) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retamount() >= dd) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retamount() <= dd) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retamount() == dd) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retamount() != dd) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 4: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> ee;
					if (std::cin.good() and (ee > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> ff;
					if (std::cin.good() and (ff >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (ee) {
				case 1: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retprice() > ff) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retprice() < ff) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retprice() >= ff) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retprice() <= ff) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retprice() == ff) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(3);
					for (int i = 0; i < ssize; i++) {
						if (salesarr[i].retprice() != ff) {
							count++;
							salesarr[i].showsales();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default:std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
				break;
			}
			break;
		}
		case 4: {
			std::cout << "Vyberit' kryterii(1) zapytu" << std::endl;
			std::cout << "1-KOD TOVARY" << std::endl;
			std::cout << "2-KOD POSTACHAL'NYKA" << std::endl;
			std::cout << "9-VYHID" << std::endl;
			while (true) {
				std::cin >> p;
				if (std::cin.good() and (p > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (p) {
			case 1: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> gg;
					if (std::cin.good() and (gg > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> hh;
					if (std::cin.good() and (hh >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (gg) {
				case 1: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retgid() > hh) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retgid() < hh) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retgid() >= hh) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retgid() <= hh) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retgid() == hh) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retgid() != hh) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 2: {
				std::cout << "1- >" << std::endl;
				std::cout << "2- <" << std::endl;
				std::cout << "3- >= " << std::endl;
				std::cout << "4- <=" << std::endl;
				std::cout << "5- =" << std::endl;
				std::cout << "6- !=" << std::endl;
				std::cout << "9- VYHID" << std::endl;
				while (true) {
					std::cin >> ii;
					if (std::cin.good() and (ii > 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				while (true) {
					std::cin >> jj;
					if (std::cin.good() and (jj >= 0)) {
						std::cin.ignore(10, '\n');
						break;
					}
					std::cin.clear();
					std::cout << "Vvedit' korektni dani\n";
					std::cin.ignore(10, '\n');
				}
				switch (ii) {
				case 1: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retpid() > jj) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 2: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retpid() < jj) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 3: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retpid() >= jj) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 4: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retpid() <= jj) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 5: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retpid() == jj) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 6: {
					count = 0;
					showtitels(4);
					for (int i = 0; i < csize; i++) {
						if (conarr[i].retpid() != jj) {
							count++;
							conarr[i].showcon();
							std::cout << std::endl;
						}

					}
					if (count == 0) {
						std::cout << "ZAPYT NE DAV REZULTATIV" << std::endl;
					}
					break;
				}
				case 9: {
					exit(1);
					break;
				}
				default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
					break;
				}
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO" << std::endl;
				break;
			}
			break;
		}
		case 9: {
			exit(1);
			break;
		}
		default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
			break;
		}
		break;
	}
	case 4: {
		std::cout << "Vyberit' tablyc'u" << std::endl;
		std::cout << "1-TOVARY" << std::endl;
		std::cout << "2-POSTACHAL'NYKY" << std::endl;
		std::cout << "3-PRODAJI" << std::endl;
		std::cout << "4-ZVIAZOK" << std::endl;
		std::cout << "9-VYHID" << std::endl;
		while (true) {
			std::cin >> d;
			if (std::cin.good() and (d > 0)) {
				std::cin.ignore(10, '\n');
				break;
			}
			std::cin.clear();
			std::cout << "Vvedit' korektni dani\n";
			std::cin.ignore(10, '\n');
		}
		switch (d) {
		case 1: {
			std::cout << "Vyberit' sortuvannya" << std::endl;
			std::cout << "1- KOD ZROST" << std::endl;
			std::cout << "2- KOD SPAD" << std::endl;
			std::cout << "3- DATA OTRYMANNYA ZROST" << std::endl;
			std::cout << "4- DATA OTRYMANNYA SPAD" << std::endl;
			std::cout << "5- KIL'KIST' ZROST" << std::endl;
			std::cout << "6- KIL'KIST' SPAD" << std::endl;
			std::cout << "7-CINA ZAKUPKY ZROST" << std::endl;
			std::cout << "8-CINA ZAKUPKY SPAD" << std::endl;
			std::cout << "9- VYHID" << std::endl;
			while (true) {
				std::cin >> kk;
				if (std::cin.good() and (kk > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (kk) {
			case 1: {
				goodssortidup(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 2: {
				goodssortiddown(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 3: {
				goodssortdateup(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 4: {
				goodssortdatedown(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 5: {
				goodssortamountup(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 6: {
				goodssortamountdown(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 7: {
				goodssortpriceup(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 8: {
				goodssortpricedown(goodsarr, gsize);
				showtitels(1);
				for (int i = 0; i < gsize; i++) {
					goodsarr[i].showgoods();
					std::cout << std::endl;
				}
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
				break;
			}
			break;
		}
		case 2: {
			std::cout << "Vyberit' sortuvannya" << std::endl;
			std::cout << "1- KOD ZROST" << std::endl;
			std::cout << "2- KOD SPAD" << std::endl;
			std::cout << "9-VYHID" << std::endl;
			while (true) {
				std::cin >> ll;
				if (std::cin.good() and (ll > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (ll) {
			case 1: {
				providersortidup(provarr, psize);
				showtitels(2);
				for (int i = 0; i < psize; i++) {
					provarr[i].showprovider();
					std::cout << std::endl;
				}
				break;
			}
			case 2: {
				providersortiddown(provarr, psize);
				showtitels(2);
				for (int i = 0; i < psize; i++) {
					provarr[i].showprovider();
					std::cout << std::endl;
				}
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default:std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
				break;
			}
			break;
		}
		case 3: {
			std::cout << "Vyberit' sortuvannya" << std::endl;
			std::cout << "1- KOD PRODAJU ZROST" << std::endl;
			std::cout << "2- KOD PRODAJUSPAD" << std::endl;
			std::cout << "3- DATA PRODAJU ZROST" << std::endl;
			std::cout << "4- DATA PRODAJU SPAD" << std::endl;
			std::cout << "5- KIL'KIST' ZROST" << std::endl;
			std::cout << "6- KIL'KIST' SPAD" << std::endl;
			std::cout << "7-ROZDRIBNA CINA ZROST" << std::endl;
			std::cout << "8-ROZDRIBNA CINA SPAD" << std::endl;
			std::cout << "10- KOD TOVARU ZROST" << std::endl;
			std::cout << "11- KOD TOVARU SPAD" << std::endl;
			std::cout << "9- VYHID" << std::endl;
			while (true) {
				std::cin >> mm;
				if (std::cin.good() and (mm > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (mm) {
			case 1: {
				salessortidup(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 2: {
				salessortiddown(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 3: {
				salessortdateup(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 4: {
				salessortdatedown(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 5: {
				salessortamountup(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 6: {
				salessortamountdown(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 7: {
				salessortpriceup(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 8: {
				salessortpricedown(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 10: {
				salessortgidup(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 11: {
				salessortgiddown(salesarr, ssize);
				showtitels(3);
				for (int i = 0; i < ssize; i++) {
					salesarr[i].showsales();
					std::cout << std::endl;
				}
				break;
			}
			case 9: {
				exit(1);
				break;
			}
			default:std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
				break;
			} break;
		}
		case 4: {
			std::cout << "1-KOD TOVARU ZROST" << std::endl;
			std::cout << "2-KOD TOVARU SPAD" << std::endl;
			std::cout << "3-KOD POSTACHAL'NYKA ZROST" << std::endl;
			std::cout << "4-KOD POSTACHAL'NYKA SPAD" << std::endl;
			std::cout << "9-VYHID" << std::endl;
			while (true) {
				std::cin >> nn;
				if (std::cin.good() and (nn > 0)) {
					std::cin.ignore(10, '\n');
					break;
				}
				std::cin.clear();
				std::cout << "Vvedit' korektni dani\n";
				std::cin.ignore(10, '\n');
			}
			switch (nn) {
			case 1: {
				consortgidup(conarr, csize);
				showtitels(4);
				for (int i = 0; i < csize; i++) {
					conarr[i].showcon();
					std::cout << std::endl;
				}
				break;
			}
			case 2: {
				consortgiddown(conarr, csize);
				showtitels(4);
				for (int i = 0; i < csize; i++) {
					conarr[i].showcon();
					std::cout << std::endl;
				}
				break;
			}
			case 3: {
				consortpidup(conarr, csize);
				showtitels(4);
				for (int i = 0; i < csize; i++) {
					conarr[i].showcon();
					std::cout << std::endl;
				}
				break;
			}
			case 4: {
				consortpiddown(conarr, csize);
				showtitels(4);
				for (int i = 0; i < csize; i++) {
					conarr[i].showcon();
					std::cout << std::endl;
				}
				break;
			}
			default: std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
				break;
			}
		}
		default:std::cout << "TAKOI FUNKCII NE PEREDBACHENO\n";
			break;
		}
		break;
	}
	case 9: {
		exit(1);
		break;
	}
	default: {
		std::cout << "Takoi funkcii ne peredbacheno" << std::endl;
	}
	}
}
	  delete[] conarr;
	  delete[] salesarr;
	  delete[] sdatearr;
	  delete[] provarr;
	  delete[] paddressarr;
	  delete[] goodsarr;
	  delete[] rdatearr;
}
