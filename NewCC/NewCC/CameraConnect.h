#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4010)



#include <string>
#include <iostream>
#include <HCNetSDK.h>
#include <string>
#include <ctime>
#include <Math.h>
#include <stdlib.h>
#include <atlstr.h>
#include <DST.h>


class CamerasConf {
public:
	int code_error;
	std::string IPadress = " ";
	int port = 0;
	std::string userName = " ";
	std::string password = " ";
	
	
	
	DWORD dwReturnLen;
	LONG lUserID = -1;
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = { 0 };
	NET_DVR_USER_LOGIN_INFO struLoginInfo = { 0 };
	int iRet = -1;
	NET_DVR_TIME timeParams = { 0 };
	NET_DVR_ZONEANDDST dstParam = { 0 };
	NET_DVR_COMPRESSIONCFG_V30 struParams = { 0 };
	NET_DVR_DEVICECFG_V40 deviceParams = { 0 };
	NET_DVR_DEVICECFG firmware = { 0 };
	CString	m_strSoftwareVersion;
	NET_DVR_NETAPPCFG ntp = { 0 };


	int dd;
	int error = 1;
	int config = -1;

public:
	CamerasConf(std::string a, int b, std::string c, std::string d) {

		NET_DVR_Init();

		//NET_DVR_SetConnectTime(250, 1);
		//NET_DVR_SetReconnect(500, true);

		
		IPadress = a;
		port = b;
		userName = c;
		password = d;

		struLoginInfo.bUseAsynLogin = 0; //Synchronous login mode
		strcpy_s(struLoginInfo.sDeviceAddress, IPadress.c_str()); //IP address
		struLoginInfo.wPort = b; //Service port
		strcpy_s(struLoginInfo.sUserName, userName.c_str()); //User name
		strcpy_s(struLoginInfo.sPassword, password.c_str()); //Password
		lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
		// << "lUserID : " << lUserID << std::endl;
		error = NET_DVR_GetLastError();
		
		iRet = NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_TIMECFG, struDeviceInfoV40.struDeviceV30.byStartChan, \
			&timeParams, sizeof(NET_DVR_TIME), &dwReturnLen);

		time_t rawtime;
		struct tm *timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		

		int diff_time = 0;
		if (timeParams.dwHour == 0 and timeParams.dwMinute == 0 and timeParams.dwSecond == 0) {
			dd = NULL;
		}
		else {
			diff_time = timeParams.dwHour * 3600 - timeinfo->tm_hour * 3600 + timeParams.dwMinute * 60 - timeinfo->tm_min * 60 + timeParams.dwSecond - timeinfo->tm_sec;
			dd = diff_time;
		}

		//NET_DVR_SetConnectTime(3000, 2);
		//NET_DVR_SetReconnect(6000, true);	

		//////////////////////////////////////////////////
		NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_ZONEANDDST, struDeviceInfoV40.struDeviceV30.byChanNum, \
			&dstParam, sizeof(NET_DVR_ZONEANDDST), &dwReturnLen);




		NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_COMPRESSCFG_V30, struDeviceInfoV40.struDeviceV30.byChanNum, \
			&struParams, sizeof(NET_DVR_COMPRESSIONCFG_V30), &dwReturnLen);



		//////////////////////////////////////////////////////
		NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_DEVICECFG_V40, struDeviceInfoV40.struDeviceV30.byChanNum, \
			&deviceParams, sizeof(NET_DVR_DEVICECFG_V40), &dwReturnLen);

		///////////////////////////////////////////////////

		NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_DEVICECFG, struDeviceInfoV40.struDeviceV30.byStartChan, \
			&firmware, sizeof(NET_DVR_DEVICECFG), &dwReturnLen);


		NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_NETAPPCFG, struDeviceInfoV40.struDeviceV30.byStartChan, \
			&ntp, sizeof(NET_DVR_NETAPPCFG), &dwReturnLen);


	}

	DST getDST() {


		return DST(dstParam.dwEnableDST, (int)(dstParam.byDSTBias), dstParam.struBeginPoint.dwMonth, \
			dstParam.struBeginPoint.dwWeekNo, dstParam.struBeginPoint.dwWeekDate, dstParam.struBeginPoint.dwHour, \
			dstParam.struBeginPoint.dwMin, dstParam.struEndPoint.dwMonth, dstParam.struEndPoint.dwWeekNo, \
			dstParam.struEndPoint.dwWeekDate, dstParam.struEndPoint.dwHour, dstParam.struEndPoint.dwMin);
	}

	int getError() {
		return error;

	}


	void printSett() {

		std::cout << "IPadress : " << IPadress << " port : " << port << " userName: " << userName << " password: " << password << std::endl;

	}


	



	~CamerasConf() {
		NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();

	}
};