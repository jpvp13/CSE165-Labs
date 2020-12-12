#ifndef RECT_H
#define RECT_H


enum Shape {none, EX, Circ};

struct Rect {
  float x;
  float y;
  float w;
  float h;

  // bool select;
  
  bool occupied;


  Shape shape;
  
  Rect ();
  
  Rect (float x, float y, float w, float h);
  
  bool contains(float mx, float my);

  // bool machine(bool select);
  
  void draw();
};




#endif
