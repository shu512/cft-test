#pragma once
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <clocale>

#define MAX_FILENAME_LEN 20
#define MAX_LEN_OUTPUT_ARRAY_STRING 20
#define MAX_LEN_STRING 50
#define MAX_LEN_OUTPUT_ARRAY 1000
#define IS_CHAR 0
#define IS_INT 1

using namespace std;

void instruct();
void MergeSortString(char *out_filename, char **in_filename, int numb_in_file, int increase_mode);
int max(char **in_array, int numb_in_file);
int min(char **in_array, int numb_in_file);
void MergeSortInt(char *out_filename, char **in_filename, int numb_in_file, int increase_mode);
int char_or_int(char *check);
int max(int in_array[], int numb_in_file);
int min(int in_array[], int numb_in_file);