#include <stdio.h>
#include <string.h>

typedef struct Person {
  char name[50];
  int citNo;
  float salary;
} memory;

void print_person_list(int index);

int main() {
	int number, output;   
	memory person[20], *pointer;
	int il, mass;
   	// allocating memory for n numbers of struct person
   	pointer = (struct Person*) malloc(sizeof(struct Person));
	printf("integet: %d\n", sizeof(int));
	// printf() displays the string inside quotation
   	printf("Hello, World!\n");


	person[0].citNo=28;
	person[0].salary=100;
	strcpy(person[0].name, "HAKAN AYDIN");
	for(int i=0; i< 20; i++){
printf("birnci kisinin ilini girinz");
	sacnf("%d", &il);
printf("birnici kisinin masini girniz");
	scanf("%d",&maas);
	person[i].citNo=il;
	person[i].salary=maas;
prinf("birnici kisinin adın girinizi");
	strcpy(person[i].name, "HAKAN AYDIN");
}
	pointer->citNo = 61;
	pointer->salary = 150;
	strcpy(pointer->name, "GOKHAN AYDIN");


	// print struct variables
	printf("Name: %s\n", pers.name);
	printf("Citizenship No: %d\n", pers.citNo);
	printf("Salary: %.2f \n", pers.salary);

	// print struct variables
	printf("Name: %s\n", pointer->name);
	printf("Citizenship No: %d\n", pointer->citNo);
	printf("Salary: %.2f \n", pointer->salary);

   	return 0;
}
////////////////////////////////////////////////
void print_person_list(int index){

}

// 1. odev typedef kullanımı ile struct tanımlama
// 2. bu structı farklı bir dosyaya tanımlayıp header'i main dosyasına include etme
// 20 kisilik bir struct dizisi oluşturma ve bunlara ad, soyad, yaş, memleket, medeni durum ekleme
// bu struct disizini bir fonkiyonua parametre ekleme ve değerleri gösterme
// bu projeyi githuba yükleme
//  n x m (max=1000)
// array x= 1000
// array y = 1000 





