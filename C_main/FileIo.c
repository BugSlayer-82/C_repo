#include <stdio.h>
int filecpy(); // function prototype for copy the data of on file to another one

int main()
{
    // /* This section is for only calling the file operation function */
    filecpy(); // Calling the file input output funtion

    return 0;
}

int filecpy() // Function definition for perform copy operation in file to file
{
    FILE *fptr1, *fptr2;              // Declare two file pointer
    char ch;                          // Declare a variable of type character
    fptr1 = fopen("source.txt", "r"); // Perform operation on file to open the File 1
    if (fptr1 == NULL)
    {                                                // If the value of file 1 is equal to null
        printf("The source file is not exist ! \n"); // Print file not exist
        return 1;                                    // Then return exit code
    }
    fptr2 = fopen("target.txt", "w"); // Perform operation on file to open the File 2
    while ((ch = fgetc(fptr1)) != EOF)
    {                     // Read the character till the condition is not reached (EOF) ==> End of File
        fputc(ch, fptr2); // Write the current character ch to File 2
    }
    printf("File copied sucessfully ! \n"); // Then print the message operation successfully
    fclose(fptr1);                          // Close the file 1
    fclose(fptr2);                          // Close the file 2
    return 0;
}