#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

void file_read(vector<string> &svec){
	string line;
	ifstream rfile("read_file.txt");
	if(rfile.is_open()){
		while (getline(rfile, line)){
			if(!line.empty())
				svec.push_back(line);
		}
		rfile.close();
		cout << "Success to Read File" << endl;
	}
	else {
		cout << "Unable to open file" << endl;
		exit(1);
	}
}

void direct_read(vector<string> &svec){
	cout << "Please Enter more than 2 sentences." << endl;
	string line;
	while (getline(cin, line))
		if(!line.empty())
			svec.push_back(line);
}

void file_print(vector<string> &svec){
	ofstream wfile("write_file.txt");
	if(wfile.is_open()){
		for (auto s : svec)
			wfile << s << endl;
		cout << "Sucess to Write File" << endl;
	}
	else {
		cout << "Unable to srite file" << endl;
		exit(1);
	}
}

void direct_print(vector<string> &svec){
	cout << "\nResult" << endl;
	for (auto s : svec)
		cout << s << endl;
}
