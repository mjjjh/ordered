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
	std::cout << "��ǰѧ����Ϊ��" << Vst.size() << std::endl;
	std::cout << "��ǰ��ʦ��Ϊ��" << Vte.size() << std::endl;
	std::cout << "\t\t ��ӭ����Ա"<<m_name<<"��¼\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------1 ����˻�-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------2 �鿴�˺�-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------3 �鿴����-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------4 ���ԤԼ-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------0 ע����¼-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t -------------------------\n";
	std::cout << "�����ָ�" << std::endl;
}

void Admin::addAccount()
{
	std::cout << "����˺�\n";
	std::cout << "����������˺�����\n";
	std::cout << "1.���ѧ��\n";
	std::cout << "2.�����ʦ\n";

	std::string filename;
	std::string tips,errorrepeat;

	int select = 0;
	while (true)
	{
		std::cin >> select;
		if (select == 1)
		{
			filename = STUDENT_FILE;
			tips = "������ѧ��ѧ�ţ�\n";
			errorrepeat = "ѧ��ѧ���ظ���������\n";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tips = "��������ʦְ�����\n";
			errorrepeat = "��ʦְ������ظ���������\n";
			break;
		}
		else
		{
			std::cout << "��������ȷ��ָ��\n";
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
	
	std::cout << "������������\n";
	std::cin >> name;
	std::cout << "����������\n";
	std::cin >> password;

	ofs.open(filename,std::ios::out|std::ios::app);
	ofs << id << " " << name << " " << password << std::endl;

	if (select == 1) Vst.emplace_back(id, name, password);
	else Vte.emplace_back(id, name, password);

	std::cout << "��ӳɹ�\n";
	ofs.close();

	system("pause");
}

void Admin::showAccount()
{
	std::cout << "�鿴�˺�\n";
	std::cout << "��ѡ��鿴����:\n";
	std::cout << "1.�鿴����ѧ��\n";
	std::cout << "2.�鿴������ʦ\n";

	int select = 0;

	std::cin >> select;
	if (select == 1)
	{
		std::cout << "����ѧ����Ϣ���£�\n";
		for (Student stu : Vst)
		{
			std::cout << "ѧ�ţ�" << stu.id << "\t������" << stu.m_name << "\t���룺" << stu.m_password << std::endl;
		}
	}
	else
	{
		std::cout << "������ʦ��Ϣ���£�\n";
		for (Teacher tea : Vte)
		{
			std::cout << "��ְ���ţ�" << tea.m_EmpId << "\t������" << tea.m_name << "\t���룺" << tea.m_password << std::endl;
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
		std::cout << "\t\t|--------1 �鿴����-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------2 �޸�����-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------3 ���ӻ���-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------4 ɾ������-------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t|--------0 ����-----------|\n";
		std::cout << "\t\t|                         |\n";
		std::cout << "\t\t -------------------------\n";
		std::cout << "�����ָ�" << std::endl;

		int select;
		std::cin >> select;
		bool out = Computeroption(select);
		if (out) break;
	}
	system("pause");
}



//ѡ���������
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
		std::cout << "��ǰӵ�еĻ�����Ϣ����:\n";
		for (Computer c : com)
			c.display();
		int index,num;
		std::cout << "�������޸ĵĻ�����ţ�\n";
		std::cin >> index;
		while (!checkComId(index))
		{
			std::cout << "û�е�ǰ������ţ������䣺\n";
			std::cin >> index;
		}
		std::cout << "�������޸ĵ�������\n";
		std::cin >> num;
		writetocom(com, index, num,2);
		std::cout << "�޸ĳɹ�\n";
		system("pause");
		break;
	}
	case 3:
	{
		int index, num;
		std::cout << "�����������ţ�\n";
		std::cin >> index;
		while (checkComId(index))
		{
			std::cout << "���е�ǰ������Ϣ,���������룺\n";
			std::cin >> index;
		}
		std::cout << "���������������\n";
		std::cin >> num;
		com.emplace_back(index, num);
		writetocom(com,index,num,3);
		std::cout << "���ӳɹ�\n";
		system("pause");
		break;
	}
	case 4:
	{
		std::cout << "��ǰӵ�еĻ�����Ϣ����:\n";
		for (Computer c : com)
			c.display();
		int index;
		std::cout << "������ɾ���Ļ�����ţ�\n";
		std::cin >> index;
		while (!checkComId(index))
		{
			std::cout << "û�е�ǰ������ţ������䣺\n";
			std::cin >> index;
		}

		writetocom(com, index, 0, 4);
		std::cout << "�޸ĳɹ�\n";
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
	std::cout << "���ԤԼ\n";
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);
	std::cout << "��ճɹ�\n";
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

	//ѧ���ļ�
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

	//��ʦ�ļ�
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

	//�����ļ�
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