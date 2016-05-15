//A very imortant point to notice here is that whenever the camera comes very close to the object (as in this case a house), it will pass that particular wall into the insides of the house*/



/*
Things yet to be updated:
1-The camera seems to be the light source. Make the sun the light source.
2-Alignment of the sun.
3-Make the sun go from east to west and move the light along with it.
*/


#include<GL/glut.h>
GLfloat pillar_front[][3]={
{0.85,0.00,0.18},{0.85,0.00,0.14},
{0.90,0.00,0.14},{0.90,0.00,0.18},
{0.85,0.40,0.18},{0.85,0.40,0.14},
{0.90,0.40,0.14},{0.90,0.40,0.18}};

GLfloat pillar_back_right[][3]={
{0.85,0.00,-0.53},{0.85,0.00,-0.49},
{0.90,0.00,-0.49},{0.90,0.00,-0.53},
{0.85,0.40,-0.53},{0.85,0.40,-0.49},
{0.90,0.40,-0.49},{0.90,0.40,-0.53}};

GLfloat pillar_back_left[][3]={
{0.10,0.00,-0.53},{0.10,0.00,-0.49},
{0.15,0.00,-0.49},{0.15,0.00,-0.53},
{0.10,0.45,-0.53},{0.10,0.45,-0.49},
{0.15,0.45,-0.49},{0.15,0.45,-0.53}};

