#pragma once
#include<string>
#include<deque>
using namespace std;
class judge {
private:
	string Name,codePath,cplPath;
	deque<deque<long long> > testPoints;
	deque<long long> answerPoints;
	long long tot = 0;
public:
	judge(string Name, string codePath) :Name(Name), codePath(codePath) {
		
	}

	~judge() = default;

	void cpl(string fileName) {

	}
};