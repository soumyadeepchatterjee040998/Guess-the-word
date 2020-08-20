#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<random>
#include<set>
#include<time.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int count = 0;
	vector<string> words;
	ifstream file("WORDS.txt");
	if (!file.is_open())
		cout << "can not open the file" << endl;
	if (file.bad())
		cout << "can not read the file" << endl;
	string s;
	while (getline(file, s))
	{
		count++;
		words.push_back(s);
	}
	srand(time(0));
	int rand_num = rand() % count;
	s = words[rand_num];
	for (int i = 0;i < s.length();i++) 
		s[i] = tolower(s[i]);
	int len = s.length();
	set<char> inp;
	int life = s.length() + int(s.length() / 2);
	for (int i = 0;i < s.length();i++)
	{
		if (s[i] == ' ')
		{
			cout << " ";
			inp.insert(' ');
			life--;
			len--;
		}
		else
			cout << "-";
	}
	cout << endl;
	while (life-- && len!=0)
	{
		cout<<"length : " << len << endl;
		char ch;
		cout << endl <<"Enter a character " << endl;
		cin >> ch;
		if (s.find(ch) != s.npos)
		{
			if (inp.size() == 0 || !binary_search(inp.begin(), inp.end(), ch))
			{
				int c = 0;
				for (int i = 0;i < s.size();i++)
				{
					if (s[i] == ch)
						c++;
				}
				len = len - c;
				system("CLS");
				inp.insert(ch);
				for (int i = 0;i < s.length();i++)
				{
					if (s[i] == ' ')
						cout << " ";
					else if (binary_search(inp.begin(), inp.end(), s[i]))
						cout << s[i];
					else
						cout << "-";
				}
				if (len==0)
				{
					cout << endl << "You Win" << endl;
					exit(1);
				}
			}
			else
			{
				cout << endl << "You have entered that character" << endl;
				life++;
			}
		}
		else
			cout << endl << "Not present " << endl;
		cout << endl << "Your life : " << life << endl;
	}
	cout << endl << "You Loose. Correct word is : " << s << endl;
	cin.get();
	return 0;
}
