#include "Header.h"


void MergeSortString(char *out_filename, char **in_filename, int numb_in_file, int increase_mode)
{
	int len_in_array = 0;
	int flag_exit = 0;
	char mb_eof; /* "may be eof"? */
	int mb_int = 1; /* may be int? */
	int index_cur;
	char **in_array = new char*[numb_in_file];
	for (int i = 0; i < numb_in_file; i++)
		in_array[i] = new char[MAX_LEN_STRING];
	char out_array[MAX_LEN_OUTPUT_ARRAY_STRING][MAX_LEN_STRING];
	int index_out_array = 0;
	ofstream out(out_filename);
	if (!out.is_open()) {
		cout << "Error: output file can`t open/create. \n";
		return;
	}
	ifstream *in = new ifstream[numb_in_file];
	for (int i = 0; i < numb_in_file; i++) {
		in[i].open(in_filename[i]);
		if (!in[i].is_open()) {
			cout << "Error: " << in_filename[i] << " :can`t open file.\n";
			in_array[i] = NULL;
		}
	}
	for (int i = 0; i < numb_in_file; i++) {
		if (in_array[i] != NULL)
			in[i] >> in_array[i];
	}
	for (int i = 0; i < numb_in_file; i++) {
		mb_int = 1;
		if (in_array[i] == NULL)
			continue;
		len_in_array = strlen(in_array[i]);
		for (int j = 0; j < len_in_array; j++)
			if ((in_array[i][j] < '0') || (in_array[i][j] > '9'))
				mb_int = 0;
		if (mb_int == 1) /* если первая строка файла содержит лишь цифры*/
			cout << "Warning: " << in_filename[i]
			<< ": are you sure, that file contains string, but not numbers?\n";
	}
	while (!flag_exit) {
		if (increase_mode == 1)
			index_cur = min(in_array, numb_in_file);
		else
			index_cur = max(in_array, numb_in_file);
		strncpy(out_array[index_out_array], in_array[index_cur], MAX_LEN_STRING);
		index_out_array++;
		if ((mb_eof = in[index_cur].eof()) == true) {
			in_array[index_cur] = NULL;
			in[index_cur].close();
		}
		else {
			in[index_cur] >> in_array[index_cur];
			while (1) {
				if (increase_mode == 1) {
					if (strncmp(in_array[index_cur], out_array[index_out_array - 1],
						MAX_LEN_STRING) < 0) {
						printf("Error: %s: %s < %s : skipped.\n", in_filename[index_cur],
							out_array[index_out_array - 1], in_array[index_cur]);
						if ((mb_eof = in[index_cur].eof()) == true) {
							in_array[index_cur] = NULL;
							in[index_cur].close();
							break;
						}
						in[index_cur] >> in_array[index_cur];
					}
					else
						break;
				}
				else {
					if (strncmp(in_array[index_cur], out_array[index_out_array - 1],
																	MAX_LEN_STRING) > 0) {

						printf("Error: %s: %s < %s : skipped.\n", in_filename[index_cur],
							out_array[index_out_array - 1], in_array[index_cur]);
						if ((mb_eof = in[index_cur].eof()) == true) {
							in_array[index_cur] = NULL;
							in[index_cur].close();
							break;
						}
						in[index_cur] >> in_array[index_cur];
					}
					else
						break;
				}
			}
		}

		if (index_out_array == MAX_LEN_OUTPUT_ARRAY) {
			for (int i = 0; i < MAX_LEN_OUTPUT_ARRAY; i++)
				out << out_array[i] << "\n";
			index_out_array = 0;
		}
		flag_exit = 1;
		for (int i = 0; i < numb_in_file; i++)
			if (in_array[i] != NULL) {
				flag_exit = 0;
				break;
			}
	}
	for (int i = 0; i < index_out_array; i++)
		out << out_array[i] << "\n";
	out.close();
	for (int i = 0; i < numb_in_file; i++)
		delete[] in_array[i];
	delete[] in_array;
	delete[] in;
}
