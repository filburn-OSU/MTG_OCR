//============================================================================
// Name        : Card_Project.cpp
// Author      : Mike Filburn
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/legacy/legacy.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/highgui/highgui_c.h"
#include <fstream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "windows.h"
#include "iomanip"



using namespace cv;
using namespace std;

void letterLoad(char from[], vector<Point> & to);
void sum (vector<Point>, int &, int &);
void find(vector<Point>  &, Mat &, char);

int toggle = 0;

DWORD WINAPI myThread(LPVOID myCounter){
	HANDLE hSerial; 																							// windows handle that is empty. needed for windows serial data transfer
	hSerial = CreateFile("COM9", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0); 	//setting up the port
	DCB dcb; 																									// empty DCB. needed for serial data transfer
	memset(&dcb, 0, sizeof(dcb));
	dcb.BaudRate = CBR_9600; //the rate of transfer. normal is CBR_9600	     115200	//
	dcb.ByteSize = 8; //never change												//
	dcb.Parity = NOPARITY; // never change											//
	dcb.StopBits = ONESTOPBIT; //never change										////something to do with creating memmory for the dcb. Do not know wtf this is
	COMMTIMEOUTS timeout;
	timeout.ReadIntervalTimeout = MAXDWORD;
	timeout.ReadTotalTimeoutConstant = 0;
	timeout.ReadTotalTimeoutMultiplier = 0;
	timeout.WriteTotalTimeoutConstant = 0;
	timeout.WriteTotalTimeoutMultiplier = 0;
	SetCommTimeouts(hSerial, &timeout);

	while(1){

		if(toggle == 0){
			    ////Read data sent on the serial port (tie pins 2 and 3. 1 is top left looking at the db9 male pins)//////////////////																	//
				BYTE Byte;																		//
				DWORD dwBytesTransferred;														//
				if(!GetCommState(hSerial, &dcb)){cout<<"here is the issue\n";}					//
				SetCommMask(hSerial, EV_RXCHAR);												//
				ReadFile(hSerial, &Byte, 1, &dwBytesTransferred, 0);     						//
				if(Byte == '3'){toggle = 3;Byte = 0;}
				if(Byte == '5'){toggle = 5;Byte = 0;}
				//////////////////////////////////////////////////////////////////////////////////
		}

		if(toggle == 1){
    				char a = 'a'; // just some daata to be transmitted serially					//
    				DWORD byteswritten; //just something to hold what was transmitted				//
    				WriteFile(hSerial, &a, 1, &byteswritten, NULL); //writes out to the serial port.//
    				toggle = 0;
		}

		if(toggle == 2){
    				char a = 'b'; // just some daata to be transmitted serially					//
    				DWORD byteswritten; //just something to hold what was transmitted				//
    				WriteFile(hSerial, &a, 1, &byteswritten, NULL); //writes out to the serial port.//
    				toggle = 0;
		}

		if(toggle == 4){
					char a = 'c'; // just some daata to be transmitted serially					//
					DWORD byteswritten; //just something to hold what was transmitted				//
					WriteFile(hSerial, &a, 1, &byteswritten, NULL); //writes out to the serial port.//
					toggle = 0;
		}

		if(toggle == 6){
					char a = 'd'; // just some daata to be transmitted serially					//
					DWORD byteswritten; //just something to hold what was transmitted				//
					WriteFile(hSerial, &a, 1, &byteswritten, NULL); //writes out to the serial port.//
					toggle = 0;
		}


    }//end of while 1
	return 0;
}




