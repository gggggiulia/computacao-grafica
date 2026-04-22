#include <GLUT/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.9f, 0.0f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.0f, 1.0f);
    glVertex2f(-0.3f, -0.8f);
    glVertex2f(-0.6f, -0.8f);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.3f, -0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(0.0f, 0.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.4f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.3f, -0.4f);
    glVertex2f(0.7f, -0.4f);
    glVertex2f(0.7f, -0.1f);
    glEnd();

    glTranslatef(0.0f, 0.5f, 0.0f);
    glutSolidSphere(0.1, 32, 32);

    glutSwapBuffers();
}

int main(int argc, char** argv){
    int mode = GLUT_DOUBLE | GLUT_RGB;
    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Casinha");

    glutDisplayFunc(display);

    glutMainLoop();
}
