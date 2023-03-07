#include <stdio.h>
#include <string.h>
#include "ymg.h"

void print_person_list(int index);

int main() {
	int number, output;   
	person pers;
	// printf() displays the string inside quotation
   	printf("Hello, World!\n");


	pers.citNo=28;
	pers.salary=100;

	strcpy(pers.name, "HAKAN AYDIN");

	// print struct variables
	printf("Name: %s\n", pers.name);
	printf("Citizenship No: %d\n", pers.citNo);
	printf("Salary: %.2f \n", pers.salary);
   	
   	create_person(pers, 2);
   	print_person_list(2);
   	
	printf("Enter a number: ");

   	scanf("%d", &number);
   	output = factorial(number);

   	printf("The factorial of the entered number: %d \n", output);
   	printf("Is the entered number prime: %d \n", prime_control(number));

   	return 0;
}
////////////////////////////////////////////////
void print_person_list(int index){

	printf("Name: %s\n", persons[index].name);
	printf("Citizenship No: %d\n", persons[index].citNo);
	printf("Salary: %.2f \n", persons[index].salary);
}

 
