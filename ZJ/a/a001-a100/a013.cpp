#include <iostream>
#include <map>
#include <vector>
using namespace std;

int romanToInt(string s) {
    map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int r=0;
    for(int i =0;i<s.length();++i){
        if(romanMap[s[i+1]]>romanMap[s[i]]){
            r+=(romanMap[s[i+1]]-romanMap[s[i]]);
            i++;
        }
        else{
            r+=romanMap[s[i]];
        }
    }
    return r;
}
string intToRoman(int num) {
    const vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string r="";
    if (num==0) return "0";
    for(int i = 0;i<values.size()&&num>0;++i){
        while(num>=values[i]){
            r+=symbols[i];
            num-=values[i];
        }
    }
    return r;
}
int main() {
    string a,b;
    while (true) {
        cin>>a;
        if (a=="#") break;
        cin>>b;
        string s = intToRoman(abs(romanToInt(a)-romanToInt(b)));
        cout << (s=="0"?"ZERO":s) << "\n";
    }
}