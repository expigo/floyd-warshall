#pragma once
#include<fstream>

class Distance
{
	int mWeight = 0;
	bool mIsInfinite = true;

public:
	Distance() = default;
	Distance(const Distance&) = default;
	//Distance(Distance&&) = default;
	//virtual  ~Distance() = default;
	explicit Distance(int);

	void setWeight(int w);
	double getWeight() const;
	bool isInfinite() const;
	bool isZero() const;
	bool operator>(const Distance&) const;
	Distance operator+(const Distance&);

	friend std::ostream& operator<<(std::ostream& os,const Distance& d);



};

