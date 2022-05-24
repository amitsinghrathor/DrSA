#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Node
{
public:
	char character = -1;
	int frequency = -1;

	Node *parent = nullptr;
	Node *left = nullptr;
	Node *right = nullptr;

	Node(char c, int f) : character(c),
						  frequency(f) {}
	Node(char c, int f, Node *l, Node *r) : character(c),
											frequency(f),
											left(l),
											right(r) {}
};

struct comparator
{
	bool operator()(const Node *n1, const Node *n2) const
	{
		return n1->frequency > n1->frequency;
	}
};

class HuffmanTree
{
public:
	Node *head = new Node(-1, -1);
	unordered_map<char, Node *> leafMap;

	HuffmanTree(unordered_map<char, int> freqMap)
	{
		build(freqMap);
	}

	HuffmanTree(string source)
	{
		unordered_map<char, int> freqMap;
		for (char c : source)
		{
			if (freqMap[c])
				freqMap[c]++;
			else
				freqMap[c] = 1;
		}

		build(freqMap);
	}

	void build(unordered_map<char, int> freqMap)
	{
		priority_queue<Node *, vector<Node *>, comparator> characters;
		for (pair<char, int> p : freqMap)
		{
			Node *n = new Node(p.first, p.second);
			characters.push(n);
		}

		while (!characters.empty())
		{
			if (characters.size() == 1)
			{
				head = characters.top();
				characters.pop();
			}
			else
			{
				Node *left = characters.top();
				characters.pop();

				Node *right = characters.top();
				characters.pop();

				if (left->character != -1)
					leafMap[left->character] = left;
				if (right->character != -1)
					leafMap[right->character] = right;

				Node *parent = new Node(-1, left->frequency + right->frequency, left, right);
				characters.push(parent);

				left->parent = parent;
				right->parent = parent;
			}
		}
	}

	string encode(char source)
	{
		string encoded = "";

		Node *current = leafMap[source];
		while (current->parent)
		{
			if (current == current->parent->left)
				encoded = "0" + encoded;
			else if (current = current->parent->right)
				encoded = "1" + encoded;

			current = current->parent;
		}

		return encoded;
	}

	string encode(string source)
	{
		string encoded = "";

		for (char c : source)
		{
			encoded += encode(c);
		}

		return encoded;
	}

	string decode(string source)
	{
		string decoded = "";

		int i = 0;
		while (i < source.length())
		{
			Node *current = head;
			while (current->left || current->right)
			{
				if (source[i] == '0')
					current = current->left;
				else
					current = current->right;

				i++;
			}
			decoded += current->character;
		}

		return decoded;
	}

	HuffmanTree &printCodes()
	{
		cout << "\nHuffman Codes:\n";
		for (pair<char, Node *> p : leafMap)
		{
			cout << "  " << p.first << " - " << encode(p.first) << endl;
		}
		return *this;
	}
};

int main()
{
	HuffmanTree H(unordered_map<char, int>{
		{'a', 5},
		{'b', 9},
		{'c', 12},
		{'d', 13},
		{'e', 16},
		{'f', 45}});
	H.printCodes();

	string toDecode = "1101111100101111001";
	cout << "\nDecoding '" << toDecode << "': " << H.decode(toDecode) << "\n\n";

	cout << "\nPress Enter to continue...";
	cin.get();
}