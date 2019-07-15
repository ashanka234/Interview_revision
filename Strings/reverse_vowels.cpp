#include<iostream>
#include<cstring>
using namespace std;

bool isVowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        return true;
    }

    return false;
}

string reverse_vowels(string str)
{
    int i=0, j=str.length()-1;

    while(i <= j)
    {
        if(isVowel(str[i]) && isVowel(str[j]))      //both are vowel then swap
        {
            swap(str[i], str[j]);
            i++; j--;
        }

        else if(isVowel(str[i]) && !isVowel(str[j]))
        {
            j--;
        }

        else if(!isVowel(str[i]) && isVowel(str[j]))
        {
            i++;
        }
        else        //both are not vowel
        {
            i++; j--;
        }
    }

    return str;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string str;
        cin >> str;
        cout << reverse_vowels(str) << endl;
    }

    return (0);
}