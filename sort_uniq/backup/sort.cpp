#include <iostream>
#include <string>
#include <vector>
#include "main.h"
#include "sort.h"

int main(){
	cout << "Please Enter more than 2 setences. " << endl;

	string line;
	vector<string> svec;
	bool sw = false;

	while (getline(cin, line))
		if (!line.empty())
			svec.push_back(line);

	auto b = svec.begin();
	auto e = svec.end();

	if (b != e && b != e-1){
		for (decltype(svec.size()) i = 0; i <= svec.size() - 1; i++){
			sw = false;
			for (decltype(svec.size()) ix = 0; ix <= svec.size() - 2; ix++){
				if (svec[ix] > svec[ix + 1]){
					swap(svec[ix], svec[ix + 1]);
					sw = true;
				}
			}

			if (!sw){
				break;
			}
		}
	}
	else {
		cout << "Please Enter more than 2 setences. " << endl;
		return 1;
	}
	cout << "\nResult" << endl;
	for (auto s : svec)
		cout << s << endl;

	return 0;
}
