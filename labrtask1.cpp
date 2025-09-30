#include<bits/stdc++.h>
using namespace std;
int isValidInteger(char str[]) {
    int i = 0;
    if (str[0] == '+' || str[0] == '-') {
        i++;
    }
    if (str[i] == '\0') {
        return 0;
    }
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char input[50];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isValidInteger(input)) {
        printf("Valid Integer Number.\n");
    } else {
        printf("Not a Valid Integer Number.\n");
    }
}
