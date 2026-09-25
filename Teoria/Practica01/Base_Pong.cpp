#include <GL/gl.h>
#include <GL/glut.h> //the glut file for windows operations
// it also includes gl.h and glu.h for the openGL library calls
#include <math.h>

#define PI 3.1415926535898

double xpos, ypos, ydir, xdir; // x and y position for house to be drawn
double sx, sy, squash;         // xy scale factors
double rot, rdir;              // rotation
double ball_speed;

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

GLfloat RadiusOfBall = 15.;
// Draw the ball, centered at the origin
void draw_ball() {
  glColor3f(0.6, 0.3, 0.);
  MyCircle2f(0., 0., RadiusOfBall);
}

void Display(void) {

  glClear(GL_COLOR_BUFFER_BIT); /* limpiamos la pantalla */

  glLoadIdentity();

  paddles_movement();
  draw_paddles(); /* dibujamos las paletas */

  if (ypos == RadiusOfBall && ydir == -1) {
    sy = sy * squash;

    if (sy < 0.8)
      // reached maximum suqash, now unsquash back up
      squash = 1.1;
    else if (sy > 1.) {
      // reset squash parameters and bounce ball back upwards
      sy = 1.;
      squash = 0.9;
      ydir = 1;
    }
    sx = 1. / sy;

    // 120 is max Y value in our world

  } else {
    // set Y position to increment 1.5 times the direction of the bounce
    ypos += ydir * ball_speed;

    // If ball touches the top, change direction of ball downwards
    if (ypos == 120 - RadiusOfBall) {
      ydir = -1;
    }
    // If ball touches the bottom, change direction of ball upwards
    else if (ypos < RadiusOfBall)
      ydir = 1;
  }

  // reset transformation state
  glLoadIdentity();

  // apply translation
  glTranslatef(xpos, ypos, 0.);

  // Translate ball back to center
  glTranslatef(0., -RadiusOfBall, 0.);
  // Scale the ball about its bottom
  glScalef(sx, sy, 1.);
  // Translate ball up so bottom is at the origin
  glTranslatef(0., RadiusOfBall, 0.);

  T[12] = xpos;
  T[13] = ypos;
  glLoadMatrixf(T); // Aplica la traslación de la pelota

  T1[13] = -RadiusOfBall;
  glMultMatrixf(T1);
  S[0] = sx;
  S[5] = sy;
  glMultMatrixf(S);
  T1[13] = RadiusOfBall;
  glMultMatrixf(T1);

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
  ypos = RadiusOfBall;
  xdir = 1;
  ydir = 1;
  sx = 1.;
  sy = 1.;
  squash = 0.9;
  rot = 0;
  ball_speed = 1.5;
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
