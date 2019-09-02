#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include<stdlib.h>
#include "imageloader.h"
#include "Character.h"
#include <vector>
#include<cstring>
#include <sstream>
#include <utility>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include "Target_Star.h"
using namespace std;
int startCount=0;
int clickCount=0;
int yPoint=87.5;
int xPoint=37.5;
int transX=0;
int transY=0;
int ballx=0;
int bally=0;
int mov = 0;
int life = 0;
int point = 0;
bool pause = false;
bool write = false;
bool bullet1=true;
bool bullet2=true;
bool bullet3=true;
bool bullet4=true;
bool bullet5=true;
bool bullet6=true;
int countHoldFire = 0;
float currentTime =0.0;
bool creation = true;
///SoundHandler soundHandle;
vector <Character> characterList;
vector <Target_star> Targets;
bool picOpen = true;
bool picScore = false;
bool picPlay = false;
char text[] = "LIFE";
char NewGameTxt[] = "New Game";
char ScoreTxt[] = "Top Scorer";
char PointTxt[] = "Points:";
char reloadTxt[] = "Reload--> r";
char restartTxt[] = "press s to restart";
char yourScoreTxt[] = "Your Score:";
char mainMenuTxt[] = "Main Menu";
char playAgainTxt[] = "Play Again";
Image* image;
GLuint ground_textureId;
std::vector<std::string> explode(const std::string & in,const std::string & delim)
{
typedef std::string::size_type size_type ;

const size_type delim_len = delim.length() ;
std::vector<std::string> result ;

size_type i = 0, j ;
for (;;)
{
j = in.find(delim, i) ;
result.push_back(in.substr(i, j-i)) ;
if (j == std::string::npos)
break ;
i = j + delim_len ;
}

return result ;
}
void Sprint( float x, float y, char *st,int color)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    if(color == 1)
    glColor3f(0.0,0.0,1.0);
    else if(color == 2)
        glColor3f(1.0,1.0,1.0);
    else if(color == 3)
        glColor3f(1.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }


}
void reload()
{
    bullet1=true;
    bullet2=true;
    bullet3=true;
    bullet4=true;
    bullet5=true;
    bullet6=true;
    clickCount = 3;

}
bool emptyMagzin()
{
    int c=0;
    if(!bullet1)
        c++;
    if(!bullet2)
        c++;
    if(!bullet3)
        c++;
    if(!bullet4)
        c++;
    if(!bullet5)
        c++;
    if(!bullet6)
        c++;
    return c==6;
}
int random(int min, int max)
{
   static bool first = true;
   if (first)
   {
       srand(time(NULL));
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void mouseMotion(int x, int y)
{
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    ballx = x;
    bally = windowHeight-y;
    //cout<<x<<", "<<windowHeight-y<<endl;
//    shootCursor cursor;
//    cursor.draw((float)ballx/200, (float)bally/200);
//    glFlush ();
    transX = ballx-xPoint;
    transY = bally-yPoint;

}
void mouse(int button, int state, int x, int y) {
    vector <int> counter;
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    ballx = x;
    bally = windowHeight-y;
    cout<<x<<", "<<windowHeight-y<<endl;
     /// delete c1;
     if(picOpen)
     {
         if(ballx >= 1080  && ballx <= 1180 && bally >= 350 && bally <= 380)
         {
             picOpen = false;
             picPlay = true;
             picScore = false;
         }
         else if(ballx >= 1080  && ballx <= 1180 && bally >= 300 && bally <= 330)
         {
             picOpen = false;
             picPlay = false;
             picScore = true;
         }
     }
     if(picPlay)
     {
         if(!emptyMagzin())
          PlaySound("enemy.wav",NULL,SND_FILENAME|SND_ASYNC);
         clickCount++;
         for(int i=1;i<7;i++)
        {
            if(i==1 && clickCount!=1 && clickCount%2!=0)
            {
                if(bullet1)
                {
                    bullet1=false;
                    break;
                }
            }
            else if(i==2 && clickCount%2!=0)
            {
                if(bullet2)
                {
                    bullet2=false;
                    break;
                }
            }
            else if(i==3 && clickCount%2!=0)
            {
                if(bullet3)
                {
                    bullet3=false;
                    break;
                }
            }
            else if(i==4 && clickCount%2!=0)
            {
                if(bullet4)
                {
                    bullet4=false;
                    break;
                }
            }
            else if(i==5 && clickCount%2!=0)
            {
                if(bullet5)
                {
                    bullet5=false;
                    break;
                }
            }
            else if(i==6 && clickCount%2!=0)
            {
                if(bullet6)
                {
                    bullet6=false;
                    break;
                }
            }
        }
        if(!emptyMagzin())
        {
        for(int i=0;i<characterList.size();i++)
        {
         if(ballx >= characterList[i].xMin && ballx <= characterList[i].xMax && bally >= characterList[i].yMin && bally <= characterList[i].yMax)
        {
            counter.push_back(i);
            point += 10;
        }
        }
     for(int i=0; i<counter.size();i++)
        {
         characterList.erase(characterList.begin() + counter[i]);
        }

     }
     }
     if(life==100)
     {
         if(ballx >= 450  && ballx <= 550 && bally >= 50 && bally <= 80)
         {
            reload();
            startCount=0;
            clickCount=-1;
            yPoint=87.5;
            xPoint=37.5;
            transX=0;
            transY=0;
            ballx=0;
            bally=0;
            mov = 0;
            life = 0;
            point = 0;
            picOpen =true;
            picPlay = false;
            picScore = false;
            characterList.clear();
         }
         else if(ballx >= 600  && ballx <= 700 && bally >= 50 && bally <= 80)
         {
            reload();
            startCount=0;
            clickCount=1;
            yPoint=87.5;
            xPoint=37.5;
            transX=0;
            transY=0;
            ballx=0;
            bally=0;
            mov = 0;
            life = 0;
            point = 0;
            picOpen =false;
            picPlay = true;
            picScore = false;
            characterList.clear();
         }
     }
}
void loadPlay_Background()
{
    image = loadBMP("desert_BG.bmp");
        ground_textureId = loadTexture(image);
        delete image;

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ground_textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0, 0.0);
            glVertex2f(0,0);
            glTexCoord2f(3.0, 0.0);
            glVertex2f(1200,0);
            glTexCoord2f(3.0, 1.0);
            glVertex2f(1200,600);
            glTexCoord2f(0.0, 1.0);
            glVertex2f(0,600);
        glEnd();
}
void load_initPic()
{
    image = loadBMP("Cover1.bmp");
        ground_textureId = loadTexture(image);
        delete image;

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ground_textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0, 0.0);
            glVertex2f(0,0);
            glTexCoord2f(1.0, 0.0);
            glVertex2f(1200,0);
            glTexCoord2f(1.0, 1.0);
            glVertex2f(1200,600);
            glTexCoord2f(0.0, 1.0);
            glVertex2f(0,600);
        glEnd();
}
void load_gameOverPic()
{
    image = loadBMP("gameOver.bmp");
        ground_textureId = loadTexture(image);
        delete image;

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ground_textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0, 0.0);
            glVertex2f(0,0);
            glTexCoord2f(1.0, 0.0);
            glVertex2f(1200,0);
            glTexCoord2f(1.0, 1.0);
            glVertex2f(1200,600);
            glTexCoord2f(0.0, 1.0);
            glVertex2f(0,600);
        glEnd();
        Sprint(500,560,yourScoreTxt,3);
        stringstream ss;
        ss<<point<<endl;
        string scoreValue = ss.str();
        int len = scoreValue.length();
        char scrvalue[len];
         for(int i=0;i<len;i++)
        {
            scrvalue[i] = scoreValue[i];
        }
        Sprint(600,560,scrvalue,3);
        //Sprint(600,500,scrvalue,1);
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(450,50);
        glVertex2f(550,50);
        glVertex2f(550,80);
        glVertex2f(450,80);
        glEnd();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(600,50);
        glVertex2f(700,50);
        glVertex2f(700,80);
        glVertex2f(600,80);
        glEnd();
        glPopMatrix();
        Sprint(454,57,mainMenuTxt,2);
        Sprint(604,57,playAgainTxt,2);
