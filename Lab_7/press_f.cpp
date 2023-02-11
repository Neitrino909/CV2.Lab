# include <opencv2/highgui.hpp>
using namaspace cv;
int main()
{
    VideoCapture cap("press_f.mp4");
if(!cap.isOpend())
    return -1;

    Mat frame;
    for (;;){
        cap >> frame;
        imshow("Video Fotage", frame);
        if(waitKey(33) >= 0) break;
    }
return 0;
}
