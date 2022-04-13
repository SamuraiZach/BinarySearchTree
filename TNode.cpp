/*
 * TNode.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: 13027
 */

#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string s, string l) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	data = new Phrase(s,l);
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	data = new Phrase();
}
TNode::~TNode(){
	cout <<"Deleting "<<data->abbr<<endl;  // comment in for testing purposes
}
void TNode::printNode() {
	cout << data->abbr<<","<<data->meaning<<","<<height<<endl;
}
