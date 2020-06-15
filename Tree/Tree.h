#pragma once

struct Element {
	int ownerPoints;
	int oppPoints;
	char name[20];
	char opponent[20];

	Element* left;
	Element* right;
	Element* parent;
};
class Tree
{
public:
	Tree();
	~Tree();
	void Print(Element * node);
	Element * Search(Element * node, char * key);
	Element* Min(Element* node);
	Element* Max(Element* node);
	void Insert(Element * newElement);
	void Delete(Element * z = nullptr);
	Element* Next(Element * node);
	Element* Previous(Element* node);
	Element* getRoot();

private:
	Element* root;
};

