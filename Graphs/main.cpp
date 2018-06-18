#include<iostream>
#include<fstream>
#include"Distance.h"
#include"DistanceMatrix.h"


int main()
{
	DistanceMatrix dm;

	std::string fileName{ "input.txt" };
	std::ifstream inFile(fileName);

	if (!inFile)
	{
		std::cout << "File not found" << std::endl;
		std::cin.get();
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	inFile >> dm;
	//std::cin >> dm;
	inFile.close();

	std::cout << dm;

	dm.floyd_warshall();

	//std::cout << dm;

	std::cin.get();
	std::cin.get();

	return 0;
}