//        vector<string> strlist;
//        ///string to int
//       // string a = "25";
//        //int b = atoi(a.c_str());
//        ///int to string
////        int a = 10;
////        stringstream ss;
////        ss << a;
////        string str = ss.str();
//        ///reading
//        string line;
//        ifstream myfile ("Scores.txt");
//        if (myfile.is_open())
//        {
//            while ( getline (myfile,line) )
//            {
//                strlist.push_back(line);
//            }
//            myfile.close();
//        }
//        int track = 99;
//        string name1 = " ";
//        if(!name1.compare(" "))
//        {
//            write = true;
//        }
//        for(int i=0;i<strlist.size();i++)
//        {
//            vector<string> tmpList = explode(strlist[i],"-");
//            int scr = atoi(tmpList[1].c_str());
//            if(point>scr && pause==false)
//            {
//                pause = true;
//                AllocConsole();
//                cout<<"Enter your name:";
//                cin>>name1;
//                track = i;
//
//
//            }
//        }
//        ///writing
//        vector<string> finalList;
//        if(track!=99 && pause && write)
//        {
//            write = false;
//            for(int i=0;i<strlist.size();i++)
//            {
//                if(i==track)
//                {
//                    stringstream ss;
//                    ss << point;
//                    string myPoint = ss.str();
//                    string myLine = name1+"-"+myPoint;
//                    finalList.push_back(myLine);
//
//                }
//                finalList.push_back(strlist[i]);
//
//            }
//            ofstream myfile ("Scores.txt");
//            if (myfile.is_open())
//            {
//                for(int i=0; i<finalList.size();i++)
//                {
//                    myfile<<finalList[i]<<"\n";
//                }
//                myfile.close();
//            }
//        }







}
void load_scorePic()
{
    image = loadBMP("HighScoreBack.bmp");
        ground_textureId = loadTexture(image);
        delete image;

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ground_textureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0, 0.0);
            glVertex2f(0,0);
            glTexCoord2f(1.0, 0.0);
            glVertex2f(1200,0);
            glTexCoord2f(1.0, 1.0);
            glVertex2f(1200,600);
            glTexCoord2f(0.0, 1.0);
            glVertex2f(0,600);
        glEnd();
}
int noOfEnemy(int n)
{
    return 1200/n;
}
void drawCursor()
{
    /// glScalef(0.4,0.4,0.0);
	 glTranslatef((float)transX, (float)transY,0.0);
	 //cout<<(float)ballx/200<<" "<<(float)bally/200<<endl;
     ///#####Cursor#######
     //glScalef(0.8,0.8,0);
        glColor3ub(0,0,255);
    glBegin(GL_LINES);
    ///top left
    //glColor3ub(0,0,255);
    glVertex2f(25,100);
    glVertex2f(25,90);
    glVertex2f(25,100);
    glVertex2f(35,100);
    ///top right
    glVertex2f(50,100);
    glVertex2f(50,90);
    glVertex2f(50,100);
    glVertex2f(40,100);
///bottom right
    glVertex2f(50,85);
    glVertex2f(50,75);
    glVertex2f(50,75);
    glVertex2f(40,75);
    ///bottom left
    glVertex2f(25,85);
    glVertex2f(25,75);
    glVertex2f(25,75);
    glVertex2f(35,75);
    glEnd();
    glBegin(GL_QUADS);
    /// - of +
    glVertex2f(30,86.5);
    glVertex2f(45,86.5);
    glVertex2f(45,88.5);
    glVertex2f(30,88.5);
    glEnd();
    glBegin(GL_QUADS);
    /// | of +
    glVertex2f(36.5,95);
    glVertex2f(36.5,80);
    glVertex2f(38.5,80);
    glVertex2f(38.5,95);
    glEnd();
    ///#####Cursor#######end
}
void drawLifeBar(int p)
{
    int length = 348-22;
    int currentLife = ((p*1.0)/100)*length;
    int x = 348-currentLife;
    glPushMatrix();


    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(20,580);
    glVertex2f(350,580);
    glVertex2f(350,550);
    glVertex2f(20,550);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(22,578);
    glVertex2f(x,578);
    glVertex2f(x,552);
    glVertex2f(22,552);
    glEnd();
    glPopMatrix();
}
void drawMagzin()
{

    glPushMatrix();
    //MainAsh
    glScalef(0.4,0.4,0.0);
    glTranslatef(0,-150,0);
glColor3ub(200,200,200);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=70;
		float x = r * cos(A)+210;
		float y = r * sin(A)+310;
		glVertex2f(x,y);
	}

	glEnd();
