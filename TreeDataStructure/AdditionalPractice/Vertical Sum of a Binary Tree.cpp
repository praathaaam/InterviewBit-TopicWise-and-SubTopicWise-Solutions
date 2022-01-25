//Link: https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/

/*
Problem Description
 
 

You are given the root of a binary tree A.

You have to find the vertical sum of the tree.

A vertical sum denotes an array of sum of the different verticals of a binary tree,

where the leftmost vertical sum is the first element of the array and rightmost vertical is the last.



Problem Constraints
1 <= Number of nodes in the binary tree <= 105
1 <= Ai <= 103


Input Format
The first argument is the root of a binary tree A.


Output Format
Return an array denoting the vertical sum of the binary tree.


Example Input
Input 1:
A =     1
      /   \
     2     3
    / \   / \
   4   5 6   7
Input 2:

A =     1
       /
      2
     /
    3


Example Output
Output 1:
[4, 2, 12, 3, 7]
Output 2:

[3, 2, 1]


Example Explanation
Explanation 1:
The element 4 is present in the leftmost vertical. 
The middle vertical consists of 3 elements 1, 5, 6.
The resultant array is [4, 2, 12, 3, 7].
Explanation 2:

The leftmost vertical is the element 3. The next verticals are 2 and 1.
Hence, the resultant array is [3, 2, 1].
*/

//Code

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void vSumR(TreeNode* root, int hd, map<int,int> &mp)
 {
     if(root==NULL) return;
     vSumR(root->left,hd-1,mp);
     mp[hd]+=root->val;
     vSumR(root->right,hd+1,mp);
 }

vector<int> Solution::verticalSum(TreeNode* root) 
{
    vector<int> ans;
    map<int,int> mp;
    vSumR(root,0,mp);
    for(auto sum:mp)
        ans.push_back(sum.second);
    return ans;
}
