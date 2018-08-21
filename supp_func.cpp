#include "Header.h"


int min(int in_array[], int numb_in_file)
{
	int min = INT_MAX, imin = -1;
	for (int i = 0; i < numb_in_file; i++)
		if ((min > in_array[i]) && (in_array[i] != NULL)) {
			min = in_array[i];
			imin = i;
		}
	return imin;
}


int max(int in_array[], int numb_in_file)
{
	int max = INT_MIN, imax = -1;
	for (int i = 0; i < numb_in_file; i++)
		if ((max < in_array[i]) && (in_array[i] != NULL)) {
			max = in_array[i];
			imax = i;
		}
	return imax;
}


int char_or_int(char *check)
{
	for (int i = 0; i < strlen(check); i++)
		if ((check[i] < '0') || (check[i] > '9'))
			return IS_CHAR;
	return IS_INT;
}


int min(char **in_array, int numb_in_file)
{
	int j;
	char min[MAX_LEN_STRING], imin;
	for (j = 0; j < numb_in_file; j++)
		if (in_array[j] != NULL) {
			strncpy(min, in_array[j], MAX_LEN_STRING);
			imin = j;
			break;
		}
	for (int i = j + 1; i < numb_in_file; i++)
		if (in_array[i] != NULL)
			if (strncmp(min, in_array[i], MAX_LEN_STRING) > 0) {
				strncpy(min, in_array[i], MAX_LEN_STRING);
				imin = i;
			}
	return imin;
}


int max(char **in_array, int numb_in_file)
{
	int j;
	char max[MAX_LEN_STRING], imax;
	for (j = 0; j < numb_in_file; j++)
		if (in_array[j] != NULL) {
			strncpy(max, in_array[j], MAX_LEN_STRING);
			imax = j;
			break;
		}
	for (int i = 1; i < numb_in_file; i++)
		if (in_array[i] != NULL)
			if (strncmp(max, in_array[i], MAX_LEN_STRING) < 0) {
				strncpy(max, in_array[i], MAX_LEN_STRING);
				imax = i;
			}
	return imax;
}


void instruct()
{
	cout << "������ ��������: ����� ����������('-a' ���'-d'). ��������������, �� ��������� - ���������� �� �����������.\n";
	cout << "������ ��������: ��� ������.'-s' - ������, '-i' - ����� �����.\n";
	cout << "������ ��������: ��� ��������� �����.\n";
	cout << "��������� ���������: �������� ������� ������(�� ����� ������).\n\n";
	cout << "� ������, ���� ������� ���������� ������� - ��������� ���������� �������� ������.\n";
	cout << "� ������, ����� ��������� ������� ���� ����, �� ��������� ������ - ��������� ���������� �������� ������.\n";
	cout << "� ������, ����� ��������� ������� ���� �����, �� ��������� ������, ��������� ����������� ������� - ������� �������������� ������������ (����������� ������ ������ ������ ������� �����).\n";
}