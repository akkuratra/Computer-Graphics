#include <math.h>
#include <time.h>
#include <GL/glut.h>
#define PI 3.14159265
double x,y,k;
int count=0;
void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void init(){
		glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void ifDisplay()
{
			//yellow sun
  		glColor3f(1.0,1.0,0.0);
	    glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(70 +cos(i) *35, 420+sin(i)*35);
				}
			glEnd();
			//tree branches
			glBegin(GL_TRIANGLES);
    glColor4f(0.8,0.84,0.96,1.0);
        glVertex2i(528,300);
        glVertex2i(544,300);
        glVertex2i(540,265);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor4f(0.8,0.84,0.96,1.0);
        glVertex2i(551,300);
        glVertex2i(574,300);
        glVertex2i(554,275);
    glEnd();
    //smoke
    glColor3f(0.5,0.5,0.5);
   	  glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(350 +cos(i) *35, 400+sin(i)*10);
				}
			glEnd();
			glColor3f(0.5,0.5,0.5);
   	  glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(360 +cos(i) *20, 409+sin(i)*10);
				}
			glEnd();
			glColor3f(0.5,0.5,0.5);
   	  glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(395 +cos(i) *10, 410+sin(i)*5);
				}
			glEnd();
}
void elseDisplay()
{
			//white sun
  		glColor3f(1.0,1.0,1.0);
   	  glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(70 +cos(i) *35, 420+sin(i)*35);
				}
			glEnd();
			//cloud
			glColor4f(0.6,0.6,0.6,1.0);
			glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(80 +cos(i) *45, 380+sin(i)*25);
				}
			glEnd();
			glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(90 +cos(i) *25, 405+sin(i)*25);
				}
			glEnd();
			glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(120 +cos(i) *25, 410+sin(i)*25);
				}
			glEnd();
			glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(130 +cos(i) *40, 385+sin(i)*25);
				}
			glEnd();
			//tree branches
			glBegin(GL_TRIANGLES);
    	glColor4f(0.4,0.3,0.5,1.0);
        glVertex2i(528,300);
        glVertex2i(544,300);
        glVertex2i(540,265);
    	glEnd();
    	glBegin(GL_TRIANGLES);
    	glColor4f(0.4,0.3,0.5,1.0);
        glVertex2i(551,300);
        glVertex2i(574,300);
        glVertex2i(554,275);
    	glEnd();
}
void hut(){
    glLineWidth(3);
    glPointSize(2);
    
    if(count%2==0)
    {
    	glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.8,0.84,0.96,1.0);
			
		}
  	else
  	{
  		glClear(GL_COLOR_BUFFER_BIT);
  		glClearColor(0.4,0.3,0.5,1.0);
  		
		}
		
    glBegin(GL_TRIANGLES);
    //triangle
		glColor4f(0.5,0.3,0.3,1);
        glVertex2i(20,250);
        glVertex2i(100,350);
        glVertex2i(180,250);
    glEnd();
    //top roof
    glBegin(GL_POLYGON);
		glColor4f(0.9,0.7,0.1,1);
        glVertex2i(100,350);
        glVertex2i(350,350);
        glVertex2i(450,250);
        glVertex2i(180,250);
    glEnd();
    //chimney
    glBegin(GL_POLYGON);
		glColor4f(0.3,0.3,0.3,1);
        glVertex2i(300,350);
        glVertex2i(330,350);
        glVertex2i(330,390);
        glVertex2i(300,400);
    glEnd();
    //bottom left
    glBegin(GL_POLYGON);
		glColor4f(0.5,0.3,0.3,1);
        glVertex2i(20,250);
        glVertex2i(180,250);
        glVertex2i(180,40);
        glVertex2i(20,40);
    glEnd();
    //bottom right
    glBegin(GL_POLYGON);
		glColor4f(0.5,0.5,0.3,1);
        glVertex2i(450,250);
        glVertex2i(180,250);
        glVertex2i(180,40);
        glVertex2i(450,40);
    glEnd();
    //door
    glBegin(GL_POLYGON);
		glColor4f(0.2,0.2,0.2,1);
        glVertex2i(50,40);
        glVertex2i(150,40);
        glVertex2i(150,200);
        glVertex2i(50,200);
    glEnd();
    //door knob
    glColor3f(0.7,0.7,0.7);
   	  glBegin(GL_POLYGON);
				for(double i =0; i < 2* 3.14; i+=3.14/30)
				{
					glVertex2f(130 +cos(i) *5, 130+sin(i)*5);
				}
			glEnd();
    //window
    glBegin(GL_LINE_LOOP);
		glColor4f(0.2,0.2,0.2,1);
        glVertex2i(210,200);
        glVertex2i(420,200);
        glVertex2i(420,90);
        glVertex2i(210,90);
    glEnd();
    glBegin(GL_LINES);
		glColor4f(0.2,0.2,0.2,1);
        glVertex2i(315,200);
        glVertex2i(315,90);
        glVertex2i(210,145);
        glVertex2i(420,145);
    glEnd();
    
    //tree
    glBegin(GL_POLYGON);
		glColor4f(0.4,0.2,0.1,1);
        glVertex2i(520,40);
        glVertex2i(500,30);
        glVertex2i(580,40);
        glVertex2i(580,300);
        glVertex2i(520,300);
    glEnd();
    
    //grass
    glBegin(GL_POLYGON);
		glColor4f(0.2,0.8,0.3,1);
        glVertex2i(0,40);
        glVertex2i(1000,40);
        glVertex2i(1000,0);
        glVertex2i(0,0);
    glEnd();
    //road 
    glBegin(GL_POLYGON);
		glColor4f(0.4,0.4,0.4,1);
        glVertex2i(20,40);
        glVertex2i(180,40);
        glVertex2i(160,0);
        glVertex2i(0,0);
    glEnd();
    
    //dark grass 
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(190,25);
        glVertex2i(195,20);
        glVertex2i(195,20);
        glVertex2i(200,25);
    glEnd();
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(260,25);
        glVertex2i(265,20);
        glVertex2i(265,20);
        glVertex2i(270,25);
    glEnd();
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(330,35);
        glVertex2i(335,30);
        glVertex2i(335,30);
        glVertex2i(340,35);
    glEnd();
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(290,35);
        glVertex2i(295,30);
        glVertex2i(295,30);
        glVertex2i(300,35);
    glEnd();
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(390,15);
        glVertex2i(395,10);
        glVertex2i(395,10);
        glVertex2i(400,15);
    glEnd();
     glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(230,15);
        glVertex2i(235,10);
        glVertex2i(235,10);
        glVertex2i(240,15);
    glEnd();
     glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(230,35);
        glVertex2i(235,30);
        glVertex2i(235,30);
        glVertex2i(240,35);
    glEnd();
    
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(330,15);
        glVertex2i(335,10);
        glVertex2i(335,10);
        glVertex2i(340,15);
    glEnd();
    glBegin(GL_LINES);
		glColor4f(0,0.5,0.2,1);
        glVertex2i(370,25);
        glVertex2i(375,20);
        glVertex2i(375,20);
        glVertex2i(380,25);
    glEnd();
    glBegin(GL_LINES);
    glColor4f(0,0.5,0.2,1);
        glVertex2i(300,15);
        glVertex2i(305,10);
        glVertex2i(305,10);
        glVertex2i(310,15);
    glEnd();
    //leaves for tree
    //dark green
    glColor4f(0,0.5,0.2,1);
       glBegin(GL_POLYGON);
				for(double i =0; i < 2*3.14; i+=3.14/30)
				{
					glVertex2f(540+cos(i) *90, 358+sin(i)*70);
				}
			glEnd();
			//light green
    glColor4f(0,0.7,0.3,1);
       glBegin(GL_POLYGON);
				for(double i =0; i < 2*3.14; i+=3.14/30)
				{
					glVertex2f(540+cos(i) *90, 408+sin(i)*70);
				}
			glEnd();
    
    
		//tree
    glBegin(GL_POLYGON);
		glColor4f(0.4,0.2,0.1,1);
        glVertex2i(520,40);
        glVertex2i(500,30);
        glVertex2i(580,40);
        glVertex2i(580,300);
        glVertex2i(520,300);
    glEnd();
    //tree roots
    glBegin(GL_POLYGON);
		glColor4f(0.4,0.2,0.1,1);
        glVertex2i(580,40);
        glVertex2i(600,25);
        glVertex2i(560,40);
    glEnd();
    
    //tree branch
    if(count%2==0)
		{
			elseDisplay();
		}
		else{
			ifDisplay();
		}
    glBegin(GL_TRIANGLES);
    glColor4f(0.4,0.2,0.1,1);
        glVertex2i(520,300);
        glVertex2i(510,300);
        glVertex2i(520,275);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor4f(0.4,0.2,0.1,1);
        glVertex2i(580,300);
        glVertex2i(590,300);
        glVertex2i(580,275);
    glEnd();
    glFlush();
}
void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		++count;
		hut();
	}
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Hut Program");
    init();
    glutDisplayFunc(hut);
    glutMouseFunc(mouse);
    
    glutMainLoop();
    return 0;
}
