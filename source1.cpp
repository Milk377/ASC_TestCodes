// 컬러로 촬영된 사진을 변환시켜서 렌즈를 찾아내는 방식을 시도함.
// 이를 위해 사진을 다양하게 변환하는것을 시도


// CV_EXPORTS_W void cvtColor(InputArray src, OutputArray dst, int code, int dstCn = 0);

/** @brief Converts an image from one color space to another where the source image is
//  stored in two planes.

This function only supports YUV420 to RGB conversion as of now.

@param src1: 8-bit image (#CV_8U) of the Y plane.
@param src2: image containing interleaved U/V plane.
@param dst: output image.
@param code: Specifies the type of conversion. It can take any of the following values:
- #COLOR_YUV2BGR_NV12
- #COLOR_YUV2RGB_NV12
- #COLOR_YUV2BGRA_NV12
- #COLOR_YUV2RGBA_NV12
- #COLOR_YUV2BGR_NV21
- #COLOR_YUV2RGB_NV21
- #COLOR_YUV2BGRA_NV21
- #COLOR_YUV2RGBA_NV21
*/

// COLOR CONVERSATION COD: TYPE: ENUM, SCALE: 1 ~ 143
// 0~7 까지 가능, 8부터 에러

// can test header with 
// C:\opencv-4.1.2\sources\samples\cpp\videocapture_basic.cpp



#include <opencv2/opencv.hpp>
#include <iostream>
#define TEST_SIZE 8


using namespace cv;
using namespace std;


int main() {

	Mat img_color;
	string sample[10];

	// 주의사항 : .jpg 는 파일 제목에 들어있으면 안됨.
	img_color = imread("resource.jpg", IMREAD_COLOR);

	if (img_color.empty()) {
		cout << "Can't read Image file" << "\n";
		return -1;
	}

	namedWindow("Color");

	for (int i = 0; i < TEST_SIZE; i++) {
		Mat temp_color;
		cvtColor(img_color, temp_color, i);
		imshow("Color", temp_color);
		string s = "Color_" + to_string(i);
		s += ".jpg";
		imwrite(s , temp_color);
	}

	waitKey(0);
	destroyAllWindows();


}