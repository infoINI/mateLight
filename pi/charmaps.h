#ifndef CHARMAPS_H
#define CHARMAPS_H
//Character maps need to be 5-wide one dimensional arrays
//each index equals a row on the matrix
//the numbers, when translated to binary, equal the pattern shown
//on each row of the matrix when the character is displayerd
//note that characters need to be mirrored

char A[5]={14,	 // 01110
           17,	 // 10001
	   31,	 // 11111
	   17,	 // 10001
	   17};	 // 10001

char B[5]={15,   //01111
	   17,	 //10001
	   15,	 //01111
	   17,	 //10001
	   15};	 //01111

char C[5]={30,	 //11110
	   1,	 //00001
	   1,	 //00001
	   1,	 //00001
	   30};	 //11110

char D[5]={15,	 //01111
           17,	 //10001
           17,	 //10001
           17,	 //10001
           15};	 //01111
           
char E[5]={31,	 //11111,
           1,	 //00001,
           15,	 //01111,
           1,	 //00001,
           31};	 //11111};   
   
char F[5]={31,	 //11111,
           1,	 //00001,
           15,	 //01111,
           1,	 //00001,
           1};	 //00001};
           
char G[5]={30,	 //11110,
           1,	 //00001,
           13,	 //01101,
           17,	 //10001,
           14};	 //01110};
           
char H[5]={17,	 //10001,
           17,	 //10001,
           31,	 //11111,
           17,	 //10001,
           17};	 //10001};     
           
char I[5]={4,	 //00100,
           4,	 //00100,
           4,	 //00100,
           4,	 //00100,
           4};	 //00100};
           
char J[5]={31,	 //11111,
           1,	 //00001,
           1,	 //00001,
           17,	 //10001,
           14};	 //01110};    
     
char K[5]={17,	 //10001,
           11,	 //01011,
           5,	 //00101,
           11,	 //01011,
           17};	 //10001};    

char L[5]={1,	 //00001,
           1,	 //00001,
           1,	 //00001,
           1,	 //00001,
           31};	 //01111};
           
char M[5]={17,	 //10001,
           27,	 //11011,
           21,	 //10101,
           17,	 //10001,
           17};	 //10001};

char N[5]={17,	 //10001,
           19,	 //10011,
           21,	 //10101,
           25,	 //11001,
           17};	 //10001};           
           
char O[5]={14,	 //01110,
           17,	 //10001,
           17,	 //10001,
           17,	 //10001,
           14};	 //01110};

char P[5]={15,	 //01111,
           17,	 //10001,
           15,	 //01111,
           1,	 //00001,
           1};	 //00001};
    
char Q[5]={14,	 //01110,
           17,	 //10001,
           17,   //10001,
           25,	 //11001,
           30};	 //11110};    

char R[5]={15,	 //01111,
           17,	 //10001,
           15,	 //01111,
           9,	 //01001,
           17};	 //10001};
          
char S[5]={30,	 //11110,
           1,	 //00001,
           14,	 //01110,
           16,	 //10000,
           15};	 //01111};

char T[5]={31,	 //11111,
           4,	 //00100,
           4,	 //00100,
           4,	 //00100,
           4};	 //00100};           
      
char U[5]={17,	 //10001,
           17,	 //10001,
           17,	 //10001,
           17,	 //10001,
           14};	 //01110}; 

char V[5]={17,	 //10001,
           17,	 //10001,
           17,	 //10001,
           10,	 //01010,
           4};	 //00100}; 

char W[5]={17,	 //10001,
           17,	 //10001,
           21,	 //10101,
           21,	 //10101,
           10};	 //01010}; 

char X[5]={17,	 //10001,
           10,	 //01010,
           4,	 //00100,
           10,	 //01010,
           17};	 //10001}; 

char Y[5]={17,	 //10001,
           10,	 //01010,
           4,	 //00100,
           4,	 //00100,
           4};	 //00100}; 

char Z[5]={31,	 //11111,
           8,	 //01000,
           4,	 //00100,
           2,	 //00010,
           31};	 //11111};

char n0[5]={14,	 //01110,
            10,	 //01010,
            10,	 //01010,
            10,	 //01010,
            14}; //01110};
            
char n1[5]={4,	 //00100,
            6,	 //00110,
            4,	 //00100,
            4,	 //00100,
            4};	 //00100};
     
char n2[5]={14,	 //01110,
            8,	 //01000,
            14,	 //01110,
            2,	 //00010,
            14}; //01110};
    
char n3[5]={14,	 //01110,
            8,	 //01000,
            14,	 //01110,
            8,	 //01000,
            14}; //01110};                
            
char n4[5]={10,	 //01010,
            10,	 //01010,
            14,	 //01110,
            8,	 //01000,
            8};	 //01000}; 

char n5[5]={14,	 //01110,
            2,	 //00010,
            14,	 //01110,
            8,	 //01000,
            14}; //01110};    
   
char n6[5]={14,	 //01110,
            2,	 //00010,
            14,	 //01110,
            10,	 //01010,
            14}; //01110};          
            
char n7[5]={14,	 //01110,
            8,	 //01000,
            8,	 //01000,
            8,	 //01000,
            8};	 //01000}; 
 
char n8[5]={14,	 //01110,
            10,	 //01010,
            14,	 //01110,
            10,	 //01010,
            14}; //01110}; 
 
char n9[5]={14,	 //01110,
            10,	 //01010,
            14,	 //01110,
            8,	 //01000,
            14}; //01110};       
       
char whitespace[5]={0,	//00000,
                    0,	//00000,
                    0,	//00000,
                    0,	//00000,
                    0};	//00000};

char exclamation[5]={4,	//00100
		     4,	//00100
		     4,	//00100
		     0,	//00000
		     4};//00100

char question[5]={14,	//01110
		  9,	//01001
		  4,	//00100
		  0,	//00000
		  4};	//00100

char percent[5]={17,	//10001
		 8,	//01000
		 4,	//00100
		 2,	//00010
		 17};	//10001

char dot[5]={0,		//00000
	     0,		//00000
	     0,		//00000
	     24,	//11000
	     24};	//11000

#endif
