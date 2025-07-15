class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (int i = 0; i < n; i++) {
            char ch = word[i];

            // Check if character is a digit or letter
            if (!(isdigit(ch) || isalpha(ch))) {
                return false; // invalid character
            }

            // Check if it's a vowel
            if (isalpha(ch)) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
