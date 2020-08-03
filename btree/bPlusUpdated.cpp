/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
 * C++ Program to Implement B+ Tree
 */
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <vector>
using namespace std;
#define bVal 4
struct Recipe {
    int id;
    string name;
};
struct BPlusTreeNode {
    string *names;//Edit this
    BPlusTreeNode **child_ptr;
    BPlusTreeNode *parent_ptr;
    BPlusTreeNode *nextLeaf;
    bool leaf;
    Recipe **leafData;
    int n;
}*root = NULL, *np = NULL, *x = NULL;
BPlusTreeNode * init() {
    np              = new BPlusTreeNode;
    np->names       = new string[bVal];//Will this be an int?
    np->child_ptr   = new BPlusTreeNode *[bVal+1];
    np->parent_ptr  = NULL;
    np->nextLeaf    = NULL;
    np->leaf        = true;
    np->leafData    = new Recipe *[bVal];
    np->n           = 0;
    
    for (int i = 0; i < bVal; i++) {
        np->child_ptr[i] = NULL;
        np->leafData[i] = NULL;
    }
    np->child_ptr[bVal] = NULL;
    np->nextLeaf = NULL;
    
    return np;
}

vector<Recipe> search(BPlusTreeNode *p, string term, vector<Recipe> result) {
    if (p->leaf == false) {
        for (int i = 0; i < bVal; i++) {
            if (term.compare(p->names[i]) < 0) {    // term comes before name
                return search(p->child_ptr[i]);     // left child
            }
        }
        return search(p->child_ptr[bVal]);          // right most child
    } else {
        for (int i = 0; i < bVal; i++) {
            if (p->leafData[i].name.rfind(term, 0) == 0) {          // recipe starts with term
                result.push_back(p->leafData[i]);
            } else {
                return result;
            }
        }
        return search(p->nextLeaf, term, result);
    }
}

void traverse(BPlusTreeNode *p) {
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->leaf == false) {
            traverse(p->child_ptr[i]);
        }
        cout << " " << p->data[i].name;  // printing name
    } 
    if (p->leaf == false) {
        traverse(p->child_ptr[i]);
    }
    cout<<endl;
}

Recipe split_child(BPlusTreeNode *x, int i) {
    int j;
    Recipe mid;
    BPlusTreeNode *np1, *np3, *y;
    np3 = init();
    np3->leaf = true;
    if (i == -1) {
        mid = x->data[2];
        x->data[2].name = "";         //originally x->data[2] = 0;
        x->n--;
        np1 = init();
        np1->leaf = false;
        x->leaf = true;
        for (j = 3; j < 5; j++) {
            np3->data[j - 3] = x->data[j];
            np3->child_ptr[j - 3] = x->child_ptr[j];
            np3->n++;
            x->data[j].name = "";     //originally x->data[j] = 0;
            x->n--;
        }
        for(j = 0; j < 6; j++) {
            x->child_ptr[j] = NULL;
        }
        np1->data[0] = mid;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    } else {
        y = x->child_ptr[i];
        mid = y->data[2];
        y->data[2].name = "";         //originally y->data[2] = 0;
        y->n--;
        for (j = 3; j < 5; j++) {
            np3->data[j - 3] = y->data[j];
            np3->n++;
            y->data[j].name = "";     //originally y->data[j] = 0;
            y->n--;
        }
        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 1] = np3; 
    }
    return mid;
}

void split(BPlusTreeNode *cur, Recipe a) {
    if (cur->leaf) {
        BPlusTreeNode right;
        right->leaf = true;
        right->nextLeaf = cur->nextLeaf;
        cur->nextLeaf = right;
        int numToMove = bVal/2;
        int i = bVal-1;
        while(numToMove > 0 && a.name.compare(cur->leafData[i].name) < 0) {
            insertNew(right, a);
            cur->leafData[i]
        }
    }
}

void insertInNode(BPlusTreeNode *cur, Recipe a)

void insertNew(BPlusTreeNode *cur, Recipe a) {
    while(cur->leaf == false) {
        int i = 0;
        while(cur->names[i].compare(a.name) < 0) {
            i++;
        }
        cur = cur->child_ptr[i];
    }
    if (cur->n < bVal) {                // can insert
        int i = cur->n;
        while(a.name.compare(cur->leafData[i-1].name) < 0) {          // a should be in correct place after this
            cur->leafData[i] = cur->leafData[i-1];
            cur->leafData[i-1] = a;
        }
        cur->n++;
    } else {                            // cannot insert, split
        split(cur, a)
    }
}
    
    
    int i;
    Recipe temp;
    x = root;
    if (x == NULL) {
        root = init();
        x = root;
    } else {
        if (x->leaf == true && x->n == bVal) {
            temp = split_child(x, -1);
            x = root;
            for (i = 0; i < (x->n); i++) {
                if ((a.name.compare(x->data[i].name) > 0) && (a.name.compare(x->data[i+1].name) < 0)) {  //((a > x->data[i]) && (a < x->data[i + 1])) //The data part?
                    i++;
                    break;
                } else if (a.name.compare(x->data[0].name) < 0) {   //(a < x->data[0])
                    break;
                } else {
                    continue;
                }
            }
            x = x->child_ptr[i];
        } else {
            while (x->leaf == false) {
                for (i = 0; i < (x->n); i++) {
                    if ((a.name.compare(x->data[i].name) > 0) && (a.name.compare(x->data[i+1].name) < 0)) {   //((a > x->data[i]) && (a < x->data[i + 1])) //Data change?
                        i++;
                        break;
                    } else if (a.name.compare(x->data[0].name) < 0) {//(a < x->data[0])
                        break;
                    } else {
                        continue;
                    }
                }
                if ((x->child_ptr[i])->n == bVal) {
                    temp = split_child(x, i);
                    x->data[x->n] = temp;//Data change? i dont think we need it
                    x->n++;
                    continue;
                } else {
                    x = x->child_ptr[i];
                }
            }
        }
    }
    x->data[x->n] = a;
    sort(x->data, x->n);
    x->n++;
}
int main() {
    int i, n;
    int id;
    string name;
    string instructions;
    cout<<"enter the no of elements to be inserted\n";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        Recipe r;
        cout<<"enter the recipe ID\n";
        cin>>r.id;
        cout<<"enter the recipe name\n";
        cin>>r.name;
    
        insert(r);
    }
    cout<<"traversal of constructed tree\n";
    traverse(root);
    getch();
}
