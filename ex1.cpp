#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void desenhaPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x / 200.0f, y / 200.0f); 
    glEnd();
}

void algoritmoBresenham(int x1, int y1, int x2, int y2, bool pontilhado) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int stepX = (x1 < x2) ? 1 : -1;
    int stepY = (y1 < y2) ? 1 : -1;
    int erro = dx - dy;

    int contador = 0; 

    while (true) {
        if (!pontilhado || (contador % 16 < 8)) {
            desenhaPixel(x1, y1);
        }
        contador++;

        if (x1 == x2 && y1 == y2) break;

        int erro2 = 2 * erro;
        if (erro2 > -dy) {
            erro -= dy;
            x1 += stepX;
        }
        if (erro2 < dx) {
            erro += dx;
            y1 += stepY;
        }
    }
}

void desenhaCurvaComBresenham(int cx, int cy, int rx, int ry, float a1, float a2, int segs) {
    float passo = (a2 - a1) / segs;
    for (int i = 0; i < segs; i++) {
        float t1 = a1 + i * passo;
        float t2 = a1 + (i + 1) * passo;
        
        int x_ini = cx + (int)(std::cos(t1) * rx);
        int y_ini = cy + (int)(std::sin(t1) * ry);
        int x_fim = cx + (int)(std::cos(t2) * rx);
        int y_fim = cy + (int)(std::sin(t2) * ry);

        algoritmoBresenham(x_ini, y_ini, x_fim, y_fim, true);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f); 

    glPointSize(3.0f); 

    desenhaCurvaComBresenham(0, 0, 80, 60, 0, M_PI, 15);

    desenhaCurvaComBresenham(0, 0, 180, 40, 0, 2 * M_PI, 30);
    desenhaCurvaComBresenham(0, -15, 180, 45, M_PI, 2 * M_PI, 20);

    desenhaCurvaComBresenham(0, -55, 70, 15, M_PI, 2 * M_PI, 12);

    algoritmoBresenham(-180, 0, -180, -15, true);
    algoritmoBresenham(180, 0, 180, -15, true);

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
    glutInitWindowSize(700, 700);
    glutCreateWindow("Nave");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}