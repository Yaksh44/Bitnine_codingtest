#include <stdio.h>
typedef enum operations {ADD, SUB, MUL, DIV, FIBO} operations;
typedef struct Node
{
int add;
int mul;
int sub;
int div;
int fibo;
} Node;

void calc(int x){
  printf("%d\n", x);
  }
int ADDD(int n1, int n2)
    {
      int x;
      x = n1 + n2;
      return x;
    }
int SUBB(int n1, int n2)
    {
      int x;
      x = n1 - n2;
      return x;
    }
int MULL(int n1, int n2)
    {
    int c;
    c = n1 * n2;
    return c;
    }
int DIVV(int n1, int n2)
    {
      int x;
      x = n1 / n2;
      return x;
    }
int FIBOO(int n, int)
{
  int i;
  int y[n+2]; 
  y[0] = 0;
  y[1] = 1;
  for (i = 2; i <= n; i++)
  {
      y[i] = y[i-1] + y[i-2];
  }
  return y[n-1];
}

int main(void) {
  
int (*makeFunc[])(int, int) = {ADDD, SUBB, MULL, DIVV, FIBOO};

int result;
Node *add = (*makeFunc[ADD])(10, 6);
Node *mul = (*makeFunc[MUL])(5,4);
Node *sub = (*makeFunc[SUB])(add,mul);
Node *fibo = (*makeFunc[FIBO])(abs(sub), NULL);

calc(add);
calc(mul);
calc(sub);
calc(fibo);
// return 0;
}
