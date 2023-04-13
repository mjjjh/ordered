#pragma once

#include"identity.h"
#include"student.h"
#include"teacher.h"
class Admin :public Identity
{
public:
	Admin();

	Admin(std::string name,std::string password);

	void menu();

	void addAccount();

	void showAccount();

	void showComputer();

	void ClearOrder();

	void init_vector();

private:
	bool checkRepeat(int id,int type);

	bool Computeroption(int select);

	bool checkComId(int index);
private:
	std::vector<Student> Vst;
	std::vector<Teacher> Vte;

	std::vector<Computer> com;


};