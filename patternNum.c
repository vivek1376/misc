/* http://www.practice.geeksforgeeks.org/problem-page.php?pid=371
   http://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, i, j, k, l, lTotal, m1, m2,
        Icnt[10] = {0}, Dcnt[10] = {0}, nCnt = 0;
    char str[10], number[10], *p, ch = '1';

    scanf ("%d", &T);

    for (i = 0; i < T; i++)
    {
	scanf ("%s", str);
        p = str;
        m1 = m2 = j = 0;

        /* zero out the arrays */
        memset (Icnt, 0, sizeof (Icnt));
        memset (Dcnt, 0, sizeof (Dcnt));

        while (*p)
        {
            if (*p == 'I')
            {
                if (* (p - 1 >= 0 ? p - 1 : p) == 'D')
                {
                    m1++;
                    m2++;
                }

                Icnt[m1]++;
            }
            else if (*p == 'D')
                Dcnt[m2]++;

            p++;
        }

        /* now form the number string */
        j = k = nCnt = lTotal = 0;
        while (Icnt[j] > 0 || Dcnt[j] > 0)
        {
            l = Icnt[j] + Dcnt[j];

            /* if I's are present */
            for (k = nCnt; k < lTotal + Icnt[j]; k++)
                number[k] = ch + nCnt++;

            /* if D's are present */
            for (k = lTotal + l; k >= lTotal + Icnt[j]; k--)
                number[k] = ch + nCnt++;

            lTotal += l;
            j++;
        }
        number[nCnt] = '\0';

        printf ("%s\n", number);
    }

    return 0;
}
