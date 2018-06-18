#include "Distance.h"

#include<limits>





Distance::Distance(int x)
{
	mWeight = x;
	mIsInfinite = false;

}


void Distance::setWeight(int w)
{
	mWeight = w;
	mIsInfinite = false;
}

double Distance::getWeight() const
{
	if (isInfinite())
		return std::numeric_limits<double>::infinity();
	else
		return mWeight;
}

bool Distance::isInfinite() const
{
	return mIsInfinite;
}

bool Distance::isZero() const
{
	if (!(isInfinite()) && mWeight == 0)
		return true;
	else
		return false;

}

bool Distance::operator>(const Distance &d) const
{
	if (d.isInfinite())
		return false;
	else if (this->isInfinite())
		return true;
	else if (this->mWeight > d.mWeight)
		return true;

	return false;
}


Distance Distance::operator+(const Distance &d)// !!!!!CHANGE IT THAT IS USES OVERLOADED CONSTRUCTOR
{


	if (this->isInfinite() || d.isInfinite())
		return Distance();
	else
		return Distance(d.mWeight + this->mWeight);

	//temp.setWeight(d.m_weight + this->m_weight);
	//	return temp;

}

std::ostream & operator<<(std::ostream & os, const Distance& d)
{
	os << d.getWeight();

	return os;
}
