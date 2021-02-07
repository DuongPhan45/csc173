#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // // Step 1
    // float tempF = 212.0;
    // // Convert to Kelvins
    // float tempK = (tempF + 459.67) * 5.0 / 9.0;
    // printf("%.2f degrees F is %.2f K\n", tempF, tempK); // format 2 digits after comma

    // // Step 2
    // if (tempK <= 32.00)
    //     printf("That’s freezing");
    // else if (tempK >= 212.00)
    //     printf("That's boiling");
    // else
    // {
    //     printf("Nice");
    // }

    // // Step 3
    // for(int i = 0; i<=10; i++)printf("%d\n",i);
    // for(int i = 10; i>=0; i-=2)printf("%d\n",i);

    // // Step 4
    // void print_asterisks(int number)
    // {
    //     while (number > 0)
    //     {
    //         printf("*");
    //         number--;
    //     }
    //     printf("\n");
    // }
    // print_asterisks(5);

    // void to_Kelvin(float tempF)
    // {
    //     float tempK = (tempF + 459.67) * 5.0 / 9.0;
    //     printf("%.2f degrees F is %.2f K\n", tempF, tempK);
    // }
    // to_Kelvin(123.00);

    // Step 5
    //     void print_input()
    //     {
    //         int a;
    //         float b;
    //         char c[50];

    //         printf("Enter in order: an int, a float, a string : ");
    //         scanf(" %d %f %s", &a, &b, c);
    //         printf("Outputs are: %d %f %s", a, b, c);
    //     }
    //     print_input();

    // //Step 6
    // void print_lines()
    // {
    //     char str[256];
    //     while (strcmp(str, "quit\n")!=0)
    //     {
    //         fgets(str, 225, stdin);
    //         printf("%s",str);
    //     }
    // }
    // print_lines();

    // Step 7

    int copy_file(char *fileRead, char *fileWrite)
    {
        // Open source file
        FILE *fr = fopen(fileRead, "r");
        if (fr == NULL)
        {
            printf("Can't open source file");
            return 0;
        }
        // Open destination file
        FILE *fw = fopen(fileWrite, "w");
        if (fw == NULL)
        {
            printf("Can't open destination file");
            return 0;
        }

        char content[256];

        while (!feof(fr))
        {
            fgets(content, 225, fr);
            printf("%s", content);
            fprintf(fw, "%s", content);
        }

        fclose(fr);
        fclose(fw);
        return 1;
    }
    copy_file("readfile.txt", "writefile.txt");
}