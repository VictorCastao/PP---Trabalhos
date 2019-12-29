#include <stdio.h>
#include <string.h>

int main(){
char st = 'abacaxio';
char atual[1025];

for (int i=0; i<4; i++)
{
strcat (atual,st);
}
printf("%s", atual);
return 0;

}
