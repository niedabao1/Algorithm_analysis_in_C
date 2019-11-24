#pragma once
typedef struct TreeNode *PtrToNode;
typedef struct PtrTonode *Tree;
struct TreeNode
{
	char key[10] = { 0 };
	Tree Left;
	Tree Right;
};
struct PtrTonode
{
	char key[10] = { 0 };
	Tree Left;
	Tree Right;
};