#include "monty.h"

/**
* main - generate a key depending on a username for crackme5
* @argc: number of arguments passed
* @argv: arguments passed to main
*
* Return: 0 on success, 1 on error
*/

int main(int argc, char *argv[])
{
    char *monty_file; 
    /* ssize_t file; */
    size_t monty_file_len;
    if (argc < 2) {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    monty_file = argv[1];
    monty_file_len = strlen(monty_file);
    /* printf("%d\n", argc);
	printf("argc:%d, argv:%p\n", argc, (void *)*argv);
    char *temp;
    temp = malloc(sizeof(char) * letters);
	if (temp == NULL)
		return (0);
    printf("file : %lu", file);
    */
    check_montyfile(monty_file, monty_file_len);
    check_file_operators(monty_file);
    return (0);
}

/**
 * check_montyfile - Read text files
 * @filename: The pointer to the file
 * @letters: The number of letters
 * Return: The number of letters print
 */
void check_montyfile(const char *filename, size_t letters)
{   
    int fdo, fdr;
    char *temp;
    temp = malloc(sizeof(char) * letters);
	if (filename == NULL)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

	
	if (temp == NULL)
		exit(EXIT_FAILURE);

	fdo = open(filename, O_RDONLY);
	if (fdo < 0)
	{
		printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
	}

	fdr = read(fdo, temp, letters);
	if (fdr < 0)
	{
		free(temp);
		exit(EXIT_FAILURE);
	}

	
	free(temp);
	close(fdo);

}

void check_file_operators(const char *filename) 
{
    char *file_operators;
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    FILE *input_file = fopen(filename, "r");
    line_size = getline(&line_buf, &line_buf_size, input_file);
    while (line_size >= 0)
    {
        printf("line[%d]: chars=%ld, buf size=%lu, contents: %s", line_count, line_size, line_buf_size, line_buf);
        file_operators[line_count] = trimspace(line_buf);

        line_count++;
        /* Show the line details */
        /* printf("line[%06d]: chars=%06ld, buf size=%06lu, contents: %s", line_count, line_size, line_buf_size, line_buf); */
        /* Get the next line */
        line_size = getline(&line_buf, &line_buf_size, input_file);
    }
    printf("\n");

    free(line_buf);
    line_buf = NULL;
    fclose(input_file);
}


/**
 * trimspace - Trim extrawhitespace from commands
 * @untrim: The pointer to the file
 * @new_cmd: The number of letters
 * Return: The number of letters print
 */
char *trimspace(char *untrim) {
    char *new_cmd; 
    int index = 0, j, k = 0, len;
    len = strlen(untrim);
    new_cmd = malloc(sizeof(char) * len);
    if (!new_cmd)
        exit(EXIT_FAILURE);
    while(((untrim[index] == " " || untrim[index] == "\t" || untrim[index] == "\n") && untrim[index + 1] == " ") || untrim[index] == "\t")
    {
        index++;
        len--;
    }

    for (j = index; j < len; j++) {
        new_cmd[k] = untrim[j];
        k++;
    }
    return new_cmd;
}