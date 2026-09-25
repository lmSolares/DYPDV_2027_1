#include <GL/gl.h>
#include <GL/glut.h> //the glut file for windows operations
// it also includes gl.h and glu.h for the openGL library calls
#include <math.h>
#include <string>

#define PI 3.1415926535898

double xpos, ypos, ydir, xdir; // x and y position for house to be drawn
double rot, rdir;              // rotation
double ball_speed;

/* score */
int score_p1 = 0;
int score_p2 = 0;
bool is_paused = false;

/* paddle players */
const double paddle_width = 3;
const double paddle_height = 20;
const double paddle_speed = 2.5;

/* player left */
const double pl_pos_x = 10;
double pl_pos_y = 60;

/* player right */
const double pr_pos_x = 150;
double pr_pos_y = 60;

/* keyboard */
bool keyStates[256] = {false};
bool specialKeyStates[256] = {false};

GLfloat T1[16] = {1., 0., 0., 0., 0., 1., 0., 0.,
                  0., 0., 1., 0., 0., 0., 0., 1.};
GLfloat S[16] = {1., 0., 0., 0., 0., 1., 0., 0.,
                 0., 0., 1., 0., 0., 0., 0., 1.};
GLfloat T[16] = {1., 0., 0., 0., 0., 1., 0., 0.,
                 0., 0., 1., 0., 0., 0., 0., 1.};

#define PI 3.1415926535898
GLint circle_points = 100;
void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius) {
  GLint i;
  GLdouble angle;
  glBegin(GL_POLYGON);
  for (i = 0; i < circle_points; i++) {
    angle = 2 * PI * i / circle_points;
    glVertex2f(centerx + radius * cos(angle), centery + radius * sin(angle));
  }
  glEnd();
}

void draw_paddles() {
  glRectf(pl_pos_x - paddle_width, pl_pos_y - paddle_height,
          pl_pos_x + paddle_width, pl_pos_y + paddle_height);

  glRectf(pr_pos_x - paddle_width, pr_pos_y - paddle_height,
          pr_pos_x + paddle_width, pr_pos_y + paddle_height);
}

void paddles_movement() {
  // jugador izquierdo
  if ((keyStates['w'] || keyStates['W']) && pl_pos_y + paddle_height < 120) {
    pl_pos_y += paddle_speed;
  }
  if ((keyStates['s'] || keyStates['S']) && pl_pos_y - paddle_height > 0) {
    pl_pos_y -= paddle_speed;
  }

  // jugador derecho
  if (specialKeyStates[GLUT_KEY_UP] && pr_pos_y + paddle_height < 120) {
    pr_pos_y += paddle_speed;
  }
  if (specialKeyStates[GLUT_KEY_DOWN] && pr_pos_y - paddle_height > 0) {
    pr_pos_y -= paddle_speed;
  }
}

GLfloat RadiusOfBall = 8.;
// Draw the ball, centered at the origin
void draw_ball() {
  glColor3f(0.6, 0.3, 0.);
  MyCircle2f(0., 0., RadiusOfBall);
}

void resume_game(int value) { is_paused = false; }

void draw_text(std::string text, float x, float y) {
  glRasterPos2f(x, y);
  for (char c : text) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
  }
}

void Display(void) {

  glClear(GL_COLOR_BUFFER_BIT); /* limpiamos la pantalla */

  glLoadIdentity();

  paddles_movement();
  draw_paddles(); /* dibujamos las paletas */

  glColor3f(1.0, 1.0, 1.0);
  draw_text(std::to_string(score_p1), 40, 110);
  draw_text(std::to_string(score_p2), 120, 110);

  /* movimiento de la pelota */
  if (!is_paused) {
    xpos += xdir * ball_speed;
    ypos += ydir * ball_speed;
  }

  // rebote en el techo y suelo
  if (ypos >= 120 - RadiusOfBall) {
    ydir = -1; // cambiamos la direccion hacia abajo
  } else if (ypos <= RadiusOfBall) {
    ydir = 1; // cambiamos la dirección hacia arriba
  }

  /* rebote con la paleta izqueirda */
  if (xdir == -1 && xpos - RadiusOfBall <= pl_pos_x + paddle_width &&
      xpos + RadiusOfBall >= pl_pos_x - paddle_width &&
      ypos - RadiusOfBall <= pl_pos_y + paddle_height &&
      ypos + RadiusOfBall >= pl_pos_y - paddle_height) {
    xdir = 1;
  }

  /* rebote con la paleta derecha */
  if (xdir == 1 && xpos + RadiusOfBall >= pr_pos_x - paddle_width &&
      xpos - RadiusOfBall <= pr_pos_x + paddle_width &&
      ypos - RadiusOfBall <= pr_pos_y + paddle_height &&
      ypos + RadiusOfBall >= pr_pos_y - paddle_height) {
    xdir = -1;
  }

  // sistema para los puntos
  if (xpos < 0) {
    score_p2++;
    // Si sale por la izquieorda, es punto para el jugador derecho
    xpos = 80;
    ypos = 60; // se regresa la pelota al estado inicial
    xdir = 1;
    is_paused = true;
    glutTimerFunc(1000, resume_game, 0); // hay una pausa de 1 segundo
  } else if (xpos > 160) {
    score_p1++;
    // si sale por la derecha, es punto para el jugador izquierdo
    xpos = 80;
    ypos = 60; // se regresa la pelota
    xdir = -1;
    is_paused = true;
    glutTimerFunc(1000, resume_game, 0);
  }

  glLoadIdentity();
  glTranslatef(xpos, ypos, 0.0f);
  draw_ball();

  glutSwapBuffers(); /* intercambiar buffers */
  glutPostRedisplay();
}

void reshape(int w, int h) {
  // on reshape and on startup, keep the viewport to be the entire size of the
  // window
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // keep our logical coordinate system constant
  gluOrtho2D(0.0, 160.0, 0.0, 120.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init(void) {
  // set the clear color
  glClearColor(0.0, 0.8, 0.0, 1.0);
  // initial position set to 0,0
  xpos = 80;
  ypos = 60;
  xdir = 1;
  ydir = 1;
  rot = 0;
  ball_speed = 0.8;
}

/* Detección de teclas */
// Controles del jugador izquierdo (detecta w y s)
void keyboardDown(unsigned char key, int x, int y) { keyStates[key] = true; }

void keyboardUp(unsigned char key, int x, int y) { keyStates[key] = false; }

// Controles del jugador derecho (detecta flechas)
void specialDown(int key, int x, int y) { specialKeyStates[key] = true; }

void specialUp(int key, int x, int y) { specialKeyStates[key] = false; }

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(320, 240);
  glutCreateWindow("Bouncing Ball");
  init();
  glutDisplayFunc(Display);
  glutReshapeFunc(reshape);

  glutKeyboardFunc(keyboardDown);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(specialDown);
  glutSpecialUpFunc(specialUp);

  glutMainLoop();

  return 1;
}
