#include "pch.h"




#include "identity.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"


#define Log(x) std::cout<<x<<std::endl


void ManagerMenu(Identity*& admin);
void StudentMenu(Identity*& student);
void TeacherMenu(Identity*& teacher);


//��¼
void Login(const std::string& Filename, int type)
{
	Identity* identity = nullptr;

	//���ļ�
	std::ifstream ifs;
	ifs.open(Filename);

	//û���ļ���ֱ�Ӵ���
	if (!ifs.is_open())
	{
		std::ofstream ofs(Filename);

		ofs.close();
		
	}

	int id;
	std::string name,password;

	if (type == 1)
	{
		Log("���������ѧ�ţ�");
		std::cin >> id;
	}
	else if (type == 2)
	{
		Log("����������ְ���ţ�");
		std::cin >> id;
	}
	
	Log("������������");
	std::cin >> name;
	Log("����������");
	std::cin >> password;

	if (type == 1)
	{
		int fid;
		std::string fname, fpasspword;
		while (ifs >> fid && ifs >> fname && ifs >> fpasspword)
		{
			if (fid == id && fname == name && fpasspword == password)
			{
				Log("ѧ����¼�ɹ�");
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
				Log("��ְ����¼�ɹ�");
				system("pause");
				system("cls");
				identity = new Teacher(id, name, password);
				TeacherMenu(identity);
				return;
			}
		}
	}
	//������֤
	else
	{
		std::string fname, fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				Log("�����ߵ�¼�ɹ�");
				system("pause");
				system("cls");
				identity = new Admin(name, password);
				ManagerMenu(identity);
				return;
			}
		}

	}

	ifs.close();

	Log("��¼����");
	system("pause");
	system("cls");


}

//�������
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
			Log("�˳��ɹ�");
			system("pause");
			return;
		default:
			Log("��������ȷָ��");
			break;
		}
	}

}


//ѧ������
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
			Log("�˳��ɹ�");
			system("pause");
			return;
		default:
			Log("��������ȷ��ָ��");
			break;
		}

	}

}

//��ʦ����
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
			Log("�˳��ɹ�");
			system("pause");
			return;
		default:
			Log("��������ȷ��ָ��");
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
		std::cout << "\t\t|--------1 ѧ��-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------2 ��ʦ-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------3 ����Ա---------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------0 �˳�-----------|\n";
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
			std::cout << "�˳��ɹ�,��ӭ�´�ʹ��\n";
			system("pause");
			return 0;
		default:
			std::cout << "��������ȷ��ָ��\n";
			system("pause");
			system("cls");
			break;
		}

	}
}