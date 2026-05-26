// main.cpp
#include <GL/glut.h>
#include "ParticleSystem.h"

ParticleSystem particleSystem;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    particleSystem.update();
    particleSystem.render();
    glutSwapBuffers();
}

void idle() {
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(5.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Particle System");
    
    init();
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
