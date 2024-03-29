#include <GL/glut.h>
#include<stdio.h>
#include<conio.h>
#define M_SIDE1 20
#define M_SIDE2 21
#define M_BACK  22
#define M_FRONT 23
#define M_CUSTOM 24
#define SIZE 500
float x_angle = 0.0;
float y_angle = 0.0;
float z_angle = 0.0;
float camera_angle=0.0;
float c=1.0;

GLfloat pos[] = { 0.0, 0.0, -10.0, 1.0 };
GLfloat white[] = { 2.5, 2.5, 6.0, 6.0 };
GLfloat red[] = { 0.7, .4, 0.0, 1.0 };
GLfloat deep_blue[] = { 0.3, 0.3, 0.9, 1.0 };
GLfloat shiny[] = { 50.0 };
GLfloat dull[] = { 0.0 };
GLUquadricObj *Cylinder;
enum { X, Y, Z } axis = X;






void change_view (int sel)
{
switch (sel)
{
	case M_CUSTOM:{printf("ENTER VIEWANGLE:");
                                 		scanf("%f",&camera_angle);};
                                 		break;
	case M_SIDE1: {camera_angle=90;}
                           		break;
case M_SIDE2: camera_angle=-90;
                           		break;
case M_BACK: camera_angle=180;
                           		break;
case M_FRONT:camera_angle=0;
default: break;
}
}

void initialize_menu (void)
{
	glutCreateMenu(change_view );
glutAddMenuEntry("SIDE VIEW 1", 20);
glutAddMenuEntry("SIDE VIEW 2", 21);
glutAddMenuEntry("BACK VIEW", 22);
glutAddMenuEntry("FRONT VIEW", 23);
glutAddMenuEntry("CUSTOM VIEW", 24);
glutAttachMenu(GLUT_MIDDLE_BUTTON);
}



void mouse_button (int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON )
{
		axis=Z; c=c+0.4;
                      printf("WIND SPEED INCREASE\t SPEED=%fKm/Hr\n\n",c*1.5);
                      glutPostRedisplay();
	}
        else if (button == GLUT_RIGHT_BUTTON )
{
                      axis = Z; c=c-0.4;
                      printf("WIND SPEED DECREASE\t SPEED=%fKm/Hr\n\n",c*1.5);
                      glutPostRedisplay();
}
}

void spin(void)
{
         switch (axis)
                  {
                      case X: x_angle += 1.0;
                                   break;
                      case Y: y_angle += 1.0;
                                   break;
                      case Z: z_angle += c ;
                                   break;
                      default: break;
                  }
         glutPostRedisplay();
}

void display (void)
{
	Cylinder = gluNewQuadric();
    	gluQuadricDrawStyle( Cylinder, GLU_FILL);
    	gluQuadricNormals( Cylinder, GLU_SMOOTH);
    	gluQuadricOrientation( Cylinder, GLU_OUTSIDE );
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();
    	glEnable(GL_TEXTURE_2D);
      //Bottom
  	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
                              GL_NEAREST);
   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                               GL_NEAREST);
   	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
  	glBegin(GL_QUADS);
   		glNormal3f(0.0, 1.0f, 0.0f);
   		glTexCoord2f(0.0f, 0.0f);
 		glVertex3f(-25.0,-25.0,-44);
  		glTexCoord2f(0.0f, 1.0f);
   		glVertex3f(-25.0,25.0,-44);
   		glTexCoord2f(1.0f, 1.0f);
   		glVertex3f(25.0,25.0,-44);
   		glTexCoord2f(1.0f, 0.0f);
   		glVertex3f(25.0,-25.0,-44);
   	glEnd();
   	glDisable(GL_TEXTURE_2D);
   	glRotatef(camera_angle,0.0,1.0,0.0);
   	gluCylinder(Cylinder,.4,.4,4,16,20);
  	 glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
   	glPushMatrix();
   	glutSolidTorus (1.4, 1.4,  6,  6);
   	glutSolidCube(2.5);
   	glPushMatrix();
   	glTranslatef(0.0,-2.0,0.0);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red); 
//material property for the base of the windmill
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, red);
   	glPushMatrix();
   	glRotatef(90.0,1.0,0.0,0.0);
  	 glTranslatef(0.0,0.0,-2.0);
   	gluCylinder(Cylinder,1.0,1.5,27,50,50);
   	glPopMatrix();
   	glPopMatrix();
   	glRotatef(z_angle, 0.0, 0.0, 1.0);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, red);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
  	glPushMatrix();
   	glTranslatef(0.0,0.0,1.5);
   	glutSolidCone(1.5,2.5,50,50);
   	glPopMatrix();
   	glPushMatrix();		//blade 1
  	 glTranslatef(0.0,0.0,2.2);
   	glRotatef(90.0,1.0,0.0,0.0);
  	 glPushMatrix();
   	glRotatef(120,0.0,1.0,0.0);
   	glutSolidCone(0.9, 16.0, 15, 15);
   	glPopMatrix();
   	glPopMatrix();
   	glPushMatrix();		//blade 2
   	glTranslatef(0.0,0.0,2.2);
   	glRotatef(90.0,1.0,0.0,0.0);
   	glPushMatrix();
   	glRotatef(-120,0.0,1.0,0.0);
   	glutSolidCone(0.9, 16.0, 15, 15);
   	glPopMatrix();
  	 glPopMatrix();
  	 glPushMatrix();		 //blade 3 
   	glTranslatef(0.0,0.0,2.2);
  	 glRotatef(90.0,1.0,0.0,0.0);
   	glutSolidCone(0.9, 16.0, 15, 15);
   	glPopMatrix();
   	glLightfv(GL_LIGHT1, GL_POSITION, pos);
   	glutSwapBuffers();
}

void init (void)
{
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-25.0, 25.0, -25.0, 25.0, -250.0, 250.0);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glEnable(GL_NORMALIZE);
}




void special (int key, int x, int y) 
{
	switch (key)
{
case GLUT_KEY_LEFT: {axis = X; camera_angle--;
                                                         printf("\n\nVIEW ANGLE=%f", camera_angle);};
						glutPostRedisplay();
						break;
case GLUT_KEY_RIGHT: {axis = Y; camera_angle++;
printf("\n\nVIEW ANGLE=%f", camera_angle);};
		  				glutPostRedisplay();
		  				break;
case GLUT_KEY_UP: c=c+0.4; 
                                                      		glutPostRedisplay();
                                                     		 break;	
               	case GLUT_KEY_END:  exit(0); 	
            	case GLUT_KEY_DOWN:{c=c-0.4;};
  	  					glutPostRedisplay();
		 				 break;
               	default: break;
              }
}

void reshape (int width, int height)
{
GLfloat w, h;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
        	glLoadIdentity();
        	if (width > height)
{
w = (25.0 * width) / height;
h = 25.0;
}
else
{
w = 25.0;
 h = (25.0 * height) / width;
}
glOrtho(-w, w, -h, h, -250.0, 250.0);
glutPostRedisplay();
 }

void main (int argc, char *argv[ ])
{
glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
       	glutInitWindowSize(SIZE, SIZE);
       	glutInitWindowPosition(100, 50);
       	glutCreateWindow("SIMULATION OF WINDMILL");
       	glutIdleFunc(spin);
      	glutDisplayFunc(display);
       	glutSpecialFunc(special);
       	glutMouseFunc(mouse_button);
       	initialize_menu();
       	glutReshapeFunc(reshape);
init();
	glEnable(GL_DEPTH_TEST);
       	glutMainLoop();
}



