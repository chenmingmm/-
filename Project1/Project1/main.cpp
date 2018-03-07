#include<iostream>
using namespace std;

#include<memory>
#include"Test.h"
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>
#include<string>
#include"BinaryTree.h"



void StrSplit(vector<string> &result, const char*src, const char*pattern)
{
	result.clear();

	if (!src ||!pattern)
		return;

	string str;
	str = src;
	str += pattern;

	string::size_type pos;
	auto size = (unsigned int)str.size();
	int patternSize = (int)strlen(pattern);

	std::string s;

	for (unsigned int i = 0; i < size; i++)
	{
		pos = str.find(pattern,i);
		if (pos<size)
		{
			s = str.substr(i, pos - i);
			result.push_back(s);
			i = unsigned int(int(pos) + patternSize - 1);
		}
	}
}


class A
{
public:
	A(){}
	virtual~A(){}

	void print()
	{
		cout << "A" << endl;
	}
protected:

};

class B :public A
{
public:
	B(){}
	~B(){}

	void print()
	{
		cout << "B" << endl;
	}

	int getnum(int num)
	{
		int re = 0;
		for (int i = 0; i < 32; i++)
		{
			int temp = num | 0;
			num = num >> 1;
			if ((temp%2)==1)
				re++;
			if (temp==0)
				break;
		}
		return re;
	}

	std::vector<int> &countOfSmallerNumberII(vector<int> &A)
	{
		int index = 0;
		static std::vector<int> re;
		for (auto iter : A)
		{
			int sum = 0;
			for (int i = 0; i < index; i++)
			{
				if (A[i]<iter)
				{
					sum++;
				}
			}
			re.push_back(sum);
			index++;
		}
		return re;
	}

	string longestPalindrome(string s) {
		string str = "", ans = "";
		int len = s.length();
		int maxl = -1, cnt;
		for (int i = 0; i < len; i++) {
			str += '#';
			str += s[i];
		}
		str += '#';
		// 将原字符串扩展成#a#b#的形式可以直接枚举长度，不用考虑回文串长度的奇偶性
		for (int i = 1; i < 2 * len; i++) {
			cnt = 0;
			while ((i - cnt >= 0) && (i + cnt <= 2 * len) && (str[i - cnt] == str[i + cnt]))
				cnt++;
			cnt--;
			if (cnt > maxl) {
				maxl = cnt;
				ans = s.substr((i - cnt) / 2, (i + cnt) / 2 - (i - cnt) / 2);
			}
		}
		return ans;
	}
	struct Node
	{
		string str;
		int frequency = 0;
		Node* pLeft = NULL;
		Node* pRight = NULL;
	};
	vector<string> topKFrequentWords(vector<string> &words, int k) {
		// write your code here
		std::map<string, int> vec;

		std::unordered_map<int, string> e;
		for (auto iter : words)
		{
			auto n = vec.find(iter);
			if (n!=vec.end())
				n->second++;
			else
				vec[iter] = 1;
		}
	}

	void swap(int &a, int &b)
	{
		if (a == b)
			return;
		a = a + b;
		b = a - b;
		a = a - b;
	}

	int getPartion(int *array, int low, int high)
	{
		int key = array[low];
		while (low < high)
		{
			while (low < high && key <= array[high]) //如果array[high]大于键值，那么本就应该在键值右边
			{
				high--;  //因此将high下标向前移动，直至找到比键值小的值，此时交换这两个值
			}

			swap(array[low], array[high]);

			while (low < high && key >= array[low])
			{
				low++;
			}

			swap(array[low], array[high]); 
		}
		return low;//返回key值的下标
	}



	void QuitSort(int *buf, int low, int high)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << buf[i] << " ";
		}
		cout << endl;
		if (low < high)
		{
			int key = getPartion(buf, low, high);

			QuitSort(buf, low, key - 1);
			QuitSort(buf, key + 1, high);
		}
	}


private:

};


struct TEST
{
	//std::map<std::string, std::string> m;
	std::vector<std::string> v;
};

int main()
{
	BinaryTree<int> tree;
	std::vector<int> vec = { 1,3,4,5,2,10,9};
	//int arry[] = { 1,2,4,5,6,3 };
	////tree.createBiTree(vec);
	for (auto iter : vec)
	{
		tree.Insert(iter);
	}
	//tree.Insert(7);
	//tree.preOrder();


	tree.preOrder();
	tree.DelNode(3);
	cout << endl;
	tree.preOrder();
	auto a = tree.Find(5);


	std::string str = "1345";
	vector<string> vec_str;
	StrSplit(vec_str, str.c_str(), ";");
	//B a;
	//a.QuitSort(arry, 0, 5);
	system("pause");
}