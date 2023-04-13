#include "pch.h"




#include "identity.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"


#define Log(x) std::cout<<x<<std::endl


void ManagerMenu(Identity*& admin);
void StudentMenu(Identity*& student);
void TeacherMenu(Identity*& teacher);


//登录
void Login(const std::string& Filename, int type)
{
	Identity* identity = nullptr;

	//读文件
	std::ifstream ifs;
	ifs.open(Filename);

	//没有文件则直接创建
	if (!ifs.is_open())
	{
		std::ofstream ofs(Filename);

		ofs.close();
		
	}

	int id;
	std::string name,password;

	if (type == 1)
	{
		Log("请输入你的学号：");
		std::cin >> id;
	}
	else if (type == 2)
	{
		Log("请输入您的职工号：");
		std::cin >> id;
	}
	
	Log("请输入姓名：");
	std::cin >> name;
	Log("请输入密码");
	std::cin >> password;

	if (type == 1)
	{
		int fid;
		std::string fname, fpasspword;
		while (ifs >> fid && ifs >> fname && ifs >> fpasspword)
		{
			if (fid == id && fname == name && fpasspword == password)
			{
				Log("学生登录成功");
				system("pause");
				system("cls");
				identity = new Student(id, name, password);
				StudentMenu(identity);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fid;
		std::string fname, fpasspword;
		while (ifs >> fid && ifs >> fname && ifs >> fpasspword)
		{
			if (fid == id && fname == name && fpasspword == password)
			{
				Log("教职工登录成功");
				system("pause");
				system("cls");
				identity = new Teacher(id, name, password);
				TeacherMenu(identity);
				return;
			}
		}
	}
	//管理验证
	else
	{
		std::string fname, fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				Log("管理者登录成功");
				system("pause");
				system("cls");
				identity = new Admin(name, password);
				ManagerMenu(identity);
				return;
			}
		}

	}

	ifs.close();

	Log("登录出错");
	system("pause");
	system("cls");


}

//管理界面
void ManagerMenu(Identity*& admin)
{
	int select;
	Admin* ad = (Admin*)admin;

	while (true)
	{
		system("cls");
		ad->menu();
		std::cin >> select;
		switch (select)
		{
		case 1:
			ad->addAccount();
			break;
		case 2:
			ad->showAccount();
			break;
		case 3:
			ad->showComputer();
			break;
		case 4:
			ad->ClearOrder();
			break;
		case 0:
			delete ad;
			Log("退出成功");
			system("pause");
			return;
		default:
			Log("请输入正确指令");
			break;
		}
	}

}


//学生界面
void StudentMenu(Identity*& student)
{
	int select;
	Student* stu = (Student*)student;
	
	while (true)
	{
		system("cls");
		stu->menu();
		std::cin >> select;
		switch (select)
		{
		case 1:
			stu->applyOrder();
			break;
		case 2:
			stu->showMyOrder();
			break;
		case 3:
			stu->showAllOrder();
			break;
		case 4:
			stu->cancelOrder();
			break;
		case 0:
			delete stu;
			Log("退出成功");
			system("pause");
			return;
		default:
			Log("请输入正确的指令");
			break;
		}

	}

}

//老师界面
void TeacherMenu(Identity*& teacher)
{
	int select;
	Teacher* tea = (Teacher*)teacher;

	while (true)
	{
		system("cls");
		tea->menu();
		std::cin >> select;
		switch (select)
		{
		case 1:
			tea->showAllOrder();
			break;
		case 2:
			tea->ExamineOrder();
			break;
		case 0:
			delete tea;
			Log("退出成功");
			system("pause");
			return;
		default:
			Log("请输入正确的指令");
			break;
		}

	}

}

int main()
{
	int select;

	while (true)
	{
		system("cls");
		std::cout << "\t\t -------------------------\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------1 学生-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------2 老师-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------3 管理员---------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------0 退出-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t -------------------------\n";
		

		std::cin >> select;

		switch (select)
		{
		case 1:
			Login(STUDENT_FILE, 1);
			break;
		case 2:
			Login(TEACHER_FILE, 2);
			break;
		case 3:
			Login(ADMIN_FILE, 3);
			break;
		case 0:
			std::cout << "退出成功,欢迎下次使用\n";
			system("pause");
			return 0;
		default:
			std::cout << "请输入正确的指令\n";
			system("pause");
			system("cls");
			break;
		}

	}
}