#include "ymg.h"
#include <string.h>

/////////////////////////////////////////////
int factorial(int number){
	if (number <=1)
		return 1;

return number * factorial(number - 1);
}

/////////////////////////////////////////////
bool prime_control(int number){
	bool state = false;
	int i;
	int toplam = 0;
 	for(i=2; i<= number; i++){
    	if(number%i == 0)
      	toplam += i;
	}

	if(toplam == number)
 	state= true;

return state;
}

/////////////////////////////////////////////
void create_person(person person, int index){
	strcpy(persons[index].name, person.name);
	persons[index].citNo = person.citNo;
	persons[index].salary = person.salary;

}
