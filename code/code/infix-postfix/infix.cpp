#include <map>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

map<string, int> priorities;

class Operator {
  public:
    virtual int apply(int l, int r) =0;
};

map<string, Operator*> operators;

class Plus : public Operator {
  virtual int apply(int l, int r) {
    return l + r;
  }
};
class Minus : public Operator {
  virtual int apply(int l, int r) {
    return l - r;
  }
};
class Multiply : public Operator {
  virtual int apply(int l, int r) {
    return l * r;
  }
};
class Divide : public Operator {
  virtual int apply(int l, int r) {
    return l / r;
  }
};

vector<string> topostfix(string expr[], int len) {
  stack<string> pending;
  vector<string> postfix;
  postfix.push_back(expr[0]);

  for(int i = 1; i < len; i += 2) {
    string curr_op = expr[i];
    string opnd = expr[i+1];

    int curr_prio = priorities[curr_op];

    while(!pending.empty()) {
      string top = pending.top();
      int top_prio = priorities[top];

      if (curr_prio > top_prio) break;

      pending.pop();
      postfix.push_back(top);
    }

    postfix.push_back(opnd);
    pending.push(curr_op);
  }

  while(!pending.empty()) {
      string top = pending.top(); pending.pop();
      postfix.push_back(top);
  }
  return postfix;
}

int main() {
  priorities["/"] = 4;
  priorities["*"] = 3;
  priorities["+"] = 2;
  priorities["-"] = 2;

  operators["/"] = new Divide();
  operators["*"] = new Multiply();
  operators["-"] = new Minus();
  operators["+"] = new Plus();

  string expr[] = {"3", "*", "4", "-", "2", "+", "1", "*", "6", "/", "6", "*", "3"};
  /*
   * 3 * 4 - 2 + 1 * 6 / 6 * 3
   * 3 4 * 2 - 1 6 6 / * 3 * +
   */
  int len = sizeof(expr)/sizeof(string);

  stack<int> eval;
  vector<string> result = topostfix(expr, len);
  for(int i = 0; i < len; ++i) {
    string token = result[i];
    if (operators.find(token) != operators.end()) {
      Operator *oper = operators[token];
      int r = eval.top(); eval.pop();
      int l = eval.top(); eval.pop();
      eval.push(oper->apply(l, r));
      cerr << ">>> " << l << " " << token << " " << r << " = " << eval.top() << endl;
    } else {
      eval.push(atoi(token.c_str()));
    }
    cout << result[i] << " ";
  }
  cout << endl;


  return 0;
}
