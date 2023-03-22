#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int bigN = 29;
const int numLetters = 26;

int hashF(string s){
    int size = s.size();
    int exp = size - 1;
    int val = 0;

    for(int i = 0; i < size; i++){
        val += (int(s[i]) * pow(numLetters,exp));
        exp -= 1;
    }
    val %= bigN;
    return val;
}

bool compareString(string s1, string s2){
    for(int i = 0; i<s1.size(); i++){
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

int findText(string text, string key) {
    int hk = hashF(key);
    int Tsize = text.size();
    int Ksize = key.size();

    for(int i = 0; i < Tsize; i++) {
        string s = text.substr(i, Ksize);
        int hashS = hashF(s);
        if(hashS != hk){
            continue;
        }
        else{

            cout << "Index: " << i;
            break;
        }
    }

}

int main(){
    string key, text;
    cout << "Hash \n Enter a text: ";
    cin >> text;
    cout << "Enter a key: ";
    cin >> key;

    findText(text, key);

    return 0;
}