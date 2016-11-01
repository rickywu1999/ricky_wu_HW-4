#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void print_per(int a){
    char per[9];
    int i = 9;
    int mod = 0;
    int rwx = 3;
    while(i > 0){
        i--;
        mod = a%2;
        a = a/2;
        if (!mod)
            per[i] = '-';
        else if (rwx == 3)
            per[i] = 'x';
        else if (rwx == 2)
            per[i] = 'w';
        else if (rwx == 1)
            per[i] = 'r';
        if (rwx == 1)
            rwx = 3;
        else
            rwx--;
    }
    printf("%.9s",per);
}

void print_size(int a){
    char* suffix[4] = {"B","KB","MB","GB"};
    int track = 0;
    while(a >= 1000){
        track++;
        a/=1000;
    }
    printf("Size: %.3d%s\n",a,suffix[track]);
}

int main(){
    umask(0);
    int fd = open("stuff", O_CREAT|O_RDWR, 0644);
    struct stat sb;
    fstat(fd,&sb);
    printf("fd: %d\n",fd);
    printf("\n");
    
    mode_t per = sb.st_mode;
    printf("%d\n",per);
    printf("Permissions of file: ");
    print_per(per);
    printf("\n\n");
    
    off_t size = sb.st_size;
    printf("Bytes:%llu\n",size);
    print_size(size);
    printf("\n");
    
    time_t t = sb.st_atime;
    printf("Last accessed: %s", ctime(&t));
    return 0;
}
