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
	else {
		cout << currentNode.getCharacter() << ":" << output << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	vector<HuffmanTreeNode *> v;
	for(int i=0;i<n;i++) {
		string str;
		float frequency;
		cin >> str >> frequency;
		v.push_back(new HuffmanTreeNode(frequency,str));
	}
	HuffmanTreeNode *leftNode, *rightNode, *parentNode;
	while(n > 1) {
		for(int i=n-1;i>n-3;i--) {
			HuffmanTreeNode *minimum = v[i];
			int index = i;
			for(int j=0;j<i;j++) {
				if(minimum->getFrequency()>v[j]->getFrequency()) {
					minimum = v[j];
					index = j;
				}
			}
			swap(v[i],v[index]);
		}
		leftNode = v[n-1];
		rightNode = v[n-2];
		parentNode = new HuffmanTreeNode((leftNode->getFrequency()+rightNode->getFrequency()),(leftNode->getCharacter()+rightNode->getCharacter()));
		parentNode->assignRight(rightNode);
		parentNode->assignLeft(leftNode);
		v[n---2] = parentNode;
	}
	traverseTree(parentNode,"");
	return 0;
}