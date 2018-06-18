#include "DistanceMatrix.h"
#include<typeinfo>
#include<iostream>
#include<algorithm>
#include<string>

using DistVec = std::vector<Distance>;

std::istream& operator>>(std::istream& is, DistanceMatrix& d)
{
	int u, v, w, V, E;

	is >> V >> E;

	d.mV = V - 1;
	d.mE = E;

	//is >> u >> v >> w;

	d.mDistMatrix.resize(d.mV, std::vector<Distance>(d.mV));
	d.mNext.resize(d.mV, std::vector<int>(d.mV));

	//for (auto& inner : d.mDistMatrix)
	//	for (auto& i : inner)
	//	{
	//		is >> u >> v >> w;
	//		i.setWeight(w);
	//	}

	for (int i = 0; i<d.mE; ++i)
	{
		is >> u >> v >> w;
		d.mDistMatrix[u - 1][v - 1].setWeight(w);
		d.mNext[u - 1][v - 1] = u - 1;						
	}

	for (int i = 0; i <d.mV; ++i)
	{
		d.mDistMatrix[i][i].setWeight(0);
		d.mNext[i][i] = i;
	}

	//std::cout << "-------" << __FUNCTION__ <<"---------" << std::endl;
	//d.showmNext();
	//std::cout << "----------------" << std::endl;

	return is;

}

std::ostream & operator<<(std::ostream & os, DistanceMatrix & d)
{
	os << typeid(d).name() << d.mV << d.mE;




	std::cout << std::endl;

	for (const auto& inner : d.mDistMatrix) {
		for (const auto& item : inner) {
			std::cout.width(5);
			os << item << " ";
		}
	std::cout << std::endl;
	}

	return os;
}

std::string DistanceMatrix::getPath(int i, int j)
{
	if (mDistMatrix[i][j].isInfinite())
		return "inf";

	int intermediate = mNext[i][j];
	std::string path{};
	if (intermediate == i)
		return "-";

	//if (mNext[i][j] == i)
	//	return "-";
	else
		path = getPath(i, intermediate) + std::to_string(intermediate + 1) + getPath(intermediate, j);

	return path;

}

bool DistanceMatrix::floyd_warshall()
{
	for (int k = 0; k < mV; ++k)
		for (int i = 0; i < mV; ++i)
			for (int j = 0; j < mV; ++j)
			{
				if (mDistMatrix[i][j] > mDistMatrix[i][k] + mDistMatrix[k][j])
				{
					std::cout << "k: " << k << "\ti: " << i << "\tk: " << j << std::endl;
					mDistMatrix[i][j] = mDistMatrix[i][k] + mDistMatrix[k][j];
					//printMatrix();
					//mNext[i][j] = mNext[k][j];
					mNext[i][j] = k;
					//std::cout << "-------" << "mNext table"<< "---------" << std::endl;
					//showmNext();

				}
			}


	//std::cout << "-------" << __FUNCTION__ << "---------" << std::endl;
	//showmNext();
	//std::cout << "----------------" << std::endl;

	std::cout << "------------RESULT-------------" << std::endl;

	for (int i = 0; i < mV; ++i)
	{
		std::cout << std::endl;
		for (int j = 0; j < mV; ++j)
		{
			if (i != j)
			{
				std::cout << "d[" << i + 1 << ", " << j + 1 << "]\t";
				std::cout << "\tPATH: " << i + 1 << getPath(i, j) << j + 1 << std::endl;
			}
		}
	}



	return true;
}

void DistanceMatrix::printMatrix() const
{
	std::for_each(mDistMatrix.cbegin(), mDistMatrix.cend(), [](auto& dv) {
		std::for_each(dv.cbegin(), dv.cend(), [](auto &d) { 
			std::cout.width(5);
			std::cout << d << " "; 
		});
		std::cout << std::endl;
	} );
	std::cout << std::endl;
}

void DistanceMatrix::showmNext() const
{
	std::for_each(mNext.cbegin(), mNext.cend(), [](auto& p) {
		std::for_each(p.cbegin(), p.cend(), [](auto &d) {
			std::cout.width(5);
			std::cout << d << " ";
		});
		std::cout << std::endl;
	});
	std::cout << std::endl;
}
