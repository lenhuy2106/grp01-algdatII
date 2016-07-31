#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string IOImport(const string file){
	string input = "";

	ifstream read(file);
	getline(read, input);
	cout << input << endl;

	return input;
}

vector<string> splitString(const string input){
	istringstream iss(input);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(tokens));

	return tokens;
}

int main() {
	vector<string> tokenList = splitString(IOImport("input.txt"));
}

