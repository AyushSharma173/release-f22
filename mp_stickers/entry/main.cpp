#include "Image.h"
#include "StickerSheet.h"
#include<iostream>
using namespace std;
int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image alma; alma.readFromFile("../tests/alma.png");
  Image i;    i.readFromFile("../tests/i.png");
  Image j;    j.readFromFile("../tests/expected-2.png");
  Image k;    k.readFromFile("../tests/expected-3.png");

  StickerSheet sheet(alma, 5);

  // cout<<"Sticker Width :"<<i.width()<<endl;
  // cout<<"Sticker Height :"<<i.height()<<endl;

  sheet.addSticker(i, 20, 200);
  sheet.addSticker(i, 450, 200);
  sheet.addSticker(i, 700, 200);
  // sheet.render().writeToFile("../myImage.png");
  Image expected;
  expected.readFromFile("../tests/expected.png");
  // cout<<sheet.getSticker(0);
  // if (sheet.getSticker(2) == NULL) {
  //   cout<<"True";
  // } else {
  //   cout << "False";
  // }

  
  return 0;
}
