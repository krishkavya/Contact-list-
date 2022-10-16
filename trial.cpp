#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	unordered_map<char,TrieNode*> child;
	bool isLast;//to check the end node
	TrieNode()
	{
		for (char i = 'a'; i <= 'z'; i++)
			child[i] = NULL;

		isLast = false;
	}
};
TrieNode *root = NULL;
void insert(string s)
{
	int len = s.length();
	TrieNode *itr = root;
	for (int i = 0; i < len; i++)
	{
		TrieNode *nextNode = itr->child[s[i]];
		if (nextNode == NULL)
		{
			nextNode = new TrieNode();

			itr->child[s[i]] = nextNode;
		}

		itr = nextNode;

		if (i == len - 1)
			itr->isLast = true;
	}
}

void display_each(TrieNode *curNode, string prefix)
{
	if (curNode->isLast)
		cout << prefix << endl;
	for (char i = 'a'; i <= 'z'; i++)
	{
		TrieNode *nextNode = curNode->child[i];
		if (nextNode != NULL)
			display_each(nextNode, prefix + (char)i);
	}
}
void display(string str)
{
	TrieNode *prevNode = root;

	string prefix = "";
	int len = str.length();
	int i;
	for (i=0; i<len; i++)
	{
		prefix += (char)str[i];
		char lastChar = prefix[i];
		TrieNode *curNode = prevNode->child[lastChar];
		if (curNode == NULL)
		{
			cout << "No Results Found for " << prefix<<endl;
			i++;
			break;
		}
		cout << "results for " << prefix
			<< " are:"<<endl;
		display_each(curNode, prefix);
		prevNode = curNode;
	}

	for (; i<len; i++)
	{
		prefix += (char)str[i];
		cout << "No Results Found for " << prefix
			<<endl;
	}
}

void Trie_insert(ofstream &contacts,int n)
{
	root = new TrieNode();

	//contacts
	while(!contacts.eof()){
        string line = getline(contacts,line);
        inser
}
    }

int main()
{
	string line;
    int n=-1;
    ifstream contacts("input.txt");
    if(contacts.is_open())
    {
        while(!contacts.eof())
        {
            getline(contacts,line);
            n++;
        }
    }

	Trie_insert(contacts, n);

	string to_search;
	cin>>to_search;
	display(to_search);

	return 0;
}