#include <stdio.h>
#include <string.h>
int main() {
    char word[15];
    printf("Enter a word (up to 14 characters): ");
    scanf("%14s", word);
    unsigned long long result = countAnagrams(word);
    printf("Number of anagrams for '%s': %llu\n", word, result);
    return 0;
}

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long countAnagrams(char* word) {
    int length = strlen(word);
    unsigned long long totalAnagrams = factorial(length);
    int letterCounts[256] = {0};
    for (int i = 0; i < length; i++) {
        letterCounts[(unsigned char)word[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (letterCounts[i] > 1) {
            totalAnagrams /= factorial(letterCounts[i]);
        }
    }
    return totalAnagrams;
}
