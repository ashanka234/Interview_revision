#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct Key
{
    int freq;
    char ch;

    bool operator< (const Key &k) const
    {
        return freq < k.freq;
    }
};

void rearrange_string(string str)
{
    int n = str.length();

    int freq_arr[26] = {0};     
    for(int i=0; i<n; i++)
        freq_arr[str[i] - 'a']++;

    priority_queue<Key> maxHeap;
    for(char c='a'; c<='z'; c++)
    {
        if(freq_arr[c-'a'] != 0)
        {
            maxHeap.push( Key { freq_arr[c-'a'], c} );
        }
    }

    string ans = "";

    Key prev { -1, '#'} ;

    while(!maxHeap.empty())
    {
        Key k = maxHeap.top();
        maxHeap.pop();
        ans = ans + k.ch;

        if(prev.freq > 0)
        {
            maxHeap.push(prev);
        }

        k.freq--;
        prev = k;
    }

    if(ans.length() != n)
        cout << "No answer possible\n";
    else
        cout << ans << endl;
}

int main()
{
    string str = "geeksforgeeks";
    rearrange_string(str);

    return (0);
}