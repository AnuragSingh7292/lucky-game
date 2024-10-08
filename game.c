#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int N;

int random_move() 
{
    return (rand() % 2 == 0) ? -1 : 1;  // Randomly generate -1 or +1
}

// Anurag's turn
int anurag(int N) 
{
    int move = random_move();
    N += move;
    printf("Anurag's turn: N = %d (Move: %d)\n\n", N, move);
    return N;
}

// Anjali's turn
int anjali(int N) 
{
    int move = random_move();
    N += move;
    printf("Anjali's turn: N = %d (Move: %d)\n\n", N, move);
    

    if (N % 3 == 0) 
    {
        printf("Anjali won the game!\n");
        exit(0);
    }
    return N;
}

int main() 
{
    srand(time(0));  // Seed the random number generator with the current time

    printf("\n\t\t\t\t\t\t**** About the game ******\n\n");
    printf("Two players, Anurag and Anjali, are playing a game. A number N is chosen, and each player takes turns modifying the number.\n");
    printf("The system randomly decides whether each player increments or decrements N by 1.\n");
    printf("If N %% 3 == 0 after Anjali's turn within 5 rounds, she wins the game. Otherwise, Anurag wins.\n\n");

    printf("Guess any number: ");
    scanf("%d", &N);

    for(int i = 0; i < 5; i++) 
    {
        // Anjali's turn
        N = anjali(N);
        
        // Anurag's turn
        N = anurag(N);
    }

    // If the loop completes, Anurag wins
    printf("Anurag won the game!\n");
    
    return 0;
}
