#include <stdio.h>
#include<string>

void set_proverb(const char** q, int  n);

int main(void)
{
	const char* s = NULL;
	int n=0;


	printf("몇번째 속담을 선택하시겠습니까?");
	scanf_s("%d", &n);
	set_proverb(&s, n);
	printf_s("selected proverb = %s \n",s);

	return 0;
}

void set_proverb(const char** q, int  n)
{
	static std::string array_2[10] = {
	"Laughter is the best medicine."
	,"Make hay while the sun shines."
	,"Slowand steady wins the race."
	,"Timeand tide wait for no man."
	,"What goes around comes around."
	,"Two heads are better than one."
	,"Too many cooks spoil the broth."
	,"All good things come to an end."
	,"Actions speak louder than words."
	,"Don't judge a book by its cover." };

	

	static const char* array[10] = {
	"Laughter is the best medicine."
	,"Make hay while the sun shines."
	,"Slowand steady wins the race."
	,"Timeand tide wait for no man."
	,"What goes around comes around."
	,"Two heads are better than one."
	,"Too many cooks spoil the broth."
	,"All good things come to an end."
	,"Actions speak louder than words."
	,"Don't judge a book by its cover."
	};

	
	*q = array[n];
}

