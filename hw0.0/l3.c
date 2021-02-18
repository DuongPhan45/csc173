#include <stdio.h>

struct Employee
{
    char *name;
    int id;
};
int main(int argc, char *argv[])
{
    struct Employee emp;
    emp.name = "Candy";
    emp.id = 213;
}
