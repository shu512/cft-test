#include "Header.h"

int main(int argc, char *argv[])
{ 
	setlocale(LC_ALL, "Russian");
	if (argc < 4) {
		instruct();
		system("pause");
		exit(EXIT_FAILURE);
	}
	int increase_mode, string_mode; /* increase_mode = 1 - по возрастанию 
									string_mode = 1 - сортировка строк */
	char out_filename[MAX_FILENAME_LEN];
	char **in_filename;
	int numb_in_file; /* количество входных файлов */
	int index_arg = 1;
	if (strncmp(argv[index_arg], "-a", 2) == 0) {
		increase_mode = 1;
		index_arg++;
	}
	else if (strncmp(argv[index_arg], "-d", 2) == 0) {
		increase_mode = 0;
		index_arg++;
	}
	else {
		increase_mode = 1; /* если аргумент пропущен - сортировка по возрастанию */
	}
	if (strncmp(argv[index_arg], "-s", 2) == 0) 
		string_mode = 1;
	else if (strncmp(argv[index_arg], "-i", 2) == 0) 
		string_mode = 0;
	else {
		instruct();
		system("pause");
		exit(EXIT_FAILURE);
	}
	index_arg++;
	strncpy(out_filename, argv[index_arg], MAX_FILENAME_LEN);
	index_arg++;
	numb_in_file = argc - index_arg;
	in_filename = (char**)malloc(sizeof(char*) * (numb_in_file));
	for (int i = 0; i < numb_in_file; i++)
		in_filename[i] = (char*)malloc(sizeof(char) * MAX_FILENAME_LEN);
	for (int i = 0; index_arg < argc; i++, index_arg++) 
		strncpy(in_filename[i], argv[index_arg], MAX_FILENAME_LEN);
	if (string_mode == 0)
		MergeSortInt(out_filename, in_filename, numb_in_file, increase_mode);
	else
		MergeSortString(out_filename, in_filename, numb_in_file, increase_mode);

	for (int i = 0; i < numb_in_file; i++)
		free(in_filename[i]);
	free(in_filename);
	system("pause");
	exit(EXIT_SUCCESS);
}