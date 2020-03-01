/*
   Name: project0.c
   Author: Kevin Wilczynski
   Description:the program reads 8bit binary numbers from text file and
   converts it to ASCII,DECIMAL,and tells the Parity
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int bin2dec(char *bin);
int display(char *stringInput);
char *padzeros(char *bin);
char *OddEven(char *bin);


int main(int argc, char* argv[]){

        int decimal;
        char *parity;
        char fname[64],buf[16];
        int w[4] = {1,5,10,10};
        int w2[4] = {4,8,10,10};//for padding of output
        char *N = argv[1];
        int i,digits = 0, decimalC = 0;


        char *unprintable[] = {"NUL", "SOH", "STX"," ETX", "EOT", "ENQ", "ACK",
                           "BEL", "BS", "HT", "LF", "VT", "FF", "CR",
                           "SO","SI", "DLE","DC1","DC2","DC3", "DC4",
                           "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC",
                           "FS", "GS","RS", "US", "SPACE"};

        FILE* file;

        if(argc <2) {
                printf("Input data not suported ");
                // scanf("%s",fname);
                // file = fopen(fname, "r");
                return 0;
        }else if(argv[1][0]=='-' && argc<3) {
                printf("Invalid Input\n");
                return 0;

        }else{

                file = fopen(argv[1], "r");
        }
        if(argv[1][0]=='0' || argv[1][0]=='1' || argv[1][0]=='-') {

                for(digits=0; N[digits] != '\0'; digits++);

                for(i=0; i<digits; i++) {
                        decimalC =decimalC+ ((pow(2,digits-1-i)) * ((int)N[i] -48));
                }
                char *bin=buf;
                if (strlen(N) < 8) {
                        bin = padzeros(N);
                }
                decimal = bin2dec(N);
                parity = OddEven(N);


                if(decimalC<31) {
                        printf("Original   ASCII   Decimal  Parity\n");
                        printf("--------  -------- -------- --------\n");
                        printf("%*s%*s%*d%*s\n", w[0], bin, w[1], unprintable[decimalC], w[2], decimalC, w[3],parity);
                }
                else{
                        printf("Original   ASCII   Decimal  Parity\n");
                        printf("--------  -------- -------- --------\n");
                        printf("%*s%*c%*d%*s\n", w[0], bin, w[1], decimalC, w[2], decimalC, w[3],parity);
                }

        }else{


                printf("Original   ASCII   Decimal  Parity\n");
                printf("--------  -------- -------- --------\n");


                while (fscanf(file, "%s", buf) != EOF) {
                        char *bin = buf;
                        if (strlen(buf) < 8) {
                                bin = padzeros(buf);
                        }
                        decimal = bin2dec(buf);
                        parity = OddEven(buf);

                        if(decimal<31) {
                                printf("%*s%*s%*d%*s\n", w[0], bin, w[1], unprintable[decimal], w[2], decimal, w[3],parity);
                        }
                        else{
                                printf("%*s%*c%*d%*s\n", w[0], bin, w[1], decimal, w[2], decimal, w[3],parity);
                        }
                }
                fclose(file);
        }
        return 0;
}

int bin2dec(char *bin){
        int dec = 0;
        int x=strlen(bin)-1;
        for(int i = 0; i < strlen(bin); i++, x--) {
                if(bin[i] == '1') {
                        dec = dec +(pow(2.0,x));
                }
        }
        return dec;
}

char *padzeros(char *bin) {
        for(int i = strlen(bin); i < 8; i++) {
                char* padding = "0";
                strncat(bin, padding, 1);
        }
        return bin;
}

char *OddEven(char *bin){
        int dec = 0;
        for(int i = 0; i < 8; i++) {
                dec += bin[i];
        }
        if(dec % 2 == 0) {
                return "even";
        }else{
                return "odd";
        }
}

int display(char *stringInput){
  
  return 0;
}
