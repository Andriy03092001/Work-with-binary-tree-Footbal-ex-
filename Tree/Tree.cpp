#include "Tree.h"
#include<iostream>
#include<ctime>
using namespace std;

Tree::Tree()
{
	root = nullptr;
}


Tree::~Tree()
{
	Delete();
}

void Tree::Print(Element* node)
{
	if (node != 0)
	{
		Print(node->left);
		cout << node->name << " vs " << node->opponent
		<< "(" << node->ownerPoints<< ":" << node->oppPoints << ")" << endl;
		Print(node->right);
	}
}

Element* Tree::Search(Element* node, char* key)
{
	while (node != nullptr && strcmp(key, node->name) != 0)
	{
		if (strcmp(key, node->name) < 0)
		{
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return node;
}

Element* Tree::Min(Element* node)
{
	//Пошук самого лівого значення, яке є і саме маленьке значення!
	if (node != nullptr)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
	}
	return node;
}

Element* Tree::Max(Element* node)
{
	if (node != nullptr)
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
	}
	return node;
}

void Tree::Insert(Element* newElement)
{
	newElement->left = nullptr;
	newElement->right = nullptr;

	Element* temp = nullptr; // указатель на будущого батька
	Element* node = root;

	//пошук місця
	while (node != nullptr)
	{
		temp = node;
		if (strcmp(newElement->name, temp->name) < 0)
		{
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	newElement->parent = temp;
	if (temp == nullptr)
	{
		root = newElement;
	}
	else if (strcmp(newElement->name, temp->name) < 0) {
		temp->left = newElement;
	}
	else{
		temp->right = newElement;
	}
}

void Tree::Delete(Element* z)
{
	if (z != nullptr)
	{
		Element* node;
		Element* temp;

		if (z->left == nullptr || z->right == nullptr)
		{
			temp = z;
		}
		else {
			temp = Next(z);
		}

		if (temp->left != nullptr) {
			node = temp->left;
		}
		else {
			node = temp->right;
		}

		if (node != nullptr) {
			node->parent = temp->parent;
		}
		if (temp->parent == nullptr) {
			root = node;
		}
		else if(temp == temp->parent->left){
			temp->parent->left = node;
		}
		else {
			temp->parent->right = node;
		}
		if (temp!=z) {
			strcpy(z->name, temp->name);
			strcpy(z->opponent, temp->opponent);
			z->oppPoints = temp->oppPoints;
			z->ownerPoints = temp->ownerPoints;
		}

		delete temp;
	}
	else {
		while (root != nullptr)
		{
			Delete(root);
		}
	}



}

Element* Tree::Next(Element* node)
{
	Element* temp = nullptr;
	if (node != nullptr) {

		if (node->right != nullptr)
		{
			return Min(node->right);
		}

		temp = node->parent;

		while (temp != nullptr && node == temp->right)
		{
			node = temp;
			temp = temp->parent;
		}

	}

	return temp;

}

Element* Tree::Previous(Element* node)
{
	Element* temp = nullptr;
	if (node != nullptr) {

		if (node->left != nullptr)
		{
			return Max(node->left);
		}
		temp = node->parent;
		while (temp != nullptr && node == temp->left)
		{
			node = temp;
			temp = temp->parent;
		}
	}
	return temp;
}

Element* Tree::getRoot()
{
	return this->root;
}
