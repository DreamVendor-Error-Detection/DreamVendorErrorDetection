#include "opencv2/highgui/highgui.hpp"
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(0); // open the video camera no. 0
	int i = 1;
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
		Mat in, frame;

		bool bSuccess = cap.read(in); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			return 2;
		}

		//cv::cvtColor(in, frame, CV_BGR2BGRA);

		//Removes black background from png
		double alpha = 0.3;
		double beta = 0.7;
		Mat alp, tmp, dst;
		Mat img = imread("Batterysmall.png");

		Mat outer = imread("MaskMasterOuter.png");
		Mat inner = imread("MaskMasterInner.png");
		
		/*
		cvtColor(img, tmp, CV_BGR2GRAY);
		threshold(tmp, alp, 100, 255, THRESH_BINARY);

		Mat rgb[3];
		split(img, rgb);

		Mat rgba[4] = { rgb[0], rgb[1], rgb[2], alp };
		merge(rgba, 4, dst); //at this point the image has a transparent background

		imshow("poo", alp);

		Size ss = dst.size();
		Size s = img.size();
		i = i + 2;
		if (i >= (dWidth - ss.width - 20)) { i = 0; }
		Mat roi = frame(Rect(i, 0, ss.width, ss.height));
		//cout << "Frame size : " << s.width << " x " << s.height << endl;
		addWeighted(dst, 1, roi, 0.9, 0.0, roi);
		*/

		Mat roiout = frame(Rect(i, 0, dWidth, dHeight));
		Mat roiin = frame(Rect(i, 0, dWidth, dHeight));

		addWeighted(outer, 1, roiout, 1, 0.0, roiout);
		addWeighted(inner, 1, roiin, 1, 0.0, roiin);

		//OverlayImage(&img, &frame);
		frame.setTo(Scalar(0, 255, 0), outer);
		frame.setTo(Scalar(255, 0, 0), inner);

		

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;

}