int main() {
//create empty vectors to hold the contour
	vector<Point> poly_A;
	vector<Point> poly_B;
	vector<Point> poly_C;
	vector<Point> poly_D;
	vector<Point> poly_E;
	vector<Point> poly_F;
	vector<Point> poly_G;
	vector<Point> poly_H;
	vector<Point> poly_I;
	vector<Point> poly_J;
	vector<Point> poly_K;
	vector<Point> poly_L;
	vector<Point> poly_M;
	vector<Point> poly_N;
	vector<Point> poly_O;
	vector<Point> poly_P;
	vector<Point> poly_Q;
	vector<Point> poly_R;
	vector<Point> poly_S;
	vector<Point> poly_T;
	vector<Point> poly_U;
	vector<Point> poly_V;
	vector<Point> poly_W;
	vector<Point> poly_X;
	vector<Point> poly_Y;
	vector<Point> poly_Z;
	vector<Point> poly__a;
	vector<Point> poly__b;
	vector<Point> poly__c;
	vector<Point> poly__d;
	vector<Point> poly__e;
	vector<Point> poly__f;
	vector<Point> poly__g;
	vector<Point> poly__h;
	vector<Point> poly__i;
	vector<Point> poly__j;
	vector<Point> poly__k;
	vector<Point> poly__l;
	vector<Point> poly__m;
	vector<Point> poly__n;
	vector<Point> poly__o;
	vector<Point> poly__p;
	vector<Point> poly__q;
	vector<Point> poly__r;
	vector<Point> poly__s;
	vector<Point> poly__t;
	vector<Point> poly__u;
	vector<Point> poly__v;
	vector<Point> poly__w;
	vector<Point> poly__x;
	vector<Point> poly__y;
	vector<Point> poly__z;
	vector<Point> poly__apple;
//Fill the vector with the contour
	letterLoad("c:/Card_Sorter_Create/new__a/new__a.txt", poly__a);
	letterLoad("c:/Card_Sorter_Create/new__b/new__b.txt", poly__b);
	letterLoad("c:/Card_Sorter_Create/new__c/new__c.txt", poly__c);
	letterLoad("c:/Card_Sorter_Create/new__d/new__d.txt", poly__d);
	letterLoad("c:/Card_Sorter_Create/new__e/new__e.txt", poly__e);
	letterLoad("c:/Card_Sorter_Create/new__f/new__f.txt", poly__f);
	letterLoad("c:/Card_Sorter_Create/new__g/new__g.txt", poly__g);
	letterLoad("c:/Card_Sorter_Create/new__h/new__h.txt", poly__h);
	letterLoad("c:/Card_Sorter_Create/new__i/new__i.txt", poly__i);
	letterLoad("c:/Card_Sorter_Create/new__j/new__j.txt", poly__j);
	letterLoad("c:/Card_Sorter_Create/new__k/new__k.txt", poly__k);
	letterLoad("c:/Card_Sorter_Create/new__l/new__l.txt", poly__l);
	letterLoad("c:/Card_Sorter_Create/new__m/new__m.txt", poly__m);
	letterLoad("c:/Card_Sorter_Create/new__n/new__n.txt", poly__n);
	letterLoad("c:/Card_Sorter_Create/new__o/new__o.txt", poly__o);
	letterLoad("c:/Card_Sorter_Create/new__p/new__p.txt", poly__p);
	letterLoad("c:/Card_Sorter_Create/new__q/new__q.txt", poly__q);
	letterLoad("c:/Card_Sorter_Create/new__r/new__r.txt", poly__r);
	letterLoad("c:/Card_Sorter_Create/new__s/new__s.txt", poly__s);
	letterLoad("c:/Card_Sorter_Create/new__t/new__t.txt", poly__t);
	letterLoad("c:/Card_Sorter_Create/new__u/new__u.txt", poly__u);
	letterLoad("c:/Card_Sorter_Create/new__v/new__v.txt", poly__v);
	letterLoad("c:/Card_Sorter_Create/new__w/new__w.txt", poly__w);
	letterLoad("c:/Card_Sorter_Create/new__x/new__x.txt", poly__x);
	letterLoad("c:/Card_Sorter_Create/new__y/new__y.txt", poly__y);
	letterLoad("c:/Card_Sorter_Create/new__z/new__z.txt", poly__z);
	letterLoad("c:/Card_Sorter_Create/apple/apple.txt", poly__apple);
//global Matrixes
	Mat image_feed;
	Mat image_feed_gray;
	Mat canny;
	Mat image_feed_gray_blur1;
	Mat image_feed_gray_blur2;
	Mat canny_morph;
	Mat sobel;
	Mat sobelImage;
	Mat sobelThresholded;
// camera set up stuff
	CvCapture *camera = cvCaptureFromCAM(-1);
	cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_WIDTH, 1280);
	cvSetCaptureProperty(camera, CV_CAP_PROP_FRAME_HEIGHT, 720);
