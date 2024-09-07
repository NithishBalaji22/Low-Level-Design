#pragma once
#include<unordered_map>
#include "Customer.hpp"

class Login
{
public:
	void getCredentials(unordered_map<int,Customer>& db);
	bool authenticateId(int id, unordered_map<int, Customer>& db);
	bool authenticatePass(string original, string entered);
	string decrypt(string password);

	
	void DisplayCustomerDetails(Customer &cus);
	void LoginPage(Customer &cus);
	void DisplayOptions();

	void generateGiftCard(Customer& cus);

	void Purchase(unordered_map<int, Customer>& db);

	void BlockCard(Customer& cus);

	void TopUp(Customer& cus);

	void DisplayHistory(Customer& cus);
};

