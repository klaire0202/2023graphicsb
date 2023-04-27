#include <windows.h>///step01-2 要放在第一行
#include <stdio.h>

int main()
{///Setting Compiler,Linker咒語：需要 winmm
    ///絕對路徑 Absolute Path
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav",NULL,SND_SYNC);

    ///目錄的斜線可以用 兩個反斜線\\，或者一個斜線/
    PlaySound("do-re-mi/do.wav",NULL,SND_SYNC);
    ///相對路徑 Relative Path

    printf("Hello World");
}
