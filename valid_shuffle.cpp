#include <bits/stdc++.h>
using namespace std;
int solve(string text, string pattern){
    int pattern_len=pattern.size();
    int text_len=text.size();
    
    //pattern = “onetwofour”,
    //text = “hellofourtwooneworld” 
    int count=0;
    vector<int>pattern_hash(26,0),text_hash(26,0);
    
    for(auto it:pattern)pattern_hash[it-'a']++;
    
    for(int i=0;i<text_len;i++){
        if(i<pattern_len)text_hash[text[i]-'a']++;
        else{
            if(pattern_hash==text_hash)count++;
            text_hash[text[i]-'a']++;
            text_hash[text[i-pattern_len]-'a']--;
            
        }
    }
    if(pattern_hash==text_hash)count++;
    return count;
}
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    cout<<solve(text,pattern)<<endl;
}
