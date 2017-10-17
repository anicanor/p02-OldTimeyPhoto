//Author: Aaron Nicanor
#include <string>
#include <vector>
#include "bitmap.h"

using namespace std;

int main(){
 /*
 -Ask user for name of the file
  -If the name of the file isn't right (not in the correct format or file doesn't exist),
  ask again
 -Store the users input if it's correct
 -Convert image into a pixel matrix
 -Create a loop that'll look through each individual element of the pixel matrix
  -Inside the two loops change the RGB values so that it makes the image into greyscale
 -Save the pixel matrix as a new image called "oldtimey.bmp"
 */
 std::string name;
 Bitmap image;
 vector <vector <Pixel> > bmp;
 Pixel rgb;

 double red;
 double green;
 double blue;
 double gray;
 
 //Obtains the user's image
 do{

    cout<<"Enter name of image file (remember to include .bmp at the end!)"<<endl;
    cin>>name;
    image.open(name);

 }while (image.isImage() == false);

 //Tells the user the image's size
 bmp = image.toPixelMatrix();
 cout<<name<<" has been loaded. It is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;

 //Converts image to grayscale
 for (int i = 0; i < bmp.size(); i++){
    for (int o = 0; o < bmp[0].size(); o++){
        rgb = bmp[i][o];
        red = rgb.red;
        green = rgb.green;
        blue = rgb.blue;
        gray = (red * 0.3) + (green * 0.59) + (blue * 0.11);
        rgb.red = gray;
        rgb.green = gray;
        rgb.blue = gray;
        bmp[i][o] = rgb;
    }
 }
 
 //Saves image as "oldtimey.bmp"
 image.fromPixelMatrix(bmp);
 image.save("oldtimey.bmp");
 cout<<"File successfuly converted into grayscale."<<endl<<" Saved file name is oldtimey."<<endl;

 return 0;
}
