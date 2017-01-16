#include <string.h>
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char str[2000];
    scanf("%[^\n]%*c", str);
    int i;
    char* the="the";
    char* of="of";
    char* and="and";
    char* but="but";
    int length=strlen(str);
    if(islower(str[0]))
       str[0]=toupper(str[0]);
    for(i=1;i+1<length;i++)
       {
           int k=1;
           if(str[i]==' ' && islower(str[i+1]))
               {
                   i++;
                   if(str[i]=='b')
                   {
                       int z=i+1;
                       while(str[z]==but[k]  && z<length  && k<strlen(but))
                       {
                           z++;
                           k++;
                       }
                        if(str[z]==' ')
                        {
                            i=z-1;
                            continue;
                        }
                        else if(z==length)
                            return (0);
                   }


                   if(str[i]=='t')
                   {
                       int z=i+1;
                       while(str[z]==the[k]  && z<length  && k<strlen(the))
                       {
                           z++;
                           k++;
                       }
                        if(str[z]==' ')
                        {
                            i=z-1;
                            continue;
                        }
                        else if(z==length)
                            return (0);
                   }




                   if(str[i]=='o')
                   {
                       int z=i+1;
                       while(str[z]==of[k]  && z<length  && k<strlen(of))
                       {
                           z++;
                           k++;
                       }
                        if(str[z]==' ')
                        {
                            i=z-1;
                            continue;
                        }
                        else if(z==length)
                            return (0);
                   }



                   if(str[i]=='a')
                   {
                       int z=i+1;
                       while(str[z]==and[k]  && z<length  && k<strlen(and))
                       {
                           z++;
                           k++;
                       }
                        if(str[z]==' ')
                        {
                            i=z-1;
                            continue;
                        }
                        else if(z==length)
                        {
                            //tstr[i-1]=toupper(str[i-1]);
                            return (0);
                        }

                   }




               str[i]=toupper(str[i]);
           }
       }
    printf("%s",str);
}
