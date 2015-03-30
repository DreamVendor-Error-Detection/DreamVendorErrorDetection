#include "opencv2/highgui/highgui.hpp"
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(0); // open the video camera no. 0
	int i = 1;
	int poo = 0;
	int blinker = 0; //switches which assignment is blinking

	//Text Strings
	char str1[200];
	char str2[200];
	char str3[200];
	char str4[200];
	char str5[200];
	char str6[200];

	sprintf(str1, "Assignments:");
	sprintf(str2, "___________");
	sprintf(str3, "Press the 'a' button");
	sprintf(str4, "Press the 'b' button");
	sprintf(str5, "Press the 'c' button");
	sprintf(str6, "Celebration Sequence Initiate");
	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat in,frame;

		bool bSuccess = cap.read(in); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			return 2;
		}

		cv::cvtColor(in, frame, CV_BGR2BGRA);
		/* //Add transparent rectangle
		Mat roi = frame(Rect(100, 100, 300, 300));
		Mat color(roi.size(), CV_8UC3, Scalar(0, 125, 125));
		double alpha = 0.3;
		addWeighted(color, alpha, roi, 1.0 - alpha, 0.0, roi); */

		//Add Circle
		//circle(frame, Point(50, 50), 50, Scalar(255, 255, 255), CV_FILLED, 8, 0);

		//Removes black background from png
		double alpha = 0.3;
		double beta = 0.7;
		Mat alp, tmp, dst;
		Mat img = imread("Batterysmall.png");
		
		cvtColor(img, tmp, CV_BGR2GRAY);
		threshold(tmp, alp, 100, 255, THRESH_BINARY);

		Mat rgb[3];
		split(img, rgb);

		Mat rgba[4] = { rgb[0], rgb[1], rgb[2], alp };
		merge(rgba, 4, dst); //at this point the image has a transparent background

		//imwrite("dst.png", dst);
		//Mat poo = imread("Battery.png");

		Size ss = dst.size();
		Size s = img.size();
		//i = i + 2;
		//if (i >= (dWidth - ss.width - 20)) { i = 0; }
		Mat roi = frame(Rect(i, 0, ss.width, ss.height));
		//cout << "Frame size : " << s.width << " x " << s.height << endl;
		addWeighted(dst, 1, roi, 0.9, 0.0, roi);

		// Adding Text ///

		putText(frame, str1, Point2f(10, 380), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 100, 255), 1);
		putText(frame, str2, Point2f(10, 385), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 100, 255), 1);

		switch (blinker) 
		{
		case 0:
			if (poo < 10)
			{
				putText(frame, str3, Point2f(10, 400), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
				poo = poo + 1;
			}
			else{ poo = 0; }
			putText(frame, str4, Point2f(10, 410), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str5, Point2f(10, 420), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str6, Point2f(10, 430), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			break;
		case 1:
			if (poo < 10)
			{
				putText(frame, str4, Point2f(10, 410), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
				poo = poo + 1;
			}
			else{ poo = 0; }
			putText(frame, str3, Point2f(10, 400), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str5, Point2f(10, 420), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str6, Point2f(10, 430), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			break;
		case 2:
			if (poo < 10)
			{
				putText(frame, str5, Point2f(10, 420), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
				poo = poo + 1;
			}
			else{ poo = 0; }
			putText(frame, str3, Point2f(10, 400), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str4, Point2f(10, 410), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str6, Point2f(10, 430), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			break;
		case 3:
			if (poo < 10)
			{
				putText(frame, str6, Point2f(10, 430), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
				poo = poo + 1;
			}
			else{ poo = 0; }
			putText(frame, str3, Point2f(10, 400), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str4, Point2f(10, 410), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			putText(frame, str5, Point2f(10, 420), FONT_HERSHEY_PLAIN, 1, Scalar(20, 255, 20, 255), 1);
			break;

		}
		
		/*
		if (waitKey(10) == 97){ blinker = 1; }
		if (waitKey(10) == 98){ blinker = 2; }
		if (waitKey(10) == 99){ blinker = 3; }
		*/

		//OverlayImage(&img, &frame);

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;

}