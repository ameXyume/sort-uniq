#include <iostream>
#include <string>
#include <vector>
#include "sort.h"
#include "uniq.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	cout << "Select sort method" << endl;
	cout << "1 : Bubble Sort" << endl;
	cout << "2 : Selection Sort" << endl;
	cout << "3 : Insertion Sort" << endl;
	cout << "4 : Merge Sort" << endl;

	int sort_number;
	cin >> sort_number;

	cout << "Please Enter more than 2 sentences. " << endl;
	string line;
	vector<string> svec;

	while (getline(cin, line))
		if(!line.empty())
			svec.push_back(line);

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
	cout << "\nResult" << endl;
	for (auto s : svec)
		cout << s << endl;
}
