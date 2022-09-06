#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
using std::cout;
using std::endl;
using std::vector;
void
print(vector<vector<int>> & mat){
	for(auto k1 : mat){
		for(auto k2 : k1)
			cout << k2 << " ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	using namespace std;
	vector<vector<int>> max;
	max.resize(2, vector<int>(3, 0));
	print(max);

	vector<vector<int>> ss(9, vector<int>(9, 12));
	print(ss);
	string s;
	cout << s + "222" << endl;
	s += "zhang123";
	for(auto k : s){
		cout << k << " ";
		//string c = k;
		//cout << c << "||" << endl;
		//cout << char('0' + 9) + "tmp";
	}
	cout << endl;
	string c = "0";
	c[0] += 9;
	string s2 = c + "tmp";
	char cc = 'g';
	s2 += cc;
	cout << s2 << endl;
	// test vector ==
	vector<int> t1 = {1, 2, 3};
	vector<int> t2 = {1, 2, 3};
	cout << "test vector" << (t1 == t2) << endl;
	// test reverse ==
	s = to_string(1996);
	std::reverse(s.begin(), s.end());
	cout << s << endl;
	string s3;
	s3 += 'w';
	s3 += 'c';
	cout << s3 << endl;
	return 0;
}	
