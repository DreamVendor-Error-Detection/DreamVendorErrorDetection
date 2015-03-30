#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace cv;
using namespace std;
stringstream ss;
string s;

int main(int argc, char** argv) {
	char filename[260 + 1];
	cout << "Enter a file name and press ENTER: ";
	cin.getline(filename, 260);
	
	*(argv + 1) = filename; //added this, made it work. Did not have contents in array
	Mat img = imread(argv[1], -1);
	Mat img2 
	Canny(img,img2);
	if (img.empty()) return -1;
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("Edge Detection Image", WINDOW_AUTOSIZE);
	imshow("Original Image", img);
	imshow("Edge Detection Image", img);
	waitKey(0);
	destroyAllWindows;
}