//global x y w h values
	int x = 5, y = 185, w = 1050, h = 95;
//global controls
	char input = 0;
//global
	int positions_counter_final = 0;
	String found_card_name;
	int size = 0;
	int final_word[30]{5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000,5000};
	char final_word_char[30]{'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
//multithreading create
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(NULL,0,myThread, &toggle,0,&myThreadID);

while(1){

	input = waitKey(33); //waits for 33 miliseconds and checks what the last input was

	if(input == 27){
		break;
	}

	if(input == 49){
		toggle = 1;
	}

	if(input == 50){
		toggle = 2;
	}

	if(toggle == 3){
	  for(int i = 0; i < 5; i++){
		image_feed = cvQueryFrame(camera);
		cvtColor(image_feed, image_feed_gray, CV_BGR2GRAY);
		Mat image_feed_gray_roi(image_feed_gray, Rect(x,y,w,h));
		medianBlur(image_feed_gray_roi, image_feed_gray_blur1, 5);
		bilateralFilter(image_feed_gray_blur1, image_feed_gray_roi , 3, 19, 3);
		bilateralFilter(image_feed_gray_roi, image_feed_gray_blur1, 3, 19, 3);
		bilateralFilter(image_feed_gray_blur1, image_feed_gray_roi , 3, 19, 3);
		Sobel(image_feed_gray_roi, image_feed_gray_blur1, CV_16S,1,0);
		Sobel(image_feed_gray_roi, image_feed_gray_blur2, CV_16S,0,1);
		sobel = abs(image_feed_gray_blur1)+abs(image_feed_gray_blur2);
		double sobmin, sobmax;
		minMaxLoc(sobel, & sobmin, &sobmax);
		sobel.convertTo(sobelImage, CV_8U, -255./sobmax, 255);
		adaptiveThreshold(sobelImage, sobelThresholded, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 3, 1);
		rectangle(image_feed, Rect(x, y, w, h), CV_RGB(255,0,0),1);
		//imshow("Image Feed", image_feed);
		imshow("Adaptive Filtered", sobelThresholded);

		Point *offset = new Point(x,y);
		vector<vector <Point> > contours;
		findContours(sobelThresholded, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, *offset);

		if(!contours.empty()){
		 vector<vector<Point> >::iterator itc= contours.begin();							//iterator to go through the contours detected
		 while (itc != contours.end()){
		 if(itc->size() < 45 || itc->size() > 400) itc = contours.erase(itc);			//eliminating contours that are to small (noise) or to large to be a letter
		 else ++itc;}
		}// end of if not contours.empty

		if(!contours.empty()){
			int positions[contours.size()];
			int positions_counter = 0;
			char letters[contours.size()];

			for(unsigned int i=0; i < contours.size(); i++){												//do below for all detected contours

						vector<Point> poly;																	//blank vector to hold the detected polygon
				        vector<Point> poly2;

						double arc_diff        = 9999;
						double area_diff       = 9999;
				        int longest_x;
				        int longest_y;

					    double result;

					    char letter = '!';

					approxPolyDP(contours[i], poly, 0, false);
					//a
							   result = matchShapes(poly, poly__a, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.8){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 160 && arc_diff < 190 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 850 && area_diff < 1030 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 24 && longest_x < 35 &&	longest_y > 20 && longest_y < 30){letter = 'a'; poly2 = poly__a;}
							    	 }
							       }
							    }
					//b
							   result = matchShapes(poly, poly__b, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.2){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 170 && arc_diff < 190 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 1350 && area_diff < 1550 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 28 && longest_x < 45 &&	longest_y > 3 && longest_y < 10){letter = 'b'; poly2 = poly__b;}
							    	 }
							       }
							    }
					//c
							   result = matchShapes(poly, poly__c, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.5){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 149 && arc_diff < 170 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 500 && area_diff < 600 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 1 && longest_x < 6 &&	longest_y > 8 && longest_y < 13){letter = 'c'; poly2 = poly__c;}
							    	 }
							       }
							    }
					//d
							   result = matchShapes(poly, poly__d, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.2){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 175 && arc_diff < 190 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 1400 && area_diff < 1570 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 27 && longest_x < 40 &&	longest_y > 28 && longest_y < 36){letter = 'd'; poly2 = poly__d;}
							    	 }
							       }
							    }
					//e
							   result = matchShapes(poly, poly__e, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.5){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 159 && arc_diff < 180 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 800 && area_diff < 940 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 9 && longest_x < 20 &&	longest_y > 7 && longest_y < 20){letter = 'e'; poly2 = poly__e;}
							    	 }
							       }
							    }
					//f
							   result = matchShapes(poly, poly__f, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.8){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 159 && arc_diff < 187 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 680 && area_diff < 890 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 1 && longest_x < 25 &&	longest_y > 8 && longest_y < 15){letter = 'f'; poly2 = poly__f;}
							    	 }
							       }
							    }
					//g
							   result = matchShapes(poly, poly__g, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 1){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 220 && arc_diff < 250 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 1100 && area_diff < 1400 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 5 && longest_x < 15 &&	longest_y > 5 && longest_y < 30){letter = 'g'; poly2 = poly__g;}
							    	 }
							       }
							    }
					//h
							   result = matchShapes(poly, poly__h, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 1){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 230 && arc_diff < 270 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 950 && area_diff < 1450 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 20 && longest_x < 27 &&	longest_y > 4 && longest_y < 15){letter = 'h'; poly2 = poly__h;}
							    	 }
							       }
							    }
					//i
							   result = matchShapes(poly, poly__i, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 1){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 90 && arc_diff < 120 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 375 && area_diff < 550 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 2 && longest_x < 37 &&	longest_y > 2 && longest_y < 14){letter = 'i'; poly2 = poly__i;}
							    	 }
							       }
							    }
					//j
							   //TBD
					//k
							   result = matchShapes(poly, poly__k, CV_CONTOURS_MATCH_I1, 0);
							   if(result < 0.8){
								   arc_diff = arcLength(poly, true);
							    if(arc_diff > 220 && arc_diff < 260 ){
							    	 area_diff = abs(contourArea(poly,true));
							    	 if(area_diff > 950 && area_diff < 1300 ){
							    	 sum(poly, longest_x, longest_y);
								        if(	longest_x > 48 && longest_x < 55 &&	longest_y > 4 && longest_y < 10){letter = 'k'; poly2 = poly__k;}
							    	 }
							       }
							    }
					//l
							   		   result = matchShapes(poly, poly__l, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 1){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 130 && arc_diff < 155 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 550 && area_diff < 750 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 48 && longest_x < 56 &&	longest_y > 4 && longest_y < 13){letter = 'l'; poly2 = poly__l;}
							   		    	 }
							   		       }
							   		    }
					//m
							   		   result = matchShapes(poly, poly__m, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 1){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 290 && arc_diff < 330 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 1250 && area_diff < 1700 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 5 && longest_x < 10 &&	longest_y > 21 && longest_y < 50){letter = 'm'; poly2 = poly__m;}
							   		    	 }
							   		       }
							   		    }
					//n
							   		   result = matchShapes(poly, poly__n, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 1){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 200 && arc_diff < 230 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 800 && area_diff < 1080 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 4 && longest_x < 9 &&	longest_y > 27 && longest_y < 32){letter = 'n'; poly2 = poly__n;}
							   		    	 }
							   		       }
							   		    }
					//o
							   		   result = matchShapes(poly, poly__o, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.2){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 125 && arc_diff < 147 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 1200 && area_diff < 1490 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 13 && longest_x < 24 &&	longest_y > 13 && longest_y < 27){letter = 'o'; poly2 = poly__o;}
							   		    	 }
							   		       }
							   		    }
					//p
							   		   result = matchShapes(poly, poly__p, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.8){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 170 && arc_diff < 195 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 1400 && area_diff < 1630 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 5 && longest_x < 25 &&	longest_y > 4 && longest_y < 17){letter = 'p'; poly2 = poly__p;}
							   		    	 }
							   		       }
							   		    }
					//q
					//r
							   		   result = matchShapes(poly, poly__r, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.8){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 130 && arc_diff < 155 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 475 && area_diff < 650 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 4 && longest_x < 8 &&	longest_y > 4 && longest_y < 14){letter = 'r'; poly2 = poly__r;}
							   		    	 }
							   		       }
							   		    }
					//s
							   		   result = matchShapes(poly, poly__r, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.8){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 180 && arc_diff < 205 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 580 && area_diff < 710 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 18 && longest_x < 40 &&	longest_y > 4 && longest_y < 24){letter = 's'; poly2 = poly__s;}
							   		    	 }
							   		       }
							   		    }
					//t
							   		   result = matchShapes(poly, poly__t, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.9){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 125 && arc_diff < 160 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 510 && area_diff < 690 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 7 && longest_x < 14 &&	longest_y > 7 && longest_y < 16){letter = 't'; poly2 = poly__t;}
							   		    	 }
							   		       }
							   		    }
					//u
							   		   result = matchShapes(poly, poly__u, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.5){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 190 && arc_diff < 220 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 850 && area_diff < 1075 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 30 && longest_x < 37 &&	longest_y > 6 && longest_y < 37){letter = 'u'; poly2 = poly__u;}
							   		    	 }
							   		       }
							   		    }
					//v
							   		   result = matchShapes(poly, poly__v, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.5){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 155 && arc_diff < 175 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 540 && area_diff < 600 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 0 && longest_x < 10 &&	longest_y > 0 && longest_y < 17){letter = 'v'; poly2 = poly__v;}
							   		    	 }
							   		       }
							   		    }
					//w
							   		   result = matchShapes(poly, poly__w, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.5){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 265 && arc_diff < 290 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 950 && area_diff < 1300 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 1 && longest_x < 6 &&	longest_y > 10 && longest_y < 39){letter = 'w'; poly2 = poly__w;}
							   		    	 }
							   		       }
							   		    }
					//x
							   		   result = matchShapes(poly, poly__x, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.2){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 190 && arc_diff < 210 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 650 && area_diff < 750 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 1 && longest_x < 40 &&	longest_y > 10 && longest_y < 25){letter = 'x'; poly2 = poly__x;}
							   		    	 }
							   		       }
							   		    }
					//y
							   		   result = matchShapes(poly, poly__y, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.5){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 185 && arc_diff < 219 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 600 && area_diff < 800 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 1 && longest_x < 5 &&	longest_y > 12 && longest_y < 18){letter = 'y'; poly2 = poly__y;}
							   		    	 }
							   		       }
							   		    }
					//z
							   		   result = matchShapes(poly, poly__z, CV_CONTOURS_MATCH_I1, 0);
							   		   if(result < 0.5){
							   			   arc_diff = arcLength(poly, true);
							   		    if(arc_diff > 155 && arc_diff < 180 ){
							   		    	 area_diff = abs(contourArea(poly,true));
							   		    	 if(area_diff > 490 && area_diff < 590 ){
							   		    	 sum(poly, longest_x, longest_y);
							   			        if(	longest_x > 1 && longest_x < 35 &&	longest_y > 8 && longest_y < 18){letter = 'z'; poly2 = poly__z;}
							   		    	 }
							   		       }
							   		    }//end of z

