#pragma once
#include "pch.h"
#include "globalFile.h"
#include"computer.h"

//basic class
class Identity
{
public:
	//菜单
	virtual void menu() = 0;

public:
	//相同元素
	std::string m_password;
	std::string m_name;
};