/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
 * C++ Program to Implement B+ Tree
 */
#include<stdio.h>
//#include<conio.h>
#include<iostream>
#include <vector>
#include <math.h>
using namespace std;
#define bVal 4
struct Recipe {
    int id;
    string name;
};
struct BPlusTreeNode {
    string names[bVal];//Edit this
    BPlusTreeNode *child_ptr[bVal+1];
    BPlusTreeNode *parent_ptr;
    BPlusTreeNode *prevLeaf;
    BPlusTreeNode *nextLeaf;
    bool leaf;
    Recipe leafData[bVal];
    int n;
}*root = NULL, *np = NULL, *x = NULL;

void insertNew(BPlusTreeNode *cur, Recipe a);
void insertInNode(BPlusTreeNode *cur, BPlusTreeNode *rightChild);

BPlusTreeNode * init() {
    np              = new BPlusTreeNode;
    np->parent_ptr  = NULL;
    np->prevLeaf    = NULL;
    np->nextLeaf    = NULL;
    np->leaf        = true;
    np->n           = 0;
    
    for (int i = 0; i < bVal; i++) {
        np->child_ptr[i] = NULL;
        np->leafData[i].id = 0;
        np->leafData[i].name = "";
    }
    np->child_ptr[bVal] = NULL;
    np->nextLeaf = NULL;
    
    return np;
}

void printBP (struct BPlusTreeNode *r) {
    if (r) {
        printf("\n BP %p : parent %p prevLeaf %p nextLeaf %p leaf %d n %d",
               r, r->parent_ptr, r->prevLeaf, r->nextLeaf, r->leaf, r->n);
        printf("\n Names : ");
        for (int i=0; i<r->n; i++) {
            printf(" %s ", r->names[i].c_str());
        }
        printf("\n Children : ");
        for (int i=0; i<=bVal; i++) {
            printf(" %p", r->child_ptr[i]);
        }
        for (int i=0; i<=bVal; i++) {
            if (r->child_ptr[i]) printBP(r->child_ptr[i]);
        }
        printf("\n Done BP %p", r);
    }
}

vector<Recipe> search(BPlusTreeNode *p, string term, vector<Recipe> result) {
    if (p == NULL) {
        //printf("\n p is NULL");
        return result;
    }

    printf("\n Search n %d", p->n);
    if (p->leaf == false) {
        printf("\n !Leaf : ");
        for (int i = 0; i < p->n; i++) {
            printf(" %s ", p->names[i].c_str());
            if (term.compare(p->names[i]) < 0) {    // term comes before name
                return search(p->child_ptr[i], term, result);     // left child
            }
        }
        return search(p->child_ptr[p->n], term, result);          // right most child
    } else {
        bool found = false;
        printf("\n Leaf : ");
        for (int i = 0; i < p->n; i++) {
            printf(" %s ", p->leafData[i].name.c_str());
            if (p->leafData[i].name.rfind(term, 0) == 0) {          // recipe starts with term
                result.push_back((p->leafData[i]));
                found = true;
            } 
            else {
                if (found) {
                    return result;
                }
            }
        }
        return search(p->nextLeaf, term, result);
    }
}

/*void traverse(BPlusTreeNode *p) {
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
}*/

/*Recipe split_child(BPlusTreeNode *x, int i) {
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
}*/

void leafSplit(BPlusTreeNode *cur, Recipe a) {
    BPlusTreeNode *right = init(); // possibly *right;
    right->leaf = true;
    right->nextLeaf = cur->nextLeaf;
    right->parent_ptr = cur->parent_ptr;
    cur->nextLeaf = right;
    int numToMove = bVal/2;
    int i = bVal-1;
    bool aLeft = true;
    //printBP(cur);
    while(numToMove > 0) {
        printf("\n numToMove %d, a %s cur %s", numToMove, a.name.c_str(), cur->leafData[i].name.c_str());
        printf("\n Cur : ");
        for (int i=0; i< bVal; i++ ) {
            printf(" %s ", cur->leafData[i].name.c_str());
        }
        printf("\n");
        printf("\n Right : ");
        for (int i=0; i< bVal; i++ ) {
            printf(" %s ", right->leafData[i].name.c_str());
        }
        printf("\n");
        if (aLeft && a.name.compare(cur->leafData[i].name) < 0) {
            printf("\n First if");
            insertNew(right, (cur->leafData[i]));
            cur->names[i] = "";
            cur->leafData[i].name = "";
            cur->leafData[i].id = 0;
            i--;
            numToMove--;
            cur->n--;
        } else if (aLeft && a.name.compare(cur->leafData[i].name) >= 0) {
            printf("\n Else if");
            aLeft = false;
            insertNew(right, a);
            numToMove--;
        } else {
            printf("\n Else ");
            insertNew(right, cur->leafData[i]);
            printf("\n Done insertNew");
            cur->names[i] = "";
            cur->leafData[i].name = "";
            cur->leafData[i].id = 0;
            numToMove--;
            cur->n--;
        }
        printf("\n Done while iteration");
    }
    printf("\n Done while - aLeft %d", aLeft);
    if (aLeft) {
        printf("\n aLeft");
        insertNew(cur, a);
        //printBP(cur);
    } else {
        printf("\n !aLeft");
    }

    //cur->n = (int) ceil(bVal/2.0);
   // right->n = bVal/2;
    
    if (cur == root) {                          // create new root node
        printf("\n create a new root node");
        BPlusTreeNode *r = init();
        r->leaf = false;
        r->child_ptr[0] = cur;
        r->child_ptr[1] = right;
        r->n = 1;
        r->names[0] = right->names[0];
        root = r;
        cur->parent_ptr = r;
        right->parent_ptr = r;
    } else {
        printf("\n Calling insertInNode with cur %p", cur);
        insertInNode(cur->parent_ptr, right);
    }
    printf("\n Root :");
    //printBP(root);
    printf("\n End Cur:");
    //printBP(cur);
    printf("\n End Right:");
    //printBP(right);
}

