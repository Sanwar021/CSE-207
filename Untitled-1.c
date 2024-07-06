#include <stdio.h>
#include <stdlib.h>
int main() {
 int n;
 double *data;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 data = (double *)calloc(n, sizeof(double));
 if (data == NULL) {
 printf("Error! memory not allocated.");
 exit(0);
 }
 int j ;
 printf("\nEnter the value of the numbers : \n ");
 for ( j = 0; j < n; ++j)
 {
 scanf("%lf", data + j);
 }
 for ( j = 1; j < n; ++j) {
 if (*data < *(data + j)) {
 *data = *(data + j);
 }
 }
 printf("Largest number = %.2lf", *data);
 free(data);
 return 0;
}