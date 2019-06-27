#include <stdio.h>

void hello_world()
{
  printf("hello world\n");
}

int main()
{
  int a;
  int *pa;
  void (*pfunc)();


  a = 0xAABBCCDD;
  pa = &a;
  pfunc = hello_world;
  pfunc();

  printf("a = %p\n", a);
  printf("&a = %p\n", &a);
  printf("pa = %p\n", pa);
  printf("*pa = %p\n", *pa);
  printf("&pa = %p\n", &pa);
  printf("hello_world = %p\n", hello_world);
  printf("pfunc = %p\n", pfunc);
  printf("&pfunc = %p\n", &pfunc);
}