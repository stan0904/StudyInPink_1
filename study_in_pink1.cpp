#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
// Kiem tra EXP
void checkEXP(int &EXP1)
{  if (EXP1<0) EXP1=0;
   else if (EXP1>600) EXP1=600;  
}
// Kiem tra HP
void checkHP(int &HP1)
{  if (HP1<0) HP1=0;
   else if (HP1>666) HP1=666; 
}
// Kiem tra M
void checkM(int &M1)
{  if (M1<0) M1=0;
   else if (M1>3000) M1=3000; 
}
//Truong hop 1
void firstMeet_Case1(int &EXP1, int &EXP2, int E1)
{int arr[4]={29,45,75,149},D=E1*3+EXP1*7;
    EXP2+=arr[E1];
    if(D%2) EXP1-=floor(D/100.0);
    else EXP1+=ceil(D/200.0);
    checkEXP(EXP1);checkEXP(EXP2);
}
//Truong hop 2
void firstMeet_Case2(int &EXP1, int &EXP2, int E1)
{  EXP1-=E1;
        if(E1<=19)  EXP2+=19+ceil(E1/4.0);
   else if(E1<=49)  EXP2+=21+ceil(E1/9.0);
   else if(E1<=65)  EXP2+=17+ceil(E1/16.0);
   else if(E1<=79)  {EXP2+=19+ceil(E1/4.0);checkEXP(EXP1);checkEXP(EXP2);if (EXP2>200) EXP2+=21+ceil(E1/9.0);}
   else if(E1<=99)  {EXP2+=19+ceil(E1/4.0);
                     checkEXP(EXP1);checkEXP(EXP2);
                     EXP2+=21+ceil(E1/9.0);
                     checkEXP(EXP1);checkEXP(EXP2);
                     if(EXP2>400) {EXP2+=17+ceil(E1/16.0);checkEXP(EXP1);checkEXP(EXP2);EXP2=ceil(EXP2*23.0/20);} }
     checkEXP(EXP1);checkEXP(EXP2);
}
//Hoan thanh Task1
int firstMeet(int & exp1, int & exp2, int e1) {
     if (e1 < 0 || e1 > 99) return -99;
else if (e1<=3) firstMeet_Case1(exp1,exp2,e1);
else if (e1<=99) firstMeet_Case2(exp1,exp2,e1);
    return exp1 + exp2;
}
// Task 2
//Con duong 1
//Gia tri P1
double traceLuggage_Street1(int EXP1)
{int N=sqrt(EXP1),N1=EXP1-N*N,N2=(N+1)*(N+1)-EXP1;
 double P1;
     if (N1<N2) P1=1;
     else P1=(EXP1/(EXP1+N2)+80)/123.0;
    return P1;    
}
//Con duong 2
//Su kien 1
void traceLuggage_Street2_Event1(int &HP1,int &M1)
{if (HP1<200) {HP1=ceil(HP1*13.0/10);M1-=150;}
 else {HP1=ceil(HP1*11.0/10);M1-=70;}
 checkHP(HP1);checkM(M1);
}
//Su kien 2
void traceLuggage_Street2_Event2(int &EXP1,int &M1)
{if (EXP1<400) M1-=200;
 else M1-=120;
 EXP1=ceil(EXP1*113.0/100);
 checkEXP(EXP1);checkM(M1);
}
//Su kien 3
void traceLuggage_Street2_Event3(int &EXP1,int &M1)
{if (EXP1<300) M1-=100;
 else M1-=120;
 EXP1=ceil(EXP1*9.0/10);
 checkEXP(EXP1);checkM(M1);
}
//Tinh toan thay doi HP1,EXP1,M1 sau 3 su kien
void traceLuggage_Street2(int &HP1, int &EXP1, int &M1, int E2)
{int M=M1;
 if (E2%2)
    {if (M1!=0){ 
     while(1)
        {traceLuggage_Street2_Event1(HP1,M1);
        if (2*M1<M) break;
        traceLuggage_Street2_Event2(EXP1,M1);
        if (2*M1<M) break;
        traceLuggage_Street2_Event3(EXP1,M1);
        if (2*M1<M) break;
        }
               }
    }
 else {if (M1!=0) {traceLuggage_Street2_Event1(HP1,M1);
                   if (M1!=0) {traceLuggage_Street2_Event2(EXP1,M1);
                               if (M1!=0) {traceLuggage_Street2_Event3(EXP1,M1);}
                              }
                  }
      } 
 HP1=ceil(HP1*83.0/100);EXP1=ceil(EXP1*117.0/100);
 checkEXP(EXP1);
}
//Gia tri P2=P1 nen chi can dung ham Tinh P1
//Con duong 3
//Tinh P3
double traceLuggage_Street3(int E2)
{double P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11},P3;
if (E2>=10) {E2=E2%10+(E2-E2%10)/10;E2=E2%10;}
P3=P[E2];
return P3;
}
//Cac thay doi gia tri khi biet P
//P=100%
void debuff1(int &EXP1)
{EXP1=ceil(EXP1*75.0/100);
}
//P<50%
void debuff2(int &EXP1,int &HP1)
{EXP1=ceil(EXP1*115.0/100);checkEXP(EXP1);
 HP1=ceil(HP1*85.0/100);
}
//P>=50%
void debuff3(int &EXP1,int &HP1)
{EXP1=ceil(EXP1*12.0/10);checkEXP(EXP1);
 HP1=ceil(HP1*90.0/100);
}
//Hoan thanh task2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   if (E2 < 0 || E2 > 99) return -99;
double P1,P2,P3,P;
P1=traceLuggage_Street1(EXP1);
traceLuggage_Street2(HP1, EXP1, M1, E2);
P2=traceLuggage_Street1(EXP1);
P3=traceLuggage_Street3(E2)/100;
P=(P1+P2+P3)/3;
if (P==1) debuff1(EXP1);
else if (P<0.5) debuff2(EXP1,HP1);
else if (P>=0.5) debuff3(EXP1,HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////