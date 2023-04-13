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
	std::cout << "\t\t 欢迎老师" << m_name << "登录\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------1 查看所有预约---|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------2 审核预约-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------0 注销登录-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t -------------------------\n";
	std::cout << "请输出指令：" << std::endl;
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