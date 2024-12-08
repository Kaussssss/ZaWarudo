#include <stdio.h>
#include <string.h>
#include <ctype.h>
int check_password_strength(char *password) {
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int length = strlen(password);
    if (length < 8) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (ispunct(password[i])) has_special = 1;    
    }

    if (has_digit) {
        return 1;
    }
    if (has_upper && has_lower && has_digit && has_special) {
        return 1;
    } else {
        return 0;
    }
}
int main(){
    char password[100];
    printf("Enter a password to check its strength: ");
    scanf("%s", password);
    if (check_password_strength(password)) {
        printf("Strong password\n");
    } else {
        printf("Weak password\n");
    }
    return 0;
}