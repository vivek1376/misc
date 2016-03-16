/*
  http://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

  Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
//#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inStr[] = ")()())";
    int strLength[20] = {0};

    int i, len, brkt, maxLen = 0, newLen = 0, start, end, ifStart = 0, openBrkt = 0, oldLen;
    int newStart = 1, clsBrkt = -1;

    stack <int> pos;

    len = strlen (inStr);

    maxLen = start = end = brkt = 0;

    for (i = 0; i < len; i++)
    {
        //printf("i: %d    brkt: %d\n",i,brkt);//d
        if (inStr[i] == '(')
            pos.push (i);

        else if (inStr[i] == ')' && !pos.empty())
        {

            /* matching open parenetheses present */
            openBrkt = pos.top();
            newLen = i - openBrkt + 1;

            oldLen = ( (i - newLen) >= 0 ? strLength[i - newLen] : 0);
            strLength[i] = oldLen + newLen;

            if (maxLen < strLength[i])
                maxLen = strLength[i];

            pos.pop();
        }
    }

    printf ("max len: %d\n", maxLen);
}
