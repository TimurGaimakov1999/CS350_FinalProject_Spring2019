#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

struct binary
{
    char opcode[100]; //6
    char rs[100]; //5
    char rt[100]; //5
    char rd[100]; //5
    char shamt[100]; //5
    char funct[100]; //6
};

// function to convert Hexadecimal to Binary Number 
char* HexToBin(char* hexdec) 
{ 
    long int i = 0;
    char * bin;
    bin = malloc(sizeof(char) * 100); 
    
    while(hexdec[i] && i < 8) 
    { 
        switch(hexdec[i]) 
        {
            case '0':
            {
                strcat(bin, "0000");
                break;
            }
            
            case '1': 
                strcat(bin, "0001");
                break; 
            
            case '2': 
                strcat(bin, "0010");
                break; 
            
            case '3': 
                strcat(bin, "0011");
                break; 
            
            case '4': 
                strcat(bin, "0100");
                break;
            
            case '5': 
                strcat(bin, "0101"); 
                break; 
            
            case '6': 
                strcat(bin, "0110"); 
                break; 
                
            case '7': 
                strcat(bin, "0111"); 
                break; 
                
            case '8': 
                strcat(bin, "1000");
                break; 
                
            case '9':  
                strcat(bin, "1001"); 
                break; 
                
            case 'A':
            case 'a':
                strcat(bin, "1010"); 
                break; 
                
            case 'B':
            case 'b':
                strcat(bin, "1011");
                break; 
                
            case 'C':
            case 'c':
                strcat(bin, "1100");  
                break; 
                
            case 'D':
            case 'd':
               strcat(bin, "1101");
                break; 
                
            case 'E': 
            case 'e':
                strcat(bin, "1110");
                break;
                
            case 'F':
            case 'f':
                strcat(bin, "1111");
                break;
                
            default: 
                printf("\nInvalid hexadecimal digit %c", hexdec[i]); 
        } 
        i++; 
    }
    if(i < 8)
    {
        while(i < 8)
        {
            strcat(bin, "0000");
            i++;
        }
    }
    return bin;
}

