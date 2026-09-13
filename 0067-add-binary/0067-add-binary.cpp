class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;

        int i = a.size() - 1;
        int j = b.size() - 1;

        stack<int> st;

        while(i >= 0 || j >= 0) {

            int num;

            if(i >= 0 && j < 0) {

                num = (a[i] - '0') + carry;

                if(num == 2) {
                    st.push(0);
                    carry = 1;
                }
                else if(num == 1) {
                    st.push(1);
                    carry = 0;
                }
                else {
                    st.push(0);
                    carry = 0;
                }

                i--;
                continue;
            }

            else if(j >= 0 && i < 0) {

                num = (b[j] - '0') + carry;

                if(num == 2) {
                    st.push(0);
                    carry = 1;
                }
                else if(num == 1) {
                    st.push(1);
                    carry = 0;
                }
                else {
                    st.push(0);
                    carry = 0;
                }

                j--;
                continue;
            }

            num = (a[i] - '0') + (b[j] - '0') + carry;

            if(num == 3) {
                st.push(1);
                carry = 1;
            }
            else if(num == 2) {
                st.push(0);
                carry = 1;
            }
            else if(num == 1) {
                st.push(1);
                carry = 0;
            }
            else {
                st.push(0);
                carry = 0;
            }

            i--;
            j--;
        }

        if(carry == 1) {
            st.push(1);
        }

        string ans = "";

        while(!st.empty()) {
            ans += to_string(st.top());
            st.pop();
        }

        return ans;
    }
};