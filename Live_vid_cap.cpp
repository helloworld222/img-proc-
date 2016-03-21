#include <iostream>
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <SerialStream.h>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
   
     int bLowH,bHighH,bLowS,bHighS,bLowV,bHighV; // for endpoint 
        int rLowH,rHighH,rLowS,rHighS,rLowV,rHighV;
        int yLowH,yHighH,yLowS,yHighS,yLowV,yHighV;
        int gLowH,gHighH,gLowS,gHighS,gLowV,gHighV;
       int oLowH,oHighH,oLowS,oHighS,oLowV,oHighV;
   
    VideoCapture cap(0); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

   //double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   //double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    //cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        Mat frame,image1, image_gray,thresholded;

        bool bSuccess = cap.read(frame); // read a new frame from video bool bSuccess = cap.read(src);

        if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }
        
        inRange(frame , Scalar(0,0, 0), Scalar(127, 127, 127), image1);

       // cvtColor( image1 , image_gray, CV_BGR2GRAY );//cvtColor(src,gray,COLOR_BGR2GRAY); 
       // threshold(image_gray,thresholded,127,255,0);

        imshow("MyVideo",image1); //show the frame in "MyVideo" window

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }
    return 0;

}
