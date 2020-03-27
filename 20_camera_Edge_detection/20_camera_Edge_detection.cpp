// 20_camera_Edge_detection.cpp : �������̨Ӧ�ó������ڵ�!
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()  //��ֵ�˲�
{
	VideoCapture cap(0);
	double scale = 0.5;

	while (1)
	{
		cv::Mat frame;
		cv::Mat hsvMat;
		cv::Mat edgeX_Mat;
		cv::Mat edgeY_Mat;
		cv::Mat edgeX_Mat_out;
		cv::Mat edgeY_Mat_out;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		Sobel(rFrame, edgeX_Mat, CV_16SC1, 1, 0, 3);
		convertScaleAbs(edgeX_Mat, edgeX_Mat_out);
		Sobel(rFrame, edgeY_Mat, CV_16SC1, 0, 1, 3);
		convertScaleAbs(edgeY_Mat, edgeY_Mat_out);

		cv::imshow("edgeX_Mat", edgeX_Mat_out);
		cv::imshow("edgeY_Mat", edgeY_Mat_out);
		cv::imshow("frame", rFrame);

		waitKey(30);
	}
}
