#pragma once
#include <iostream>

using namespace std;

char* insert_char()
{
	cin.clear();
	char buff[256];
	cin.getline(buff, sizeof(buff));
	if (strcmp(buff, "") == 0) cin.getline(buff, sizeof(buff));
	int len = strlen(buff);
	char* str = new char[len + 1];
	strcpy(str, buff);
	return str;
}
void insert_arr(char *arr)
{
	cin.getline(arr, 8, '\n');
	if (strcmp(arr, "") == 0) cin.getline(arr, 8, '\n');
	cin.clear();
}