//https://www.geeksforgeeks.org/problems/number-to-words0335/1
// for indian number system
#include <iostream>
#include <vector>
using namespace std;
// 438237764
// Arrays to store words for numbers
string ones[] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };
string tens[] = { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };


string numberToWords(int n, string suffix){
    string s = "";
    if(n>19){
        s += tens[n/10] + ones[n%10]; // 43 = forty+three
    }
    else{
        s += ones[n]; 
    }
    if(n){
        s += suffix; //crore
    }
    return s;
}

string convertToWords(long n){
    string res;
    res += numberToWords(n/10000000, "crore "); // 43 -> forty three crore
    res += numberToWords((n/100000)%100, "lakh "); // 82 -> eighty two lakh
    res += numberToWords((n/1000)%100, "thousand "); // 37 -> thirty seven thousand
    res += numberToWords((n/100)%10, "hundred "); // 7 -> seven hundred
    if(n>100 && n%100){
        res += "and ";
    }
    res += numberToWords(n%100, ""); // 64 -> sixty four
    return res;
}

int main() {
    long number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Number in words: " << convertToWords(number) << endl;
    return 0;
}

//https://leetcode.com/problems/integer-to-english-words/
// for american number system
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ones[20] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
    string tens[10] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };

    string convertToWords(long n, string suffix) {
        string s = "";

        // Process hundreds place
        if (n >= 100) {
            s += ones[n / 100] + "Hundred ";
            n %= 100;
        }
        
        // Process tens and ones place
        if (n >= 20) {
            s += tens[n / 10] + ones[n % 10];
        } else if (n > 0) {
            s += ones[n];
        }

        // Add suffix if the original group was non-zero
        if (!s.empty()) {
            s += suffix;
        }
        return s;
    }

    string numberToWords(int n) {
        if (n == 0) return "Zero";  // Edge case for zero

        string res;
        res += convertToWords(n / 1000000000, "Billion ");
        res += convertToWords((n / 1000000) % 1000, "Million ");
        res += convertToWords((n / 1000) % 1000, "Thousand ");
        res += convertToWords((n / 100) % 10, "Hundred ");
        res += convertToWords(n % 100, "");

        // Remove the trailing space if any
        if (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};

// For testing purposes
int main() {
    Solution solution;
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Number in words: " << solution.numberToWords(number) << endl;
    return 0;
}
