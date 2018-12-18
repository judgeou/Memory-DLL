#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MemoryModule.h"

using namespace std;

typedef int(*exp1)(int, int);

int main()
{
    cout << "输入要载入DLL的地址：";
	char dllpath[200];
	cin.getline(dllpath, 200);
	ifstream dllfile(dllpath, ios::binary | ios::ate);

	if (dllfile.good()) {
		// read dllfile data
		auto filesize = dllfile.tellg();
		dllfile.seekg(0);
		char * filedata = new char[filesize];
		dllfile.read(filedata, filesize);
		dllfile.close();

		// load dll
		MemoryLoadLibrary(filedata, filesize);
	}
	else {
		cout << "找不到 DLL 文件";
	}
}