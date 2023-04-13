#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<regex>

class Order
{
private:
	int m_Size;
	std::map<int, std::map<std::string, std::string>> m_orderData;
 
public:
	Order();
	void updateOrder();
	void showone(int id);
	void showall();
	void cancel(int id);
	void exam();
};