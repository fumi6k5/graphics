#include "graphics.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void display(void){
  
  glColor3d(0.0, 0.0, 0.0);
  drawRectangle(100, 100, 600, 400);
  glColor3d(1.0, 0.0, 0.0);
  fillCircle(400, 300, 150);
  
}

int main(int argc, char *argv[]){
  initGraphics(argc, argv, WINDOW_WIDTH, WINDOW_HEIGHT);
  glutMainLoop();

  return 0;
}
