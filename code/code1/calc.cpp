/** build parse tree for an expression
 *
 */
#include <iostream>
using namespace std;
const char* expr = "1 + 2 * 3 / 5 + 6 - ( 8 * 2 )";

enum Op{NONE, PLUS, MINUS, MULT, DIV};

struct node{
    Op op;
    int v;
    node* left;
    node* right;
}


