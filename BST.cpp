/*
 * BST.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: 13027
 */


#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}
BST::BST(string s, string l) {
	root = new TNode(s,l);
}

bool BST::insert(string s,string l) {
	TNode *node = new TNode(s,l);
	TNode *temp = root;
	TNode *newParent = NULL;
	//bool check = true;
	//bool retBool;
	if(root == NULL){
		root = node;
		setHeight(node);
		return true;
	}else{
		while(true){
			newParent = temp;
			if(node->data->abbr < newParent->data->abbr){
				temp = temp->left;
				if(temp == NULL){
					newParent->left = node;
					node->parent = newParent;
					setHeight(node);
					return true;
				}
			}else if(node->data->abbr > newParent->data->abbr){
				temp = temp->right;
				if(temp == NULL){
					newParent->right = node;
					node->parent = newParent;
					setHeight(node);
					return true;
				}
			}else{
				return false;
			}
		}
	}
}

TNode *BST::find(string s) {
	TNode *temp = root;
	//temp->data->abbr; == s
	while(temp->data->abbr != s){
		if(temp != NULL){
			if(temp->data->abbr > s){
				temp = temp->left;
			}else{
				temp = temp->right;
			}

			if(temp == NULL){
				return NULL;
			}
		}
	}
	return temp;
}



void BST::setHeight(TNode *tmp) {
	if(tmp == NULL){
		return;
	}else if(tmp->left == NULL && tmp->right == NULL){ //has zero children (leaf)
		setHeight(tmp->parent);
	}else if(tmp->left != NULL && tmp->right == NULL){ // at least has a kid
		tmp->height = tmp->left->height + 1;
		setHeight(tmp->parent);
	}else if(tmp->right != NULL && tmp->left == NULL){
		tmp->height = tmp->right->height + 1;
		setHeight(tmp->parent);
	}else if(tmp->left != NULL && tmp->right != NULL){
		if(tmp->left->height >= tmp->right->height){
			tmp->height = tmp->left->height + 1;
			setHeight(tmp->parent);
		}else if(tmp->left->height < tmp->right->height){
			tmp->height = (tmp->right->height) + 1;
			setHeight(tmp->parent);
		}
	}
}
void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}
void BST::printTreeIO(TNode *tmp) {
	if(tmp == NULL){
		return;
	}
	printTreeIO(tmp->left);
	cout<<tmp->data->abbr<<","<<tmp->data->meaning<<","<<tmp->height<<endl;
	printTreeIO(tmp->right);
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}
void BST::printTreePre(TNode *tmp) {
	if(tmp == NULL){
		return;
	}
	cout<<tmp->data->abbr<<","<<tmp->data->meaning<<","<<tmp->height<<endl;
	printTreePre(tmp->left);
	printTreePre(tmp->right);
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePost(TNode *tmp) {
	if(tmp == NULL){
		return;
	}
	printTreePost(tmp->left);
	printTreePost(tmp->right);
	cout<<tmp->data->abbr<<","<<tmp->data->meaning<<","<<tmp->height<<endl;
}
void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		//tmp->printNode();  // for testing, comment back in
		delete(tmp);
	}
}

TNode *BST::removeNoKids(TNode *tmp) {
	if(tmp->parent->left == tmp){
		tmp->parent->left = NULL;
		tmp->parent = NULL;
	}else if(tmp->parent->right == tmp){
		tmp->parent->right = NULL;
		tmp->parent = NULL;
	}
	return tmp;
}
TNode *BST::removeOneKid(TNode *tmp,bool leftFlag) {
	if(tmp->parent->right == tmp){
		if(leftFlag){
			tmp->parent->right = tmp->left;
			tmp->left->parent = tmp->parent;
		}else{
			tmp->parent->right = tmp->right;
			tmp->right->parent = tmp->parent;
		}
	}else if(tmp->parent->left == tmp){
		if(leftFlag){
			tmp->parent->left = tmp->left;
			tmp->left->parent = tmp->parent;
		}else{
			tmp->parent->left = tmp->right;
			tmp->right->parent = tmp->parent;
		}
	}
	return tmp;
}
TNode *BST::remove(string s) {
	TNode *current = root;
	TNode *removed;
	while(current->data->abbr != s){
		if(s > current->data->abbr){
			current = current->right;
		}else if(s < current->data->abbr){
			current = current->left;
		}
	}
	if(current->left != NULL && current->right != NULL){ //double kid
		TNode *replace = current->left;
		while(replace->right != NULL){
			replace = replace->right;
		}
		current->data = replace->data;
		if(replace->left == NULL && replace->right == NULL){
			removed = removeNoKids(replace);
		}else{
			if(replace->left != NULL){ //left one kid
				removed = removeOneKid(replace, true);
			}else{ // right one kid
				removed = removeOneKid(replace, false);
			}
		}
	}else{
		if(current->left == NULL && current->right == NULL){ //Leaf
			removed = removeNoKids(current);
		}else{
			if(current->left != NULL){ //left one kid
				removed = removeOneKid(current, true);
			}else{ // right one kid
				removed = removeOneKid(current, false);
			}
		}
	}
	return removed;

}

