/*
 * TempData.h
 *
 *  Created on: Apr 12, 2019
 *      Author: slupoli
 */

#ifndef TEMPDATA_H_
#define TEMPDATA_H_

#include <iostream>

class TempData
{
	private:
		int value; // second part of total String in Degrees
		float precipitation; // how much rain fell

	public:

		TempData()
		{
			value = 0;
			precipitation = 0.0;
		}

		TempData(int v, float p)
		{
			value = v;
			precipitation = p;
		}

		int getValue() const
		{
			return value;
		}

		double getPrecipitation() const
		{
			return precipitation;
		}

		void setValue(int v)
		{
			value = v;
		}

		void setPrecipitation(double p)
		{
			precipitation = p;
		}

		TempData(const TempData & RHS)
		{
			value = RHS.getValue();
			precipitation = RHS.getPrecipitation();
		}

		bool operator==(const TempData& RHS)
		{
			return (this->getValue() == RHS.getValue() && this->getPrecipitation() == RHS.getPrecipitation());
		}

		bool operator<(const TempData& RHS)
		{
			return (this->getValue() < RHS.getValue());
		}

};

std::ostream& operator <<(std::ostream& out, const TempData &data)
{
	out << "Temp: " << data.getValue() << ", Precip: " << data.getPrecipitation();
	out << std::endl;
	return out;
}

int compVal(const TempData& a, const TempData& b)
{
	return a.getValue()<b.getValue();
}

int compPrecip(const TempData& a, const TempData& b)
{
	return a.getPrecipitation()<b.getPrecipitation();
}


#endif /* TEMPDATA_H_ */