if(!poly2.empty()){
	find(poly, image_feed, letter); 			//draws the contout/letter over the image
    Rect position;								//blank rect used below
	position = boundingRect(poly);				//bounding rect of the drew contour/letter
	positions[positions_counter] = position.x; 	//each contout/letter has a "x" position. This just stores them in an array
	letters[positions_counter] = letter;	   	//each contour/letter has a char value. This just stores them in an array
	positions_counter = positions_counter + 1; 	//each contour/letter added increases the array. This will be used later. positions_counter is an int.
	}//end of !poly2.empty()
}//end of contours.size

//this block is placing all contours/letters found in order from left to right by x value.
for(int i = 0 ; i < positions_counter; i++){			// loop for every char, x.position, stored from above
  for (int j = 0 ; j < positions_counter; j++){			// loop within a loop to compare all char, x.positions against each other
   if (positions[i]<=positions[j]){						//
	  int temp;											//
	  temp = positions[i];
	  positions[i] = positions[j];
	  positions[j] = temp;
	  char temp_c;
	  temp_c = letters[i];
	  letters[i] = letters[j];
	  letters[j] = temp_c;
    }
  }
}

//add all found contours/letters  char to a string.
for (int i = 0; i < positions_counter; i++){
		found_card_name.append(1, letters[i]);
}


