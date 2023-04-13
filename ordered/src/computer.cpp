#include"computer.h"

Computer::Computer()
{}

Computer::Computer(int id,int col)
	:id(id),colum(col)
{}

void Computer::display()
{
	std::cout << "机房编号： " << id << " 机房容量： " << colum << std::endl;
}