void pillars(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3fv(pillar_front[a]);
	glVertex3fv(pillar_front[b]);
	glVertex3fv(pillar_front[c]);
	glVertex3fv(pillar_front[d]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3fv(pillar_back_right[a]);
	glVertex3fv(pillar_back_right[b]);
	glVertex3fv(pillar_back_right[c]);
	glVertex3fv(pillar_back_right[d]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3fv(pillar_back_left[a]);
	glVertex3fv(pillar_back_left[b]);
	glVertex3fv(pillar_back_left[c]);
	glVertex3fv(pillar_back_left[d]);
	glEnd();
}

void vertices()
{		
	glBegin(GL_QUADS);//left wall
		glColor3f(0.6,0.6,0.0);
		glNormal3f(-1.0,0.0,0.0);
		glVertex3f(-0.20,0.00,0.50);
		glVertex3f(-0.20,0.40,0.50);
		glVertex3f(-0.20,0.40,0.0);
		glVertex3f(-0.20,0.00,0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);//left wall
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.20,0.00,0.50);
		glVertex3f(-0.20,0.395,0.50);
		glVertex3f(-0.20,0.395,0.00);
		glVertex3f(-0.20,0.00,0.00);
	glEnd();

	glBegin(GL_QUADS);//right wall
		glColor3f(0.2,0.3,0.4);
		glNormal3f(1.0,0.0,0.0);
		glVertex3f(0.50,0.00,0.50);
		glVertex3f(0.50,0.40,0.50);
		glVertex3f(0.50,0.40,0.00);
		glVertex3f(0.50,0.00,0.00);
	glEnd();

	glBegin(GL_LINE_LOOP);//right wall
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.50,0.00,0.50);
		glVertex3f(0.50,0.395,0.50);
		glVertex3f(0.50,0.395,0.00);
		glVertex3f(0.50,0.00,0.00);
	glEnd();

	glBegin(GL_POLYGON);//front of the house
		glColor3f(0.6,0.6,0.0);
		glNormal3f(0.0,0.0,1.0);
		glVertex3f(-0.20,0.00,0.50);//left-bottom corner
		glVertex3f(-0.20,0.40,0.50);//left-top corner
		glVertex3f(0.30,0.50,0.50);//middle-top
		glVertex3f(0.50,0.40,0.50);//right-top corner
		glVertex3f(0.50,0.00,0.50);//right-bottom corner
	glEnd();

	glBegin(GL_POLYGON);//back of the house
		glColor3f(0.2,0.3,0.4);
		glNormal3f(0.0,0.0,-1.0);
		glVertex3f(-0.20,0.00,0.00);//left-bottom corner
		glVertex3f(-0.20,0.40,0.00);//left-top corner
		glVertex3f(0.30,0.50,0.00);//middle-top
		glVertex3f(0.50,0.40,0.00);//right-top corner
		glVertex3f(0.50,0.00,0.00);//right-bottom corner
	glEnd();

	glBegin(GL_QUADS);//roof-left
		glColor3f(1.0,0.0,0.1);
		glVertex3f(-0.25,0.39,0.53);//roof-left_front
		glVertex3f(-0.25,0.39,-0.05);//roof-left_back
		glVertex3f(0.30,0.50,-0.05);//roof-middle_back
		glVertex3f(0.30,0.50,0.53);//roof-middle_front
	glEnd();

	glBegin(GL_LINE_LOOP);//roof-left
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.25,0.39,0.53);//roof-left_front
		glVertex3f(-0.25,0.39,-0.05);//roof-left_back
		glVertex3f(0.30,0.50,-0.05);//roof-middle_back
		glVertex3f(0.30,0.50,0.53);//roof-middle_front
	glEnd();

	glBegin(GL_QUADS);//roof-right
		glColor3f(0.81176,0.3254,0.0);
		glVertex3f(0.55,0.3755,0.53);//right_front
		glVertex3f(0.55,0.3755,-0.05);//right_back
		glVertex3f(0.30,0.50,-0.05);//middle_back
		glVertex3f(0.30,0.50,0.53);//middle_front
	glEnd();

	glBegin(GL_LINE_LOOP);//roof-right
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.55,0.3755,0.53);//right_front
		glVertex3f(0.55,0.3755,-0.05);//right_back
		glVertex3f(0.30,0.50,-0.05);//middle_back
		glVertex3f(0.30,0.50,0.53);//middle_front
	glEnd();

	glBegin(GL_QUADS);//base
		glColor3f(0.2,0.3,0.4);
		glNormal3f(0.0,-1.0,0.0);
		glVertex3f(-0.20,0.00,0.50);//left-front corner
		glVertex3f(-0.20,0.00,0.00);//left-back corner
		glVertex3f(0.50,0.00,0.00);//right-back corner
		glVertex3f(0.50,0.00,0.50);//right-front corner
	glEnd();


	glBegin(GL_LINE_LOOP);//base
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.20,0.00,0.50);//left-front corner
		glVertex3f(-0.20,0.00,0.00);//left-back corner
		glVertex3f(0.50,0.00,0.00);//right-back corner
		glVertex3f(0.50,0.00,0.50);//right-front corner
	glEnd();

	glBegin(GL_QUADS);//door
		glColor3f(0.5,0.1,0.3);
		glVertex3f(-0.10,0.00,0.501);//bottom-left corner
		glVertex3f(-0.10,0.20,0.501);//top-left corner
		glVertex3f(0.10,0.20,0.501);//top-right corner
		glVertex3f(0.10,0.00,0.501);//bottom-right corner
	glEnd();	

	glBegin(GL_LINE_LOOP);//door
		glColor3f(0.5,0.1,0.3);
		glVertex3f(-0.10,0.00,0.501);//bottom-left corner
		glVertex3f(-0.10,0.20,0.501);//top-left corner
		glVertex3f(0.10,0.20,0.501);//top-right corner
		glVertex3f(0.10,0.00,0.501);//bottom-right corner
	glEnd();

	glBegin(GL_QUADS);//right window
		glColor3f(0.5,0.1,0.3);
		glVertex3f(0.5001,0.25-0.010,0.102);//back-bottom
		glVertex3f(0.5001,0.35-0.010,0.102);//back-top
		glVertex3f(0.5001,0.35-0.010,0.20);//fronttop
		glVertex3f(0.5001,0.25-0.010,0.20);//front-bottom
	glEnd();

	glBegin(GL_LINE_LOOP);//right window
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.5001,0.25-0.010,0.102);//back-bottom
		glVertex3f(0.5001,0.35-0.010,0.102);//back-top
		glVertex3f(0.5001,0.35-0.010,0.20);//fronttop
		glVertex3f(0.5001,0.25-0.010,0.20);//front-bottom
	glEnd();

	glBegin(GL_QUADS);//left window
		glColor3f(0.5,0.1,0.3);
		glVertex3f(-0.2001,0.34,0.102);//back-bottom
		glVertex3f(-0.2001,0.15,0.102);//back-top
		glVertex3f(-0.2001,0.15,0.40);//front-top
		glVertex3f(-0.2001,0.34,0.40);//front-bottom
	glEnd();

		glBegin(GL_LINE_LOOP);//left window
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.2001,0.34,0.102);//back-bottom
		glVertex3f(-0.2001,0.15,0.102);//back-top
		glVertex3f(-0.2001,0.15,0.40);//front-top
		glVertex3f(-0.2001,0.34,0.40);//front-bottom
	glEnd();


