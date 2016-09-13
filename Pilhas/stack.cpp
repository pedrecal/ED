#include <iostream>
#include <stack>

using namespace std;

int main ()
{
  stack<int> myStack;

  myStack.push(5);
  myStack.push(2);
  myStack.push(3);

  cout << "Size of stack" << myStack.size() << endl;

}
