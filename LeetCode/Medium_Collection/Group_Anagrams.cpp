/*

Group Anagrams

Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters
of a different word or phrase, typically using all the original 
letters exactly once. 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string , vector<string>> m ;
        for(auto s : strs){
            string ss = s;
            sort(ss.begin(), ss.end());
            m[ss].push_back(s);
        }
        
        vector<vector<string>> v;
        for(auto x : m){
            v.push_back(x.second);
        }
        
        return v; 
    }
};
