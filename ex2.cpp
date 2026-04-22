#include <GLUT/glut.h>
#include <OpenGL/gl.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, -0.8f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.8f, -0.8f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.8f);
    glEnd();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cores");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}