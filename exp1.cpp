#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

using namespace std;
int main()
{
int i=0,j=0,x=0,n,flag=0;
void *p,*add[5];
char ch,srch,b[15],d[15],c;
printf("Expression terminated by $ : ");
while((c=getchar())!='$')
{
b[i]=c;
i++;
}
n=i-1;
printf("Given Expression : ");
i=0;
while(i<=n)
{
printf("%c",b[i]);
i++;
}
printf("\n\n\t Symbol Table\n\n");
printf("Symbol\t Address \t Type\n");
while(j<=n)
{
c=b[j];
if(isalpha(toascii(c)))
{
p=malloc(c);
add[x]=p;
d[x]=c;
printf("%c\t%p\t identifer\n",c,p);
x++;
}
else if(c=='+'||c=='-'||c=='*'||c=='=')
{
p=malloc(c);
add[x]=p;
d[x]=c;
printf("%c\t%p\t operator\n",c,p);
x++;
}
else if(isdigit(c))
{
p=malloc(c);
add[x]=p;
d[x]=c;
printf("%c\t%p\t constant\n",c,p);
x++;
}
j++;
}
printf("\n\nThe symbol is to be searched: ");
cin>>srch;
for(i=0;i<=x;i++)
{
if(srch==d[i])
{
printf("\nSymbol Found");
printf("\n%c%s%p\n",srch," @address ",add[i]);
flag=1;
}}
if(flag==0)
printf("\nSymbol Not Found");
getchar();

return 0;
}