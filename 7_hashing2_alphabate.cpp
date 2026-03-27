#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    /*
    ============================================
    🔹 CHARACTER HASHING (Frequency Count)
    ============================================
    - We store frequency of each character
    - ASCII size = 256 → covers all characters
    - Index = ASCII value of character
    */

    // Step 1: Input string
    string s;
    cout << "Enter a string: ";
    cin >> s;   // Note: works for single word (no spaces)

    // Step 2: Precompute hash array
    int hash[256] = {0};

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        hash[ch]++;   // Increase frequency
    }

    /*
    Example:
    s = "aabbc"

    hash['a'] = 2
    hash['b'] = 2
    hash['c'] = 1
    */

    // Step 3: Number of queries
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    // Step 4: Process queries
    while(q--){
        char c;
        cout << "Enter character to find frequency: ";
        cin >> c;

        cout << "Frequency of '" << c << "' is: " << hash[c] << endl;
    }

    return 0;
}