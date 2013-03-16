#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node node;

struct _node {
    char *key;
    char *value;
    node *child;
    node *sibling;
};

node* with(node *root, char *part) {
    //fprintf(stderr, "%s\n", part);
    char *value = malloc(strlen(part));
    strcpy(value, part);

    char *key = strsep(&value, "=");

    node *child = root->child;
    for (child = root->child; child != NULL; child = child->sibling) {
        if (strcmp(child->key, key) == 0) {
            return child;
        }
    }

    //fprintf(stderr, "* %s > %s\n", root->key, key);
    child = malloc(sizeof(node));
    child->child = NULL;
    child->sibling = root->child;

    child->key = key;
    child->value = value;

    return root->child = child;
}

node* parse() {
    node *root = malloc(sizeof(node)); 
    root->key = "root";
    root->child = NULL;
    root->sibling = NULL;

    char *line = NULL;
    size_t capacity = 0;
    size_t read;

    while ((read = getline(&line, &capacity, stdin)) != -1) {
        //fprintf(stderr, "# %d %d\n", line[read], line[read-1]);
        line[read - 1] = '\0';
        node *n = root;
        char *lne = line;
        char *part;
        while ((part = strsep(&lne, ".")) != NULL) {
            n = with(n, part);
        }
    }

    free(line);

    return root;
}

void do_indent(int n) {
    int i;
    for (i = 0; i < n; ++i) {
        putchar(' ');
    }
}

void print(node *root, int indent) {
    if (root->child == NULL) {
        printf("\"%s\"", root->value);
        return;
    }

    printf("{\n");
    node *n = root->child;
    while (n != NULL) {
        do_indent(indent + 2);
        printf("\"%s\" : ", n->key);
        print(n, indent + 2);
        n = n->sibling;
        if (n != NULL) {
            putchar(',');
        }
        putchar('\n');
    }
    do_indent(indent);
    printf("}");
}

int main() {
    node *root = parse();
    print(root, 0);

    return 0;
}
