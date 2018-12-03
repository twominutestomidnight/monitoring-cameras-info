#pragma once


#include <iostream>
//#include <map>
#include <vector>
#include <string>

class bitrate
{
public:
	bitrate(int, std::string);
	int getCode();
	std::string getBitrate();
	~bitrate();

private:
	int code = 0;
	std::string value = "inf";
};

bitrate::bitrate(int c, std::string str) {
	code = c;
	value = str;
	//std::cout << "code bitrate : " << code << " description : " << value << std::endl;

}
int bitrate::getCode() {
	return code;
}


std::string bitrate::getBitrate() {
	return value;
}


bitrate::~bitrate() {

}

std::vector<bitrate> getBit() {
	std::vector<bitrate> bit;
	bit.push_back(bitrate(0, "reserved"));
	bit.push_back(bitrate(1, "16K"));
	bit.push_back(bitrate(2, "32K"));
	bit.push_back(bitrate(3, "48k"));
	bit.push_back(bitrate(4, "64K"));
	bit.push_back(bitrate(5, "80K"));
	bit.push_back(bitrate(6, "96K"));
	bit.push_back(bitrate(7, "128K"));
	bit.push_back(bitrate(8, "160k"));
	bit.push_back(bitrate(9, "192K"));
	bit.push_back(bitrate(10, "224K"));
	bit.push_back(bitrate(11, "256K"));
	bit.push_back(bitrate(12, "320K"));
	bit.push_back(bitrate(13, "384K"));
	bit.push_back(bitrate(14, "448K"));
	bit.push_back(bitrate(15, "512K"));
	bit.push_back(bitrate(16, "640K"));
	bit.push_back(bitrate(17, "768K"));
	bit.push_back(bitrate(18, "896K"));
	bit.push_back(bitrate(19, "1024K"));
	bit.push_back(bitrate(20, "1280K"));
	bit.push_back(bitrate(21, "1536K"));
	bit.push_back(bitrate(22, "1792K"));
	bit.push_back(bitrate(23, "2048K"));
	bit.push_back(bitrate(24, "3072K"));
	bit.push_back(bitrate(25, "4096K"));
	bit.push_back(bitrate(26, "8192K"));
	bit.push_back(bitrate(27, "16384K"));



	return bit;
}
