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
	CImg<unsigned char> src("scan1.bmp"); 
 	
	int width = src.width();
	int height = src.height();
	int depth = src.depth();
	int array[1000][1000];
	int ans[500];	
 //New grayscale images.
	//CImg<unsigned char> gray1(width,height,depth,1);
	CImg<unsigned char> gray2(width,height,depth,1);
 
 
	unsigned char r,g,b;
	//unsigned char gr1 = 0;
	unsigned char gr2 = 0;
 	int i=0;
	/* Convert RGB image to grayscale image */
	for( i=0;i<width;i++){
		for(int j=0;j<height;j++){
 
			//Return a pointer to a located pixel value. 
			r = src(i,j,0,0); // First channel RED
			g = src(i,j,0,1); // Second channel GREEN
			b = src(i,j,0,2); // Third channel BLUE
 
 /*
			//PAL and NTSC
			//Y = 0.299*R + 0.587*G + 0.114*B
			gr1 = round(0.299*((double)r) + 0.587*((double)g) + 0.114*((double)b));
 */
			//HDTV 
			//Y = 0.2126*R + 0.7152*G + 0.0722*B
			gr2 = round(0.2126*((double)r) + 0.7152*((double)g) + 0.0722*((double)b));
 
			//gray1(i,j,0,0) = gr1;
			gray2(i,j,0,0) = gr2;
			

			array[i][j]=gr2;		
		

			}
 
	}
 
	//save the new grayscale images
//	gray1.save("gray1.bmp");
	gray2.save("gray2.bmp");
 	
	/*for(int k=0;k<79;k++)
		{
			for(int l=0;l<31;l++)
			cout<<array[k][l]<<" ";	
				
		cout<<"\n";
		}

cout<<"\n\n";
*/
//cout<<ans[0]<<" "<<ans[1]<<"\n";
int count0=0;
i=0;
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int k=146;
int l=86;

i=0;
count0=count1=count2=count3=count4=0;
for ( k=146;k<370;k++)
{
		for( l=86;l<120;l++)
			{
			if(array[k][l]>220)
				{
				if (k>146 && k<188)
					count0++;
				
				if (k>191 && k<233)
					count1++;
				
				if (k>237 && k<279)
					count2++;
				
				if (k>281 && k<323)
					count3++;
				
				if (k>328 && k<370)
					count4++;
				
				
				}
				
			}
}

if (count0>700)
ans[i]=0;
else
ans[i]=1;
i++;
if (count1>700)
ans[i]=0;
else
ans[i]=1;
i++;
if (count2>700)
ans[i]=0;
else
ans[i]=1;
i++;
if (count3>700)
ans[i]=0;
else
ans[i]=1;
i++;
if (count4>700)
ans[i]=0;
else
ans[i]=1;
i++;



k=146;
l=86+62;

for (int z=1;z<20;z++)
{
count0=count1=count2=count3=count4=0;
for ( k=146;k<370;k++)
{
		for(l=86+z*61;l<120+z*61;l++)
			{
			if(array[k][l]>220)
				{
				if (k>146 && k<188)
					count0++;
				
				if (k>191 && k<233)
					count1++;
				
				if (k>237 && k<279)
					count2++;
				
				if (k>281 && k<323)
					count3++;
				
				if (k>328 && k<370)
					count4++;
				
				
				}
				
			}
}

if (count0>750)
ans[i]=0;
else
ans[i]=1;
i++;
if (count1>750)
ans[i]=0;
else
ans[i]=1;
i++;
if (count2>750)
ans[i]=0;
else
ans[i]=1;
i++;
if (count3>750)
ans[i]=0;
else
ans[i]=1;
i++;
if (count4>750)
ans[i]=0;
else
ans[i]=1;
i++;

}
/*
for(int k=146;k<188;k++)
		{
			for(int l=87;l<120;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;
count=0;
for(int k=191;k<233;k++)
		{
			for(int l=87;l<120;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=237;k<279;k++)
		{
			for(int l=87;l<120;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;



count=0;
for(int k=281;k<323;k++)
		{
			for(int l=87;l<120;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=328;k<370;k++)
		{
			for(int l=87;l<120;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

//end of first line
count=0;
for(int k=146;k<188;k++)
		{
			for(int l=149;l<182;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;
count=0;
for(int k=191;k<233;k++)
		{
			for(int l=149;l<182;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=237;k<279;k++)
		{
			for(int l=149;l<182;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;



count=0;
for(int k=281;k<323;k++)
		{
			for(int l=149;l<182;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=328;k<370;k++)
		{
			for(int l=149;l<182;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;
//end of 2nd line
count=0;
for(int k=146;k<188;k++)
		{
			for(int l=210;l<243;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;
count=0;
for(int k=191;k<233;k++)
		{
			for(int l=210;l<243;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=237;k<279;k++)
		{
			for(int l=210;l<243;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;



count=0;
for(int k=281;k<323;k++)
		{
			for(int l=210;l<243;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=328;k<370;k++)
		{
			for(int l=210;l<243;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;


//end of 3rd line
count=0;
for(int k=146;k<188;k++)
		{
			for(int l=271;l<304;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;
count=0;
for(int k=191;k<233;k++)
		{
			for(int l=271;l<304;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=237;k<279;k++)
		{
			for(int l=271;l<304;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;



count=0;
for(int k=281;k<323;k++)
		{
			for(int l=271;l<304;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;

count=0;
for(int k=328;k<370;k++)
		{
			for(int l=271;l<304;l++)
				{if(array[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans[i]=0;
	else
	ans[i]=1;

i++;


		
	
	//show all images
	
 	//cout<<"\n"<<count;
CImg<unsigned char> src1("gray2.bmp");
/*
for(int k=0;k<403;k++)
		{
			for(int l=0;l<302;l++)
				{	
				if (array[k][l]<100)
				src1(k,l,0,0) = 0;
				//src=0;
				if (array[k][l]>150)
				src1(k,l,0,0) = 250;	
				}
		//cout<<"\n";
		}
src1.save("gray3.bmp");
	(src,src1).display("RGB to Grayscale");
 */

