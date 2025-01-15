class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int n = __builtin_popcount(num2);  // Number of set bits in num2
        int result = 0;  // The number to minimize XOR

        // Use bits from num1
        for (int i = 31; i >= 0 && n > 0; i--) {
            if (num1 & (1 << i)) {  // Check if bit i is set in num1
                result |= (1 << i);  // Set the same bit in result
                n--;  // Decrease required set bits
            }
        }

        // If still need more bits, use the lowest unset bits
        for (int i = 0; i <= 31 && n > 0; i++) {
            if (!(result & (1 << i))) {  // If bit i is not set in result
                result |= (1 << i);  // Set this bit in result
                n--;  // Decrease required set bits
            }
        }

        return result;  // Return the result minimizing XOR
    }
};