//MainBlack
glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=70;
		float x = r * cos(A)+200;
		float y = r * sin(A)+300;
		glVertex2f(x,y);
	}

	glEnd();

//1
if(bullet1)
   glColor3ub(0,255,255);
   else
    glColor3ub(100,100,100);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=15;
		float x = r * cos(A)+175;
		float y = r * sin(A)+340;
		glVertex2f(x,y);
	}

	glEnd();
//2
if(bullet2)
   glColor3ub(0,255,255);
   else
    glColor3ub(100,100,100);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=15;
		float x = r * cos(A)+230;
		float y = r * sin(A)+340;
		glVertex2f(x,y);
	}

	glEnd();
//3
if(bullet3)
   glColor3ub(0,255,255);
   else
    glColor3ub(100,100,100);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=15;
		float x = r * cos(A)+160;
		float y = r * sin(A)+300;
		glVertex2f(x,y);
	}

	glEnd();
//4
if(bullet4)
   glColor3ub(0,255,255);
   else
    glColor3ub(100,100,100);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=15;
		float x = r * cos(A)+245;
		float y = r * sin(A)+300;
		glVertex2f(x,y);
	}

	glEnd();

	//5
	if(bullet5)
   glColor3ub(0,255,255);
   else
    glColor3ub(100,100,100);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=15;
		float x = r * cos(A)+175;
		float y = r * sin(A)+260;
		glVertex2f(x,y);
	}

	glEnd();