/////////////////////TOP-HOUSE///////////////////////////////////


	glBegin(GL_POLYGON);//front face (top house)
		glColor3f(0.5,0.3,0.5);
		glNormal3f(0.0,0.0,1.0);
		glVertex3f(0.50,0.40,0.25);
		glVertex3f(0.30,0.50,0.25);
		glVertex3f(0.00,0.44,0.25);
		glVertex3f(0.00,0.80,0.25);
		glVertex3f(0.50,0.90,0.25);
		glVertex3f(1.00,0.80,0.25);
		glVertex3f(1.0,0.40,0.25);
	glEnd();

	glBegin(GL_POLYGON);//back face (top house)
		glColor3f(0.5,0.3,0.5);
		glNormal3f(0.0,0.0,-1.0);
		glVertex3f(0.50,0.40,-0.60);
		glVertex3f(0.30,0.50,-0.60);
		glVertex3f(0.00,0.44,-0.60);
		glVertex3f(0.00,0.80,-0.60);
		glVertex3f(0.50,0.90,-0.60);
		glVertex3f(1.00,0.80,-0.60);
		glVertex3f(1.00,0.40,-0.60);
	glEnd();

	glBegin(GL_POLYGON);//base of the top-house (right)
		glColor3f(0.5,0.1,0.0);
		glNormal3f(0.0,-1.0,0.0);
		glVertex3f(1.0,0.40,0.249);
		glVertex3f(0.5,0.40,0.249);
		glVertex3f(0.3,0.5001,0.249);
		glVertex3f(0.3,0.5001,-0.60);
		glVertex3f(0.5,0.4001,-0.60);
		glVertex3f(1.0,0.4001,-0.60);
	glEnd();
	
	glBegin(GL_LINE_LOOP);//base of the top-house (right)
		glColor3f(0.5,0.1,0.0);
		glVertex3f(1.0,0.40,0.249);
		glVertex3f(0.5,0.40,0.249);
		glVertex3f(0.3,0.5001,0.249);
		glVertex3f(0.3,0.5001,-0.60);
		glVertex3f(0.5,0.4001,-0.60);
		glVertex3f(1.0,0.4001,-0.60);
	glEnd();

	glBegin(GL_POLYGON);//base of the top-house (left)
		glColor3f(0.5,0.1,0.0);
		glNormal3f(0.0,-1.0,0.0);
		glVertex3f(0.0,0.44,0.25);
		glVertex3f(0.0,0.44,-0.60);
		glVertex3f(0.3,0.5001,-0.60);
		glVertex3f(0.3,0.5001,0.25);
	glEnd();

	glBegin(GL_LINE_LOOP);//base of the top-house (left)
		glColor3f(0.5,0.1,0.0);
		glVertex3f(0.0,0.44,0.25);
		glVertex3f(0.0,0.44,-0.60);
		glVertex3f(0.3,0.5001,-0.60);
		glVertex3f(0.3,0.5001,0.25);
	glEnd();

	glBegin(GL_QUADS);//left wall of the top_house
		glColor3f(0.5,0.3,0.5);
		glNormal3f(-1.0,0.0,0.0);
		glVertex3f(0.00,0.44,0.25);//bottom front
		glVertex3f(0.00,0.80,0.25);//top front
		glVertex3f(0.00,0.80,-0.60);//top back
		glVertex3f(0.00,0.44,-0.60);//bottom back
	glEnd();

	glBegin(GL_LINE_LOOP);//left wall of the top_house
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.00,0.44,0.25);//bottom front
		glVertex3f(0.00,0.785,0.25);//top front
		glVertex3f(0.00,0.785,-0.60);//top back
		glVertex3f(0.00,0.44,-0.60);//bottom back
	glEnd();

	glBegin(GL_QUADS);//right wall of the top_house
		glColor3f(0.5,0.3,0.5);
		glNormal3f(1.0,0.0,0.0);
		glVertex3f(1.0,0.40,0.25);//bottom front
		glVertex3f(1.0,0.80,0.25);//top front
		glVertex3f(1.0,0.80,-0.60);//top back
		glVertex3f(1.0,0.40,-0.60);//bottom back
	glEnd();

	glBegin(GL_LINE_LOOP);//right wall of the top_house
		glColor3f(0.0,0.0,0.0);
		glVertex3f(1.0,0.40,0.25);//bottom front
		glVertex3f(1.0,0.785,0.25);//top front
		glVertex3f(1.0,0.785,-0.60);//top back
		glVertex3f(1.0,0.40,-0.60);//bottom back
	glEnd();

	glBegin(GL_QUADS);//left roof of the top-house
		glColor3f(1.0,0.0,0.1);
		glVertex3f(-0.05,0.79,0.28);//roof-left_front
		glVertex3f(-0.05,0.79,-0.63);//roof-left_back
		glVertex3f(0.50,0.90,-0.63);//roof-middle_back
		glVertex3f(0.50,0.90,0.28);//roof-middle_front
	glEnd();

	glBegin(GL_LINE_LOOP);//left roof of the top-house
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.05,0.79,0.28);//roof-left_front
		glVertex3f(-0.05,0.79,-0.63);//roof-left_back
		glVertex3f(0.50,0.90,-0.63);//roof-middle_back
		glVertex3f(0.50,0.90,0.28);//roof-middle_front
	glEnd();

	glBegin(GL_QUADS);//right roof of the top house
		glColor3f(0.81176,0.3254,0.0);
		glVertex3f(1.05,0.79,0.28);//top-front
		glVertex3f(1.05,0.79,-0.63);//top-back
		glVertex3f(0.50,0.90,-0.63);//middle_back
		glVertex3f(0.50,0.90,0.28);//middle_front
	glEnd();

	glBegin(GL_LINE_LOOP);//right roof of the top house
		glColor3f(0.0,0.0,0.0);
		glVertex3f(1.05,0.79,0.28);//top-front
		glVertex3f(1.05,0.79,-0.63);//top-back
		glVertex3f(0.50,0.90,-0.63);//middle_back
		glVertex3f(0.50,0.90,0.28);//middle_front
	glEnd();

 //////////////Drawing the pillars///////////////////
	glBegin(GL_POLYGON);
		glColor3f(0.3,0.3,0.3);
		//front_pillar bottom vertices
		pillars(0,1,2,3);//bottom
		pillars(3,2,6,7);//right
		pillars(1,2,6,5);//back
		pillars(0,1,5,4);//left
		//front pillar top vertices
		pillars(4,5,6,7);//top
		pillars(0,3,7,4);//front
	glEnd();
 /////////////////////////////////////////////////////

	glBegin(GL_QUADS);//Top house window (front)
		glColor3f(0.6,0.6,0.0);
		glVertex3f(0.65,0.60,0.2501);//bottom-left corner (Keeping the z-axis 0.0001 forward from the front-face)
		glVertex3f(0.65,0.75,0.2501);//top-left corner
		glVertex3f(0.92,0.75,0.2501);//top-right corner
		glVertex3f(0.92,0.60,0.2501);//bottom-right corner
	glEnd();

	glBegin(GL_LINE_LOOP);//Top house window (front)
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.65,0.60,0.2501);//bottom-left corner (Keeping the z-axis 0.0001 forward from the front-face)
		glVertex3f(0.65,0.75,0.2501);//top-left corner
		glVertex3f(0.92,0.75,0.2501);//top-right corner
		glVertex3f(0.92,0.60,0.2501);//bottom-right corner
	glEnd();

	glBegin(GL_QUADS);//Top house window (left)
		glColor3f(1.0,0.0,0.1);
		glVertex3f(-0.001,0.60,-0.50);//front-down
		glVertex3f(-0.001,0.60,-0.33);//back-down
		glVertex3f(-0.001,0.75,-0.33);//back-top
		glVertex3f(-0.001,0.75,-0.50);//front-top
	glEnd();
	
	glBegin(GL_LINE_LOOP);//Top house window (left)
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-0.001,0.60,-0.50);//front-down
		glVertex3f(-0.001,0.60,-0.33);//back-down
		glVertex3f(-0.001,0.75,-0.33);//back-top
		glVertex3f(-0.001,0.75,-0.50);//front-top
	glEnd();
}
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;
static GLdouble viewer[]={0.0,3.0,8.0};

