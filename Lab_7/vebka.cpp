# include <opencv2/highgui.hpp>
using namaspace cv;
int main(int, char**)
{
    cv::namedWindow("Video Footage", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap(0);
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
