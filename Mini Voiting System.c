#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0;
    }
}

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - Votes: %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    if (numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Please choose between 1 and %d.\n", MAX_CANDIDATES);
        return 1;
    }

    Candidate candidates[MAX_CANDIDATES];
    initializeCandidates(candidates, numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d, please select your candidate (1-%d): ", i + 1, numCandidates);
        int choice;
        scanf("%d", &choice);

        if (choice < 1 || choice > numCandidates) {
            printf("Invalid choice. Please select a valid candidate.\n");
        } else {
            candidates[choice - 1].votes++;
            printf("Thank you for voting!\n");
        }
    }

    printf("\nVoting Results:\n");
    displayCandidates(candidates, numCandidates);

    // Find the winner
    int maxVotes = candidates[0].votes;
    int winnerIndex = 0;

    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("The winner is %s with %d votes!\n", candidates[winnerIndex].name, maxVotes);

    return 0;
}