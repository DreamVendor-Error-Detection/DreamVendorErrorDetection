#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
	*(argv + 1) = "C:\\Users\\johng_000\\Pictures\\BP.png"; //added this, made it work. Did not have contents in array
	Mat img = imread(argv[1], -1);
	if (img.empty()) return -1;
	namedWindow("Example1", WINDOW_AUTOSIZE);
	imshow("Example1", img);
	waitKey(0);
	destroyWindow("Example1");
}
