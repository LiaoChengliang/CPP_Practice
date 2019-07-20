#include<iostream>
#include<string>
#include"MSystem.h"


int main()
{
	System system;
	while (1)
	{
		system.Operate();
		int option;
		std::cin >> option;
		switch (option)
		{
		case 1:system.Add(); break;
		case 2:system.Show(); break;
		case 3:system.Delete(); break;
		case 4:system.Modify(); break;
		case 5:system.Sort(); break;
		case 6:system.Search(); break;
		case 7:return 0;
		}
	}
	return 0;
}
