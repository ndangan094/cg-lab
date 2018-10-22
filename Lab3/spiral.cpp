#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <fstream>
#include <iostream>
#include <wtypes.h>
#include <math.h>
using namespace std;
#define radian 3.141592652/180.0
#define SIZEBOARD 720 // kich thuoc window


typedef GLfloat twodimpoint[2];
float radius = 1; // more than this gets ugl
int limit = 4;
void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    gluOrtho2D(-3, 3, -3, 3);
    //GetDesktopResolution();
    //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void glFermatSpiral()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
	float a = 0.05;
	float b = 0.2;
	float thetaStart = 1.0;
	float thetaEnd = 25.0;
	unsigned int samples = 200;
    float dt = (thetaEnd - thetaStart) / (float)samples;

    for( unsigned int i = 0; i <= samples; ++i )
    {
        // archimedean spiral
        float theta = thetaStart + (i * dt);
        // Specific to made a Fermat Spiral.
        float r = sqrt( theta );
        // polar to cartesian
        float x = r * cos( theta );
        float y = r * sin( theta );
        // Square root means two solutions, one positive and other negative. 2 points to be drawn.
        glVertex2f( x, y );
        x = -r * cos( theta );
        y = -r * sin( theta );
        glVertex2f( x, y );
    }

    glEnd();
    glutSwapBuffers();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(SIZEBOARD, SIZEBOARD);
    glutInitWindowPosition(300, 0);

    glutCreateWindow("LSpiral");
    glutDisplayFunc(glFermatSpiral);
    initGL();

    glutMainLoop();

}

