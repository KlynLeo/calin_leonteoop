#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
ifstream file("text.in");

class cmp {
public:
	bool operator()(pair<string, int> a, pair<string, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
	}
};

bool delim(char c, string exp) {
	for (int i = 0; i < exp.length(); i++)
		if (c == exp[i])
			return true;
	return false;
}

int main() {

	string s;
	string delimitators = ".,?! ";
	vector<string> v;

	getline(file, s);
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	int l = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (delim(c, delimitators)) {
			string s2 = s.substr(l, i - l);
			l = i + 1;
			if (s2.length() > 0) 
				v.push_back(s2);
		}
	}

	vector<string> uniq;
	map<string, int> m;

	for (auto i : v) {
		if (m[i] == 0) 
			uniq.push_back(i);
		m[i]++;
	}

	vector<pair<string, int>> frecv;
	for (auto i : uniq) 
		frecv.push_back(make_pair(i, m[i]));

	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
	for (auto i : frecv) 
		pq.push(i);

	while (!pq.empty()) 
	{
		cout << pq.top().first << " => " << pq.top().second << endl;
		pq.pop();
	}

	return 0;
}