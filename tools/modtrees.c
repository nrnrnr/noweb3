#line 14 "modtrees.nw"
static char rcsid[] = "$Id: modtrees.nw,v 2.21 2006/06/12 21:03:53 nr Exp nr $";
static char rcsname[] = "$Name: v2_11b $";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strsave.h"
#include "modules.h"
#include "modtrees.h"
#include "errors.h"

typedef struct tnode {          /* tree node */
  struct tnode *left, *right;
  Module data;
} TNODE;

static struct tnode *root=NULL;
        
#line 60 "modtrees.nw"
static Module insert_tree(TNODE **rootptr, char *modname);
static Module lookup_tree(TNODE **rootptr, char *modname);
#line 33 "modtrees.nw"
Module insert (char *modname) {
    return insert_tree (&root, modname);
}

static Module
insert_tree(TNODE **rootptr, char *modname) {
     if (*rootptr==NULL) {
         
#line 56 "modtrees.nw"
       checkptr(*rootptr=(struct tnode *) malloc (sizeof(struct tnode)));
       (*rootptr)->left = (*rootptr)->right = NULL;
#line 41 "modtrees.nw"
         return (*rootptr)->data = newmodule(modname);
     } 
     if (strcmp((*rootptr)->data->name,modname)==0) {
         return (*rootptr)->data;
     } else if (strcmp((*rootptr)->data->name,modname)<0) {
         return insert_tree(&((*rootptr)->left),modname);
     } else /* >0 */ {
         return insert_tree(&((*rootptr)->right),modname);
     }

}
#line 64 "modtrees.nw"
Module lookup (char *modname) {
    return lookup_tree (&root, modname);
}

static Module
lookup_tree(TNODE **rootptr, char *modname) {
     if (*rootptr==NULL) {
        return NULL;
     } 
     if (strcmp((*rootptr)->data->name,modname)==0) {
         return (*rootptr)->data;
     } else if (strcmp((*rootptr)->data->name,modname)<0) {
         return lookup_tree(&((*rootptr)->left),modname);
     } else /* >0 */ {
         return lookup_tree(&((*rootptr)->right),modname);
     }
}
#line 88 "modtrees.nw"
static
void apply_to_tree(TNODE *p, void (*fun)(Module)) {
    if (p != NULL) {
        apply_to_tree(p->left,fun);
        (*fun)(p->data);
        apply_to_tree(p->right,fun);
    }
}
void apply_each_module(void (*fun)(Module)) {
    apply_to_tree(root,fun);
}
