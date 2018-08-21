#include "Header.h"


/* ְכדמנטעל גחÿע טח https://habr.com/post/281675/ */
void MergeSortInt(char *out_filename, char **in_filename, int numb_in_file, int increase_mode)
{
	int flag_exit = 0;
	int flag_exit2 = 0;
	char mb_eof; // "may be eof"?
	char in_buff[MAX_LEN_STRING];
	int index_cur;
	int *in_array = new int[numb_in_file];
	int out_array[MAX_LEN_OUTPUT_ARRAY];
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
		flag_exit = 0;
		if (in_array[i] != NULL) {
			while (!flag_exit) {
				if ((mb_eof = in[i].eof()) == true) {
					in_array[i] = NULL;
					in[i].close();
					break;
				}
				in[i] >> in_buff;
				if (char_or_int(in_buff)) {
					flag_exit = 1;
					in_array[i] = atoi(in_buff);
				}
				else { /* וסכט ג פאיכו גלוסעמ int - char */
					cout << "Error: " << in_filename[i] << ": \"" << in_buff
						<< "\" skipped.\n";
					flag_exit = 0;
				}
			}
		}
	}
	flag_exit = 0;
	while (!flag_exit) {
		if (increase_mode == 1)
			index_cur = min(in_array, numb_in_file);
		else
			index_cur = max(in_array, numb_in_file);
		out_array[index_out_array] = in_array[index_cur];
		index_out_array++;
		if ((mb_eof = in[index_cur].eof()) == true) {
			in_array[index_cur] = NULL;
			in[index_cur].close();
		}
		else {
			flag_exit2 = 0;
			while (!flag_exit2) {
				if ((mb_eof = in[index_cur].eof()) == true) {
					in_array[index_cur] = NULL;
					in[index_cur].close();
					break;
				}
				in[index_cur] >> in_buff;
				if (char_or_int(in_buff)) {
					flag_exit2 = 1;
					in_array[index_cur] = atoi(in_buff);
				}
				else { /* וסכט ג פאיכו גלוסעמ int - char */
					cout << "Error: " << in_filename[index_cur] << ": \""
						<< in_buff << "\" skipped.\n";
					flag_exit2 = 0;
				}
			}
			while (1) {
				if (increase_mode == 1) {
					if (in_array[index_cur] < out_array[index_out_array - 1]) {
						printf("Error in \"%s\": %d > %d : skipped.\n", in_filename[index_cur],
							out_array[index_out_array - 1], in_array[index_cur]);
						if ((mb_eof = in[index_cur].eof()) == true) {
							in_array[index_cur] = NULL;
							in[index_cur].close();
							break;
						}
						flag_exit2 = 0;
						while (!flag_exit2) {
							if ((mb_eof = in[index_cur].eof()) == true) {
								in_array[index_cur] = NULL;
								in[index_cur].close();
								break;
							}
							in[index_cur] >> in_buff;
							if (char_or_int(in_buff)) {
								flag_exit2 = 1;
								in_array[index_cur] = atoi(in_buff);
							}
							else { /* וסכט ג פאיכו גלוסעמ int - char */
								cout << "Error: " << in_filename[index_cur] << ": \""
									<< in_buff << "\" skipped.\n";
								flag_exit2 = 0;
							}
						}

					}
					else
						break;
				}
				else {
					if (in_array[index_cur] > out_array[index_out_array - 1]) {
						printf("Error: %s: %d < %d : skipped.\n", in_filename[index_cur],
							out_array[index_out_array - 1], in_array[index_cur]);
						if ((mb_eof = in[index_cur].eof()) == true) {
							in_array[index_cur] = NULL;
							in[index_cur].close();
							break;
						}
						flag_exit2 = 0;
						while (!flag_exit2) {
							if ((mb_eof = in[index_cur].eof()) == true) {
								in_array[index_cur] = NULL;
								in[index_cur].close();
								break;
							}
							in[index_cur] >> in_buff;
							if (char_or_int(in_buff)) {
								flag_exit2 = 1;
								in_array[index_cur] = atoi(in_buff);
							}
							else { /* וסכט ג פאיכו גלוסעמ int - char */
								cout << "Error: " << in_filename[index_cur] << ": \""
									<< in_buff << "\" : skipped.\n";
								flag_exit2 = 0;
							}
						}
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
	delete[] in_array;
	delete[] in;
}