// driver code 
int main() 
{ 
//    struct binary val;
    
    // Get the Hexadecimal number 
    char hexdec[100] = ""; 
    char sub[100] = "";
    char temp[100];
    
//    char *bin1 = HexToBin(hexdec);
    int location;
    
    char *assembly;
//    char total[1000] = "";
    
    // Prompting user
    printf("Loading data.txt\nRead 27 lines of data\n");
    
    printf("Enter program counter (in hex digits with no x at front) : ");
    scanf("%x", &location);
    
    printf("\nInitial program counter = x%x", location);
    
    printf("\n\nLocation\tInstruction\n");
    
    // Files
    FILE *f_Pointer;
    f_Pointer = fopen("data.txt", "r");
    char singleLine[100];
    
    while(!feof(f_Pointer))
    {
        //char *d[100] = fgets(singleLine, 100, f_Pointer);
        assembly = malloc(sizeof(char) * 100);
        char *line = fgets(singleLine, 100, f_Pointer);
        char *bin1 = HexToBin(line);
        
        // from hex to string
        sprintf(temp, "%x", location);

        strcat(assembly, "x");
        strcat(assembly, temp);
        int c = 0;

        // shamt  
        while(c < 5) 
        {
            sub[c] = bin1[21 + c];
            c++;
        }
        sub[c] = '\0';

        int _0_ = strcmp(sub, "00000"),
            _1_ = strcmp(sub, "00001"),
            _2_ = strcmp(sub, "00010"),
            _3_ = strcmp(sub, "00011"),
            _4_ = strcmp(sub, "00100"),
            _5_ = strcmp(sub, "00101"),
            _6_ = strcmp(sub, "00110"),
            _7_ = strcmp(sub, "00111"),
            _8_ = strcmp(sub, "01000"),
            _9_ = strcmp(sub, "01001"),
            _10_ = strcmp(sub, "01010"),
            _11_ = strcmp(sub, "01011"),
            _12_ = strcmp(sub, "01100"),
            _13_ = strcmp(sub, "01101"),
            _14_ = strcmp(sub, "01110"),
            _15_ = strcmp(sub, "01111"),
            _16_ = strcmp(sub, "10000"),
            _17_ = strcmp(sub, "10001"),
            _18_ = strcmp(sub, "10010"),
            _19_ = strcmp(sub, "10011"),
            _20_ = strcmp(sub, "10100"),
            _21_ = strcmp(sub, "10101"),
            _22_ = strcmp(sub, "10110"),
            _23_ = strcmp(sub, "10111"),
            _24_ = strcmp(sub, "11000"),
            _25_ = strcmp(sub, "11001"),
            _26_ = strcmp(sub, "11010"),
            _27_ = strcmp(sub, "11011"),
            _28_ = strcmp(sub, "11100"),
            _29_ = strcmp(sub, "11101"),
            _30_ = strcmp(sub, "11110"),
            _31_ = strcmp(sub, "11111");
    
        int dec1 = 0;
        {
            if(_0_ == 0)
            {
                dec1 = 0;
            }
        }
        // for R-type instr: shamt
        char num[100] = "";
        char val[100] = "";
        if(_0_ == 0)
        {
          strcat(num, " 0");
          strcat(val, "00");
        }
        else if(_1_ == 0)
        {
          strcat(num, " 1");
          strcat(val, "01");
        }
        else if(_2_ == 0)
        {
          strcat(num, " 2");
          strcat(val, "02");
        }
        else if(_3_ == 0)
        {
          strcat(num, " 3");
          strcat(val, "03");
        }
        else if(_4_ == 0)
        {
          strcat(num, " 4");
          strcat(val, "04");
        }
        else if(_5_ == 0)
        {
          strcat(num, " 5");
          strcat(val, "05");
        }
        else if(_6_ == 0)
        {
          strcat(num, " 6");
          strcat(val, "06");
        }
        else if(_7_ == 0)
        {
          strcat(num, " 7");
          strcat(val, "07");
        }
        else if(_8_ == 0)
        {
          strcat(num, " 8");
          strcat(val, "08");
        }
        else if(_9_ == 0)
        {
          strcat(num, " 9");
          strcat(val, "09");
        }
        else if(_10_ == 0)
        {
          strcat(num, "10");
          strcat(val, "0A");
        }
        else if(_11_ == 0)
        {
          strcat(num, "11");
          strcat(val, "0B");
        }
        else if(_12_ == 0)
        {
          strcat(num, "12");
          strcat(val, "0C");
        }
        else if(_13_ == 0)
        {
          strcat(num, "13");
          strcat(val, "0D");
        }
        else if(_14_ == 0)
        {
          strcat(num, "14");
          strcat(val, "0E");
        }
        else if(_15_ == 0)
        {
          strcat(num, "15");
          strcat(val, "0F");
        }
        else if(_16_ == 0)
        {
          strcat(num, "16");
          strcat(val, "10");
        }
        else if(_17_ == 0)
        {
          strcat(num, "17");
          strcat(val, "11");
        }
        else if(_18_ == 0)
        {
          strcat(num, "18");
          strcat(val, "12");
        }
        else if(_19_ == 0)
        {
          strcat(num, "19");
          strcat(val, "13");
        }
        else if(_20_ == 0)
        {
          strcat(num, "20");
          strcat(val, "14");
        }
        else if(_21_ == 0)
        {
          strcat(num, "21");
          strcat(val, "15");
        }
        else if(_22_ == 0)
        {
          strcat(num, "22");
          strcat(val, "16");
        }
        else if(_23_ == 0)
        {
          strcat(num, "23");
          strcat(val, "17");
        }
        else if(_24_ == 0)
        {
          strcat(num, "24");
          strcat(val, "18");
        }
        else if(_25_ == 0)
        {
          strcat(num, "25");
          strcat(val, "19");
        }
        else if(_26_ == 0)
        {
          strcat(num, "26");
          strcat(val, "1A");
        }
        else if(_27_ == 0)
        {
          strcat(num, "27");
          strcat(val, "1B");
        }
        else if(_28_ == 0)
        {
          strcat(num, "28");
          strcat(val, "1C");
        }
        else if(_29_ == 0)
        {
          strcat(num, "29");
          strcat(val, "1D");
        }
        if(_30_ == 0)
        {
          strcat(num, "30");
          strcat(val, "1E");
        }
        else if(_31_ == 0)
        {
          strcat(num, "31");
          strcat(val, "1F");
        }
		    strcat(assembly, "\t");

        // opcode
        c = 0;
        while(c < 6) 
        {
            sub[c] = bin1[0 + c];
            c++;
        }
        sub[c] = '\0';
    
        int r_Format = strcmp(sub, "000000"), //0
    
            j1_Format = strcmp(sub, "000010"), //2
            j2_Format = strcmp(sub, "000011"), //3
        
            i1_Format = strcmp(sub, "000100"), //4
            i2_Format = strcmp(sub, "000101"), //5
            i5_Format = strcmp(sub, "001000"), //8
            i7_Format = strcmp(sub, "001010"), //10
            i9_Format = strcmp(sub, "001100"), //12
            i10_Format = strcmp(sub, "001101"), //13
            i11_Format = strcmp(sub, "001110"), //14
            i12_Format = strcmp(sub, "001111"), //15
            i32_Format = strcmp(sub, "100011"), //35
            i40_Format = strcmp(sub, "101011"); //43
        
        int dec = 0;
        char sub1[100] = "";
        char temp[100] = "x";
    
        if(r_Format == 0)
        {
            dec = 1;
        }
        else if(j1_Format == 0 || j2_Format == 0)
        {
            dec = 2;
            if(j1_Format == 0)
            {
                strcat(assembly, "j\t\t0x");
                c = 0;
                while(c < 6) 
                {
                    sub1[c] = line[2 + c];
                    c++;
                }
                sub1[c] = '\0';
                strcat(assembly, sub1);
            }
            else if(j2_Format == 0)
            {
                strcat(assembly, "jal\t\t0x");
                c = 0;
                while(c < 6) 
                {
                    sub1[c] = line[2 + c];
                    c++;
                }
                sub1[c] = '\0';
                strcat(assembly, sub1);
            }
        }
        else
        {
            dec = 3;
            if(i1_Format == 0)
            {
                strcat(assembly, "beq  ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i2_Format == 0)
            {
                strcat(assembly, "bne  ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i5_Format == 0)
            {
                strcat(assembly, "addi ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i7_Format == 0)
            {
                strcat(assembly, "slti ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i9_Format == 0)
            {
                strcat(assembly, "andi ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i10_Format == 0)
            {
                strcat(assembly, "ori  ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i11_Format == 0)
            {
                strcat(assembly, "xori ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i12_Format == 0)
            {
                strcat(assembly, "lui  ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i32_Format == 0)
            {
                strcat(assembly, "lw   ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
            else if(i40_Format == 0)
            {
                strcat(assembly, "sw   ");
                c = 0;
                while(c < 4) 
                {
                    sub1[c] = line[4 + c];
                    c++;
                }
                temp[c] = '\0';
            }
        }

        int decimal = (int)strtol(sub1, NULL, 16);

        if(decimal > 32767)
        {
          decimal -= 65536;
        } 

        char int_to_str[100];
        sprintf(int_to_str, "%d", decimal);

        // funct      
        c = 0;
        while(c < 6) 
        {
            sub[c] = bin1[26 + c];
            c++;
        }
        sub[c] = '\0';
    
        int jr = strcmp(sub, "001000"),
            mult = strcmp(sub, "011000"),
            division = strcmp(sub, "011010"),
            addition = strcmp(sub, "100000"),
            subtraction = strcmp(sub, "100010"),
            And = strcmp(sub, "100100"),
            Or = strcmp(sub, "100101"),
            XoR1 = strcmp(sub, "101000"),
            XoR2 = strcmp(sub, "100110"),
            nor = strcmp(sub, "100111"),
            slt = strcmp(sub, "101010"),
            nop = strcmp(sub, "000000");

        int _0 = strcmp(sub, "000000"),
            _1 = strcmp(sub, "000001"),
            _2 = strcmp(sub, "000010"),
            _3 = strcmp(sub, "000011"),
            _4 = strcmp(sub, "000100"),
            _5 = strcmp(sub, "000101"),
            _6 = strcmp(sub, "000110"),
            _7 = strcmp(sub, "000111"),
            _8 = strcmp(sub, "001000"),
            _9 = strcmp(sub, "001001"),
            _10 = strcmp(sub, "001010"),
            _11 = strcmp(sub, "001011"),
            _12 = strcmp(sub, "001100"),
            _13 = strcmp(sub, "001101"),
            _14 = strcmp(sub, "001110"),
            _15 = strcmp(sub, "001111"),
            _16 = strcmp(sub, "010000"),
            _17 = strcmp(sub, "010001"),
            _18 = strcmp(sub, "010010"),
            _19 = strcmp(sub, "010011"),
            _20 = strcmp(sub, "010100"),
            _21 = strcmp(sub, "010101"),
            _22 = strcmp(sub, "010110"),
            _23 = strcmp(sub, "010111"),
            _24 = strcmp(sub, "011000"),
            _25 = strcmp(sub, "011001"),
            _26 = strcmp(sub, "011010"),
            _27 = strcmp(sub, "011011"),
            _28 = strcmp(sub, "011100"),
            _29 = strcmp(sub, "011101"),
            _30 = strcmp(sub, "011110"),
            _31 = strcmp(sub, "011111"),
            _32 = strcmp(sub, "100000"),
            _33 = strcmp(sub, "100001"),
            _34 = strcmp(sub, "100010"),
            _35 = strcmp(sub, "100011"),
            _36 = strcmp(sub, "100100"),
            _37 = strcmp(sub, "100101"),
            _38 = strcmp(sub, "100110"),
            _39 = strcmp(sub, "100111"),
            _40 = strcmp(sub, "101000"),
            _41 = strcmp(sub, "101001"),
            _42 = strcmp(sub, "101010"),
            _43 = strcmp(sub, "101011"),
            _44 = strcmp(sub, "101100"),
            _45 = strcmp(sub, "101101"),
            _46 = strcmp(sub, "101110"),
            _47 = strcmp(sub, "101111"),
            _48 = strcmp(sub, "110000"),
            _49 = strcmp(sub, "110001"),
            _50 = strcmp(sub, "110010"),
            _51 = strcmp(sub, "110011"),
            _52 = strcmp(sub, "110100"),
            _53 = strcmp(sub, "110101"),
            _54 = strcmp(sub, "110110"),
            _55 = strcmp(sub, "110111"),
            _56 = strcmp(sub, "111000"),
            _57 = strcmp(sub, "111001"),
            _58 = strcmp(sub, "111010"),
            _59 = strcmp(sub, "111011"),
            _60 = strcmp(sub, "111100"),
            _61 = strcmp(sub, "111101"),
            _62 = strcmp(sub, "111110"),
            _63 = strcmp(sub, "111111");

        if(jr == 0 && dec == 1)
        {
            strcat(assembly, "jr   ");
        }
    
        else if(mult == 0 && dec == 1)
        {
            strcat(assembly, "mul  ");
        }
    
        else if(division == 0 && dec == 1)
        {
            strcat(assembly, "div  ");
        }    
    
        else if(addition == 0 && dec == 1)
        {
            strcat(assembly, "add  ");
        }

        else if(subtraction == 0 && dec == 1)
        {
            strcat(assembly, "sub  ");
        }
    
        else if(And == 0 && dec == 1)
        {
            strcat(assembly, "and  ");
        }    
    
        else if(Or == 0 && dec == 1)
        {
            strcat(assembly, "or   ");
        }
    
        else if((XoR1 == 0 || XoR2 == 0) && dec == 1)
        {
            strcat(assembly, "xor  ");
        }
    
        else if(nor == 0 && dec == 1)
        {
            strcat(assembly, "nor  ");
        }
    
        else if(slt == 0 && dec == 1)
        {
            strcat(assembly, "slt  ");
        }

        else if(nop == 0 && dec == 1)
        {
            strcat(assembly, "nop  "); 
        }

        // for R-type instr: funct
        char num1[100] = "";
        char val1[100] = "";
        if(_0 == 0)
        {
          strcat(num1, " 0");
          strcat(val1, "00");
        }
        else if(_1 == 0)
        {
          strcat(num1, " 1");
          strcat(val1, "01");
        }
        else if(_2 == 0)
        {
          strcat(num1, " 2");
          strcat(val1, "02");
        }
        else if(_3 == 0)
        {
          strcat(num1, " 3");
          strcat(val1, "03");
        }
        else if(_4 == 0)
        {
          strcat(num1, " 4");
          strcat(val1, "04");
        }
        else if(_5 == 0)
        {
          strcat(num1, " 5");
          strcat(val1, "05");
        }
        else if(_6 == 0)
        {
          strcat(num1, " 6");
          strcat(val1, "06");
        }
        else if(_7 == 0)
        {
          strcat(num1, " 7");
          strcat(val1, "07");
        }
        else if(_8 == 0)
        {
          strcat(num1, " 8");
          strcat(val1, "08");
        }
        else if(_9 == 0)
        {
          strcat(num1, " 9");
          strcat(val1, "09");
        }
        else if(_10 == 0)
        {
          strcat(num1, "10");
          strcat(val1, "0A");
        }
        else if(_11 == 0)
        {
          strcat(num1, "11");
          strcat(val1, "0B");
        }
        else if(_12 == 0)
        {
          strcat(num1, "12");
          strcat(val1, "0C");
        }
        else if(_13 == 0)
        {
          strcat(num1, "13");
          strcat(val1, "0D");
        }
        else if(_14 == 0)
        {
          strcat(num1, "14");
          strcat(val1, "0E");
        }
        else if(_15 == 0)
        {
          strcat(num1, "15");
          strcat(val1, "0F");
        }
        else if(_16 == 0)
        {
          strcat(num1, "16");
          strcat(val1, "10");
        }
        else if(_17 == 0)
        {
          strcat(num1, "17");
          strcat(val1, "11");
        }
        else if(_18 == 0)
        {
          strcat(num1, "18");
          strcat(val1, "12");
        }
        else if(_19 == 0)
        {
          strcat(num1, "19");
          strcat(val1, "13");
        }
        else if(_20 == 0)
        {
          strcat(num1, "20");
          strcat(val1, "14");
        }
        else if(_21 == 0)
        {
          strcat(num1, "21");
          strcat(val1, "15");
        }
        else if(_22 == 0)
        {
          strcat(num1, "22");
          strcat(val1, "16");
        }
        else if(_23 == 0)
        {
          strcat(num1, "23");
          strcat(val1, "17");
        }
        else if(_24 == 0)
        {
          strcat(num1, "24");
          strcat(val1, "18");
        }
        else if(_25 == 0)
        {
          strcat(num1, "25");
          strcat(val1, "19");
        }
        else if(_26 == 0)
        {
          strcat(num1, "26");
          strcat(val1, "1A");
        }
        else if(_27 == 0)
        {
          strcat(num1, "27");
          strcat(val1, "1B");
        }
        else if(_28 == 0)
        {
          strcat(num1, "28");
          strcat(val1, "1C");
        }
        else if(_29 == 0)
        {
          strcat(num1, "29");
          strcat(val1, "1D");
        }
        if(_30 == 0)
        {
          strcat(num1, "30");
          strcat(val1, "1E");
        }
        else if(_31 == 0)
        {
          strcat(num1, "31");
          strcat(val1, "1F");
        }
        else if(_32 == 0)
        {
          strcat(num1, "32");
          strcat(val1, "20");
        }
        else if(_33 == 0)
        {
          strcat(num1, "33");
          strcat(val1, "21");
        }
        else if(_34 == 0)
        {
          strcat(num1, "34");
          strcat(val1, "22");
        }
        else if(_35 == 0)
        {
          strcat(num1, "35");
          strcat(val1, "23");
        }
        else if(_36 == 0)
        {
          strcat(num1, "36");
          strcat(val1, "24");
        }
        else if(_37 == 0)
        {
          strcat(num1, "37");
          strcat(val1, "25");
        }
        else if(_38 == 0)
        {
          strcat(num1, "38");
          strcat(val1, "26");
        }
        else if(_39 == 0)
        {
          strcat(num1, "39");
          strcat(val1, "27");
        }
        else if(_40 == 0)
        {
          strcat(num1, "40");
          strcat(val1, "28");
        }
        else if(_41 == 0)
        {
          strcat(num1, "41");
          strcat(val1, "29");
        }
        else if(_42 == 0)
        {
          strcat(num1, "42");
          strcat(val1, "2A");
        }
        else if(_43 == 0)
        {
          strcat(num1, "43");
          strcat(val1, "2B");
        }
        else if(_44 == 0)
        {
          strcat(num1, "44");
          strcat(val1, "2C");
        }
        else if(_45 == 0)
        {
          strcat(num1, "45");
          strcat(val1, "2D");
        }
        else if(_46 == 0)
        {
          strcat(num1, "46");
          strcat(val1, "2E");
        }
        else if(_47 == 0)
        {
          strcat(num1, "47");
          strcat(val1, "2F");
        }
        else if(_48 == 0)
        {
          strcat(num1, "48");
          strcat(val1, "30");
        }
        else if(_49 == 0)
        {
          strcat(num1, "49");
          strcat(val1, "31");
        }
        else if(_50 == 0)
        {
          strcat(num1, "50");
          strcat(val1, "32");
        }
        else if(_51 == 0)
        {
          strcat(num1, "51");
          strcat(val1, "33");
        }
        else if(_52 == 0)
        {
          strcat(num1, "52");
          strcat(val1, "34");
        }
        else if(_53 == 0)
        {
          strcat(num1, "53");
          strcat(val1, "35");
        }
        else if(_54 == 0)
        {
          strcat(num1, "54");
          strcat(val1, "36");
        }
        else if(_55 == 0)
        {
          strcat(num1, "55");
          strcat(val1, "37");
        }
        else if(_56 == 0)
        {
          strcat(num1, "56");
          strcat(val1, "38");
        }
        else if(_57 == 0)
        {
          strcat(num1, "57");
          strcat(val1, "39");
        }
        else if(_58 == 0)
        {
          strcat(num1, "58");
          strcat(val1, "3A");
        }
        else if(_59 == 0)
        {
          strcat(num1, "59");
          strcat(val1, "3B");
        }
        else if(_60 == 0)
        {
          strcat(num1, "60");
          strcat(val1, "3C");
        }
        else if(_61 == 0)
        {
          strcat(num1, "61");
          strcat(val1, "3D");
        }
        else if(_62 == 0)
        {
          strcat(num1, "62");
          strcat(val1, "3E");
        }
        else if(_63 == 0)
        {
          strcat(num1, "63");
          strcat(val1, "3F");
        }

		    strcat(assembly, "\t");
        // rd      
        c = 0;
        while(c < 5) 
        {
            sub[c] = bin1[16 + c];
            c++;
        }
        sub[c] = '\0';
        
        _0_ = strcmp(sub, "00000");
        _1_ = strcmp(sub, "00001");
        _2_ = strcmp(sub, "00010");
        _3_ = strcmp(sub, "00011");
        _4_ = strcmp(sub, "00100");
        _5_ = strcmp(sub, "00101");
        _6_ = strcmp(sub, "00110");
        _7_ = strcmp(sub, "00111");
        _8_ = strcmp(sub, "01000");
        _9_ = strcmp(sub, "01001");
        _10_ = strcmp(sub, "01010");
        _11_ = strcmp(sub, "01011");
        _12_ = strcmp(sub, "01100");
        _13_ = strcmp(sub, "01101");
        _14_ = strcmp(sub, "01110");
        _15_ = strcmp(sub, "01111");
        _16_ = strcmp(sub, "10000");
        _17_ = strcmp(sub, "10001");
        _18_ = strcmp(sub, "10010");
        _19_ = strcmp(sub, "10011");
        _20_ = strcmp(sub, "10100");
        _21_ = strcmp(sub, "10101");
        _22_ = strcmp(sub, "10110");
        _23_ = strcmp(sub, "10111");
        _24_ = strcmp(sub, "11000");
        _25_ = strcmp(sub, "11001");
        _26_ = strcmp(sub, "11010");
        _27_ = strcmp(sub, "11011");
        _28_ = strcmp(sub, "11100");
        _29_ = strcmp(sub, "11101");
        _30_ = strcmp(sub, "11110");
        _31_ = strcmp(sub, "11111");
    
        if(_0_ == 0 && dec == 1)
        {
            strcat(assembly, " $0, ");
        }
        else if(_1_ == 0 && dec == 1)
        {
            strcat(assembly, "$at, "); 
        }
        else if(_2_ == 0 && dec == 1)
        {
            strcat(assembly, "$v0, "); 
        }
        else if(_3_ == 0 && dec == 1)
        {
            strcat(assembly, "$v1, "); 
        }
        else if(_4_ == 0 && dec == 1)
        {
            strcat(assembly, "$a0, "); 
        }
        else if(_5_ == 0 && dec == 1)
        {
            strcat(assembly, "$a1, ");
        }
        else if(_6_ == 0 && dec == 1)
        {
            strcat(assembly, "$a2, "); 
        }
        else if(_7_ == 0 && dec == 1)
        {
            strcat(assembly, "$a3, "); 
        }
        else if(_8_ == 0 && dec == 1)
        {
            strcat(assembly, "$t0, "); 
        }
        else if(_9_ == 0 && dec == 1)
        {
            strcat(assembly, "$t1, ");
        }
        else if(_10_ == 0 && dec == 1)
        {
            strcat(assembly, "$t2, "); 
        }
        else if(_11_ == 0 && dec == 1)
        {
            strcat(assembly, "$t3, "); 
        }
        else if(_12_ == 0 && dec == 1)
        {
            strcat(assembly, "$t4, "); 
        }
        else if(_13_ == 0 && dec == 1)
        {
            strcat(assembly, "$t5, "); 
        }
        else if(_14_ == 0 && dec == 1)
        {
            strcat(assembly, "$t6, "); 
        }
        else if(_15_ == 0 && dec == 1)
        {
            strcat(assembly, "$t7, ");
        }
        else if(_16_ == 0 && dec == 1)
        {
            strcat(assembly, "$s0, "); 
        }
        else if(_17_ == 0 && dec == 1)
        {
            strcat(assembly, "$s1, "); 
        }
        else if(_18_ == 0 && dec == 1)
        {
            strcat(assembly, "$s2, "); 
        }
        else if(_19_ == 0 && dec == 1)
        {
            strcat(assembly, "$s3, ");
        }
        else if(_20_ == 0 && dec == 1)
        {
            strcat(assembly, "$s4, "); 
        }
        else if(_21_ == 0 && dec == 1)
        {
            strcat(assembly, "$s5, "); 
        }
        else if(_22_ == 0 && dec == 1)
        {
            strcat(assembly, "$s6, "); 
        }
        else if(_23_ == 0 && dec == 1)
        {
            strcat(assembly, "$s7, "); 
        }
        else if(_24_ == 0 && dec == 1)
        {
            strcat(assembly, "$t8, "); 
        }
        else if(_25_ == 0 && dec == 1)
        {
            strcat(assembly, "$t9, ");
        }
        else if(_26_ == 0 && dec == 1)
        {
            strcat(assembly, "$k0, "); 
        }
        else if(_27_ == 0 && dec == 1)
        {
            strcat(assembly, "$k1, "); 
        }
        else if(_28_ == 0 && dec == 1)
        {
            strcat(assembly, "$gp, "); 
        }
        else if(_29_ == 0 && dec == 1)
        {
            strcat(assembly, "$sp, ");
        }
        else if(_30_ == 0 && dec == 1)
        {
            strcat(assembly, "$fp, "); 
        }
        else if(_31_ == 0 && dec == 1)
        {
            strcat(assembly, "$ra, "); 
        } 
    
        // rs    
        c = 0;
        while(c < 5) 
        {
            sub[c] = bin1[6 + c];
            c++;
        }
        sub[c] = '\0';

        _0_ = strcmp(sub, "00000");
        _1_ = strcmp(sub, "00001");
        _2_ = strcmp(sub, "00010");
        _3_ = strcmp(sub, "00011");
        _4_ = strcmp(sub, "00100");
        _5_ = strcmp(sub, "00101");
        _6_ = strcmp(sub, "00110");
        _7_ = strcmp(sub, "00111");
        _8_ = strcmp(sub, "01000");
        _9_ = strcmp(sub, "01001");
        _10_ = strcmp(sub, "01010");
        _11_ = strcmp(sub, "01011");
        _12_ = strcmp(sub, "01100");
        _13_ = strcmp(sub, "01101");
        _14_ = strcmp(sub, "01110");
        _15_ = strcmp(sub, "01111");
        _16_ = strcmp(sub, "10000");
        _17_ = strcmp(sub, "10001");
        _18_ = strcmp(sub, "10010");
        _19_ = strcmp(sub, "10011");
        _20_ = strcmp(sub, "10100");
        _21_ = strcmp(sub, "10101");
        _22_ = strcmp(sub, "10110");
        _23_ = strcmp(sub, "10111");
        _24_ = strcmp(sub, "11000");
        _25_ = strcmp(sub, "11001");
        _26_ = strcmp(sub, "11010");
        _27_ = strcmp(sub, "11011");
        _28_ = strcmp(sub, "11100");
        _29_ = strcmp(sub, "11101");
        _30_ = strcmp(sub, "11110");
        _31_ = strcmp(sub, "11111");
    
        if(_0_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, " $0, ");
        }
        else if(_1_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$at, "); 
        }
        else if(_2_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$v0, "); 
        }
        else if(_3_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$v1, "); 
        }
        else if(_4_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$a0, "); 
        }
        else if(_5_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$a1, ");
        }
        else if(_6_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$a2, "); 
        }
        else if(_7_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$a3, "); 
        }
        else if(_8_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t0, "); 
        }
        else if(_9_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t1, ");
        }
        else if(_10_ == 0 && (dec == 1 || dec == 3))
        {   
            strcat(assembly, "$t2, "); 
        }
        else if(_11_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t3, "); 
        }
        else if(_12_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t4, "); 
        }
        else if(_13_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t5, "); 
        }
        else if(_14_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t6, "); 
        }
        else if(_15_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t7, ");
        }
        else if(_16_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s0, "); 
        }
        else if(_17_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s1, "); 
        }
        else if(_18_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s2, "); 
        }
        else if(_19_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s3, ");
        }
        else if(_20_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s4, "); 
        }
        else if(_21_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s5, "); 
        }
        else if(_22_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s6, "); 
        }
        else if(_23_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$s7, "); 
        }
        else if(_24_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t8, "); 
        }
        else if(_25_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$t9, ");
        }
        else if(_26_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$k0, "); 
        }
        else if(_27_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$k1, "); 
        }
        else if(_28_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$gp, "); 
        }
        else if(_29_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$sp, ");
        }
        else if(_30_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$fp, "); 
        }
        else if(_31_ == 0 && (dec == 1 || dec == 3))
        {
            strcat(assembly, "$ra, "); 
        }
    
        // rt     
        c = 0;
        while(c < 5) 
        {
            sub[c] = bin1[11 + c];
            c++;
        }
        sub[c] = '\0';

        _0_ = strcmp(sub, "00000");
        _1_ = strcmp(sub, "00001");
        _2_ = strcmp(sub, "00010");
        _3_ = strcmp(sub, "00011");
        _4_ = strcmp(sub, "00100");
        _5_ = strcmp(sub, "00101");
        _6_ = strcmp(sub, "00110");
        _7_ = strcmp(sub, "00111");
        _8_ = strcmp(sub, "01000");
        _9_ = strcmp(sub, "01001");
        _10_ = strcmp(sub, "01010");
        _11_ = strcmp(sub, "01011");
        _12_ = strcmp(sub, "01100");
        _13_ = strcmp(sub, "01101");
        _14_ = strcmp(sub, "01110");
        _15_ = strcmp(sub, "01111");
        _16_ = strcmp(sub, "10000");
        _17_ = strcmp(sub, "10001");
        _18_ = strcmp(sub, "10010");
        _19_ = strcmp(sub, "10011");
        _20_ = strcmp(sub, "10100");
        _21_ = strcmp(sub, "10101");
        _22_ = strcmp(sub, "10110");
        _23_ = strcmp(sub, "10111");
        _24_ = strcmp(sub, "11000");
        _25_ = strcmp(sub, "11001");
        _26_ = strcmp(sub, "11010");
        _27_ = strcmp(sub, "11011");
        _28_ = strcmp(sub, "11100");
        _29_ = strcmp(sub, "11101");
        _30_ = strcmp(sub, "11110");
        _31_ = strcmp(sub, "11111");
    
        if(_0_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$0");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$0, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_1_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$at");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$at, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_2_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$v0");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$v0, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_3_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$v1");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$v1, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_4_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$a0");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$a0, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_5_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$a1");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$a1, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_6_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$a2");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$a2, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_7_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$a3");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$a3, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_8_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t0");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t0, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_9_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t1");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t1, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_10_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t2");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t2, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_11_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t3");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t3, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_12_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t4");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");                
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t4, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_13_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t5");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t5, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            } 
        }
        else if(_14_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t6");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t6, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_15_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t7");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t7, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_16_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s0");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s0, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_17_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s1");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s1, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_18_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s2");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s2, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_19_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s3");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s3, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_20_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s4");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s4, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_21_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s5");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s5, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_22_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s6");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s6, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_23_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$s7");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$s7, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_24_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t8");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t8, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_25_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$t9");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$t9, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_26_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$k0");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$k0, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_27_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$k1");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$k1, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_28_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$gp");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$gp, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            } 
        }
        else if(_29_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$sp");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$sp, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_30_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$fp");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$fp, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        else if(_31_ == 0 && (dec == 1 || dec == 3))
        {
            if(dec == 1)
            {
                strcat(assembly, "$ra");
                strcat(assembly, "\t(s/f: x");
                strcat(assembly, val);
                strcat(assembly, ", x");
                strcat(assembly, val1);
                strcat(assembly, " = dec ");
                strcat(assembly, num);
                strcat(assembly, ", ");
                strcat(assembly, num1);
                strcat(assembly, ")");
            }
            else if(dec == 3)
            {
                strcat(assembly, "$ra, x");
                strcat(assembly, sub1);
                strcat(assembly, "\t: dec ");
                strcat(assembly, int_to_str);
            }
        }
        puts(assembly);
        assembly = "";
        location = location + 4;
    }
    fclose(f_Pointer);
    printf("Program ending");
} 