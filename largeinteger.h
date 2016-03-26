#define MAXVARIABLE 10
#define MAXSIZE 1024
#define MAXARRAYVARIABLE 10
#define MAXARRAYSIZE 1024



extern int Print_Number(char variable[]);
extern int Print_Array(char variable[],int id);
extern int Copy_Array(char variable1[],int id1,char variable2[],int id2);
extern int Copy_toNumber(char variable1[],char variable2[],int id);
extern int Copy_toArray(char variable1[],int id,char variable2[]);
extern int Copy_Number(char variable1[],char variable2[]);
extern int Store_Number(char sign,int * value, int size, char variable[]);
extern int Store_Array(char sign,int * value, int size, char variable[],int id);
extern int Scan_Number(char variable[]);
extern int Scan_Array(char variable[],int id);
extern int Logical_opp(char variable1[],char variable2[]);
extern int Logical_opp_Arrays_Numbers(char variable1[],int id,char variable2[]);
extern int Logical_opp_Numbers_Arrays(char variable1[],char variable2[],int id);
extern int Logical_opp_Arrays(char variable1[],int id1,char variable2[],int id2);
