#pragma once

#pragma once


#include <iostream>
//#include <map>
#include <vector>
#include <string>


class resolution {
public:
	resolution(int, std::string);
	int getCode();
	std::string getValue();
	~resolution();

private:
	int code = 0;
	std::string value = "inf";
};



resolution::resolution(int c, std::string str) {
	code = c;
	value = str;
	//std::cout << "code reso : " << code << " description : " << value << std::endl;
};


int resolution::getCode() {
	//std::cout << " code : " << code << std::endl;
	return code;
}


std::string resolution::getValue() {
	//std::cout  << " value : " << value << std::endl;
	return value;
}



resolution::~resolution() {
};



std::vector<resolution> getReso() {
	std::vector<resolution> res;
	res.push_back(resolution(0, "DCIF"));
	res.push_back(resolution(1, "CIF"));
	res.push_back(resolution(2, "QCIF"));
	res.push_back(resolution(3, "4CIF"));
	res.push_back(resolution(4, "2CIF"));
	res.push_back(resolution(6, "QVGA(320*240)"));
	res.push_back(resolution(7, "QQVGA(160*120)"));
	res.push_back(resolution(12, "384*288"));
	res.push_back(resolution(13, "576*576"));
	res.push_back(resolution(16, "VGA(640*480)"));
	res.push_back(resolution(17, "UXGA(1600*1200)"));
	res.push_back(resolution(18, "SVGA(800*600)"));
	res.push_back(resolution(19, "HD720p(1280*720)"));
	res.push_back(resolution(20, "XVGA"));
	res.push_back(resolution(21, "HD900p"));
	res.push_back(resolution(22, "1360*1024"));
	res.push_back(resolution(23, "1536*1536"));
	res.push_back(resolution(24, "1920*1920"));
	res.push_back(resolution(27, "HD1080i"));
	res.push_back(resolution(28, "2560*1920"));
	res.push_back(resolution(29, "1600*304"));
	res.push_back(resolution(30, "2048*1536"));
	res.push_back(resolution(31, "2448*2048"));
	res.push_back(resolution(32, "2448*1200"));
	res.push_back(resolution(33, "2448*800"));
	res.push_back(resolution(34, "XGA(1024*768)"));
	res.push_back(resolution(35, "SXGA(1280*1024)"));
	res.push_back(resolution(36, "WD1(960*576/960*480)"));
	res.push_back(resolution(37, "1080i"));
	res.push_back(resolution(38, "WSXGA(1440*900)"));
	res.push_back(resolution(39, "HD_F(1920*1080/1280*720)"));
	res.push_back(resolution(40, "HD_H(1920*540/1280*360)"));
	res.push_back(resolution(41, "HD_Q(960*540/630*360)"));
	res.push_back(resolution(42, "2336*1744"));
	res.push_back(resolution(43, "1920*1456"));
	res.push_back(resolution(44, "2592*2048"));
	res.push_back(resolution(45, "3296*2472"));
	res.push_back(resolution(46, "1376*768"));
	res.push_back(resolution(47, "1366*768"));
	res.push_back(resolution(48, "1360*768"));
	res.push_back(resolution(49, "WSXGA+"));
	res.push_back(resolution(50, "720*720"));
	res.push_back(resolution(51, "1280*1280"));
	res.push_back(resolution(52, "2048*768"));
	res.push_back(resolution(53, "2048*2048"));
	res.push_back(resolution(54, "2560*2048"));
	res.push_back(resolution(55, "3072*2048"));
	res.push_back(resolution(56, "2304*1296"));
	res.push_back(resolution(57, "WXGA(1280*800)"));
	res.push_back(resolution(58, "1600*600"));
	res.push_back(resolution(59, "1600*900"));
	res.push_back(resolution(60, "2752*2208"));
	res.push_back(resolution(61, "reserved"));
	res.push_back(resolution(62, "4000*3000"));
	res.push_back(resolution(63, "4096*2160"));
	res.push_back(resolution(64, "3840*2160"));
	res.push_back(resolution(65, "4000*2250"));
	res.push_back(resolution(66, "3072*1728"));
	res.push_back(resolution(67, "2592*1944"));
	res.push_back(resolution(68, "2464*1520"));
	res.push_back(resolution(69, "1280*1920"));
	res.push_back(resolution(70, "2560*1440"));
	res.push_back(resolution(71, "1024*1024"));
	res.push_back(resolution(72, "160*128"));
	res.push_back(resolution(73, "324*240"));
	res.push_back(resolution(74, "324*240"));
	res.push_back(resolution(75, "336*256"));
	res.push_back(resolution(76, "640*512"));
	res.push_back(resolution(77, "2720*2048"));
	res.push_back(resolution(78, "384*256"));
	res.push_back(resolution(79, "384*216"));
	res.push_back(resolution(80, "320*256"));
	res.push_back(resolution(81, "320*180"));
	res.push_back(resolution(82, "320*192"));
	res.push_back(resolution(83, "512*384"));
	res.push_back(resolution(84, "325*256"));
	res.push_back(resolution(85, "256*192"));
	res.push_back(resolution(86, "640*360"));
	res.push_back(resolution(87, "1776x1340"));
	res.push_back(resolution(88, "1936x1092"));
	res.push_back(resolution(89, "2080x784"));
	res.push_back(resolution(90, "2144x604"));
	res.push_back(resolution(91, "1920*1200"));
	res.push_back(resolution(92, "4064*3040"));
	res.push_back(resolution(93, "3040*3040"));
	res.push_back(resolution(94, "3072*2304"));
	res.push_back(resolution(95, "3072*1152"));
	res.push_back(resolution(96, "2560*2560"));
	res.push_back(resolution(97, "2688*1536"));
	res.push_back(resolution(98, "2688*1520"));
	res.push_back(resolution(99, "3072*3072"));
	res.push_back(resolution(100, "3392*2008"));
	res.push_back(resolution(101, "4000*3080"));
	res.push_back(resolution(102, "960*720"));
	res.push_back(resolution(103, "1024*1536"));
	res.push_back(resolution(104, "704*1056"));
	res.push_back(resolution(105, "352*528"));
	res.push_back(resolution(106, "2048*1530"));
	res.push_back(resolution(107, "2560*1600"));
	res.push_back(resolution(108, "2800*2100"));
	res.push_back(resolution(109, "4088*4088"));
	res.push_back(resolution(110, "4000*3072"));
	res.push_back(resolution(111, "960*1080(1080p Lite)"));
	res.push_back(resolution(112, "640*720(half 720p)"));
	res.push_back(resolution(113, "640*960"));
	res.push_back(resolution(114, "320*480"));
	res.push_back(resolution(115, "3840*2400"));
	res.push_back(resolution(116, "3840*1680"));
	res.push_back(resolution(117, "2560*1120"));
	res.push_back(resolution(118, "704*320"));
	res.push_back(resolution(119, "1200*1920"));
	res.push_back(resolution(120, "480*768"));
	res.push_back(resolution(121, "768*480"));
	res.push_back(resolution(122, "320*512"));
	res.push_back(resolution(123, "512*320"));
	res.push_back(resolution(124, "4096*1800"));
	res.push_back(resolution(125, "1280*560"));
	res.push_back(resolution(126, "2400*3840"));
	res.push_back(resolution(127, "480*272"));
	res.push_back(resolution(128, "512*272"));
	res.push_back(resolution(129, "2592*2592"));
	res.push_back(resolution(130, "1792*2880"));
	res.push_back(resolution(131, "1600*2560"));
	res.push_back(resolution(132, "2720*1192"));
	res.push_back(resolution(133, "3MP(1920*1536/2048*1536)"));
	res.push_back(resolution(134, "5MP(2560*1944)"));
	res.push_back(resolution(135, "2560*960"));
	res.push_back(resolution(136, "2064*1544"));
	res.push_back(resolution(137, "4096*1200"));
	res.push_back(resolution(138, "3840*1080"));
	res.push_back(resolution(139, "2720*800"));
	res.push_back(resolution(140, "512*232"));
	res.push_back(resolution(141, "704*200"));
	res.push_back(resolution(142, "512*152"));
	res.push_back(resolution(143, "2048*896"));
	res.push_back(resolution(144, "2048*600"));
	res.push_back(resolution(145, "1280*376"));
	res.push_back(resolution(146, "2592*1520"));
	res.push_back(resolution(147, "2592*1536"));
	res.push_back(resolution(148, "3072*8192"));
	res.push_back(resolution(149, "768*2048"));
	res.push_back(resolution(150, "8208*3072"));
	res.push_back(resolution(151, "4096*1536"));
	res.push_back(resolution(152, "6912*2800"));
	res.push_back(resolution(153, "3456*1400"));
	res.push_back(resolution(154, "480*720"));
	res.push_back(resolution(155, "800*450"));
	res.push_back(resolution(156, "480*270"));
	res.push_back(resolution(157, "2560*1536"));
	res.push_back(resolution(160, "3264*2448"));
	res.push_back(resolution(161, "288*320"));
	res.push_back(resolution(162, "144*176"));
	res.push_back(resolution(163, "480*640"));
	res.push_back(resolution(164, "240*320"));
	res.push_back(resolution(165, "120*160"));
	res.push_back(resolution(166, "576*720"));
	res.push_back(resolution(167, "720*1280"));
	res.push_back(resolution(168, "576*960"));
	res.push_back(resolution(169, "2944*1656"));
	res.push_back(resolution(170, "432*240"));
	res.push_back(resolution(171, "2160*3840"));
	res.push_back(resolution(172, "1080*1920"));
	res.push_back(resolution(173, "7008*1080"));
	res.push_back(resolution(174, "3504*540"));
	res.push_back(resolution(175, "1752*270"));
	res.push_back(resolution(176, "876*135"));
	res.push_back(resolution(177, "4096*1440"));
	res.push_back(resolution(178, "4096*1080"));
	res.push_back(resolution(179, "1536*864"));
	res.push_back(resolution(186, "3200*1800"));
	res.push_back(resolution(187, "1752*272"));
	res.push_back(resolution(188, "872*136"));
	res.push_back(resolution(189, "1280*1440"));
	res.push_back(resolution(190, "3520*544"));
	res.push_back(resolution(191, "1728*256"));
	res.push_back(resolution(192, "864*128"));
	res.push_back(resolution(193, "5470*3684"));


	return res;
}