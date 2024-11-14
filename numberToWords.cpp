//https://www.geeksforgeeks.org/problems/number-to-words0335/1
//https://leetcode.com/problems/integer-to-english-words/description/
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
