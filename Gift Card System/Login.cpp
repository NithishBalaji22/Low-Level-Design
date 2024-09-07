#include "Login.hpp"
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void Login::getCredentials(unordered_map<int, Customer>& db) {
	int id;
	string pass;
	cout << "Enter customer id: ";
	cin >> id;

	bool isCus = this->authenticateId(id,db);

	if (isCus) {
		cout << "Enter your Password: ";
		cin >> pass;
		
		string oldPass = db[id].getPassword();

		bool isValidPassword = this->authenticatePass(decrypt(oldPass), pass);

		if (isValidPassword) {
			this->LoginPage(db[id]);
			return;
		}
		else {
			cout << "Incorrect Password!" << endl;
			return;
		}
	}
	else {
		cout << "Customer Not Found!" << endl;
		return;
	}
	return;
}

bool Login::authenticateId(int id, unordered_map<int, Customer>& db) {
	for (auto i : db) {
		if (i.first == id) return true;
	}
	return false;
}

string Login::decrypt(string password) {
	string pass = password;
	for (int i = 0; i < pass.size(); i++) {
		char c = pass[i] - 1;
		pass[i] = c;
	}
	return pass;
}

bool Login::authenticatePass(string original, string entered) {
	return original == entered;
}


void Login::DisplayCustomerDetails(Customer &cus) {
	cout << "Customer Id	: " << cus.getCusId() << endl;
	cout << "Account No	: " << cus.getAccNo() << endl;;
	cout << "Name		: " << cus.getName() << endl;;
	cout << "Balance		: " << cus.getBalance() << endl;;
	
	if (cus.getisgift()) {
		cout << "Card Number	: " << cus.getGiftCardNum() <<endl;
		cout << "Card PIN	: " << cus.getPin() << endl;
		cout << "Gift Balance	: " << cus.getGiftbalance() << endl;
	}
	return;
}

void Login::DisplayOptions() {
	cout << "OPTIONS" << endl;
	cout << "1.Create a new Gift Card" << endl;
	cout << "2.Top Up the existing Card" << endl;
	cout << "3.Show Gift Card Transaction History" << endl;
	cout << "4.Block the existing Card" << endl;
	cout << "5.Logout" << endl;
	return;
}

void Login::LoginPage(Customer &cus) {
	system("cls");
	this->DisplayCustomerDetails(cus);
	cout << "Login Successful !!";
	_getch();

	int choice;
	do {
		system("cls");
		this->DisplayOptions();
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				this->generateGiftCard(cus);
				_getch();
				break;
			case 2:
				this->TopUp(cus);
				_getch();
				break;
			case 3:
				this->DisplayHistory(cus);
				_getch();
				break;
			case 4:
				this->BlockCard(cus);
				_getch();
				break;
			case 5:
				cout << "Logged Out!" << endl;
				return;
				break;
			default:
				cout << "Invalid choice!";
				_getch();
				break;
		}
	} while (1);
	return;
}


void Login::generateGiftCard(Customer& cus) {
	srand(time(nullptr));
	float amount;
	//card number
	int cardNum = rand() % 100000;

	int PIN = rand() % 10000;

	cout << "Enter gift card amount: ";
	cin >> amount;

	if (amount > cus.getBalance()) {
		cout << "Insufficient Balance!";
		return;
	}
	else {
		cus.updateGiftCardStatus(true);

		cus.updategiftcard(cardNum, PIN, amount);

		float UpdatedBalance = cus.getBalance() - amount;

		cus.updateBalance(UpdatedBalance);

		cout << "Gift Card Created Successfully!" << endl;
		cout << "Card Number: " << cus.getGiftCardNum() <<endl;
		cout << "Card PIN: " << cus.getPin() <<endl;
		cus.updateHistory(amount, "Created", amount);
		return;
	}

}


void Login::Purchase(unordered_map<int, Customer>& db) {
	int bill,cardNo,PIN;
	cout << "Enter Bill Amount	: ";
	cin >> bill;
	cout << "Enter your card Number	: ";
	cin >> cardNo;

	int cusId;
	bool flag = true;

	for (auto i : db) {
		if (i.second.getGiftCardNum() == cardNo) {
			cusId = i.first;
			flag = false;
		}
	}
	if (flag) {
		cout << "Invalid Gift Card!";
		return;
	}
	else {
		cout << "Enter PIN		: ";
		cin >> PIN;

		if (PIN != db[cusId].getPin()) return;

		float availableBalance = db[cusId].getGiftbalance();

		if (bill > availableBalance) {
			cout << "Insufficient Balance!";
			return;
		}
		else {
			float bal = availableBalance - bill;
			db[cusId].updateGiftBalance(bal);
			
			//transaction update
			db[cusId].updateHistory(bill, "Purchase", bal);

			cout << "Available Balance	: " << bal;
			return;
		}

	}

}


void Login::BlockCard(Customer& cus) {
	float amt = cus.getGiftbalance();
	float tot = cus.getBalance() + amt;
	cus.updateBalance(tot);
	cus.updateGiftCardStatus(false);
	cus.updateGiftBalance(0.0);

	cout << "Card Blocked Successfully!";
	cus.updateHistory(amt, "Blocked", 0.0);
	return;
}

void Login::TopUp(Customer& cus) {
	float amt;
	if (!cus.getisgift()) {
		cout << "Create a card to Top up!" << endl;
		return;
	}
	cout << "Enter top Up amount: ";
	cin >> amt;

	if (amt > cus.getBalance()) {
		cout << "Insufficient Balance";
		return;
	}
	float tot = amt + cus.getGiftbalance();
	cus.updateGiftBalance(tot);

	cus.updateBalance(cus.getBalance() - amt);
	cus.updateHistory(amt, "Top Up", tot);
	cout << "Topup Successful!" << endl;
	return;
}

void Login::DisplayHistory(Customer& cus) {
	vector<pair<pair<float, string>, float>> history;
	history = cus.getHistory();

	if (history.size() == 0) {
		cout << "No Transactions" << endl;
		return;
	}

	cout << setw(30) << left << "Amount(Debited/Credited)" << setw(20) << left << "Mode" << "Total" << endl;

	for (auto i : history) {
		cout << setw(30) << left << i.first.first << setw(20) << left << i.first.second << i.second <<endl;
	}
	return;
}