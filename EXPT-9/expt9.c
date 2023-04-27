#include <stdio.h>
#include <string.h>
#define d 256

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0;
	int t = 0; 
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;


	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (i = 0; i <= N - M; i++) {

		if (p == t) {
		
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}

			if (j == M)
				printf("Pattern found at index %d \n", i);
		}

		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;
			if (t < 0)
				t = (t + q);
		}
	}
}

// Driver Code 
int main()
{
	char txt[] = "Deep Is Deep";
	char pat[] = "Deep";

	// A prime number
	int q = 101;

	// function call
	search(pat, txt, q);
	return 0;
}


// C program for Naive Pattern Searching algorithm
/*#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	for (int i = 0; i <= N - M; i++) {
		int j;

		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M) 
			printf("Pattern found at index %d \n", i);
	}
}


int main()
{
	char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";

	search(pat, txt);
	return 0;
}
*/