#pragma once


#include <iostream>
#include <string>


class DST
{
public:
	DST(int, int, int, int, int, int, int, int, int, int, int, int);
	void printDST(DST);
	bool dstsComp(DST, DST);
	~DST();

public:
	int getDst = 0;
	int bias = 60;

	int startMonth = 3;
	int startWeekN = 4;
	int startWeekDate = 0;
	int startHour = 3;
	int startMin = 0;

	int endMonth = 10;
	int endWeekN = 4;
	int endWeekDate = 0;
	int endHour = 3;
	int endMin = 0;



};

DST::DST(int a, int b, int c, int d, int e, int f, int g, int h, int k, int l, int m, int o) {
	getDst = a;
	bias = b;

	startMonth = c;
	startWeekN = d;
	startWeekDate = e;
	startHour = f;
	startMin = g;

	endMonth = h;
	endWeekN = k;
	endWeekDate = l;
	endHour = m;
	endMin = o;
}


void DST::printDST(DST a) {
	std::cout << "dwEnableDST: " << a.getDst << " byDSTBias: " \
		<< (int)(a.bias) << " dwStartMonth: " << a.startMonth << " startWeekN: " << a.startWeekN \
		<< " startWeekDate: " << a.startWeekDate << " startHour: " << a.startHour << " startMin:" << a.startMin \
		<< " endMonth: " << a.endMonth << " endWeekN: " << a.endWeekN \
		<< " endWeekDate: " << a.endWeekDate << " endHour: " << a.endHour << " endMin:" << a.endMin << std::endl;

}

bool DST::dstsComp(DST e, DST b) {
	DST eth = e;
	DST candidate = b;
	if (eth.getDst == candidate.getDst and \
		eth.bias == candidate.bias and\
		eth.startMonth == candidate.startMonth and\
		eth.startWeekN == candidate.startWeekN and\
		eth.startWeekDate == candidate.startWeekDate and\
		eth.startHour == candidate.startHour and\
		eth.startMin == candidate.startMin and\
		eth.endMonth == candidate.endMonth and\
		eth.endWeekN == candidate.endWeekN and\
		eth.endWeekDate == candidate.endWeekDate and\
		eth.endHour == candidate.endHour and\
		eth.endMin == candidate.endMin) {
		return true;
	}
	else {
		return false;
	}
}
DST::~DST()
{

}