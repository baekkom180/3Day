#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>



#define IMG_Width	640
#define IMG_Height	480
using namespae cv;
using namespace std;

Mat Canny_Edge_Detection(Mat img)
{
    Mat mat_blur_img, mat_canny_img;
    blur(img,mat_blur_img,Size(3,3));
    Canny(mat_blur_img,mat_canny_img,40,130,3);

    return mat_blur_img;
}

int main(){

	int img_width, img_height;
	img_width = 640;
	img_height = 480;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////// OpenCV 변 수선 언///////////////////////////////////////////////////
	
	Mat mat_image_org_color;
	Mat mat_image_org_gray;
	Mat mat_image_gray_result;
    Mat mat_image_canny_Edge;
	Mat image;
	
	Scalar GREEN(0,255,0);
	Scalar RED(0,0,255);
	Scalar BLUE(255,0,0);
	Scalar YELLOW(0,255,255);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	mat_image_org_color = imread("/home/pi/CSW/1/images/line_1_0.jpg");
	
	img_width = mat_image_org_color.size().width;
    img_height = mat_image_org_color.size().height;
	
	printf("Image size[%3d,%3d]\n", img_width, img_height);
	
	namedWindow("Display window", CV_WINDOW_NORMAL);
	resizeWindow("Display window", img_width, img_height);
	moveWindow("Display window", 10, 10);

    namedWindow("Gray window", CV_WINDOW_NORMAL);
	resizeWindow("Gray window", img_width, img_height);
	moveWindow("Gray window", 700, 10);

    namedWindow("Canny Edge window", CV_WINDOW_NORMAL);
	resizeWindow("Canny Edge window", img_width, img_height);
	moveWindow("Canny Edge window", 10, 500);
	
	while(1)
    {
		cvtColor(mat_image_org_color,mat_image_org_gray,CV_RGB2GRAY); //coloar to gray conversion
        //threshold(mat_image_org_gray,mat_image_canny_Edge,200,255,THRESHO_BINARY);
        
        mat_image_canny_Edge= Canny_Edge_Detection(mat_image_org_gray);
        
        if(mat_image_org_color.empty())
        {
            cerr << "빈 영상입니다. \n";
            break;
        }
		imshow("Display window", mat_image_org_color);
        imshow("Gray Image window", mat_image_org_gray);
        imshow("Canny Edge window", mat_image_canny_Edge);
		if(waitKey(10)>0)
			break;	
    }
		destroyAllWindows();
		
		return 0;
}