//this adds any new found letters to the final word
for(int i = 0; i < positions_counter; i++){
	 if(positions[i] < final_word[i]-2){
		 size = size + 1;

		 int temp = final_word[i];
		 final_word[i] = positions[i];
		 char temp_char = final_word_char[i];
		 final_word_char[i] = letters[i];

		 for(int j = i+1; j < size; j++){
			 int temp2 = final_word[j];
			 final_word[j]=temp;
			 temp = temp2;
			 char temp_char2 = final_word_char[j];
			 final_word_char[j] = temp_char;
			 temp_char = temp_char2;
		 	 }
	 	 }
 	 }//end of int i = 0; i < positions_counter; i++ from above

	if(positions_counter_final < positions_counter){
		positions_counter_final = positions_counter;
	}
 }//end of !contours.empty


		   rectangle(image_feed, Rect(x, y, w, h), CV_RGB(255,0,255),1);		//white rect to user can see where the detection spot is
		   putText(image_feed, found_card_name,Point(10,10) ,FONT_HERSHEY_COMPLEX_SMALL, 0.8,Scalar(0,0,255),1);
		   imshow("Image Feed",image_feed);
		   found_card_name.clear();
		   waitKey(1000);// enable to see more of what is going on


    }//end of picture take and analyze loop. after ends we are done with the card <5

	              fstream outfile;
	              outfile.open("C:/final_char.txt", fstream::in | fstream::out | fstream::app);

	  	  		  for(int i=0; i < positions_counter_final; i++){
	  	  			  outfile << final_word_char[i];
	  	  		  }
	  	  		  outfile << "\t";
	  	  		  outfile.close();

