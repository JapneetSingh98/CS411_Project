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
using namespace std;
#define bVal 4
struct Recipe {
    int id;
    string name;
    string instructions;
    int prepTime;
    int cookTime;
    int servings;
};
struct BPlusTreeNode {
    Recipe *data;//Edit this
    BPlusTreeNode **child_ptr;
    BPlusTreeNode *parent_ptr;
    BPlusTreeNode *next;
    bool leaf;
    int n;
}*root = NULL, *np = NULL, *x = NULL;
BPlusTreeNode * init() {
    np = new BPlusTreeNode;
    np->data = new Recipe[bVal];//Will this be an int?
    np->child_ptr = new BPlusTreeNode *[bVal+1];
    np->next = NULL;
    np->leaf = true;
    np->n = 0;
    for (int i = 0; i < bVal+1; i++) {
        np->child_ptr[i] = NULL;
    }
    return np;
}

vector<int> search(BPlusTreeNode *p, string term) {
    
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
void sort(Recipe *p, int n) {
    int i, j;
    Recipe temp;
    for (i = 0; i < n; i++) {
        for (j = i; j <= n; j++) {
            if ( p[i].name.compare(p[j].name) > 0) { //p[i].name > p[j].name)
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
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
void insert(Recipe a) {
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
        cout<<"enter the recipe instructions\n";
        cin>>r.instructions;
    
        insert(r);
    }
    cout<<"traversal of constructed tree\n";
    traverse(root);
    getch();
}
