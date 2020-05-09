#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

  unsigned int AddressNumber, PageNumber, OffSetNumber;

if(argc < 2)
  return 0;

AddressNumber = atoi(argv[1]);
PageNumber = AddressNumber / 4096;
OffSetNumber = AddressNumber % 4096;

printf("The address %d contains:\n", AddressNumber);
printf("page number = %d\n", PageNumber);
printf("offset = %d\n",OffSetNumber);

return 0;

}
