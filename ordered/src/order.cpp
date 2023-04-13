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
		std::cout << "无预约记录\n";
		return;
	}
	int index = 0;
	for (std::map<int, std::map<std::string, std::string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		if (std::stoi(it->second["stuId"]) == id)
		{
			std::cout << "预约日期：周" << it->second["date"];
			std::cout << "\t时段：" << (it->second["interval"] == "1" ? "上午" : "下午");
			std::cout << "\t机房：" << it->second["roomId"];
			std::cout << "\t状态：" << (it->second["status"] == "1" ? "审核中" : (it->second["status"] == "2" ? "预约成功" : (it->second["status"] == "-1" ? "预约取消":"审核未通过，预约失败")));
			std::cout << std::endl;
		}
	}
}


void Order::showall()
{
	if (m_Size == 0)
	{
		std::cout << "无预约记录\n";
		return;
	}
	for (std::map<int, std::map<std::string, std::string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		std::cout << "第" << it->first << "记录：";
		std::cout << "\t预约日期：周" << it->second["date"];
		std::cout << "\t时段：" << (it->second["interval"] == "1" ? "上午" : "下午");
		std::cout << "\t学号：" << it->second["stuId"];
		std::cout << "\t姓名：" << it->second["stuName"];
		std::cout << "\t机房：" << it->second["roomId"];
		std::cout << "\t状态：" << (it->second["status"] == "1" ? "审核中" : (it->second["status"] == "2" ? "预约成功" :(it->second["status"] == "-1" ? "预约取消": "审核未通过，预约失败")));
		std::cout << std::endl;
	}
}



void Order::cancel(int id)
{
	if (m_Size == 0)
	{
		std::cout << "无预约记录\n";
		return;
	}
	std::cout << "审核中或预约成功的记录可以取消\n";
	
	std::vector<int> v;

	int index = 0;
	for (int i = 0;i<m_orderData.size();i++)
	{
		if (std::stoi(m_orderData[i]["stuId"]) == id)
		{
			if (m_orderData[i]["status"] == "1" || m_orderData[i]["status"] == "2")
			{
				v.emplace_back(i);
				std::cout << "编号：" << index++;
				std::cout << "\t预约日期：周" << m_orderData[i]["date"];
				std::cout << "\t时段：" << (m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				std::cout << "\t机房：" << m_orderData[i]["roomId"];
				std::cout << "\t状态：" << (m_orderData[i]["status"] == "1" ? "审核中" : (m_orderData[i]["status"] == "2" ? "预约成功" : (m_orderData[i]["status"] == "-1"?"预约取消": "审核未通过，预约失败")));
				std::cout << std::endl;
			}
		}
	}
	if (!index)
	{
		std::cout << "暂无可以取消的记录\n";
		return;
	}
	int select;

	std::cout << "请输入取消预约编号：\n";
	std::cin >> select;
	while (true)
	{
		if (select < index && index >= 0)
		{
			break;
		}
		std::cout << "请输入正确编号：\n";
		std::cin >> select;
	}

	m_orderData[v[select]]["status"] = "-1";
	updateOrder();
	std::cout << "取消成功\n";
}


void Order::exam()
{
	if (m_Size == 0)
	{
		std::cout << "无预约记录\n";
		return;
	}
	int index = 0;
	std::vector<int> x;
	for (int i = 0; i < m_orderData.size(); i++)
	{
		if (m_orderData[i]["status"] == "1")
		{
			x.emplace_back(i);
			std::cout << "编号：" << index++;
			std::cout << "\t预约日期：周" << m_orderData[i]["date"];
			std::cout << "\t时段：" << (m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			std::cout << "\t学号：" << m_orderData[i]["stuId"];
			std::cout << "\t姓名：" << m_orderData[i]["stuName"];
			std::cout << "\t机房：" << m_orderData[i]["roomId"];
			std::cout << "\t状态：" << (m_orderData[i]["status"] == "1" ? "审核中" :"出错");
			std::cout << std::endl;
		}
	}
	if (!index)
	{
		std::cout << "无待审核记录\n";
		return;
	}
		

	int select;
	std::cout << "请输入审核编号\n";
	std::cin >> select;
	while (true)
	{
		if (select < index && select >= 0)
		{
			break;
		}
		std::cout << "请重新输入编号\n";
		std::cin >> select;
	}

	int check;
	std::cout << "请输入审核结果：\n";
	std::cout << "0.通过\n";
	std::cout << "1.不通过\n";
	std::cin >> check;
	while (true)
	{
		if (check == 0 || check == 1)
			break;
		std::cout << "请输入正确的指令：\n";
		std::cin >> check;
	}

	m_orderData[x[select]]["status"] = (check == 0 ? "2" : "0");
	updateOrder();
	std::cout << "审核成功\n";
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