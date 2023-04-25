#pragma once
typedef struct
{
	char surname[15];
	char name[15];
	char otchestvo[15];
} fio;

typedef struct
{
	int year;
	int month;
	int day;
} date;

typedef struct
{
	char diagnos[15];
	fio f;
	date d;
} bolnoy;