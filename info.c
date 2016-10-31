#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char * per_convert(int a){
  int count = 3;
  while(count--){
    int block = a%1000;
    a = a/1000;
    while (block){
      


int main(){
  umask(0);
  int fd;
  struct stat sb;
  fstat(fd,&sb);
  fd = open("stuff", O_CREAT|O_RDWR, 0644);
  printf("fd: %d\n",fd);
  int per = sb.st_mode;
  int per2 = 10;
  while (per){
    per2 += per%2;
    per = per/2;
  }
  printf("%s\n",per_convert(per2););
  return 0;
}
