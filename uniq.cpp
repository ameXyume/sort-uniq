#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void uniq(vector<string> &svec){
	int i = 0;
	for (auto it = svec.cbegin(); it != svec.cend() && !it -> empty(); ++it, ++i)
		if(svec[i] == svec[i + 1])
			while(svec[i] == svec[i + 1])
				svec.erase(it);
	
}
