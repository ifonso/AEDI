#ifndef DATE_H_
#define DATE_H_

typedef struct {
    unsigned int day;
    unsigned int month;
    unsigned int year;
} Date;

int set_date(Date * d, int day, int month, int year);
void print_date(Date * d);

#endif // DATE_H_