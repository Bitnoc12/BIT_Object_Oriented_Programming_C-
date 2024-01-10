#include <iostream>
#include <cstring>
using namespace std;
class X
{
  public:
    X(int x1,char *x2,float x3):a(x1),c(x3)
    {
      b=new char[sizeof(x2)+1];
      strcpy(b,x2);
    }
    X():a(0),b("X::X()"),c(10){ }
    X(int x1,char *x2="X::X(...)",int x3=10):a(x1),b(x2),c(x3) {}
    X(const X& other)
    {
      a=other.a;
      b="X::X(const X &other)";
      c=other.c;
    }
    void print()
    {
      cout<<"a="<<a<<"\t"<<"b="<<b<<"\t"<<"c="<<c<<endl;
    }
  private:
    int a;
    char *b;
    float c;
};

int main(){
  X *p=new X(4, "X::X(int,char,float)",32);
  X x1,x2(10),x3(x1);
  p->print();
  x1.print();
  x2.print();
  x3.print();
  delete p;
  return 0;
}