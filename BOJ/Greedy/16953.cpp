#include <cstdio>

int main(void) {

	int A, B;
	scanf("%d %d", &A, &B);


	int iCnt = 0;
	while ( A < B ) {

		if ( 1 == B % 10 ) {
			B /= 10;
			iCnt++;
		}

		else if ( 0 == B % 2 ) {
			B /= 2;
			iCnt++;
		}

		else {
			B = 0;
			break;
		}
	}

	printf("%d", (A == B) ? iCnt + 1 : -1);

	return 0;
}