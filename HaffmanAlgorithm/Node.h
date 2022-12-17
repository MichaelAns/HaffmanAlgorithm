#pragma once
class Node
{
	public:
		char symbol;
		int occurence;
		Node* left;
		Node* right;
		Node() {}
		Node(Node* l, Node* r) {
			left = l;
			right = r;
			occurence = l->occurence + r->occurence;
		}
};

