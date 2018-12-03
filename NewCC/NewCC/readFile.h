#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> Read(std::string st) {
	std::string path = st;
	std::vector<std::string> lines;
	{
		std::ifstream f(path);
		if (f.is_open()) {
			std::cout << "reading..." << std::endl;
		}
		else {
			std::cout << "Error opening file " << std::endl;
		}
		std::string line;
		while (std::getline(f, line))
			lines.push_back(line);
		f.close();
	}
	int size = lines.size();
	vector<string> v;

	for (auto i = 0; i < lines.size(); i++)
	{

		string t;
		istringstream ss(lines[i]);
		while (ss >> t)
			v.push_back(t);

	}

	cout << "finish read file." << endl;
	return v;
}