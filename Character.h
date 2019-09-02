#include <stdio.h>
#include<math.h>
#include <GL/glut.h>

class Character
{
public:
    bool visible;
    void draw(int x);
    bool backWardMoving;
    bool forWardMoving;
    int moveXmin;
    int moveXmax;
    int movingValue;
    int xMin;
    int xMax;
    int yMin;
    int yMax;
    int xGunPoint;
    int yGunPoint;
    int trans;
    int timeCount;
    int timeToVisible;
    int holdFire;
    bool firing;
    void makeVisible();
    Character();

protected:
    void checkForwardBackward();
};
Character::Character()
{
    firing = false;
    visible = false;
    forWardMoving = true;
    backWardMoving = false;
    movingValue = 0;
    timeCount = 0;
    holdFire = 10;
}
void Character::checkForwardBackward()
{
    if(forWardMoving)
    {
        if(xMax>=moveXmax)
        {
            forWardMoving = false;
            backWardMoving = true;
        }
    }
    else if(backWardMoving)
    {
        if(xMin<=moveXmin)
        {
            forWardMoving = true;
            backWardMoving = false;
        }
    }
}
void Character::makeVisible()
{
    if((timeCount >= timeToVisible)&& visible==false)
    {
      visible = true;
    }
}
void Character::draw(int x)
{
    trans = x;
    trans = (trans*30)/100;
    if(visible)
    {
  glPushMatrix();
  glScalef(0.3,0.3,0);
    //Leg
    glTranslatef(x,400,0);
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2i(70, 35);
glVertex2i(40, 35);
glVertex2i(80, 150);
glVertex2i(120, 150);

glBegin(GL_QUADS);
glVertex2i(80, 150);
glVertex2i(100, 180);
glVertex2i(170, 180);
glVertex2i(190, 150);

glBegin(GL_QUADS);
glVertex2i(140, 150);
glVertex2i(190, 150);
glVertex2i(210, 40);
glVertex2i(180, 40);
//shoe
glColor3ub (0, 0,0);
glVertex2i(70, 35);
glVertex2i(40, 35);
glVertex2i(20, 25);
glVertex2i(60, 25);

glVertex2i(210, 40);
glVertex2i(180, 40);
glVertex2i(190, 30);
glVertex2i(230, 30);

//hand
glColor3ub (0.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2i(115, 180);
glVertex2i(120, 210);
glVertex2i(105, 220);
glVertex2i(80, 200);

glVertex2i(150, 230);
glVertex2i(160, 215);
glVertex2i(115, 180);
glVertex2i(120, 210);

glVertex2i(105, 220);
glVertex2i(80, 200);
glVertex2i(60, 220);
glVertex2i(90, 240);

glVertex2i(90, 240);
glVertex2i(60, 220);
glVertex2i(45, 230);
glVertex2i(65, 255);

glVertex2i(90, 240);
glVertex2i(65, 255);
glVertex2i(110, 280);
glVertex2i(120, 250);

glVertex2i(90, 240);
glVertex2i(110, 210);
glVertex2i(130, 210);
glVertex2i(120, 250);

glVertex2i(120, 250);
glVertex2i(110, 280);
glVertex2i(120, 290);
glVertex2i(125, 280);


glVertex2i(120, 340);
glVertex2i(170, 340);
glVertex2i(160, 355);
glVertex2i(130, 355);


glVertex2i(120, 290);
glVertex2i(125, 280);
glVertex2i(160, 280);
glVertex2i(170, 290);

glVertex2i(170, 290);
glVertex2i(160, 280);
glVertex2i(170, 270);
glVertex2i(220, 270);

glVertex2i(190, 240);
glVertex2i(220, 240);
glVertex2i(220, 270);
glVertex2i(190, 270);

glVertex2i(190, 255);
glVertex2i(190, 270);
glVertex2i(160, 280);
glVertex2i(180, 250);

glVertex2i(200, 240);
glVertex2i(220, 240);
glVertex2i(220, 220);
glVertex2i(200, 220);

glVertex2i(200, 240);
glVertex2i(220, 240);
glVertex2i(220, 220);
glVertex2i(200, 220);

glVertex2i(220, 225);
glVertex2i(220, 215);
glVertex2i(215, 215);
glVertex2i(215, 225);

glVertex2i(205, 200);
glVertex2i(205, 220);
glVertex2i(220, 220);
glVertex2i(230, 205);

glVertex2i(185, 215);
glVertex2i(170, 215);
glVertex2i(170, 195);
glVertex2i(185, 195);

glVertex2i(185, 195);
glVertex2i(195, 195);
glVertex2i(195, 185);
glVertex2i(180, 180);

glVertex2i(185, 195);
glVertex2i(180, 180);
glVertex2i(170, 185);
glVertex2i(170, 195);

glVertex2i(215, 185);
glVertex2i(230, 205);
glVertex2i(195, 200);
glVertex2i(180, 180);

glVertex2i(125, 280);
glVertex2i(160, 280);
glVertex2i(170, 270);
glVertex2i(115, 250);



glVertex2i(165, 240);
glVertex2i(180, 240);
glVertex2i(180, 260);
glVertex2i(160, 275);






glColor3ub (108,108,108);
glVertex2i(125, 290);
glVertex2i(165, 290);
glVertex2i(170, 315);
glVertex2i(120, 315);

glColor3ub (255,236,168);
glVertex2i(170, 315);
glVertex2i(120, 315);
glVertex2i(120, 340);
glVertex2i(170, 340);

//eye
glColor3ub (0,0,0);
glVertex2i(130, 320);
glVertex2i(140, 320);
glVertex2i(140, 330);
glVertex2i(130, 330);

glVertex2i(150, 320);
glVertex2i(160, 320);
glVertex2i(160, 330);
glVertex2i(150, 330);

//glove
glColor3ub (255,241,193);
glVertex2i(160, 215);
glVertex2i(150, 230);
glVertex2i(170, 240);
glVertex2i(180, 215);

glVertex2i(170, 240);
glVertex2i(180, 215);
glVertex2i(205, 225);
glVertex2i(190, 240);

glVertex2i(195, 200);
glVertex2i(195, 220);
glVertex2i(205, 220);
glVertex2i(205, 200);



//gun
glColor3ub (159,99,66);
glVertex2i(185, 195);
glVertex2i(195, 195);
glVertex2i(195, 220);
glVertex2i(185, 220);

glVertex2i(175, 225);
glVertex2i(175, 240);
glVertex2i(200, 240);
glVertex2i(200, 225);

glVertex2i(180, 240);
glVertex2i(195, 240);
glVertex2i(195,250);
glVertex2i(180,250);

glVertex2i(185,250);
glVertex2i(185,255);
glVertex2i(190,255);
glVertex2i(190,250);


glColor3ub (193,193,200);
glVertex2i(185,230);
glVertex2i(190,230);
glVertex2i(190,235);
glVertex2i(185,235);


/*
//belt
glColor3ub (125, 0, 19);
glBegin(GL_QUADS);
glVertex2i(50, 65);
glVertex2i(50, 68);
glVertex2i(23, 68);
glVertex2i(23, 65);*/

//body
glColor3ub (45, 45, 45);
glBegin(GL_QUADS);
glVertex2i(115, 180);
glVertex2i(170, 180);
glVertex2i(180, 220);
glVertex2i(160, 215);

glVertex2i(155, 230);
glVertex2i(165, 240);
glVertex2i(163, 270);
glVertex2i(150, 265);

glVertex2i(155, 230);
glVertex2i(150, 265);
glVertex2i(120, 252);
glVertex2i(120, 210);

glBegin(GL_QUADS);
glVertex2i(100, 180);
glVertex2i(115, 180);
glVertex2i(116, 180);
glVertex2i(95, 192);



glEnd();
  glPopMatrix();
    }
  xMin = ((30*20)/100) + trans;
  xMax = ((30*230)/100) + trans;
  yMin = ((30*25)/100) +(30*400)/100;
  yMax = ((30*355)/100)+(30*400)/100;

  xGunPoint = ((30*187)/100) + trans;
  yGunPoint = ((30*232)/100)+(30*400)/100;

  checkForwardBackward();

}
//float _angle1 = 30.0f;
//void myDisplay(void)
//{
//glClear (GL_COLOR_BUFFER_BIT);
//
//
//
//glFlush ();
//}
//void myInit (void)
//{
//glClearColor(1.0, 1.0, 1.0, 0.0);
//glColor3f(0.0f, 0.0f, 0.0f);
//glPointSize(4.0);
//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
//gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//}
//
//main(int argc, char** argv)
//{
//glutInit(&argc, argv);
//glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
//glutInitWindowSize (640, 480);
//glutInitWindowPosition (100, 150);
//glutCreateWindow ("my first attempt");
//glutDisplayFunc(myDisplay);
//myInit ();
//glutMainLoop();
//}
