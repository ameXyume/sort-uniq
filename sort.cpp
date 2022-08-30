#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void bubble(vector<string> &svec){
	bool sw = false;

	for(decltype(svec.size()) i = 0; i <= svec.size() - 1; i++){
		sw = false;
		for (decltype(svec.size()) ix = 0; ix <= svec.size() - 2; ix++){
			if(svec[ix] > svec[ix + 1]){
				swap(svec[ix], svec[ix + 1]);
				sw = true;
			}
		}
		if(!sw)
			break;
	}
}

void select(vector<string> &svec){
	for(decltype(svec.size()) i = 0; i <= svec.size() - 1; i++){
		auto x = svec.size() - 1;
		for (decltype(svec.size()) ix = i; ix <= svec.size() - 1; ix++){
			if(svec[x] > svec[ix])
				x = ix;
		}
		swap(svec[x], svec[i]);
	}
}

void insert(vector<string> &svec){
	for (decltype(svec.size()) i = 1; i <= svec.size() - 1; i++){
		auto ix = i;
		while (svec[i] != *svec.begin() && ix != 0 && svec[i] < svec[ix - 1]){ 
			--ix;
		}
		if (svec[i] < svec[ix]){
			svec.emplace(svec.begin() + ix, svec[i]);
			svec.erase(svec.begin() + i + 1);
		}
	}
}

void merge(vector<string> &svec){
	auto b = svec.begin();
	auto mid = svec.begin() + svec.size()/2;
	auto e = svec.end();
	vector<string> left = {b, mid};
	vector<string> right = {mid, e};

	if(left.size() >= 2)
		merge(left);
	if(right.size() >= 2)
		merge(right);

	decltype(left.size()) i = 0;
	decltype(right.size()) j = 0;
	decltype(svec.size()) k = 0;

	while(left[i - 1] != *(left.end() - 1) && right[j - 1] != *(right.end() - 1)){
		if(left[i] <= right[j]){
			svec[k] = left[i];
			i++;
			k++;
		} else {
			svec[k] = right[j];
			j++;
			k++;
		}
	}
	while(left[i - 1] != *(left.end() - 1)){
		svec[k] = left[i];
		i++;
		k++;
	}
	while(right[j - 1] != *(right.end() - 1)){
		svec[k] = right[j];
		j++;
		k++;
	}
}
