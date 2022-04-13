/*
 * Abbr.hpp
 *
 *  Created on: Apr 19, 2020
 *      Author: 13027
 */

#ifndef ABBR_HPP_
#define ABBR_HPP_
#include "BST.hpp"

class Abbr {
	int prints;
	string fn;
public:
	BST *tree;
	Abbr(string filename, int p);
	void readFile();
	string strip(string s, string def);
	void Interface();
	void translateSentence();
	TNode *getAcr();
	void addPhrases();
	void deletePhrases();
	void printPhrases();
};



#endif /* ABBR_HPP_ */
