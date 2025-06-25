#include<bits/stdc++.h>
using namespace std;

class minStack {
    public:
        stack<pair<int,int>>st;

    minStack(){
       cout <<  "Constructer called\n";
    }

    void push(int m) {
        int x = m;

        if(!st.empty()) {
            int y = st.top().second;
            x = min(m,y);
        }
        st.push({m,x});
    }

    void pop() {
        if(!st.empty()) st.pop();
        else {
            cout << "Stack is Empty\n";
        }
    }

    int getMin() {
        if(!st.empty()) {
            return st.top().second;
        } 
        return -1;
    }
    int top() {
        if(!st.empty()) return st.top().first;

        return -1;
    }

};



int main() {
    minStack st;
    
    while(true) {
        
        int op; cin >> op;
        if(op == 5) break;

        switch (op) {
            case 1:
                int x; cin >> x;
                st.push(x);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout << st.top() << endl;
                break;
            case 4: 
                cout << st.getMin() << endl;
                break;
            
            default:
                break;
        }
    }

}