//these below are all to reset for next card
	 size = 0;
	 for (int i = 0; i < 30; i++){
		 final_word[i] = 5000;
	 }
	 for (int i = 0; i < 30; i++){
		 final_word_char[i] = 'a';
	 }
	 toggle = 4;
	 positions_counter_final = 0;
}//end of if toggle == 3.

if(toggle == 5){
	waitKey(1000);
	image_feed = cvQueryFrame(camera);
	imshow("Image Feed", image_feed);
	fstream outfile;
	outfile.open("C:/final_char.txt", fstream::in | fstream::out | fstream::app);

			outfile << "10th edition";

	outfile << "\n";
	outfile.close();
	toggle = 6;
}


if(toggle == 0){
		 image_feed = cvQueryFrame(camera);
		 cvtColor(image_feed, image_feed_gray, CV_BGR2GRAY);
		 Mat image_feed_gray_roi(image_feed_gray, Rect(x,y,w,h));
		 medianBlur(image_feed_gray_roi, image_feed_gray_blur1, 5);
		 bilateralFilter(image_feed_gray_blur1, image_feed_gray_roi , 3, 19, 3);
		 bilateralFilter(image_feed_gray_roi, image_feed_gray_blur1, 3, 19, 3);
		 bilateralFilter(image_feed_gray_blur1, image_feed_gray_roi , 3, 19, 3);
		 Sobel(image_feed_gray_roi, image_feed_gray_blur1, CV_16S,1,0);
		 Sobel(image_feed_gray_roi, image_feed_gray_blur2, CV_16S,0,1);
		 sobel = abs(image_feed_gray_blur1)+abs(image_feed_gray_blur2);
		 double sobmin, sobmax;
		 minMaxLoc(sobel, & sobmin, &sobmax);
		 sobel.convertTo(sobelImage, CV_8U, -255./sobmax, 255);
		 adaptiveThreshold(sobelImage, sobelThresholded, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 3, 1);
		 rectangle(image_feed, Rect(x, y, w, h), CV_RGB(255,0,255),1);
		 imshow("Image Feed", image_feed);
		 imshow("Adaptive Filtered", sobelThresholded);
}

  }//end of while(1)
  cvReleaseCapture(&camera);
  destroyAllWindows();
  return 0;
}//end of main program






