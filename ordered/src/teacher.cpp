#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int Empid, std::string name, std::string password)
	:m_EmpId(Empid)
{
	m_name = name;
	m_password = password;
}

void Teacher::menu()
{
	std::cout << "\t\t ��ӭ��ʦ" << m_name << "��¼\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------1 �鿴����ԤԼ---|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------2 ���ԤԼ-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------0 ע����¼-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t -------------------------\n";
	std::cout << "�����ָ�" << std::endl;
}

void Teacher::showAllOrder()
{
	Order ors;
	ors.showall();
	system("pause");

}

void Teacher::ExamineOrder()
{
	Order ors;
	ors.exam();
	system("pause");
}