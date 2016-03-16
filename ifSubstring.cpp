#include <cstdio>
#include <cstring>

using namespace std;

int cmpStrings (char *s1, char *s2);

int main()
{
    char s1[] = "hel";
    char s2[] = " hello";

    printf ("comparision: %d\n", cmpStrings (s1, s2));

    return 0;
}

int cmpStrings (char *s1, char *s2)
{
    int i, j, len1, len2;

    j = 0;
    len1 = strlen (s1);
    len2 = strlen (s2);

    for (i = 0; i < len2; i++)
    {
        if (s1[0] == s2[i])
        {
            if (len1 > len2 - i)
                return 0;

            for (j = 0; j < len1; j++, i++)
                if (s1[j] != s2[i])
                    return 0;

            return 1;
        }
    }
    
    return 0;
}
