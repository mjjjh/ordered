#pragma once
#include "pch.h"
#include "globalFile.h"
#include"computer.h"

//basic class
class Identity
{
public:
	//�˵�
	virtual void menu() = 0;

public:
	//��ͬԪ��
	std::string m_password;
	std::string m_name;
};