#include<iostream>
#include<cstring>
using namespace std;

void print_str(char *str, int l, int r)
{
    for(int i=l; i<=r; i++)
    {
        cout << str[i] ;
    }
    cout << endl;
}

void max_pal_substr(char *str, int n)
{
    int dp[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = 0;
        }
    }

    int max_length = 0;
    int start = 0;

    //string of length 1 is always palindrome
    for(int i=0; i<n; i++)
    {
        dp[i][i] = 1;
    }

    //search for string of length 1
    //agar dono char same hue toh palindrome hoga
    for(int i=0; i<n-1; i++)
    {
        if(str[i] == str[i+1])
        {
            dp[i][i+1] = 1;
            max_length = 2;
        }
    }

    //check for string length > 2
    //aage peeche ka check, then uske andar ka dp se check hoga
    for(int k = 3; k <= n; k++) // k is the curr length of substr
    {
        for(int i=0; i < n-k+1; i++)        //i is starting of curr substr; yeh substr i se n-k tak jayega, -1 because index is 1 less
        {
            int j = i + k - 1;          //starting se k length ka hai substr, so i+k is the ending, -1 because index liya hai

            if(str[i] == str[j])    //yeh do match hue, toh andar ka check kro dp se
            {
                if(dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    if(k > max_length)
                    {
                        max_length = k;
                        start = i;
                    }
                }
            }
        }
    }
    
    cout << max_length << endl;
    print_str(str, start, start+max_length-1);
    return;
}

int main()
{
    char str[10000];
    int t;

    cin >> t;
    while(t--)
    {
        cin >> str;
        int n = strlen(str);
        max_pal_substr(str, n);
    }

    return (0);
}