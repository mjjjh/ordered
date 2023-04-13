#pragma once

#include "identity.h"
#include "order.h"

class Student :public Identity
{
public:
	int id;
	std::vector<Computer> coms;
public:
	Student();

	Student(int id, std::string name, std::string password);

	//²Ëµ¥
	virtual void menu() override;

	//apply
	void applyOrder();

	//watch
	void showMyOrder();

	//show all
	void showAllOrder();

	//cancel
	void cancelOrder();

private:
	void InitVector();
	bool checkExit(int room);
};