#include <stdio.h>
#include <string.h>
int main(void){
int sum = 0;

char array[30];
gets(array);

while(1){

char arr[30];
gets(arr);
if(strcmp(arr,"고무오리 디버깅 끝") == 0){
break;
}
else{
if(strcmp(arr,"문제") == 0){
sum = sum + 1;
}
else if(strcmp(arr,"고무오리") == 0){
if(sum == 0){
sum = sum + 2;
}
else {sum = sum - 1;}


}}}


if(sum == 0){
printf("고무오리야 사랑해");
}
else
printf("힝구");
}