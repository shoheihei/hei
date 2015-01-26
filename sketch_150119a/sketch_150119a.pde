void setup(){
  size(600, 600);
}
int x1=0, x2=400, y1=0, y2=50;
int a = 2;

void draw(){
  background(0);
  quad(x1, y1, x2, y1, x2, y2, x1, y2);
  x1 = x1 + a;
  x2 = x2 + a;
  if(x2 >= width && a == 2){
    y1 = y2;
    y2 += 50;
    a = a * -1;
  }
  if(x1 <= 0 && a == -2){
    y1 = y2;
    y2 += 50;
    a = a * -1;
  }
  if((x1 <= 0 || x2 >= width) && y2 >= height){
  y1 = 0;
  y2 = 50;
  }
}
