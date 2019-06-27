# ポインタについて

## 実験用コード

```C
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
  hello_world()
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
```

## コンパイル

```bash-statement
% gcc -no-pie function_pointer.c -o function_pointer
```

セキュリティの機能であるPosition Independent Executionは切っておく。
関数の位置を固定にして分かりやすくするため。


## 実行結果

```bash-statement
hello world
a = 0xaabbccdd
&a = 0x7ffc4ec378b4
pa = 0x7ffc4ec378b4
*pa = 0xaabbccdd
&pa = 0x7ffc4ec378b8
hello_world = 0x4005a7
pfunc = 0x4005a7
&pfunc = 0x7ffc4ec378c0
```

&を付けるとアドレスになり、*を付けるとそのアドレスの中身が表示される。
hello_worldは既にアドレスになっているので不要。

各ローカル変数はスタックの上に取られているので0x7ffから始まるアドレスになっている。

## ダンプ結果

```bash-statement
% objdump -d -M intel ./function_pointer
00000000004005a7 <hello_world>:
  4005a7:       55                      push   rbp
  4005a8:       48 89 e5                mov    rbp,rsp
  4005ab:       48 8d 3d a2 01 00 00    lea    rdi,[rip+0x1a2]        # 400754 <_IO_stdin_used+0x4>
  4005b2:       e8 d9 fe ff ff          call   400490 <puts@plt>
  4005b7:       90                      nop
  4005b8:       5d                      pop    rbp
  4005b9:       c3                      ret
```

## gdb

```bash-statement
% gdb ./function_pointer
```

とやってstartで最初にbreakpoint貼って後はniを打ってると動作が終えます。
