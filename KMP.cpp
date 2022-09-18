#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getNext(const string &pattern, int *next)
{
    next[0] = 0;

    for (size_t i = 1, j = 0; i < pattern.size(); ++i)
    {
        while ((j > 0) && (pattern[j] != pattern[i]))    
        {
            j = next[j];      //回溯j
        }

        if (pattern[j] == pattern[i])
            j++;              //前进j

        next[i] = j;
    }
}

vector<int> KMP_Matcher(const string& t,  const string& p, int *n)
{
    vector<int> result;

    for (size_t i = 0, j=0; i < t.size(); ++i)
    {
        while (j > 0 && p[j] != t[i])
        {
            j = n[j];
        }

        if (p[j] == t[i])
            j++;

        if (j == p.size()-1)
        {
            result.push_back(i - (p.size()-1)+1);    //起始位置
            j = n[j];
        }

    }

    return result;
}


int main()
{
    string  text = "TTTTababacaDDDDababacaGGGGababacaAAAA";
    string  pattern = "ababaca";

    int *next = new int[pattern.size()];

    getNext(pattern, next);

    for (size_t i = 0; i < pattern.size(); ++i)
    {
        cout << next[i] << "  ";
    }

    cout << endl;

    vector<int> result = KMP_Matcher(text, pattern, next);

    for (int s : result)
        cout << s << " ";

    if (next != nullptr) delete[] next;

    system("pause");
    return EXIT_SUCCESS;
}