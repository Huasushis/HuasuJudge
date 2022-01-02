#pragma once
#include "unzip.h"
#include<string>
#include<cstdio>
#include<cstdlib>
#include<direct.h>
#include<io.h>
using namespace std;

class Untest {
private:
	string fileName,zipPath,folderPath;

public:
	
	Untest(string fileName) :fileName(fileName) {
		folderPath = "%appdata%\\HuasuJudge\\" + fileName + "zip";
		if (_access(folderPath.c_str(), 0) != 0) {		//Make dir to store zip
			mkdir(folderPath.c_str());
		}

	}

	~Untest() = default;

	void unZIP() {					//Unzip Test Points
		HZIP hz = OpenZip(zipPath.c_str(), 0);
		ZIPENTRY ze;
		GetZipItem(hz, -1, &ze);
		int numitems = ze.index;
		for (int i = 0; i < numitems; i++) {
			GetZipItem(hz, i, &ze);
			UnzipItem(hz, i, ze.name);
		}
		CloseZip(hz);
	}

	void clear() {
		rmdir(folderPath.c_str());
	}
};