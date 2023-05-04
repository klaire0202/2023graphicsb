///Week12-1_printf_fprintf.cpp
///要開檔案指標 fopen()
#include <stdio.h>
int main()
{///檔案指標 fout=fopen("檔名","模式"); 要開檔
    FILE * fout = fopen("file.txt","w");///w:write
    printf("Hello World\n");
    fprintf(fout,"Hello World 在檔案裡\n");
}