void internalSplit(BPlusTreeNode *cur, BPlusTreeNode *rightChild) {
    BPlusTreeNode *right = init();
    right->leaf = false;
    right->parent_ptr = cur->parent_ptr;
    int numToMove = bVal/2;
    int i = bVal-1;
    bool aLeft = true;
    while(numToMove > 0) {
        if (aLeft && rightChild->names[0].compare(cur->names[i]) < 0) {
            insertInNode(right, cur->child_ptr[i]); //leafData[i]);
            cur->names[i] = "";
            cur->child_ptr[i] = NULL;
            i--;
            numToMove--;
        } else if (aLeft && rightChild->names[0].compare(cur->names[i]) > 0) {
            aLeft = false;
            insertInNode(right, rightChild);
            numToMove--;
        } else {
            insertInNode(right, cur->child_ptr[i]); //leafData[i]);
            cur->names[i] = "";
            cur->child_ptr[i] = NULL;
            numToMove--;
        }
    }
   
    //Recipe a;
    if (aLeft) {
        //insertNew(cur, a);
        insertInNode(cur, rightChild);
    }
    cur->n = (int) ceil(bVal/2.0);
    right->n = bVal/2;
    
    if (cur == root) {                          // create new root node
        BPlusTreeNode *r = init();
        r->leaf = false;
        r->child_ptr[0] = cur;
        r->child_ptr[1] = right;
        r->n = 2;
        r->names[0] = right->names[0];
        root = r;
        cur->parent_ptr = r;
        right->parent_ptr = r;
    } else {
        insertInNode(cur->parent_ptr, right);
    }
}

void insertInNode(BPlusTreeNode *cur, BPlusTreeNode *rightChild) {
    printf("\ninsertInNode : cur %p, rightChild %p", cur, rightChild);
    if (!cur) {
        printf("\n insertInNode NULL pointer");
        return;
    }
    if (!rightChild) {
        printf("\n insertInNode NULL rightChild");
        return;
    }
    if (cur->n < bVal) {                // can insert
        int i = cur->n;
        while(i > 0 && rightChild->names[0].compare(cur->names[i-1]) < 0) {
            cur->names[i] = cur->names[i-1];
            cur->child_ptr[i+1] = cur->child_ptr[i];
            i--;
        }
        cur->names[i] = rightChild->names[0];
        cur->child_ptr[i+1] = rightChild;
        
        rightChild->parent_ptr = cur;
        cur->n++;
    } else {                            // cannot insert, split
        internalSplit(cur, rightChild);
    }
}

void insertNew(BPlusTreeNode *cur, Recipe a) {
    while(cur && (cur->leaf == false)) {
        int i = 0;
        while((i < bVal) && cur->names[i] != "" && cur->names[i].compare(a.name) < 0) {
            i++;
        }
        cur = cur->child_ptr[i];
    }
    if (!cur) {
        printf("\n Error@@@@@@@@@@@@@@");
        return;
    }

    printf("\n cur->n %d", cur?cur->n:-1);
    if (cur->n < bVal) {                // can insert
        printf("\n can insert");
        int i = cur->n;
        while((i > 0) && (a.name.compare(cur->names[i-1]) < 0)) {    // a should be in correct place after this
            printf("\n insertNew i %d", i);
            cur->names[i] = cur->names[i-1];
            cur->leafData[i] = cur->leafData[i-1];
            i--;
        }
        cur->names[i] = a.name;
        cur->leafData[i].name = a.name;
        cur->leafData[i].id = a.id;
            
        cur->n++;
    } else {                            // cannot insert, split
        printf("\n cannot insert, split");
        leafSplit(cur, a);
    }
}
    
    /*
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
    */
int main() {
    int i, n;
    int id;
    string name;
    string instructions;
    root = init();
    x = root;
    //printf(x);

#if 0
    cout<<"enter the no of elements to be inserted\n";
    cin>>n;
#endif
    n = 26;
    string str[27] = {"-","a","b","c","d","e","f","g","h","i","j","k","l","m",
                      "n","o","p","q","r","s","t","u","v","w","x","y","z"};
    for(i = 0; i < n; i++)
    {
        Recipe r;
        r.id = i+1;
        r.name = str[i+1];
#if 0
        cout<<"enter the recipe ID\n";
        cin>>r.id;
        cout<<"enter the recipe name\n";
        cin>>r.name;
#endif
    
        insertNew(root, r);
        printf("\n**** Done inserting %s", r.name.c_str());
        printBP(root);
        printf("\n==== Done printing %s", r.name.c_str());
    }
    printf("\n+++++++++++");
  while (true) {    
    string term = "";
    cout<<"Search:\n";
    cin>>term;
    
    vector<Recipe> result;
    result = search(root, term, result);
    printf("\n");
    
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i].id << "   " << result[i].name << "\n";
    }
    
  }
    getchar();
}
