#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "sort.h"
#include "uniq.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

int main(){
	cout << "Select sort method" << endl;
	cout << "1 : Bubble Sort" << endl;
	cout << "2 : Selection Sort" << endl;
	cout << "3 : Insertion Sort" << endl;
	cout << "4 : Merge Sort" << endl;

	int sort_number;
	cin >> sort_number;
	vector<string> svec;

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
		return 1;
	}

	auto b = svec.begin();
	auto e = svec.end();
	if (b == e || b == e-1){
		cout << "Please Enter more than 2 sentences." << endl;
		return 1;
	}

	switch(sort_number){
		case 1 :
			svec = bubble(svec);
			break;
		case 2 :
			svec = select(svec);
			break;
		case 3 :
			svec = insert(svec);
			break;
		case 4 :
			svec = merge(svec);
			break;
	}
	svec = uniq(svec);

	ofstream wfile("write_file.txt");
	if(wfile.is_open()){
		for (auto s : svec)
			wfile << s << endl;
		cout << "Success to Wirte File" << endl;
	}
	else {
		cout << "Unable to write file" << endl;
		return 1;
	}

	return 0;
}
