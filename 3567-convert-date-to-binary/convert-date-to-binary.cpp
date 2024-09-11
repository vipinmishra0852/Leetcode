class Solution {
public:
    // Helper function to convert an integer to a binary string
    string toBinary(int n) {
        if (n == 0) return "0";  // Handle edge case for zero
        string binary = "";
        while (n > 0) {
            binary = to_string(n % 2) + binary;
            n /= 2;
        }
        return binary;
    }

    string convertDateToBinary(string date) 
    {
        // Extract year, month, and day from the input date string "YYYY-MM-DD"
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);
        
        // Convert year, month, and day to integers
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        // Convert each of them to binary strings
        string binaryYear = toBinary(y);
        string binaryMonth = toBinary(m);
        string binaryDay = toBinary(d);

        // Return the binary representation in the format "year-month-day"
        return binaryYear + '-' + binaryMonth + '-' + binaryDay;
    }
};
