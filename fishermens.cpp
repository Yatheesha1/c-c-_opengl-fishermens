//g++ 'fishing.cpp' -lGL -lGLU -lglut

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

GLfloat a=0,b=0,m=0,c=0;
int k=0;
int seq=0;

void rgb(int r,int g,int b)
{
  glColor3f(r/255.0,g/255.0,b/255.0);	
}

void displaytext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);   
}

void start()
{
     displaytext(0.3,0.7,0.6,"CGV MINI PROJECT",460,320);
     displaytext(0.3,0.7,0.6,"________________",460,310);
     displaytext(0.3,0.7,0.6,"FISHER MEN ON THEIR DUTY",425,280);
     displaytext(0.3,0.7,0.6,"4SF14CS135 & 4SF14CS145",430,240);
     if(k)
      displaytext(0.9,0.3,0.7,"Press Cover(c/C) Night(n/N) Day(d/D)!",390,100);
     k=~k;
     glutPostRedisplay();
     glutSwapBuffers();
}

void ship()
{	
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_POLYGON);
  glVertex2f(48,376);
  glVertex2f(48,408);
  glVertex2f(52,410);
  glVertex2f(53,376);
  glEnd();	

  glColor3f(0.1,0.1,0.1);
  glBegin(GL_POLYGON);
  glVertex2f(28,366);
  glVertex2f(28,378);
  glVertex2f(100,378);
  glVertex2f(100,366);
  glEnd();	
  
  glPointSize(5.5);
  glColor3f(1,1,1);
  glBegin(GL_POINTS);
  glVertex2f(37,373);
  glColor3f(1,0,0);
  glVertex2f(50,408);
  glEnd();
	
  glColor3f(0.2,0.2,0.2);
  glBegin(GL_POLYGON);
  glVertex2f(30,340);
  glVertex2f(20,370);
  glVertex2f(230,370);
  glVertex2f(210,340);
  glEnd();  
}

void fishes(int x,int y,int z)
{
 glPushMatrix();
 glScaled(0.8,0.8,0.8);
 glTranslatef(z,0,0);
 glColor3f(0.5,0.5,0.5);
 glBegin(GL_POLYGON);
 glVertex2f(50+x,250+y);
 glVertex2f(45+x,260+y);
 glVertex2f(55+x,255+y);
 glVertex2f(55+x,245+y);
 glVertex2f(45+x,240+y);
 glVertex2f(50+x,250+y);
 glEnd();

 glBegin(GL_POLYGON);
 glVertex2f(55+x,255+y);
 glVertex2f(65+x,260+y);
 glVertex2f(75+x,265+y);
 glVertex2f(85+x,265+y);
 glVertex2f(90+x,260+y);
 glVertex2f(95+x,250+y);
 glVertex2f(92+x,245+y);
 glVertex2f(85+x,242+y);
 glVertex2f(75+x,240+y);
 glVertex2f(65+x,240+y);
 glVertex2f(55+x,245+y);
 glVertex2f(55+x,255+y);
 glEnd();

 glColor3f(0,0,0);
 glLineWidth(1);//mouth	
 glBegin(GL_LINE_STRIP);
 glVertex2f(95+x,250+y);
 glVertex2f(90+x,250+y);
 glVertex2f(82+x,252+y);
 glEnd();
 
 glPointSize(2.5);//eye
 glColor3f(0,0,0);
 glBegin(GL_POINTS);
 glVertex2f(90+x,253+y);
 glEnd();
 
 glPopMatrix();
}

