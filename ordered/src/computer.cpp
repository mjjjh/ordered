#include"computer.h"

Computer::Computer()
{}

Computer::Computer(int id,int col)
	:id(id),colum(col)
{}

void Computer::display()
{
	std::cout << "������ţ� " << id << " ���������� " << colum << std::endl;
}