char ch;
int a=0;
for (a=0;a<100;a++)
{if (a%5==0)
	{cout<<"\n";}
cout<<ans[a]<<" ";
}

CImg<unsigned char> src2("serial_no.bmp"); 
 	
	 width = src2.width();
	 height = src2.height();
	 depth = src2.depth();
	 int array1[1000][1000];
	 int ans1[20];	
 //New grayscale images.
	//CImg<unsigned char> gray1(width,height,depth,1);
	CImg<unsigned char> gray3(width,height,depth,1);
 
 
	//unsigned char r,g,b;
	//unsigned char gr1 = 0;
	 gr2 = 0;
 	 i=0;
	/* Convert RGB image to grayscale image */
	for( i=0;i<width;i++){
		for(int j=0;j<height;j++){
 
			//Return a pointer to a located pixel value. 
			r = src2(i,j,0,0); // First channel RED
			g = src2(i,j,0,1); // Second channel GREEN
			b = src2(i,j,0,2); // Third channel BLUE
 
 /*
			//PAL and NTSC
			//Y = 0.299*R + 0.587*G + 0.114*B
			gr1 = round(0.299*((double)r) + 0.587*((double)g) + 0.114*((double)b));
 */
			//HDTV 
			//Y = 0.2126*R + 0.7152*G + 0.0722*B
			gr2 = round(0.2126*((double)r) + 0.7152*((double)g) + 0.0722*((double)b));
 
			//gray1(i,j,0,0) = gr1;
			gray3(i,j,0,0) = gr2;
			

			array1[i][j]=gr2;		
		

			}
 
	}
 
	//save the new grayscale images
//	gray1.save("gray1.bmp");
	gray3.save("serial_copy.bmp");


 int count=0;
i=0;
for(int k=1;k<39;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;

for(int k=46;k<84;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;


count=0;

for(int k=90;k<128;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;

for(int k=135;k<172;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;


count=0;

for(int k=179;k<217;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;

for(int k=223;k<261;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;



count=0;

for(int k=267;k<308;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;

for(int k=312;k<350;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;
for(int k=356;k<395;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;

for(int k=401;k<438;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;


count=0;

for(int k=445;k<483;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;


count=0;

for(int k=490;k<528;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;

count=0;

for(int k=533;k<572;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;


count=0;

for(int k=577;k<617;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;


count=0;

for(int k=623;k<660;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;
count=0;

for(int k=666;k<704;k++)
		{
			for(int l=3;l<34;l++)
				{if(array1[k][l]>220)	
					count++;		
			}	
		//cout<<"\n";
		}

if (count>700)
	ans1[i]=0;
	else
	ans1[i]=1;

i++;
int decimal=0;
for (i=15;i>0;i--)
{
	decimal=decimal+ ans1[i]*pow(2,15-i);

}
//cout<<decimal;

//Writing CSV file

ofstream inFile;
inFile.open("info.csv");
inFile<<"No: ";
inFile<<"Status ";
inFile<<"SerialNo ";


	for (i=0;i<15;i++)
		{
		inFile<<i+1;
		inFile<<" ";
		
		}
//End of First
	inFile<<endl;
	inFile<<"1 ";
	inFile<<"OK ";
	
	inFile<<decimal<<" ";
	for (i=0;i<15;i++)
		{
		for(int j=i*5;j<(i*5)+5;j++)
		if(ans[j]==1)
		{
		ch=65+(j%5);	
		inFile<<ch;
		inFile<<" ";
		}
		}

inFile.close();












return 0;
//	return 0;
}
