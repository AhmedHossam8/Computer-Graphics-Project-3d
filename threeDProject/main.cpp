#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>

float yRotated = 0;
void timer(int);
float step=0;
double shiftXaxis = 0;
double shiftZaxis = 0;

void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        shiftXaxis --;
        break;
    case GLUT_KEY_RIGHT:
        shiftXaxis ++;
        break;
    case GLUT_KEY_UP:
        shiftZaxis--;
        break;

    case GLUT_KEY_DOWN:
        shiftZaxis++;
        break;
    }

    if(shiftXaxis >= 11){
        shiftXaxis = -10;
    }
    if(shiftXaxis <= -10){
        shiftXaxis = 10;
    }

}

void triangle()
{

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-1.0f, -1.0f, 1.0f);

    glVertex3f(1.0f, -1.0f, 1.0f);
    // down face
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f(1.0f, -1.0f, -1.0f);
    //back
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    //left
    glColor3f(1.0f, 0.0f, 0.0f); //reed
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    glPopMatrix();
}

void fallingIce(){
    //ice
    glPushMatrix();
    glTranslatef(-4,3,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.08,30,30);
    glPopMatrix();
}

void sun()
{
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(4,4,0);
    glRotatef(yRotated,0.0f, 1.0f, 0.0f);
    glRotatef( 90.0f,0.0f,0.0f,1.0f);
    yRotated+= 0.1f;
    glutSolidSphere(0.7,30,30);
}

void sky()
{
    glPushMatrix();
    glTranslatef(0+step,2.7,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.4,30,30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3+step,2.5,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.4,30,30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3+step,2.5,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.4,30,30);
    glPopMatrix();
}


void iceMan()
{
    //base sphere
    glPushMatrix();
    glTranslatef(0,-3.25,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.6,30,30);
    glPopMatrix();

    //middle sphere
    glPushMatrix();
    glTranslatef(0,-2.3,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.4,30,30);
    glPopMatrix();

    //top sphere
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0,-1.7,0);
    glutSolidSphere(0.2,30,30);
    glPopMatrix();

    //nose
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glTranslatef(0,-1.7,0);
    glutSolidCone(0.1,0.5,30,30);
    glPopMatrix();
}


//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------

void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);

    //falling ice
    glPushMatrix();
    glTranslated(0,-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(1,0.5-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(0.5,-0.5-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(1.5,-1-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(2,0-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(2.5,0-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(3,0.5-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(3.5,1-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(4,0-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(4.5,0.5-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(5,0.5-step,0);
    fallingIce();
    glPopMatrix();

    //falling ice
    glPushMatrix();
    glTranslated(5.5,1-step,0);
    fallingIce();
    glPopMatrix();

    //sun
    glPushMatrix();
    sun();
    glPopMatrix();

    //sky 1
    glPushMatrix();
    sky();
    glPopMatrix();

    //sky 2
    glPushMatrix();
    glTranslatef(-2,1,0);
    sky();
    glPopMatrix();

    //sky 3
    glPushMatrix();
    glTranslatef(-4,-1,0);
    sky();
    glPopMatrix();

    //sky 4
    glPushMatrix();
    glTranslatef(2,0.5,0);
    sky();
    glPopMatrix();

    //sky 5
    glPushMatrix();
    glTranslatef(5,-1,0);
    sky();
    glPopMatrix();

    //iceman 1
    glPushMatrix();
    glTranslatef(-3,-1.5,0);
    glTranslated(shiftXaxis,0,0);
    iceMan();
    glPopMatrix();

    //iceman 2
    glPushMatrix();
    glTranslatef(-0.5,-1.5,0);
    glRotatef(yRotated,0.0f, 1.0f, 0.0f);
    glRotatef( 90.0f,0.0f,-1.0f,0.0f);
    yRotated+= 0.1f;
    iceMan();
    glPopMatrix();

    //triangle
    glPushMatrix();
    glTranslatef(3,-2,0);
    glRotatef(15, 0, 1, 0);
    triangle();
    glPopMatrix();

    //Cube
    glPushMatrix();
    glTranslatef(3,-4,0);
    glRotatef(15, 0, 1, 0);
    glutSolidCube(2);
    glPopMatrix();
    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
//    yRotated += 1;
    glutPostRedisplay();
}

void texture (void)
{

    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("Ahmed Hossam 20200187");

    glutTimerFunc(0,timer,0);
    glClearColor (1.0, 1.0, 1.0, 0.0);

    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);
    glutSpecialFunc(keyboard);

    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    texture();


//    PlaySound("F:\Term 5\Computer Graphics\week 1\threeDProject",SND_ASYNC);
    glutMainLoop();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    step+=0.005;
    if (step>=10){
        step = -10;
    }
}
