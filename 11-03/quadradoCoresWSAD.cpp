#include <GLUT/glut.h>
#include <OpenGL/gl.h>

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

float r = 1.0f, g = 0.2f, b = 0.5f;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(x, y, 0.0f);
    glColor3f(r, g, b);
    
    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char tecla, int xMouse, int yMouse){
    switch(tecla){
        case 'w':
            y += step;
            break;
        case 's':
            y -= step;
            break;
        case 'a':
            x -= step;
            break;
        case 'd':
            x += step;
            break;

        case '1':
            r = 0.1f; 
            g = 0.5f; 
            b = 0.9f;
            break;
        case '2':
            r = 0.2f; 
            g = 0.8f; 
            b = 0.4f;
            break;
        case '3':
            r = 1.0f; 
            g = 0.2f; 
            b = 0.5f;
            break;
    }
    glutPostRedisplay(); //Redesenhar a cada uso das teclas
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    int mode = GLUT_DOUBLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    glutInitWindowSize(500,500);
    glutCreateWindow("Círculo para o teclado");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
