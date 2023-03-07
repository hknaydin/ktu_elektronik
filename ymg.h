#include <stdbool.h>

#ifndef YMG_H_
#define YMG_H_
/**
 * \brief   battery_simulated_init function 
 */
typedef struct Person {
  char name[50];
  int citNo;
  float salary;
} person;

person persons[10];

int factorial(int number);
bool prime_control(int number);
void find_super_numbers(int number);

void create_person(person persons, int index);
#endif /* YMG_H_ */
