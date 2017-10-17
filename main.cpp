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
 -Create a matrix that is the same as the selected image
 -Create a loop to go through the rows and a loop inside to go through the columns of
 the selected image
  -Inside the two loops change the RGB values so that it makes the image into greyscale and
  save it into the clones matrix
 -create a file and save the new image created in the clone matrix as oldtimey.bmp
 */
 std::string name;
 Bitmap image;
 vector <vector <Pixel> > bmp;
 Pixel rgb;

 double red;
 double green;
 double blue;
 double gray;

 do{
    cout<<"Enter name of image file (must be a bpm)"<<endl;
    cin>>name;
    image.open(name);
 }while (image.isImage() == false);

 bmp = image.toPixelMatrix();
 cout<<name<<" has been loaded. It is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;

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
 
 image.fromPixelMatrix(bmp);
 image.save("oldtimey.bmp");
 cout<<"File successfuly converted into grayscale."<<endl<<" Saved file name is oldtimey."<<endl;

 return 0;
}
