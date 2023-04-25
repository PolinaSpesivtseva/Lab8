#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "lab8.h"
#define DEBUG 1

void output_sick_person(bolnoy bol)
{
	printf("%s, ", bol.f.name);
	printf("%s, ", bol.f.surname);
	printf("%s, ", bol.f.otchestvo);
	printf("%d.", bol.d.year);
	printf("%d.", bol.d.month);
	printf("%d, ", bol.d.day);
	printf("%s\n", bol.diagnos);
}

void find(bolnoy* bol, int n, char* d)
{
	int max_year = 0;
	int max_month = 0;
	int max_day = 0;
	int nom = 0;
	int sch = 0;
	bolnoy m[20];
	int j = 0;
	bolnoy b = { NULL, NULL, NULL, NULL, 0, 0, 0 };

	for (int i = 0; i < n; i++)
	{
		if (strcmp(bol[i].diagnos, d) == 0)
		{
			if (bol[i].d.year > max_year)
			{
				b = bol[i];
				max_year = bol[i].d.year;
			}
			else if (bol[i].d.year == max_year)
			{
				if (bol[i].d.month > max_month)
				{
					b = bol[i];
					max_month = bol[i].d.month;
				}
				else if (bol[i].d.month == max_month)
				{
					if (bol[i].d.day > max_day)
					{
						b = bol[i];
						max_day = bol[i].d.day;
					}
				}
			}
			sch++;
		}

	}
	if (sch == 0) printf("Not found");
	else if (sch == 1)
	{
		printf("%s, ", b.f.name);
		printf("%s, ", b.f.surname);
		printf("%s, ", b.f.otchestvo);
		printf("%d.", b.d.year);
		printf("%d.", b.d.month);
		printf("%d, ", b.d.day);
		printf("%s\n", b.diagnos);
	}
	else if (sch > 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(bol[i].diagnos, d) == 0)
			{
				if ((bol[i].d.year > max_year) || ((bol[i].d.year == max_year) && (bol[i].d.month > max_month)) || ((bol[i].d.month == max_month) && (bol[i].d.day > max_day)) || ((bol[i].d.year == max_year) && (bol[i].d.month == max_month) && (bol[i].d.day == max_day)))
				{
					output_sick_person(bol[i]);
				}
			}

		}

	}

}

int main()
{
#if DEBUG == 1

	bolnoy bol[20];
	int n = 5;

	strcpy(bol[0].f.name, "Alina");
	strcpy(bol[0].f.surname, "Petrova");
	strcpy(bol[0].f.otchestvo, "Nikolaevna");
	bol[0].d.year = 2003;
	bol[0].d.month = 12;
	bol[0].d.day = 30;
	strcpy(bol[0].diagnos, "coronavirus");

	strcpy(bol[1].f.name, "Dasha");
	strcpy(bol[1].f.surname, "Borisova");
	strcpy(bol[1].f.otchestvo, "Sergeevna");
	bol[1].d.year = 2003;
	bol[1].d.month = 7;
	bol[1].d.day = 9;
	strcpy(bol[1].diagnos, "cold");

	strcpy(bol[2].f.name, "Masha");
	strcpy(bol[2].f.surname, "Sidorova");
	strcpy(bol[2].f.otchestvo, "Aleksandrovna");
	bol[2].d.year = 2003;
	bol[2].d.month = 7;
	bol[2].d.day = 9;
	strcpy(bol[2].diagnos, "cold");

	strcpy(bol[3].f.name, "Ivan");
	strcpy(bol[3].f.surname, "Ivanov");
	strcpy(bol[3].f.otchestvo, "Ivanovich");
	bol[3].d.year = 2006;
	bol[3].d.month = 10;
	bol[3].d.day = 22;
	strcpy(bol[3].diagnos, "sore throat");

	strcpy(bol[4].f.name, "Makar");
	strcpy(bol[4].f.surname, "Kirillov");
	strcpy(bol[4].f.otchestvo, "Kirillovich");
	bol[4].d.year = 2002;
	bol[4].d.month = 11;
	bol[4].d.day = 7;
	strcpy(bol[4].diagnos, "fracture");


	for (int i = 0; i < 5; i++)
	{
		output_sick_person(bol[i]);
	}

#elif DEBUG == 0
	bolnoy bol[20];
	int n;
	printf("Enter number of sick persons: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Input name of the sick person: ");
		scanf("%s", &bol[i].f.name);

		printf("Input surname of the sick person: ");
		scanf("%s", &bol[i].f.surname);

		printf("Input otchestvo of the sick person: ");
		scanf("%s", &bol[i].f.otchestvo);

		printf("Input year: ");
		scanf("%d", &bol[i].d.year);

		printf("Input month: ");
		scanf("%d", &bol[i].d.month);

		printf("Input day: ");
		scanf("%d", &bol[i].d.day);

		printf("Input diagnos: ");
		scanf("%s", &bol[i].diagnos);

	}
	for (int i = 0; i < n; i++)
	{
		output_sick_person(bol[i]);
	}

#endif
	char d[20];
	printf("Input DIAGNOS: ");
	scanf("%s", d);
	find(bol, n, d);
	return 0;
}
