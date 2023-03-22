#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int bigN = 29;
const int numLetters = 26;

int hashFunction(string s){
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

int findKey(string text, string key) {
    int hk = hashFunction(key);
    int Tsize = text.size();
    int Ksize = key.size();

    for(int i = 0; i < Tsize; i++) {
        string s = text.substr(i, Ksize);
        int hashS = hashFunction(s);
        if(hashS != hk){
            continue;
        }
        else{
            if(compareString(text,key) == true){
                cout << "\nStrings are the same\nIndex: 0";
                return 0;
            }
            else{
                cout << "\nIndex: " << i;
                return i;
            }
        }
    }
    cout << "\nKey wasn't found";
    return -1;

}

int main(){
    string key, text;
    cout << "Rabin-Karp algorithm\nFinding key in the text\nEnter a text: ";
    cin >> text;
    cout << "\nEnter a key: ";
    cin >> key;

    findKey(text, key);

    return 0;
}