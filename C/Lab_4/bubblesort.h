
#ifndef __BUBBLESORT_H
#define __BUBBLESORT_H



 struct data
{
	char surname[35];
	char givenname[35];
	char department[35];
	float payrate;
	char eyecolor[35];
};




extern void bubblesort(struct data *entry, int maxsize);
extern void swap(struct data *a, struct data *b);
extern void bubblesortpointer(struct data *entry2, int maxsize);
extern void bubblesortaddress(struct data *entry3, int maxsize);








#endif

