#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include "QuarternaryTree.h"



////Written by Piotr Senkow, Boyan Kukov, and Sarah Anderson December 2016

using namespace std;

void QuarterTree::InsertNode(char * word) { //to create our tree from sequences

	if (!Root) {	//should be a root, if not we're going to make one from the first char
		Root = createNode(word[0]);
	}
	QTreeNode *ptr; //pointer to access node values
	ptr = Root; //start from the Root
	int i = 1; //start from first relevant character since we will have root already

	while (i < strlen(word)) {
		if (word[i] == 'a') { //test for character 'a'
			if (ptr->aChild) {
				ptr = ptr->aChild;
			} //if aChild exists, move there 
			else {
				ptr->aChild = createNode(word[i]);
				ptr = ptr->aChild;
			} //if aChild doesn't exist, create one
			i++;
		}
		else if (word[i] == 'g') {
			if (ptr->gChild) {
				ptr = ptr->gChild;
			}	//if gChild exists move there
			else {
				ptr->gChild = createNode(word[i]);
				ptr = ptr->gChild;
			}	//if gChild doesn't exist, create one
			i++;
		}
		else if (word[i] == 'c') { //same for cChild
			if (ptr->cChild) {
				ptr = ptr->cChild;
			}
			else {
				ptr->cChild = createNode(word[i]);
				ptr = ptr->cChild;
			}
			i++;
		}
		else if (word[i] == 't') { //same for tChild
			if (ptr->tChild) {
				ptr = ptr->tChild;
			}
			else {
				ptr->tChild = createNode(word[i]);
				ptr = ptr->tChild;
			}
			i++;
		}
	}
}
QTreeNode * QuarterTree::createNode(char val) {
	QTreeNode *newnode = new QTreeNode();
	newnode->Data = val; //storing value 
	newnode->aChild = NULL; //all four children are initialized to NULL 
	newnode->gChild = NULL;
	newnode->cChild = NULL;
	newnode->tChild = NULL;
	return newnode;
}

int QuarterTree::CountNodes(QTreeNode* Root) { //input needs to be the Root Node as a start
	if (Root == NULL) { return 0; } //if the root is null, tree empty and has no nodes except root (so 0); 
	else { //otherwise count through each of the four options and add 1 for root
		return (1 + CountNodes(Root->aChild) + CountNodes(Root->gChild) + CountNodes(Root->cChild) + CountNodes(Root->tChild));
	}
}

int QuarterTree::ComputeHeight(QTreeNode*  Root) {
	int aHeight, gHeight, cHeight, tHeight;
	if (Root == NULL) { return 0; } //if tree has no height return 0

	aHeight = ComputeHeight(Root->aChild); //recursive call down 'a' 
	gHeight = ComputeHeight(Root->gChild); //recursive call down 'g' 
	cHeight = ComputeHeight(Root->cChild); //recursive call down 'c' 
	tHeight = ComputeHeight(Root->tChild); //recursive call down 'g' 

	int left = fmax(aHeight, gHeight);
	int right = fmax(cHeight, tHeight);
	int largest = fmax(left, right);
	//find the largest of the computed heights using fmax and add 1 for height of tree

	return largest + 1;
}

char QuarterTree::TraverseTree(char * sequence) {
	if (!Root) { return '!'; }
	int size = 0;
	size = strlen(sequence);
	QTreeNode *ptr; //pointer to access node values
	ptr = Root;//starting from Root if e
	int i = 1; //start from first relevant character since we will have root already
	while (i < (size - 1)) {
		cout << "Checking character : " << sequence[i] << endl;
		if (sequence[i] == 'a') { //moving to 'a' child if 'a'
			if (ptr->aChild) { ptr = ptr->aChild; i++; }
			else { cout << endl << "Sequence broken at character : " << sequence[i] << " at iteration " << i << endl; break; }
		}
		else if (sequence[i] == 'g') { //moving to 'g' child if 'g'
			if (ptr->gChild) { ptr = ptr->gChild; i++; }
			else { cout << endl << "Sequence broken at character : " << sequence[i] << " at iteration " << i << endl; break; }
		}
		else if (sequence[i] == 'c') { //moving to 'c' child if 'c'
			if (ptr->cChild) { ptr = ptr->cChild; i++; }
			else { cout << endl << "Sequence broken at character : " << sequence[i] << " at iteration " << i << endl; break; }
		}
		else if (sequence[i] == 't') { //moving to 't' child if 't'
			if (ptr->tChild) { ptr = ptr->tChild; i++; }
			else { cout << endl << "Sequence broken at character : " << sequence[i] << " at iteration " << i << endl; break; }
		}
		else {
			cout << "Maria, this is the wrong letter, don't do this." << endl; break;
		}
	}
	if (i == (size - 1)) //if it finished iterations, it gives you this 
	{
		cout << endl << "CONGRATULATIONS YOU HAVE A HORRIBLE DISEASE : " << endl << endl << sequence << endl << endl;

	}
	else { cout << endl << "Unable to find Sequence : " << endl << endl << sequence << endl << endl; }
	return '!';
}