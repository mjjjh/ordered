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

//�˵�
void Student::menu()
{
	std::cout << "\t\t ��ӭѧ��" << m_name << "��¼\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------1 ����ԤԼ-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------2 �鿴�ҵ�ԤԼ---|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------3 �鿴����ԤԼ---|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------4 ȡ��ԤԼ-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t|--------0 ע����¼-------|\n";
	std::cout << "\t\t|                         |\n";
	std::cout << "\t\t -------------------------\n";
	std::cout << "�����ָ�" << std::endl;
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

//����
void Student::applyOrder()
{
	using std::cout;
	using std::cin;
	
	int day, half, room;

	cout << "��������ʱ��Ϊ��һ������\n";
	cout << "������ԤԼʱ��\n";
	cout << "1.��һ\n";
	cout << "2.�ܶ�\n";
	cout << "3.����\n";
	cout << "4.����\n";
	cout << "5.����\n";

	cin >> day;
	while (day < 1 && day>5)
	{
		cout << "��ѡ����ȷ��ʱ��\n";
		cin >> day;
	}
	cout << "������ԤԼ��ʱ���\n";
	cout << "1.����\n";
	cout << "2.����\n";
	cin >> half;
	while (half != 1 && half != 2)
	{
		cout << "��������ȷ��ʱ���\n";
		cin >> half;
	}

	cout << "��ѡ�����\n";
	for (Computer c : coms)
		c.display();
	cin >> room;
	while (checkExit(room))
	{
		cout << "��������ȷ�Ļ���:\n";
		cin >> room;
	}

	cout << "ԤԼ�ɹ�������С�\n";

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

//�鿴ԤԼ
void Student::showMyOrder()
{
	Order ors;
	ors.showone(id);
	system("pause");

}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	Order ors;
	ors.showall();
	system("pause");
}

//ȡ��ԤԼ
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
