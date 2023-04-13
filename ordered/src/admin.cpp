#include"admin.h"

void writetocom(std::vector<Computer>& coms, int id, int num, int type);
Admin::Admin()
{}

Admin::Admin(std::string name, std::string password)
{
	m_name = name;
	m_password = password;
	init_vector();
}

void Admin::menu()
{
	std::cout << "当前学生数为：" << Vst.size() << std::endl;
	std::cout << "当前老师数为：" << Vte.size() << std::endl;
	std::cout << "\t\t 欢迎管理员"<<m_name<<"登录\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------1 添加账户-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------2 查看账号-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------3 查看机房-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------4 清空预约-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------0 注销登录-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t -------------------------\n";
	std::cout << "请输出指令：" << std::endl;
}

void Admin::addAccount()
{
	std::cout << "添加账号\n";
	std::cout << "请输入添加账号类型\n";
	std::cout << "1.添加学生\n";
	std::cout << "2.添加老师\n";

	std::string filename;
	std::string tips,errorrepeat;

	int select = 0;
	while (true)
	{
		std::cin >> select;
		if (select == 1)
		{
			filename = STUDENT_FILE;
			tips = "请输入学生学号：\n";
			errorrepeat = "学生学号重复，请重输\n";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tips = "请输入老师职工编号\n";
			errorrepeat = "老师职工编号重复，请重输\n";
			break;
		}
		else
		{
			std::cout << "请输入正确的指令\n";
		}

	}

	std::ofstream ofs;
	int id;
	std::string  name, password;

	std::cout << tips;
	while (true)
	{
		std::cin >> id;
		bool flag = checkRepeat(id, select);
		if (flag) break;
		std::cout << errorrepeat;
	}
	
	std::cout << "请输入姓名：\n";
	std::cin >> name;
	std::cout << "请输入密码\n";
	std::cin >> password;

	ofs.open(filename,std::ios::out|std::ios::app);
	ofs << id << " " << name << " " << password << std::endl;

	if (select == 1) Vst.emplace_back(id, name, password);
	else Vte.emplace_back(id, name, password);

	std::cout << "添加成功\n";
	ofs.close();

	system("pause");
}

void Admin::showAccount()
{
	std::cout << "查看账号\n";
	std::cout << "请选择查看内容:\n";
	std::cout << "1.查看所有学生\n";
	std::cout << "2.查看所有老师\n";

	int select = 0;

	std::cin >> select;
	if (select == 1)
	{
		std::cout << "所有学生信息如下：\n";
		for (Student stu : Vst)
		{
			std::cout << "学号：" << stu.id << "\t姓名：" << stu.m_name << "\t密码：" << stu.m_password << std::endl;
		}
	}
	else
	{
		std::cout << "所有老师信息如下：\n";
		for (Teacher tea : Vte)
		{
			std::cout << "教职工号：" << tea.m_EmpId << "\t姓名：" << tea.m_name << "\t密码：" << tea.m_password << std::endl;
		}
	}
	system("pause");
}

void Admin::showComputer()
{
	while (true)
	{
		system("cls");
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------1 查看机房-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------2 修改数据-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------3 增加机房-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------4 删除机房-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------0 返回-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t -------------------------\n";
		std::cout << "请输出指令：" << std::endl;

		int select;
		std::cin >> select;
		bool out = Computeroption(select);
		if (out) break;
	}
	system("pause");
}



//选择机房操作
bool Admin::Computeroption(int select)
{
	switch (select)
	{
	case 1:
		for (Computer c : com)
			c.display();
		system("pause");
		break;
	case 2:
	{
		std::cout << "当前拥有的机房信息如下:\n";
		for (Computer c : com)
			c.display();
		int index,num;
		std::cout << "请输入修改的机房编号：\n";
		std::cin >> index;
		while (!checkComId(index))
		{
			std::cout << "没有当前机房编号，请重输：\n";
			std::cin >> index;
		}
		std::cout << "请输入修改的容量：\n";
		std::cin >> num;
		writetocom(com, index, num,2);
		std::cout << "修改成功\n";
		system("pause");
		break;
	}
	case 3:
	{
		int index, num;
		std::cout << "请输入机房编号：\n";
		std::cin >> index;
		while (checkComId(index))
		{
			std::cout << "已有当前机房信息,请重新输入：\n";
			std::cin >> index;
		}
		std::cout << "请输入机房容量：\n";
		std::cin >> num;
		com.emplace_back(index, num);
		writetocom(com,index,num,3);
		std::cout << "增加成功\n";
		system("pause");
		break;
	}
	case 4:
	{
		std::cout << "当前拥有的机房信息如下:\n";
		for (Computer c : com)
			c.display();
		int index;
		std::cout << "请输入删除的机房编号：\n";
		std::cin >> index;
		while (!checkComId(index))
		{
			std::cout << "没有当前机房编号，请重输：\n";
			std::cin >> index;
		}

		writetocom(com, index, 0, 4);
		std::cout << "修改成功\n";
		system("pause");
		break;
	}
	case 0:
		return true;
	default:
		break;
	}
	return false;
}


void Admin::ClearOrder()
{
	std::cout << "清空预约\n";
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);
	std::cout << "清空成功\n";
	system("pause");
}


void Admin::init_vector()
{
	Vst.clear();
	Vte.clear();
	com.clear();

	std::ifstream ifs;

	int id;
	std::string name, pass;

	//学生文件
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::ofstream ofs(STUDENT_FILE);

		ofs.close();
	}


	while (ifs>>id && ifs>>name && ifs>>pass)
	{
		Vst.emplace_back(id,name,pass);
	}

	ifs.close();

	//老师文件
	ifs.open(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::ofstream ofs;
		ofs.open(TEACHER_FILE);
		ofs.close();
	}
	while (ifs >> id && ifs >> name && ifs >> pass)
	{
		Vte.emplace_back(id, name, pass);
	}
	ifs.close();

	//机房文件
	int num;
	ifs.open(COMPUTER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::ofstream ofs;
		ofs.open(COMPUTER_FILE);
		ofs.close();
	}
	while (ifs >> id && ifs >> num)
	{
		com.emplace_back(id, num);
	}
	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (Student stu : Vst)
			if (id == stu.id)
				return false;
	}
	else
	{
		for (Teacher tea : Vte)
			if (id == tea.m_EmpId)
				return false;
	}
	return true;
}


bool Admin::checkComId(int index)
{
	for (Computer c : com)
	{
		if (c.id == index)
			return true;
	}
	return false;
}


void writetocom(std::vector<Computer>& coms, int id, int num, int type)
{
	std::ofstream ofs;
	if (type == 3)
	{
		ofs.open(COMPUTER_FILE, std::ios::app);
		ofs << id << " " << num << std::endl;
	}
	else if (type == 2)
	{
		ofs.open(COMPUTER_FILE, std::ios::out);
		for (Computer& c : coms)
		{
			if (c.id == id) c.colum = num;
			ofs << c.id << " " << c.colum << std::endl;
		}
	}
	else
	{
		ofs.open(COMPUTER_FILE, std::ios::out);
		for (auto it = coms.begin(); it != coms.end(); it++)
		{
			if (id == it->id)
			{
				coms.erase(it);
				break;
			}
		}
		for (Computer& c : coms)
		{
			ofs << c.id << " " << c.colum << std::endl;
		}
	}
}