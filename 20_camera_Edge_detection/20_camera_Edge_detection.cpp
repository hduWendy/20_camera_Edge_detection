// 20_camera_Edge_detection.cpp : �������̨Ӧ�ó������ڵ㡣
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

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		Sobel(rFrame, edgeX_Mat, CV_32FC1, 1, 0, 3);
		Sobel(rFrame, edgeY_Mat, CV_32FC1, 0, 1, 3);
		convertScaleAbs;

		cv::imshow("edgeX_Mat", edgeX_Mat);
		cv::imshow("edgeY_Mat", edgeY_Mat);
		cv::imshow("frame", rFrame);

		waitKey(30);
	}
}
