#include <stdio.h>

int isValidTime(char* t) {
  char minutes[2];
  if (t[5]!='\0')//special character 
    return 0;
  //check when : appears
  if (t[1]==':') {
  //in this case one digit hour
  if (t[0]<'0' || t[0]>'9') 
  return 0;
  //The mins in this case
    minutes[0]=t[2];
    minutes[1]=t[3];
  }
  //check when : appears
  if (t[2]==':') {
    //in this case Two digit hour,first digit
    if (t[0]<'0' || t[0]>'2')
     return 0;
    //Two digit hour,second digit
    if (t[1]<'0' || t[1]>'9') 
    return 0;
    //// Wrong input
    if (t[0]=='2' && t[1]>'3') 
    return 0;
    //The mins in this case
    minutes[0]=t[3];
    minutes[1]=t[4];
  }
  else 
  return 0;
  // The mins should be
  if (minutes[0]<'0' || minutes[0]>'5') 
  return 0;
  if (minutes[1]<'0' || minutes[1]>'9') 
  return 0;
  
  return 1;
}

int isValidNote(char* n) {
  for (int i = 0; n[i]!='\0'; i++) {
    // every note contains characters like lower or upper case English alphabet
    if ((n[i]>'Z' && n[i]<'a') || (n[i]<'A' || n[i]>'z')) 
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
    if (argc>=2)//Enough argumets
    {
        FILE *fptr;
        for (int i=1;i<argc;i++)
        {
            if ((isValidTime(argv[i])) && (isValidNote(argv[i+1])))
                {
                    fptr = fopen("todolist.txt","a");
                    //Printing as in example
                    fprintf(fptr,"%s-%s\n",argv[i],argv[i+1]);
                    
                    fclose(fptr);
                }
                else
                {
                    printf("Wrong Input!\n");
                }
                
                i++;//Next
          }
        return 0;
    }
    else {
        printf("Wrong input!\n");//Not enough arguments
        return 1;
    }
    
    
}