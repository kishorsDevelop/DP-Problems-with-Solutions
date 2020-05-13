/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].

*/

#include<bits/stdc++.h>
using namespace std;

//using memoisation
vector<string> helper(vector<string> v,string s,unordered_map<string,vector<string>> &mp){
       
       if(mp.find(s)!=mp.end()){
            return mp[s];
       }
       vector<string> res;

       if(s.length() == 0){
           res.push_back("");
       }
       for(int i=0;i<=s.length();i++){
          string sub = s.substr(0,i);
          if(find(v.begin(),v.end(),sub)!=v.end()){
               vector<string> tmp = helper(v,s.substr(i,s.length()),mp);
               
               for(auto x : tmp){
                     res.push_back(sub+(x.length()==0?"":" ")+x);
               }
          }
       }
  mp[s] = res;
  return res;
}
vector<string> func(vector<string> v,string s){
      unordered_map<string,vector<string>> mp;
      return helper(v,s,mp);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
      vector<string> v;
       while(n--){
           string s;
           cin>>s;
           v.push_back(s);
       }
       string a;
       cin>>a;
       vector<string> ans = func(v,a);
       for(int i=0;i<ans.size();i++){
         cout<<"("<<ans[i]<<")";
       }
       cout<<endl;
    }
}
