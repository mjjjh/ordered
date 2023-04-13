#include "student.h"

Student::Student() 
{}

Student::Student(int id, std::string name, std::string password)
	:id(id)
{
	m_name = name;
	m_password = password;
	InitVector();
}

//菜单
void Student::menu()
{
	std::cout << "\t\t 欢迎学生" << m_name << "登录\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------1 申请预约-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------2 查看我的预约---|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------3 查看所有预约---|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------4 取消预约-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------0 注销登录-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t -------------------------\n";
	std::cout << "请输出指令：" << std::endl;
}


bool Student::checkExit(int room)
{
	for (Computer c : coms)
	{
		if (c.id == room)
			return false;
	}
	return true;
}

//申请
void Student::applyOrder()
{
	using std::cout;
	using std::cin;
	
	int day, half, room;

	cout << "机房开放时间为周一至周五\n";
	cout << "请输入预约时间\n";
	cout << "1.周一\n";
	cout << "2.周二\n";
	cout << "3.周三\n";
	cout << "4.周四\n";
	cout << "5.周五\n";

	cin >> day;
	while (day < 1 && day>5)
	{
		cout << "请选择正确的时间\n";
		cin >> day;
	}
	cout << "请输入预约的时间段\n";
	cout << "1.上午\n";
	cout << "2.下午\n";
	cin >> half;
	while (half != 1 && half != 2)
	{
		cout << "请输入正确的时间段\n";
		cin >> half;
	}

	cout << "请选择机房\n";
	for (Computer c : coms)
		c.display();
	cin >> room;
	while (checkExit(room))
	{
		cout << "请输入正确的机房:\n";
		cin >> room;
	}

	cout << "预约成功，审核中。\n";

	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::app);
	ofs << "date:" << day << " ";
	ofs << "interval:" << half << " ";
	ofs << "stuId:" << id<< " ";
	ofs << "stuName:" << m_name << " ";
	ofs << "roomId:" << room<< " ";
	ofs << "status:" << 1 << std::endl;
	ofs.close();
	system("pause");
}

//查看预约
void Student::showMyOrder()
{
	Order ors;
	ors.showone(id);
	system("pause");

}

//查看所有预约
void Student::showAllOrder()
{
	Order ors;
	ors.showall();
	system("pause");
}

//取消预约
void Student::cancelOrder()
{
	Order ors;
	ors.cancel(id);
	system("pause");
}


void Student::InitVector()
{
	coms.clear();

	std::ifstream ifs;
	ifs.open(COMPUTER_FILE,std::ios::in);
	int id, num;
	while (ifs >> id && ifs >> num)
	{
		coms.emplace_back(id, num);
	}
	ifs.close();
}
