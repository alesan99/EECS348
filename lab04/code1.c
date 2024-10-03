#include <stdio.h>
int recursiveCombination(int score, int combination[], int playId, int size);

int main() {
	int nflScore;
	printf("Enter score: ");
	scanf("%d", &nflScore);

	while (nflScore >= 2) { // Continue if input is >= 2
   		int combination[128]; // reserve space to store plays
		// use recursion to find all plays that lead exactly to score
		recursiveCombination(nflScore, combination, 0, 0);

		// Ask for next number
		printf("Enter score: ");
		scanf("%d", &nflScore);
	}

	return 0;
}

int recursiveCombination(int score, int combination[], int playId, int size) {
	int plays[5] = {
		6, // TD
		3, // FG
		2, // Safety
		8, // TD +2pt
		7 // TD +1pt
	};

	if (score == 0) {
		// Combination leads to 0
		int counts[5] = {0, 0, 0, 0, 0}; // count how many of each
		for (int i = 0; i < size; i++) {
			counts[combination[i]]++;
		}
		// Print combination
		printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d 3pt FG, %d Safety", counts[3], counts[4], counts[0], counts[1], counts[2]);
		printf("\n");
		return 1;
	} else if (score < 0) {
		// Wrong
		return 0;
	}

	// Next step
	for (int i = playId; i < 5; i++) {
		combination[size] = i; // Mark down which play was used
		recursiveCombination(score - plays[i], combination, i, size + 1);
	}
}