//////////////////////////////////////////////////////////////////////////////////////////



void letterLoad(char from[], vector<Point> & to){
ifstream infile(from);
if (infile.is_open()){
	String x,y;
	int i = 0;
	while (getline (infile,x), getline (infile,y)){
		Point *p = new Point(0,0);
		to.push_back(*p);
		istringstream ss(x);
		ss>> to[i].x;
		istringstream zz(y);
		zz>> to[i].y;
		i++;
	}

  infile.close();
 }
}

void sum (vector<Point> poly, int &longest_x, int &longest_y){
	   Rect a;
	   a = boundingRect(poly);

	   int x = a.width;
	   int y = a.height;

	   longest_x = 0;
	   longest_y = 0;

	   int white_points_old = 0;
	   int white_points = 0;

	   		      for ( int i = a.y; i < a.y+y; i++){
	   		    	  white_points = 0;
	   		    	  for (int j = a.x; j < a.x+x; j++){
	   		    		  if(pointPolygonTest(poly, Point2f(j,i), true) > 0){white_points = white_points+1;}
	   		    	 }
	   		    	  if (white_points > white_points_old){longest_x = i - a.y; white_points_old = white_points;}
	   		      }

	   			     white_points_old = 0;
	   			     white_points = 0;

	   		      for ( int i = a.x; i < a.x+x; i++){
	   		    	  white_points = 0;
	   		    	  for (int j = a.y; j < a.y+y; j++){
	   		    		  if(pointPolygonTest(poly, Point2f(i,j), true) > 0){white_points = white_points+1;}
	   		    	 }
	   		    	  if (white_points > white_points_old){longest_y = i - a.x; white_points_old = white_points;}
	   		      }
}


void find(vector<Point>  &poly, Mat &image_feed, char letter){
	vector<Point>::iterator itp= poly.begin();					//Used to draw the polygon to image_feed
	while (itp!= (poly.end()-1)){								//Used to draw the polygon to image_feed
	line(image_feed,*itp,*(itp+1),Scalar(0,255,0),2);			//Used to draw the polygon to image_feed
	itp++;
	}//end of while iterator

	//putText(image_feed, &letter ,Point(poly[0].x-20,poly[0].y) ,FONT_HERSHEY_COMPLEX_SMALL, 0.8,Scalar(0,0,255),1);


}
