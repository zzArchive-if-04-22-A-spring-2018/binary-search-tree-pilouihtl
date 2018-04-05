/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include "general.h"

struct Node{
   int data;
   Bst left;
   Bst right;
};
Bst new_bst(){
  Bst bst = 0;
  return bst;
}
void delete_bst(Bst bst){
  if(bst == 0){
    return;
  }
  delete_bst(bst->right);
  sfree(bst);
  delete_bst(bst->left);
}
int get_depth(Bst bst){
  if(bst == 0){
    return 0;
  }
  int depth = get_depth(bst->left) + 1;
  int elseDepth = get_depth(bst->right) + 1;
  if(depth > elseDepth){
    return depth;
  }
  return elseDepth;
}

void add(Bst* bst, int value)
{
  Bst &root = *bst;
  if(root == 0)
  {
    root = (Bst)malloc(sizeof(struct Node));
    root->data = value;
    root->left = 0;
    root->right = 0;
    bst = &root;
  }
  else if(value <= root->data)
  {
    add(&(root->left), value);
  }
  else if(value > root->data)
  {
    add(&(root->right), value);
  }
}
int root_value(Bst bst){
  if(bst == 0){
    return 0;
  }
  return bst->data;
}
Bst left_subtree(Bst root){
  if(root == 0){
    return 0;
  }
  return root->left;
}
Bst right_subtree(Bst root){
  if(root == 0){
    return 0;
  }
  return root->right;
}
int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst == 0){
    return 0;
  }
  int count = 1;
  elements[start] = bst->data;
  start++;
  count += traverse_pre_order(bst->left, elements, start);
  count += traverse_pre_order(bst->right, elements, start - 1 + count);
  return count;
}
int traverse_in_order(Bst bst, int *elements, int start){
  if(bst == 0){
    return 0;
  }
  int count = 1;
  elements[start] = bst->data;
  start++;
  count += traverse_in_order(bst->right, elements, start);
  count += traverse_in_order(bst->left, elements, start - 1 + count);
  return count;
}
int traverse_post_order(Bst bst, int *elements, int start){
  return 0;
}
bool are_equal(Bst bst1, Bst bst2){
  return false;
}
void most_left_longest_branch(Bst bst, Bst* branch){

}
int get_number_of_subtrees(Bst bst){
  if(bst == 0){
    return 0;
  }
  return 1;
}