//6
if(bullet6)
   glColor3ub(0,255,255);
   else
    glColor3ub(100,100,100);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=15;
		float x = r * cos(A)+230;
		float y = r * sin(A)+260;
		glVertex2f(x,y);
	}

	glEnd();

    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y) {
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
      case 'r':
          PlaySound("reload.wav",NULL,SND_FILENAME|SND_ASYNC);
        reload();
        break;
      case 's':     // ESC key
         //picOpen=false;
         //picScore=false;
         //picPlay=true;

         break;
   }
}
void myDisplay(void)
{

glClear (GL_COLOR_BUFFER_BIT);
    if(picOpen)
    {
        pause = false;
        load_initPic();
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(1080,350);
        glVertex2f(1180,350);
        glVertex2f(1180,380);
        glVertex2f(1080,380);
        glEnd();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(1080,300);
        glVertex2f(1180,300);
        glVertex2f(1180,330);
        glVertex2f(1080,330);
        glEnd();
        glBegin(GL_QUADS);
        glEnd();
        glPopMatrix();
        Sprint(1084,360,NewGameTxt,2);
        Sprint(1084,310,ScoreTxt,2);
    }
    else if(picScore)
    {
        load_scorePic();
        pause = false;
    }
    else if(life == 100)
    {
        //life=0;
        load_gameOverPic();

    }
    else if(picPlay)
    {
        pause = false;
       // cout<<bullet1<<bullet2<<bullet3<<bullet4<<bullet5<<bullet6<<endl;
        if(startCount==0)
        {
            reload();
            startCount++;
        }
        loadPlay_Background();
        drawLifeBar(life);
        drawMagzin();
        Sprint(360,560,text,1);
        Sprint(1050,560,PointTxt,1);
        stringstream ss;
        ss<<point<<endl;
        string scoreValue = ss.str();
        int len = scoreValue.length();
        char scrvalue[len];
         for(int i=0;i<len;i++)
        {
            scrvalue[i] = scoreValue[i];
        }
        if(point>0)
            Sprint(1150,560,scrvalue,1);
        //if(creation)
        if(emptyMagzin())
        {
            Sprint(100,100,reloadTxt,1);
        }
        int cTime = currentTime;
        if(characterList.empty())
        {
            int n = noOfEnemy(5);
            for(int i=1;i<=5;i++)
            {
                Character c1;
                c1.moveXmin = (i*n)-n+1;
                c1.moveXmax = (i*n)-1;
                c1.timeToVisible = random(cTime,cTime+4);
                characterList.push_back(c1);
            }
            creation = false;
        }
        vector <int> c;
          int t = currentTime;
        for(int i=0;i<characterList.size();i++)
        {
            characterList[i].draw(((characterList[i].movingValue+characterList[i].moveXmin)*100)/30);
            characterList[i].makeVisible();
            if(t >= characterList[i].timeToVisible + 4 || characterList[i].firing)
            {

                characterList[i].timeToVisible = t;
                Target_star t1;
                t1.draw(characterList[i].xGunPoint, characterList[i].yGunPoint);
                c.push_back(i);
                ///soundHandle.enemyShoot();
                if(characterList[i].holdFire == 10)
                {
                    t1.playFireSound();
                }
                characterList[i].holdFire--;
                //Targets.push_back(t1);
            }
        }

        if(!c.empty())
        {
            for(int i=0;i<c.size();i++)
            {
                characterList[c[i]].firing = true;
            }
        }
        countHoldFire++;

            for(int i=0;i<c.size();i++)
            {
                if(characterList[c[i]].holdFire==0)
                {
                    characterList[c[i]].firing = false;
                    characterList[c[i]].holdFire = 10;
                    if(life<100)
                        life += 10;
                }
            }
            //if(countHoldFire == 500)
                c.clear();


//        shootCursor cursor;
//        cursor.draw();
        //glBegin(GL_POINTS);

		//glVertex3f((float)ballx/200, (float)bally/200, 0.0);



	//glEnd();

    }
    glPushMatrix();
    drawCursor();
    glPopMatrix();

glFlush ();
glutPostRedisplay();

}
void update(int value)
{
    if(picPlay)
        currentTime += (float)((20*1.0)/1000);
    for(int i=0;i<characterList.size();i++)
    {
        characterList[i].timeCount = currentTime;
        if(characterList[i].forWardMoving)
        {
            characterList[i].movingValue += 2;
        }
        else if(characterList[i].backWardMoving)
        {
            characterList[i].movingValue -= 2;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20,update,0);
}
void myInit(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluOrtho2D(0.0, 1200.0, 0.0, 600.0);

}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1200, 600);
glutInitWindowPosition (200, 150);
glutCreateWindow ("Hello World");
FreeConsole();
glutSetCursor(GLUT_CURSOR_NONE);
glutDisplayFunc(myDisplay);
glutKeyboardFunc(keyboard);
glutMouseFunc(mouse);
glutPassiveMotionFunc(mouseMotion);
glutTimerFunc(20,update,0);

//glutTimerFunc(1000,countTime,0);
myInit ();
glutMainLoop();

return 0; /* ISO C requires main to return int. */
}
