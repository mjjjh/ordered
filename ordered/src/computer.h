#pragma once
#include<iostream>

class Computer
{
public:
	int id;
	int colum;
public:
	Computer();
	Computer(int id, int col);
	void display();
};