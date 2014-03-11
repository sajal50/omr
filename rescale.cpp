#include "CImg.h"
#include  <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace cimg_library;
using namespace std;
 
int main() {
 
	//Construct image from reading an image file. 
	CImg<unsigned char> src("scan.bmp"); 
 	int flag=0;
	int width = src.width();
	int height = src.height();
	int depth = src.depth();
	int array[1000][1000];
	int ans[20];	

	
 
 
	unsigned char r,g,b;
	//unsigned char gr1 = 0;
	unsigned char gr2 = 0;
 	int i=0;
	int k=0;
	int l=0;
	int j=0;
	int ref=0;
	for( i=196;i<196+50;i++){
		for( j=424;j<424+50;j++){
 
			 
			r = src(i,j,0,0); // First channel RED
			g = src(i,j,0,1); // Second channel GREEN
			b = src(i,j,0,2); // Third channel BLUE
 
 
			gr2 = round(0.2126*((double)r) + 0.7152*((double)g) + 0.0722*((double)b));
 			//cout<<(int)gr2<<" ";
			ref=gr2;
			if (ref<50)
			{  height=j;
				width=i;
				cout<<height<<" "<<width;
						
				CImg<unsigned char> gray2(1310-width,2018-height,depth,1);
				for (k=0;k<(1310-width);k++)
				{
					for(l=0;l<(2018-height);l++)
							{
							r = src(k+width,l+height,0,0); // First channel RED
							g = src(k+width,l+height,0,1); // Second channel GREEN
							b = src(k+width,l+height,0,2);
							gr2 = round(0.2126*((double)r) + 0.7152*((double)g) + 0.0722*((double)b));
							//cout<<(int)gr2;							
							gray2(k,l,0,0) = gr2;
							

							}

				}
			gray2.save("scan1.bmp");	
						
			flag=1;			
						
			goto save;
			
			
			}


				
		

			}
 
	}
	save:
 	if (flag)

	cout<<"yes";
	
return 0;
}

 	
