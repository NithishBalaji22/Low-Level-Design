#include "Customer.hpp"


int Customer::getCusId() {
	return this->CustId;
}

int Customer::getAccNo() {
	return this->AccountNo;
}

string Customer::getName() {
	return this->Name;
}

float Customer::getBalance() {
	return this->balance;
};

string Customer::getPassword() {
	return this->password;
};


void Customer::updateGiftCardStatus(bool status) {
	this->isgift = status;
}

void Customer::updategiftcard(int& cardNumber, int& PIN, float& amt) {
	this->giftCardNum = cardNumber;
	this->PIN = PIN;
	this->giftbalance = amt;
}


int Customer::getGiftCardNum() {
	return this->giftCardNum;
}

int Customer::getPin() {
	return this->PIN;
}

float Customer::getGiftbalance() {
	return this->giftbalance;
}

void Customer::updateBalance(float amt) {
	this->balance = amt;
}

void Customer::updateGiftBalance(float amt) {
	this->giftbalance = amt;
}

bool Customer::getisgift() {
	return this->isgift;
}

void Customer::updateHistory(float amt, string mode,float final) {
	this->history.push_back({ { amt,mode } ,final});
}

vector<pair<pair<float, string>, float>> Customer::getHistory() {
	return this->history;
}