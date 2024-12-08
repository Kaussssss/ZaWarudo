#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    return (rand() % 6) + 1;
}
int main() {
    srand(time(0));
    int dice_result = roll_dice();
    printf("You rolled: %d\n", dice_result);
    if (dice_result >= 2 && dice_result <= 6) {
        printf("Valid dice roll!\n");
    } else {
        printf("Invalid dice roll. Something went wrong!\n");
    }
    return 0;
}