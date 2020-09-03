#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

//The preprocessing funtion for bouer moore bad character heuristic
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    //Initialize all occurences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
    {
        badchar[i] = -1;
    }

    //Fill the actual value of last occurences of a character
    for (i = 0; i < size; i++)
    {
        badchar[(int)str[i]] = i;
    }
}
/* A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm
*/
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    //Fill the bad character array by calling the preprocessing function badCharHeuristic for given pattern
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        /* keep reducing index j of pattern while characters of pattern and text are matching at this shift s
        */
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        /* If the pattern is present at current shift, then index j will become -1 after the above loop 
        */
        if (j < 0)
        {
            cout << s << "\n";
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
        {
            s += max(1,j-badchar[txt[s+j]]);
        }
    }
}
int main(){
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt,pat);
    return 0;
}
