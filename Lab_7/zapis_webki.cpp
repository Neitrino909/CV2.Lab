#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    VideoCapture cap(0);

    if (!cap.isOpened())
    {
        cerr << "Unable to open the webcam" << endl;
        return -1;
    }

    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
    VideoWriter video("out.avi", VideoWriter::fourcc('M','J','P','G'), 10, Size(frame_width, frame_height));

    while (true)
    {
        Mat frame;
        cap >> frame;

        if (frame.empty())
        {
            cerr << "Unable to capture frame" << endl;
            break;
        }
        video.write(frame);
        imshow("Webcam", frame);

        if (waitKey(1) == 27)
        {
            break;
        }
    }
    cap.release();
    video.release();
    destroyAllWindows();
    return 0;
}