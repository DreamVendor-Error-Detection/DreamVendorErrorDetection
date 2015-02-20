#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(int argc, char** argv){
	*(argv + 1) = "C:\\Users\\johng_000\\Google Drive\\Spring 2015\\Research\\testvideo.mp4";
	namedWindow("Example3", WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(string(argv[1]));
	Mat frame;
	while (1){
		cap >> frame;
		if (!frame.data) break;
		imshow("Example3", frame);
		if (waitKey(33) >= 0) break;
	}
	return 0;
}