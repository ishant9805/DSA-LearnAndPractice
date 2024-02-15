#include<bits/stdc++.h>

using namespace std;

unordered_map<char, char>::iterator findByValue(unordered_map<char, char> ump, char c) {
    unordered_map<char, char>::iterator itr;
    for ( itr = ump.begin(); itr != ump.end(); itr++)
    {
        if (itr -> second == c) {
            return itr;
        }
    }
    return ump.end();
}

bool areIsomorphic(string &str1, string &str2) {
    unordered_map<char, char> umpp;
    for (int i = 0; i < str1.length(); i++)
    {
        // --------------------------------------
        // unordered_map<char, char>::iterator itr;
        // cout << "\nAll Elements : \n"; 
        // for (itr = umpp.begin();  
        //     itr != umpp.end(); itr++)  
        // { 
        //     // itr works as a pointer to  
        //     // pair<string, double> type  
        //     // itr->first stores the key part and 
        //     // itr->second stores the value part 
        //     cout << itr->first << "  " <<  
        //             itr->second << endl; 
        // } 
        // --------------------------------------
        if ((umpp.find(str1[i]) == umpp.end()) && (findByValue(umpp, str2[i]) == umpp.end())){
            umpp.insert(make_pair(str1[i], str2[i]));
        } else {
            if ((umpp[str1[i]] == str2[i]) || umpp->findByValue()) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Starting Program" << endl;
    string str1 = "hgvoo";
    string str2 = "bnnff";
    cout << areIsomorphic(str1, str2) << endl;
    return 0;
}