#include <stdio.h>

void set_proverb(char** q, int n);
int main(void)
{
	char* s = NULL;
	int n = 0;
	printf("몇번째 선택?");
	scanf_s("%d", &n);
	set_proverb(&s, n);
	printf("selected proverb = %s\n", s);
	return 0;
}

void set_proverb(char** q, int n)
{
	static char* array[10] = {
	"Laughter",
	"Make",
	"Slowand",
	"Time",
	"What",
	"Two",
	"Too",
	"All",
	"Actions",
	"Don't"
	};


	*q = array[n];
}