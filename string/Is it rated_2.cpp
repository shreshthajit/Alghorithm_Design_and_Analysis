#https://en.cppreference.com/w/cpp/io/c/fflush?fbclid=IwAR0DfeX_iVbIei-FldPlZZMnybdM9iq9Hokl393olZnRy6cKFKbTdniZz6E
#https://codeforces.com/blog/entry/89260?fbclid=IwAR14LzQrk5zrZ6lXNugumJ81r42ynY09OCFzLq_EqkohelQgMIV7V9LceRE
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[10000];
    while ( scanf("%[^\n]", str) != EOF)
    {
        getchar();//getchar() function is used to get/read a character from keyboard input.
        printf("no\n");
        fflush(stdout);
    }
}
