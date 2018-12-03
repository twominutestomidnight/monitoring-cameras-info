#pragma once


#include <iostream>
//#include <map>
#include <vector>
#include <string>


class codec {
public:
	codec(int, std::string);
	int getCode();
	std::string getValue();
	~codec();

private:
	int code = 0;
	std::string value = "inf";
};


codec::codec(int c, std::string str) {
	code = c;
	value = str;
	//std::cout << "code : " << code << ", description : " << value << std::endl;
};


int codec::getCode() {
	return code;
}


std::string codec::getValue() {
	return value;
}



codec::~codec() {
};



std::vector<codec> getCodec() {
	std::vector<codec> cod;
	cod.push_back(codec(0, "private h264"));
	cod.push_back(codec(1, "standard H264"));
	cod.push_back(codec(2, "standard MPEG4"));
	cod.push_back(codec(7, "M-JPEG"));
	cod.push_back(codec(8, "MPEG2"));
	cod.push_back(codec(9, "SVAC"));
	cod.push_back(codec(10, "Standard h265"));

	return cod;
}