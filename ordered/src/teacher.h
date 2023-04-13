#pragma once
#include "identity.h"
#include "order.h"

class Teacher :public Identity
{
public:
	int m_EmpId;

public:
	Teacher();
	
	Teacher(int Empid, std::string name, std::string password);

	void menu() override;

	void showAllOrder();

	void ExamineOrder();

};