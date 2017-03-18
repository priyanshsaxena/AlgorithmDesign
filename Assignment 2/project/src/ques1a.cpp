#include <bits/stdc++.h>

using namespace std;

class HuffmanTreeNode {

		float frequency;
		string character;
		HuffmanTreeNode *left, *right;

	public:

		HuffmanTreeNode(float freq, string chr) {
			left = right = NULL;
			character = chr;
			frequency = freq;  
		}

		void assignLeft(HuffmanTreeNode *node) {
			this->left = node;
		}

		void assignRight(HuffmanTreeNode *node) {
			this->right = node;
		}

		HuffmanTreeNode * getRight() {
			return this->right;
		}

		HuffmanTreeNode * getLeft() {
			return this->left;
		}

		float getFrequency() {
			return frequency;
		}

		string getCharacter() {
			return character;
		}

};

void traverseTree(HuffmanTreeNode *node, string output) {
	HuffmanTreeNode currentNode = *node;
	if(currentNode.getCharacter().size()>1) {
		if(currentNode.getLeft() != NULL) traverseTree(currentNode.getLeft(),output+"0");
		if(currentNode.getRight() != NULL) traverseTree(currentNode.getRight(),output+"1");
	}
	else cout << currentNode.getCharacter() << ":" << output << "\n";
}

class Comparator {
	public:
		bool operator() (HuffmanTreeNode *a, HuffmanTreeNode *b) {
			return a->getFrequency() > b->getFrequency();
		}
};

int main() {
	int n;
	cin >> n;
	priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Comparator > pQueue;
	for(int i=0;i<n;i++) {
		string str;
		float frequency;
		cin >> str >> frequency;
		pQueue.push(new HuffmanTreeNode(frequency,str));
	}
	HuffmanTreeNode *leftNode, *rightNode, *parentNode;
	while(n-- > 1) {
		leftNode = pQueue.top();
		pQueue.pop();
		rightNode = pQueue.top();
		pQueue.pop();
		parentNode = new HuffmanTreeNode((leftNode->getFrequency()+rightNode->getFrequency()),(leftNode->getCharacter()+rightNode->getCharacter()));
		parentNode->assignRight(rightNode);
		parentNode->assignLeft(leftNode);
		pQueue.push(parentNode);
	}
	traverseTree(parentNode,"");
	return 0;
}