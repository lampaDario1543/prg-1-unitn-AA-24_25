#include <iostream>
#include <cstdlib>

using namespace std;

struct tree
{
    int info;
    tree *left;
    tree *right;
};

const int MAXVALUE=100;

void insert(tree *&result, const int num)
{
    if (result == NULL)
    {
        result = new tree;
        *result = {num, NULL, NULL};
    }
    else if (result->info < num)
    {
        insert(result->left, num);
    }
    else
    {
        insert(result->right, num);
    }
}

tree *crea_tree(const int num)
{
    tree *result = NULL;
    for (int i = 0; i < num; i++)
    {
        insert(result, rand() % MAXVALUE);
    }
    return result;
}

void print_tree_l(const tree *root)
{
    if (root != NULL)
    {
        print_tree_l(root->right);
        std::cout << " " << root->info;
        print_tree_l(root->left);
    }
}

void print_tree_t(tree *root, int spazio = 0)
{
    if (root != NULL)
    {
        spazio++;
        print_tree_t(root->right, spazio);

        for (int i = 1; i < spazio; i++)
            std::cout << "  ";
        std::cout << root->info << "\n";
        print_tree_t(root->left, spazio);
    }
}

void delete_tree(tree *&root)
{
    if (root != NULL)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = NULL;
    }
}

void move(tree *& root, tree *& n){
    if(n->info>root->info){
        if(root->right==NULL){
            root->right=n;
            return;
        }
        move(root->right,n);
    }else{
        if(root->left==NULL){
            root->left=n;
            return;
        }
        move(root->left,n);
    }
}

int main(){
    tree * root = crea_tree(10);
    print_tree_t(root);
    cout << "_----------------------------"<<endl;
    print_tree_t(root);
    delete_tree(root);
    return 0;
}