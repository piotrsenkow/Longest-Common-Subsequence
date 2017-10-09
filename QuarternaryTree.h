#include<iostream>
//Written by Piotr Senkow, Boyan Kukov, and Sarah Anderson December 2016
using namespace std;

class QTreeNode {
public:
	char Data;
	QTreeNode *aChild;
	QTreeNode *gChild;
	QTreeNode *cChild;
	QTreeNode *tChild;
};

class QuarterTree {
public:
	QTreeNode *Root;
public:
	QuarterTree() {
		Root = NULL;
	}
	void InsertNode(char * word);
	QTreeNode* createNode(char val);
	int CountNodes(QTreeNode*node);
	int ComputeHeight(QTreeNode*  Root);
	char TraverseTree(char * sequence);
}; 
#pragma once
