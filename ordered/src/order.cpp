#include"order.h"
#include "globalFile.h"

std::pair<std::string, std::string> get(const std::string& str);


Order::Order()
{
	std::ifstream ifs;
	std::string data;
	std::string interval;
	std::string stuId;
	std::string stuName;
	std::string roomId;
	std::string status;

	ifs.open(ORDER_FILE, std::ios::in);
	m_Size = 0;

	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs>>status)
	{
		std::map<std::string, std::string> m;
		
		m.insert(get(data));
;		m.insert(get(interval));
		m.insert(get(stuId));
		m.insert(get(stuName));
		m.insert(get(roomId));
		m.insert(get(status));

		m_orderData.insert(std::make_pair(m_Size++, m));
	}
	ifs.close();
}

void Order::updateOrder()
{
	if (m_Size == 0)
		return;
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::out | std::ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << m_orderData[i]["date"] << " ";
		ofs << "interval:" << m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << m_orderData[i]["roomId"] << " ";
		ofs << "status:" << m_orderData[i]["status"] << std::endl;
	}
	ofs.close();
}

void Order::showone(int id)
{
	if (m_Size == 0)
	{
		std::cout << "��ԤԼ��¼\n";
		return;
	}
	int index = 0;
	for (std::map<int, std::map<std::string, std::string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		if (std::stoi(it->second["stuId"]) == id)
		{
			std::cout << "ԤԼ���ڣ���" << it->second["date"];
			std::cout << "\tʱ�Σ�" << (it->second["interval"] == "1" ? "����" : "����");
			std::cout << "\t������" << it->second["roomId"];
			std::cout << "\t״̬��" << (it->second["status"] == "1" ? "�����" : (it->second["status"] == "2" ? "ԤԼ�ɹ�" : (it->second["status"] == "-1" ? "ԤԼȡ��":"���δͨ����ԤԼʧ��")));
			std::cout << std::endl;
		}
	}
}


void Order::showall()
{
	if (m_Size == 0)
	{
		std::cout << "��ԤԼ��¼\n";
		return;
	}
	for (std::map<int, std::map<std::string, std::string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		std::cout << "��" << it->first << "��¼��";
		std::cout << "\tԤԼ���ڣ���" << it->second["date"];
		std::cout << "\tʱ�Σ�" << (it->second["interval"] == "1" ? "����" : "����");
		std::cout << "\tѧ�ţ�" << it->second["stuId"];
		std::cout << "\t������" << it->second["stuName"];
		std::cout << "\t������" << it->second["roomId"];
		std::cout << "\t״̬��" << (it->second["status"] == "1" ? "�����" : (it->second["status"] == "2" ? "ԤԼ�ɹ�" :(it->second["status"] == "-1" ? "ԤԼȡ��": "���δͨ����ԤԼʧ��")));
		std::cout << std::endl;
	}
}



void Order::cancel(int id)
{
	if (m_Size == 0)
	{
		std::cout << "��ԤԼ��¼\n";
		return;
	}
	std::cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ��\n";
	
	std::vector<int> v;

	int index = 0;
	for (int i = 0;i<m_orderData.size();i++)
	{
		if (std::stoi(m_orderData[i]["stuId"]) == id)
		{
			if (m_orderData[i]["status"] == "1" || m_orderData[i]["status"] == "2")
			{
				v.emplace_back(i);
				std::cout << "��ţ�" << index++;
				std::cout << "\tԤԼ���ڣ���" << m_orderData[i]["date"];
				std::cout << "\tʱ�Σ�" << (m_orderData[i]["interval"] == "1" ? "����" : "����");
				std::cout << "\t������" << m_orderData[i]["roomId"];
				std::cout << "\t״̬��" << (m_orderData[i]["status"] == "1" ? "�����" : (m_orderData[i]["status"] == "2" ? "ԤԼ�ɹ�" : (m_orderData[i]["status"] == "-1"?"ԤԼȡ��": "���δͨ����ԤԼʧ��")));
				std::cout << std::endl;
			}
		}
	}
	if (!index)
	{
		std::cout << "���޿���ȡ���ļ�¼\n";
		return;
	}
	int select;

	std::cout << "������ȡ��ԤԼ��ţ�\n";
	std::cin >> select;
	while (true)
	{
		if (select < index && index >= 0)
		{
			break;
		}
		std::cout << "��������ȷ��ţ�\n";
		std::cin >> select;
	}

	m_orderData[v[select]]["status"] = "-1";
	updateOrder();
	std::cout << "ȡ���ɹ�\n";
}


void Order::exam()
{
	if (m_Size == 0)
	{
		std::cout << "��ԤԼ��¼\n";
		return;
	}
	int index = 0;
	std::vector<int> x;
	for (int i = 0; i < m_orderData.size(); i++)
	{
		if (m_orderData[i]["status"] == "1")
		{
			x.emplace_back(i);
			std::cout << "��ţ�" << index++;
			std::cout << "\tԤԼ���ڣ���" << m_orderData[i]["date"];
			std::cout << "\tʱ�Σ�" << (m_orderData[i]["interval"] == "1" ? "����" : "����");
			std::cout << "\tѧ�ţ�" << m_orderData[i]["stuId"];
			std::cout << "\t������" << m_orderData[i]["stuName"];
			std::cout << "\t������" << m_orderData[i]["roomId"];
			std::cout << "\t״̬��" << (m_orderData[i]["status"] == "1" ? "�����" :"����");
			std::cout << std::endl;
		}
	}
	if (!index)
	{
		std::cout << "�޴���˼�¼\n";
		return;
	}
		

	int select;
	std::cout << "��������˱��\n";
	std::cin >> select;
	while (true)
	{
		if (select < index && select >= 0)
		{
			break;
		}
		std::cout << "������������\n";
		std::cin >> select;
	}

	int check;
	std::cout << "��������˽����\n";
	std::cout << "0.ͨ��\n";
	std::cout << "1.��ͨ��\n";
	std::cin >> check;
	while (true)
	{
		if (check == 0 || check == 1)
			break;
		std::cout << "��������ȷ��ָ�\n";
		std::cin >> check;
	}

	m_orderData[x[select]]["status"] = (check == 0 ? "2" : "0");
	updateOrder();
	std::cout << "��˳ɹ�\n";
}


std::pair<std::string, std::string> get(const std::string& str)
{
	std::regex r("(.+):(.+)");
	std::smatch result;
	if (std::regex_search(str, result, r))
	{
		return { result[1],result[2] };
	}
}