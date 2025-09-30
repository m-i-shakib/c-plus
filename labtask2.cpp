#include<bits/stdc++.h>
using namespace std;
int isValidFloat(char str[]) {
    int i = 0;
    int dot = 0;
    int digit = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    if (str[i] == '\0') return 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot++;
            if (dot > 1) return 0;
        } else if (isdigit(str[i])) {
            digit++;
        } else {
            return 0;
        }
    }
    if (digit == 0) return 0;
    return 1;
}
int main() {
    char input[50];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isValidFloat(input)) {
        printf("Valid Float Number.\n");
    } else {
        printf("Not a Valid Float Number.\n");
    }
}
