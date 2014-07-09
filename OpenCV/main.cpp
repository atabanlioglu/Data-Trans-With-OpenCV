#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <conio.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap; //

    cap.open("http://192.168.43.1:6363/shot.jpg");
    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Kamera acilmadi" << endl;
        return -1;
    }

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Alinan Frame : " << dWidth << " 1 " << dHeight << endl;

    namedWindow("SonFrame",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
   // namedWindow("NegatifFrame",CV_WINDOW_AUTOSIZE);

 
        Mat frame;
        Mat contours;

        bool bSuccess = cap.read(frame); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Frame okunmadi" << endl;
             
        }

        flip(frame, frame, 1);
        imshow("SonFrame", frame); //show the frame in "MyVideo" window

        Canny(frame, contours, 500, 1000, 5, true);
        //imshow("NegatifFrame", contours);

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "Cik" << endl;
           
       }
    
	getch();
    return 0;
}