void init()
{
	float light_diffuse[] = {2.0, 2.0, 0.0, 0.0};
	float light_ambient[] = {0.8, 0.8, 1.0, 0.0};
	float light_position[] = {10.0, 5.0, 5.0, 0.0};
	//The next two line enable some of the the characteristics needed for lighing
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);

 //////////////////////SUN///////////////////////////////
			glColor3f(1.0,0.6,0.0);
    		glutSolidSphere(1.0,20,20);
 ////////////////////////////////////////////////////////

	glScalef(5.0,5.0,5.0);//
	vertices();//calling the vertices function mentioned above
	glFlush();
	glutSwapBuffers();
}

void mouse(int bt, int st, int x, int y)
{
	if(bt==GLUT_LEFT_BUTTON&&st==GLUT_DOWN)
		axis=0;

	if(bt==GLUT_MIDDLE_BUTTON&&st==GLUT_DOWN)
		axis=1;

	if(bt==GLUT_RIGHT_BUTTON&&st==GLUT_DOWN)
		axis=2;

	theta[axis]+=1;
	if(theta[axis]>360)
		theta[axis]-=360;
	display();
}

void keys(unsigned char key, int x, int y)
{
	if(key=='x') viewer[0]-=1;
	if(key=='X') viewer[0]+=1;
	if(key=='s') viewer[1]-=1;
	if(key=='S') viewer[1]+=1;
	if(key=='z') viewer[2]-=1;
	if(key=='Z') viewer[2]+=1;
	display();
}

void myreshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glFrustum(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,2,20);
	else
		glFrustum(-2,2,-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,2,20);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("My house");
	glClearColor(0.0,0.0,0.0,0.0);
	init();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);//To retain the original color of the objects
	glutReshapeFunc(myreshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glutMainLoop();
}
