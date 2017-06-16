#include <GL/glut.h>
#include "math.h"

typedef struct {
  int x ;
  int y ;
} POINT ;

void display() ;
void initGraphics(int, char *[], int, int) ;

void drawPoint(int, int) ;
void drawLine(int, int, int, int) ;
void drawRectangle(int, int, int, int) ;
void fillRectangle(int, int, int, int) ;
void drawCircle(int, int, int) ;
void fillCircle(int, int, int) ;

void drawLines(POINT [], int) ;
void drawPolygon(POINT [], int) ;
void fillPolygon(POINT [], int) ;
