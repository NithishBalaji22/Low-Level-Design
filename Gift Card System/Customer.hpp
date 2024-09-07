#pragma once
#include<bits/stdc++.h>
using namespace std;


class Customer
{
private:
	int CustId;
	int AccountNo;
	string Name;
	float balance;
	string password;
	bool isgift = false;
	int giftCardNum = 0;
	int PIN = 0;
	float giftbalance = 0;
	vector<pair<pair<float, string>,float>> history;
	

public:
	Customer() : CustId(0), AccountNo(0), Name(""), balance(0.0), password(""), isgift(false){}

	Customer(int id, int accno, string name, float bal, string pass) : CustId(id), AccountNo(accno), Name(name), balance(bal), password(pass) {}


	//Getter methods
	int getCusId();
	int getAccNo();
	string getName();
	float getBalance();
	string getPassword();
	int getGiftCardNum();
	int getPin();
	float getGiftbalance();
	bool getisgift();
	vector<pair<pair<float, string>, float>> getHistory();

	//Setter methods
	void updateGiftCardStatus(bool status);
	void updategiftcard(int& cardNum, int& PIN, float& amount);
	void updateBalance(float amt);
	void updateGiftBalance(float amt);
	void updateHistory(float amt, string mode,float final);
};

