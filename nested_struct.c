
#include <stdio.h>
#include <string.h>
#define FIRST_NAME_LEN 10
#define LAST_NAME_LEN 15

struct person_name {
	char first[FIRST_NAME_LEN+1];
	char middle_initial;
	char last[LAST_NAME_LEN+1];
} ;

struct student {
	struct person_name name;
	int id, age;
	char sex;
} student1, student2;

int main(void)
{
	void display_name(struct person_name p);
	struct student build_student(const char *first, const char middle_initial,const char *last);
	void print_name(struct student p);
	strcpy(student1.name.first, "Fred");
	student1.name.middle_initial =  'E';
	strcpy(student1.name.last, "Flintstone");
	display_name(student1.name);
	
	struct student student2 = build_student("Wilma", 'S', "Flintstone");
	display_name(student2.name);
	print_name(student1);
	print_name(student2);
	return 0;
}
void display_name(struct person_name p)
{
	printf("student first name is: %s\n", p.first);
	printf("student middle initual is: %c\n", p.middle_initial);
	printf("student last name is: %s\n", p.last);
	printf("\n");
}
struct student build_student(const char *first, const char middle_initial,const char *last)
{
	struct student p;
	
	strcpy(p.name.first, first);
	p.name.middle_initial = middle_initial;
	strcpy(p.name.last, last);
	return p;
}
void print_name(struct student p)
{
	printf("student first name is: %s\n", p.name.first);
	printf("student middle initual is: %c\n", p.name.middle_initial);
	printf("student last name is: %s\n", p.name.last);
	printf("\n");
}
