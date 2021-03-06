#include "pch.h"
#include <iostream>
#include <HCNetSDK.h>
#include <vector>
#include <Codec.h>
#include <Resolution.h>
#include <Bitrate.h>
#include <readFile.h>
#include <string>
#include <CameraConnect.h>
#include <DST.h>
#include <time.h>
#include <atlstr.h>




int main(int argc, char* argv[])
{


	std::cout << "getting codecs : " << std::endl;
	std::vector<codec> codecVec = getCodec();
	std::cout << "getting resolutions : " << std::endl;
	std::vector<resolution> resVec = getReso();
	std::cout << "getting bitrates : " << std::endl;
	std::vector<bitrate> bitVec = getBit();

	//read file 

	//std::string pathInput = "data.txt";
	//std::string pathOutput = "res2.txt";
	std::string pathInputData = argv[1];
	std::string pathOutputData = argv[2];

	std::ofstream output(pathOutputData);
	output << "ip" << "\t" << "code error" << "\t " << "enable dst" << "\t" << "diff time local-camera" << "\t" << \
		"bitrate" << "\t" << \
		"enctype" << "\t" << "resolution" << "\t" << \
		"Serial number " << "\t" << " Software Version " << "\t" << " NTP " << std::endl;






	std::vector<string> buf = Read(pathInputData);
	int size = buf.size();
	int cameras_num = size / 4;
	std::cout << "cameras_num :" << cameras_num << std::endl;
	int raz = (int)(cameras_num*0.25);
	//std::cout << "raz :" << raz << std::endl;
	int dva = (int)(cameras_num*0.5);
	//std::cout << "dva :" << dva << std::endl;
	int three = (int)(cameras_num*0.75);
	//std::cout << "three :" << three << std::endl;

	DST ethalon(1, 60, 2, 4, 0, 3, 0, 9, 4, 0, 4, 0);
	DST dstTemp(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	bool enableDST = false;

	clock_t start, end;
	start = clock();
	int ii = 0;
	for (int j = 0; j < buf.size() - 3; j += 4) {
		
		CamerasConf temp = CamerasConf(buf[j], std::atoi(buf[j + 1].c_str()), buf[j + 2], buf[j + 3]);
		//temp.printSett();
		enableDST = dstTemp.dstsComp(ethalon, temp.getDST());
		int e = temp.getError();
		if (e != 0) {
			switch (e) {
			case 1: {
				output << temp.IPadress << "\t" << " Error : " << e << " User name or password error." << std::endl;
				break;
			}
			case 3: {
				output << temp.IPadress << "\t" << " Error : " << e << " SDK is not initialized." << std::endl;
				break;
			}
			case 5: {
				output << temp.IPadress << "\t" << " Error : " << e << " The number of connection with the device has exceeded the max limit." << std::endl;
				break;
			}
			case 7: {
				output << temp.IPadress << "\t" << " Error : " << e << " Failed to connect to the device. The device is off-line" << std::endl;
				break;
			}
			case 10:
			{
				output << temp.IPadress << "\t" << " Error : " << e << " Timeout when receiving data from the device." << std::endl;
				break;
			}
			case 17: {
				output << temp.IPadress << "\t" << " Error : " << e << " Input  value or format of the parameters does not match with the requirements." << std::endl;
				break;
			}
			case 21: {
				output << temp.IPadress << "\t" << " Error : " << e << " Device hark disk is full." << std::endl;
				break;
			}
			default: {
				output << temp.IPadress << "\t" << " Error : " << e << " Unspecified error" << std::endl;
			}
			}
		}
		else {
			bool flag = false;
			int currentJ = 0;
			int currentK = 0;
			int currentR = 0;
			for (int j = 0; j < resVec.size(); j++) {
				if ((int)temp.struParams.struNormHighRecordPara.byResolution == resVec[j].getCode()) {
					flag = true;
					currentJ = j;
					for (int k = 0; k < bitVec.size(); k++) {
						if ((int)temp.struParams.struNormHighRecordPara.byVideoEncType == bitVec[k].getCode()) {
							currentK = k;
							for (int r = 0; r < codecVec.size(); r++) {
								if ((int)temp.struParams.struNormHighRecordPara.byVideoEncType == codecVec[r].getCode()) {
									currentR = r;
									break;
								}

							}
							break;
						}
					}
					break;
				}
			}
			if (flag == true) {

				CString	m_strSoftwareVersion = _T("");
				
				if (((temp.firmware.dwSoftwareVersion >> 24) & 0xFF) > 0)
				{
					m_strSoftwareVersion.Format(_T("V%d.%d.%d build %02d%02d%02d"), \
						(temp.firmware.dwSoftwareVersion >> 24) & 0xFF, (temp.firmware.dwSoftwareVersion >> 16) & 0xFF, temp.firmware.dwSoftwareVersion & 0xFFFF, (temp.firmware.dwSoftwareBuildDate >> 16) & 0xFFFF, (temp.firmware.dwSoftwareBuildDate >> 8) & 0xFF, temp.firmware.dwSoftwareBuildDate & 0xFF);
					output << temp.IPadress << "\t" << temp.getError() << "\t" << enableDST << \
						"\t" << temp.dd << "\t" << \
						bitVec[currentK].getBitrate() << "\t" << \
						codecVec[currentR].getValue() << "\t" << \
						resVec[currentJ].getValue() << "\t" << temp.struDeviceInfoV40.struDeviceV30.sSerialNumber << \
						"\t" << CT2A(m_strSoftwareVersion) << \
						"\t" << (int)temp.ntp.struNtpClientParam.byEnableNTP << std::endl;
				}
				else if (((temp.firmware.dwSoftwareVersion >> 24) & 0xFF) != 0)
				{
					m_strSoftwareVersion.Format(_T("V%d.%d build %02d%02d%02d"), \
						(temp.firmware.dwSoftwareVersion >> 16) & 0xFFFF, temp.firmware.dwSoftwareVersion & 0xFFFF, (temp.firmware.dwSoftwareBuildDate >> 16) & 0xFFFF, (temp.firmware.dwSoftwareBuildDate >> 8) & 0xFF, temp.firmware.dwSoftwareBuildDate & 0xFF);
					output << temp.IPadress << "\t" << temp.getError() << "\t" << enableDST << \
						"\t" << temp.dd << "\t" << \
						bitVec[currentK].getBitrate() << "\t" << \
						codecVec[currentR].getValue() << "\t" << \
						resVec[currentJ].getValue() << "\t" << temp.struDeviceInfoV40.struDeviceV30.sSerialNumber << \
						"\t" << CT2A(m_strSoftwareVersion) << \
						"\t" << (int)temp.ntp.struNtpClientParam.byEnableNTP << std::endl;
				}
				else 
				{
					CamerasConf temp2 = CamerasConf(buf[j], std::atoi(buf[j + 1].c_str()), buf[j + 2], buf[j + 3]);
					enableDST = dstTemp.dstsComp(ethalon, temp2.getDST());
					m_strSoftwareVersion.Format(_T("V%d.%d.%d build %02d%02d%02d"), \
						(temp2.firmware.dwSoftwareVersion >> 24) & 0xFF, (temp2.firmware.dwSoftwareVersion >> 16) & 0xFF, temp2.firmware.dwSoftwareVersion & 0xFFFF, (temp2.firmware.dwSoftwareBuildDate >> 16) & 0xFFFF, (temp2.firmware.dwSoftwareBuildDate >> 8) & 0xFF, temp2.firmware.dwSoftwareBuildDate & 0xFF);
					output << temp2.IPadress << "\t" << temp2.getError() << "\t" << enableDST << \
						"\t" << temp2.dd << "\t" << \
						bitVec[currentK].getBitrate() << "\t" << \
						codecVec[currentR].getValue() << "\t" << \
						resVec[currentJ].getValue() << "\t" << temp2.struDeviceInfoV40.struDeviceV30.sSerialNumber << \
						"\t" << CT2A(m_strSoftwareVersion) << \
						"\t" << (int)temp2.ntp.struNtpClientParam.byEnableNTP << std::endl;
				}
				/*

				if ((temp.firmware.dwSoftwareVersion >> 24 & 0xFF) == 0 && (temp.firmware.dwSoftwareBuildDate >> 16 & 0xFFF)) {
					//std::cout << "error with version, ip : " << temp.IPadress << std::endl;
					//CamerasConf temp2 = CamerasConf(buf[j], std::atoi(buf[j + 1].c_str()), buf[j + 2], buf[j + 3]);
					enableDST = dstTemp.dstsComp(ethalon, temp.getDST());
					m_strSoftwareVersion.Format(_T("V%d.%d.%d build %02d%02d%02d"), \
						(temp.firmware.dwSoftwareVersion >> 24) & 0xFF, (temp.firmware.dwSoftwareVersion >> 16) & 0xFF, temp.firmware.dwSoftwareVersion & 0xFFFF, \
						(temp.firmware.dwSoftwareBuildDate >> 16) & 0xFFFF, (temp.firmware.dwSoftwareBuildDate >> 8) & 0xFF, temp.firmware.dwSoftwareBuildDate & 0xFF);
					output << temp.IPadress << "\t" << "undefigned error with version :" << \
						"\tV" << (temp.firmware.dwSoftwareVersion >> 24 & 0xFF) << "." << (temp.firmware.dwSoftwareVersion >> 16 & 0xFF) << "." << \
						(temp.firmware.dwSoftwareVersion & 0xFFFF) << " build " << (temp.firmware.dwSoftwareBuildDate >> 16 & 0xFFF) << "0" << \
						(temp.firmware.dwSoftwareBuildDate >> 8 & 0xFF) << (temp2.firmware.dwSoftwareBuildDate & 0xFF) << \
						"\t" << (int)temp2.ntp.struNtpClientParam.byEnableNTP << std::endl;
				}

				
				if (((temp.firmware.dwSoftwareBuildDate >> 8 & 0xFF) < 10) and ((temp.firmware.dwSoftwareBuildDate >> 8 & 0xFF) > 0))  {

					output << temp.IPadress << "\t" << temp.getError() << "\t" << enableDST << \
						"\t" << temp.dd << "\t" << \
						bitVec[currentK].getBitrate() << "\t" << \
						codecVec[currentR].getValue() << "\t" << \
						resVec[currentJ].getValue() << "\t" << temp.struDeviceInfoV40.struDeviceV30.sSerialNumber << \
						"\tV" << (temp.firmware.dwSoftwareVersion >> 24 & 0xFF) << "." << (temp.firmware.dwSoftwareVersion >> 16 & 0xFF) << "." << \
						(temp.firmware.dwSoftwareVersion & 0xFFFF) << " build " << (temp.firmware.dwSoftwareBuildDate >> 16 & 0xFFF) << "0" << \
						(temp.firmware.dwSoftwareBuildDate >> 8 & 0xFF) << (temp.firmware.dwSoftwareBuildDate & 0xFF) << \
						"\t" << (int)temp.ntp.struNtpClientParam.byEnableNTP << std::endl;

				}
				else {
					output << temp.IPadress << "\t" << temp.getError() << "\t" << enableDST << \
						"\t" << temp.dd << "\t" << \
						bitVec[currentK].getBitrate() << "\t" << \
						codecVec[currentR].getValue() << "\t" << \
						resVec[currentJ].getValue() << "\t" << temp.struDeviceInfoV40.struDeviceV30.sSerialNumber << \
						"\tV" << (temp.firmware.dwSoftwareVersion >> 24 & 0xFF) << "." << (temp.firmware.dwSoftwareVersion >> 16 & 0xFF) << "." << \
						(temp.firmware.dwSoftwareVersion & 0xFFFF) << " build " << (temp.firmware.dwSoftwareBuildDate >> 16 & 0xFFF) << \
						(temp.firmware.dwSoftwareBuildDate >> 8 & 0xFF) << (temp.firmware.dwSoftwareBuildDate & 0xFF) << \
						"\t" << (int)temp.ntp.struNtpClientParam.byEnableNTP << std::endl;
				}
				*/
			}
		}
		if (ii == 0) {
			std::cout << " The work has been started" << std::endl;
		}


		if (ii == raz) {
			std::cout << " 25% of cameras were processed" << std::endl;
		}

		if (ii == dva) {
			std::cout << " 50% of cameras were processed, stay tuned" << std::endl;
		}

		if (ii == three) {
			std::cout << " 75% of cameras were processed" << std::endl;
		}
		ii += 1;
	}
	end = clock();

	std::cout << " Done." << std::endl;
	printf("The cameras  code block was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	output.close();

    std::cout << "Hello World!\n"; 

}

