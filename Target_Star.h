#include <stdio.h>
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>
class Target_star
{
public:
    bool visible;
    int x1;
    int y1;
    void draw(int x, int y);
    void makeVisible();
    void playFireSound();
    Target_star();
};
Target_star::Target_star()
{
    visible = false;
    x1 = (20*125)/100;
    y1 = (20*145)/100;
}
void Target_star::playFireSound()
{
    PlaySound("enemyShoot.wav",NULL,SND_FILENAME|SND_ASYNC);
}
void Target_star::draw(int x, int y)
{
    int defX = ((x-x1)*100)/20;
    int defY = ((y-y1)*100)/20;
glPushMatrix();
glScalef(0.2,0.2,0.0);
glTranslatef(defX,defY,0.0);
glBegin(GL_TRIANGLES);
glColor3ub (85, 204,255);
glVertex2i(90, 145);
glVertex2i(155, 145);
glColor3ub (255, 255,255);
glVertex2i(130, 20);

glColor3ub (85, 204,255);
glVertex2i(155, 145);
glVertex2i(90, 145);
glColor3ub (255, 255,255);
glVertex2i(130, 290);

glColor3ub (85, 204,255);
glVertex2i(120, 120);
glVertex2i(120, 175);
glColor3ub (255, 255,255);
glVertex2i(290, 150);

glColor3ub (85, 204,255);
glVertex2i(120, 120);
glVertex2i(120, 175);
glColor3ub (255, 255,255);
glVertex2i(1, 150);

glColor3ub (85, 204,255);
glVertex2i(150, 120);
glVertex2i(100, 170);
glColor3ub (255, 255,255);
glVertex2i(220, 240);

glColor3ub (85, 204,255);
glVertex2i(150, 120);
glVertex2i(100, 170);
glColor3ub (255, 255,255);
glVertex2i(40, 60);

glColor3ub (85, 204,255);
glVertex2i(100, 125);
glVertex2i(140, 170);
glColor3ub (255, 255,255);
glVertex2i(230, 50);

glColor3ub (85, 204,255);
glVertex2i(100, 125);
glVertex2i(140, 170);
glColor3ub (255, 255,255);
glVertex2i(25, 230);





glEnd();
  glPopMatrix();
}
