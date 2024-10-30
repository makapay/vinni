#include <stdio.h>
#include <stdlib.h>

#define  MAX_MONTH 12

typedef struct {
    int month;
    int year;
    int count;
} SalesData;

int main() {
    FILE * fp = fopen("in.txt", "r");
    if (fp == NULL) {
        perror("Ошибка");
        return 1;
    }
    
    SalesData sales[MAX_MONTH] = {0}; 
    char date[11]; 
    char name[50]; 
    char car[50]; 
    int price;
    
    while(fscanf(fp, "%s %s %s %d", date, name, car, &price) == 4){
        int  month, year;
        sscanf(date, "%*d.%d.%d", &month, &year);
        if(month >=1 && month <=  MAX_MONTH){
            if (sales[month - 1].count == 0){
                sales[month - 1].month = month;
                sales[month - 1].year = year;
            }
            sales[month - 1].count++;
        }
    }
    
    fclose(fp);
    
    FILE  * fp1 = fopen("out.txt",  "w");
    fprintf(fp1, "Месяц года количество\n");
    for(int i = 0; i < MAX_MONTH; i++){
            if (sales[i].count >  0){
                fprintf(fp1, "%d.%d.%d\n", sales[i].month, sales[i].year, sales[i].count);
        }
    }
        
    fclose(fp1);
    
    return 0;
        
}
