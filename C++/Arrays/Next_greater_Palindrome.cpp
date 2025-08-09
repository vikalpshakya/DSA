
// Question link: https://www.geeksforgeeks.org/problems/next-smallest-palindrome4740/1

vector<int> generateNextPalindrome(int num[], int n) {
        // Check if all digits are 9
        bool all9 = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                all9 = false;
                break;
            }
        }
        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        // Copy first half into palindrome
        vector<int> palindrome(num, num + n);
        for (int i = 0; i < n / 2; i++) {
            palindrome[n - i - 1] = palindrome[i];
        }

        // Check if palindrome > original
        bool greater = false;
        for (int i = 0; i < n; i++) {
            if (palindrome[i] > num[i]) { greater = true; break; }
            if (palindrome[i] < num[i]) { break; }
        }

        // If not greater, increment middle and mirror again
        if (!greater) {
            int carry = 1;
            int mid = (n - 1) / 2;
            while (mid >= 0 && carry) {
                int val = palindrome[mid] + carry;
                carry = val / 10;
                palindrome[mid] = val % 10;
                palindrome[n - mid - 1] = palindrome[mid];
                mid--;
            }
        }

        return palindrome;
    }