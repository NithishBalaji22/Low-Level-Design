#include<bits/stdc++.h>
using namespace std;
#include<conio.h>
#include<Windows.h>


#include "Customer.hpp"
#include "Login.hpp"

unordered_map<int, Customer> db;
void initializeDB() {
	Customer c1(11, 110110, "Kumar", 10000, "AplpNbjm");
	db.insert({ 11,c1 });

	Customer c2(22, 220220, "Mathu", 20000, "Cboljoh");
	db.insert({ 22,c2 });

	Customer c3(33, 330330, "Robin", 30000, "kbwb22");
	db.insert({ 33,c3 });

}

void displayOptions() {
	cout << "OPTIONS" << endl;
	cout << "1.Account Login" << endl;
	cout << "2.Purchase" << endl;
	cout << "3.Exit" << endl;
}

int main() {
	initializeDB();
	Customer c;
	int choice;
	do {
		system("cls");
		displayOptions();
		cout << "Enter you choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				Login l;
				l.getCredentials(db);
				_getch();
				break;
			
			case 2:
				Login l1;
				l1.Purchase(db);
				_getch();
				break;

			case 3:
				cout << "Thank you!" << endl;
				Sleep(1000);
				exit(0);

			default:
				cout << "Invalid choice!" << endl;
				_getch();
				break;
		}
	} while (1);

}



