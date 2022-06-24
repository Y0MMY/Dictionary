#include <iostream>
#include <map>
#include "Dictionary.h"



int main()
{
	Dictionary<int, std::string> dic;
	dic.set(0, "First string");
	dic.set(1, "Second string");
	try
	{
		std::cout << dic.get(0) << std::endl;
		std::cout << dic.is_set(1) << std::endl;
		std::cout << dic.get(2) << std::endl;
	}
	catch (const KeyNotFoundException<int> &e)
	{
		std::cout << "Error Code: " << e.GetKey() << std::endl;
		std::cout << "Description: " << e.what() << std::endl;
	}
    return 0;
}