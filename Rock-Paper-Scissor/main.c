#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_computer_choice() {
    int n = rand() % 3; // Generate 0, 1, or 2
    return (n == 0) ? 's' : (n == 1) ? 'p' : 'z'; // 's' = Stone, 'p' = Paper, 'z' = Scissors
}

int determine_winner(char player, char computer) {
    if (player == computer) return -1; // Draw
    if ((player == 's' && computer == 'z') || (player == 'p' && computer == 's') || (player == 'z' && computer == 'p')) {
        return 1; // Player wins
    }
    return 0; // Computer wins
}

int main() {
    srand(time(NULL)); // Seed random number generator
    char player_choice, computer_choice;

    printf("\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR: ");
    scanf(" %c", &player_choice); // Space before %c to ignore leading whitespace

    computer_choice = get_computer_choice(); // Get computer choice

    int result = determine_winner(player_choice, computer_choice); // Determine the winner

    if (result == -1) {
        printf("\n\n\t\t\t\tGame Draw!\n");
    } else if (result == 1) {
        printf("\n\n\t\t\t\tWow! You have won the game!\n");
    } else {
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
    }

    printf("\t\t\t\tYou chose: %c and Computer chose: %c\n", player_choice, computer_choice);

    return 0;
}
