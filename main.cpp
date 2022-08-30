#include <iostream>
#include <string>
#include <vector>
#include "sort.h"
#include "uniq.h"
#include "IOmethod.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	int Enter_number = 0;
	bool Enter_key = false;

	while (!Enter_key){
		cout << "How to Input sentences." << endl;
		cout << "1 : Read File" << endl;
		cout << "2 : Direct Enter" << endl;

		cin >> Enter_number;
		switch (Enter_number){
			case 1 :
			case 2 :
				Enter_key = true;
				break;
			default :
				cout << "Please Choose the Input method from 1, 2" << endl;
				break;
		}
	}

	int Out_number = 0;
	bool Out_key = false;

	while (!Out_key){
		cout << "How to Output sentences." << endl;
		cout << "1 : Write File" << endl;
		cout << "2 : Direct Out" << endl;

		cin >> Out_number;
		switch(Out_number){
			case 1 :
			case 2 :
				Out_key = true;
				break;
			default :
				cout << "Please Choose the Output method from 1, 2" << endl;
				break;
		}
	}

	int sort_number = 0;
	bool sort_key = false;


	while (!sort_key){
		cout << "Select sort method" << endl;
		cout << "1 : Bubble Sort" << endl;
		cout << "2 : Selection Sort" << endl;
		cout << "3 : Insertion Sort" << endl;
		cout << "4 : Merge Sort" << endl;

		cin >> sort_number;
		switch(sort_number) {
			case 1 :
			case 2 :
			case 3 :
			case 4 :
				sort_key = true;
				break;
			default :
				cout << "Please Choose the sorting method from 1 to 4" << endl;
				break;
		}
	}

	vector<string> svec;

	switch(Enter_number) {
		case 1 :
			file_read(svec);
			break;
		case 2 :
			direct_read(svec);
			break;
	}

	auto b = svec.begin();
	auto e = svec.end();
	if (b == e || b == e-1){
		cout << "Please Enter more than 2 sentences." << endl;
		return 1;
	}

	switch(sort_number){
		case 1 :
			bubble(svec);
			break;
		case 2 :
			select(svec);
			break;
		case 3 :
			insert(svec);
			break;
		case 4 :
			merge(svec);
			break;
	}
	uniq(svec);

	switch(Out_number){
		case 1 :
			file_print(svec);
			break;
		case 2 :
			direct_print(svec);
			break;
	}
	return 0;
}