void DrawSegment(float cx, float cy, float r, int degree1,int degree2,int shade) 
{ 
	int num_segments=360;
	if(shade==0)
	  glBegin(GL_LINE_LOOP); 
	if(shade==1)
	  glBegin(GL_POLYGON);
	for(int i = degree1; i < degree2; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void sky(int t)
{
  //sky
  if(t==0 || t==1)
    glColor3f(0.4,0.4,0.5);
  if(t==2)  
    glColor3f(0.4,0.7,1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0,350);
  glVertex2f(0,700);
  glVertex2f(1100,700);
  glVertex2f(1100,350);
  glEnd();
}

void sea()
{
  //sea
  glBegin(GL_POLYGON);
  glColor3f(0.0,0.627,0.627);
  if(seq==2)
   rgb(2, 89, 99);
  glVertex2f(0,0);
  glVertex2f(1100,0);
  glColor3f(0.0,0.2,0.2);
   if(seq==2)
    rgb(5, 154, 170);
  glVertex2f(1100,350);
  glVertex2f(0,350);
  glEnd();
}

void stars()
{
  glPointSize(3);//eye
  glColor3f(1,1,1);
  glBegin(GL_POINTS);
  int p[]={0,150,300,100,500,250,800,50,1000,250,800,200};
  for(int i=0;i<sizeof(p);i+=2)
    glVertex2f(90+p[i],400+p[i+1]);
  glEnd();
}

void seashore()
{
  glBegin(GL_POLYGON);
  int p[]={650,350,690,400,780,500,830,510,880,450,950,400,1000,470,1100,420,1100,350,650,350};
  for(int j=0;j<20;j+=2)
  {
	rgb(147, 153, 126); 
    glVertex2f(p[j],p[j+1]);
  }
  glEnd();

  glBegin(GL_POLYGON);
  int q[]={1100,350,650,350,680,300,700,250,700,230,750,220,850,150,1000,100,1100,50};
  for(int j=0;j<18;j+=2)
  {
	rgb(56, 99, 22);
    glVertex2f(q[j],q[j+1]);
  }
  glEnd();
}

void man()
{
  glColor3f(0,0,0);
  DrawSegment(200,408,8,0,360,1);	//head
  glBegin(GL_POLYGON);//body
  glVertex2f(190,400);
  glVertex2f(210,400);
  glVertex2f(210,378);
  glVertex2f(190,378);
  glEnd();
  
  glBegin(GL_POLYGON);//left leg
  glVertex2f(191,378);
  glVertex2f(192,368);
  glVertex2f(197,368);
  glVertex2f(198,378);
  glEnd();
  
  glBegin(GL_POLYGON);//right leg
  glVertex2f(202,378);
  glVertex2f(203,368);
  glVertex2f(208,368);
  glVertex2f(209,378);
  glEnd();
  
  glColor3f(0,0,0);
  glLineWidth(6);//hand
  glBegin(GL_LINE_STRIP);
  glVertex2f(208,396);
  glVertex2f(216,403);
  glEnd();
  
  //if(seq==1 || (seq==2 && a<490))
  {
  glLineWidth(2);//stick	
  glBegin(GL_LINE_STRIP);
  glVertex2f(216,403);
  glVertex2f(240,408);
  glEnd();
  
  glColor3f(0.5,0.5,0.5);
  glLineWidth(1);//rope	
  glBegin(GL_LINE_STRIP);
  glVertex2f(240,408);
  glVertex2f(240,250);
  glVertex2f(235,250);
  glEnd();
  }
  
}

void process()
{
	if(seq==1 || (seq==2 && a<490))
	  a+=0.5;
    c+=0.5;
    b+=0.7;
	if(a>1100)
	 a=-600;
	if(b>1600)
	 b=-300;
	if(c>1100) 
	 c=-600;
	  
    glPushMatrix();  
	fishes(0,0,b);
	fishes(-200,-135,b);
	fishes(-300,-100,b);  
	fishes(100,-150,b);
	fishes(-200,-65,b);
	glPushMatrix();
	
	if(seq==2)
      seashore();	
	glPushMatrix();
	glTranslatef(a,-50,0);
	ship();
	man();
	glTranslatef(230,-280,0);
	glScaled(1.3,1.3,1.3);
	ship();
	man();
	glPopMatrix();
}

//moon
void moon()	
{
  m+=0.1;
  glPushMatrix();
  glTranslatef(0,m,0);
  glColor3f(0.9,1.0,1.0);
  DrawSegment(200,500,40,0,360,1);
  glPopMatrix();
}
//sun
void sun()	
{
  m+=0.1;
  glPushMatrix();
  glTranslatef(0,m,0);
  glColor3f(1.0,1.0,0.0);
  DrawSegment(900,500,40,0,360,1);
  glPopMatrix();
}

//cloud
void cloud(int x,int y,int t)
{
  glPushMatrix();
  glTranslatef(c/1.5,0,0);
  if(t==1)
    glColor3f(0.82,0.82,0.82);
  if(t==2)
    glColor3f(1,1,1);
  if(t!=0)  
  {
    DrawSegment(160+x,350+y,20,0,360,1);
    DrawSegment(200+x,350+y,35,0,360,1);
    DrawSegment(225+x,350+y,35,0,360,1);
    DrawSegment(265+x,350+y,20,0,360,1);
    glPopMatrix();
  }  
}

void myinit()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glPointSize(1.0);
  gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void keys(unsigned char key,int x,int y)
{
	if(key=='n'||key=='N')
		seq=1;
	if(key=='d'||key=='D')
		seq=2;
	if(key=='c'||key=='C')
		seq=0;	
	a=0;
	b=0;
	m=0;			
}

void displayfst()
{
  glClear(GL_COLOR_BUFFER_BIT);
  sea();
  sky(seq);
  if(seq==0)
  {
	start();
  }
  if(seq==1)
  {
    moon();
    stars();
    cloud(100,200,seq);
    process();
  }
  if(seq==2)
  {
	sun();
    cloud(100,200,seq);
    process();  
  }
  glutPostRedisplay();
  glutSwapBuffers();
}

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(1100.0,700.0);
  glutInitWindowPosition(0,0);
  glutCreateWindow("FISHING");
  glutKeyboardFunc(keys);
  myinit();
  glutDisplayFunc(displayfst);
  glutMainLoop();
  return 0;
}
