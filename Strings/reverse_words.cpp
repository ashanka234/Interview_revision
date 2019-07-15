#include<iostream>
#include<cstring>
using namespace std;

void reverse(char *str, int l, int r)
{
    if(l>=r)
    {
        return ;
    }

    swap(str[l], str[r]);
    reverse(str, l+1, r-1);
}

void reverse_words(char *str, int l, int r)
{
    int word_begin = l;
    int word_end = l;

    while(str[word_end] != '\0')
    {
        word_end++;
        if(str[word_end] == '\0')
        {
            reverse(str, word_begin, word_end-1);
        }
        else if(str[word_end] == '.')
        {
            reverse(str, word_begin, word_end-1);
            word_begin = word_end+1;
        }
    }

    reverse(str, l, r);
}

int main()
{
    char str[2000];
    int t;

    cin >> t;
    while(t--)
    {
        cin >> str;
        reverse_words(str, 0, strlen(str)-1);
        cout << str << endl;
    }

    return (0);
}