#pragma once
#include<fstream>
#include<vector>
#include<memory>
#include"Distance.h"



class DistanceMatrix
{
private:
	int mV;														// no of edges		 
	int mE;														// no of vertices
	std::vector <std::vector<Distance>>mDistMatrix;				// Distance Matrix
	std::vector<std::vector<int>> mNext;						// vector for storing


	std::string getPath(int i, int j);							// recursive formula for getting path

public:
	DistanceMatrix() = default;
	virtual ~DistanceMatrix() = default;

	bool floyd_warshall();
	void printMatrix() const;
	void showmNext() const;





	friend std::istream& operator >> (std::istream& is, DistanceMatrix& d);
	friend std::ostream& operator<<(std::ostream& os, DistanceMatrix& d);
};

