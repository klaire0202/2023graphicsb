#include <opencv/highgui.h>
int main()
{
    IplImage*img=cvLoadImage("1.png");///圖檔要放在豬面城市的目錄裡
    cvShowImage("week07",img);
    cvWaitKey(0);///畫面不要閃退，等一下案任意見繼續
}
