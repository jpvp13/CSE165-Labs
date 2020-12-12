#include "RectChild.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

RectChild::RectChild(float x,float y, float w, float h, float red, float green, float blue): Rect(x, y, w, h, red, green, blue){

}

void RectChild::newdraw(){
    glColor3f(red, green, blue);

    glBegin(GL_POLYGON);

    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);

    glEnd();
}