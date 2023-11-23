#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct Trie {
    Trie* children[26];
    int temp = -1;
    bool cnt = false;
    bool leaf = false;

    ~Trie() {
        for(int i=0; i<26; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(char *c) {
        if (*c=='\0')  {
            leaf = true;
            return;
        }
        int cur = *c-'a';
        if (children[cur]==NULL) {
            children[cur] = new Trie();
        }
        if (temp!=-1 && temp!=cur) cnt = true;
        temp = cur;
        children[cur]->insert(c+1);
    }
} Trie;

int ans = 0;

void find(Trie *t, int val) {
    for(int i=0; i<26; i++) {
        if (t->children[i]!=NULL) {
            if (t->children[i]->leaf) {
                ans += val;
                // cout << char('a'+i) << val << '\n';
                find(t->children[i], val+1);
            }
            else {
                if (t->children[i]->cnt) find(t->children[i], val+1);
                else find(t->children[i], val);
            }
        }
    }
}

int main() {
    while(cin >> n) {
        cin.ignore();    
        Trie* head = new Trie();
        for (int i=0; i<n; i++) {
            char s[100];
            cin.getline(s, 100);
            head->insert(s); 
        }
        ans = 0;
        find(head, 1);
        delete head;
        cout << fixed; cout.precision(2);
        cout << ans/double(n) << '\n';
    }
}