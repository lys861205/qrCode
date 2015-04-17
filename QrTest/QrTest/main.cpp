// #include "QR_Encode.h"
// #include <fstream>
// using namespace std;
// 
// int main()
// {
// 		CQR_Encode encode;
// 		CHAR *source = "Hello World";
// 		BOOL ret = encode.EncodeData(QR_LEVEL_L, QR_VRESION_S, TRUE, 1, source);
// 		ofstream out;
// 		out.open("test.bmp", ios::binary|ios::out|ios::trunc);
// 
// // 		for(int i = 0; i < MAX_MODULESIZE; ++i)
// // 		{
// // 				out.write((const char*)encode.m_byModuleData[i],strlen((const char*)encode.m_byModuleData[i]));
// // 		}
// 		out.write(source, strlen(source));
// 		
// 		return ret;
// }




#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
//#include <opencv2/opencv.hpp>
#include "QR_Encode.h"
#define QR_MARGIN	4
using namespace std;

int main(int argc, char* argv[])
{
		int i,j;
		//IplImage *image = NULL;
		CQR_Encode* pQR_Encode = new CQR_Encode;
		int nLevel = 0;
		int nVersion = 0;
		bool bAutoExtent = 1;
		int nMaskingNo = -1;
		char pCodeStr[1000] = "ÄãºÃ";
		if (pQR_Encode->EncodeData(0, 0, 1, -1, pCodeStr))
		{
				int originalSize = pQR_Encode->m_nSymbleSize + (QR_MARGIN * 2);
				//image = cvCreateImage(cvSize(originalSize,originalSize),8,1);
				//memset(image->imageData,255,image->widthStep*image->height);
				for (i = 0; i < pQR_Encode->m_nSymbleSize; ++i)
				{
						for (j = 0; j < pQR_Encode->m_nSymbleSize; ++j)
						{
								if (pQR_Encode->m_byModuleData[i][j])
								{
										//CV_IMAGE_ELEM(image,uchar,j+ QR_MARGIN, i+ QR_MARGIN) = 0;
								}
						}
				}
				//cvSaveImage("12.bmp",image,0);
		}
		else
		{
				printf("error\n");
		}	
		return 0;
}
