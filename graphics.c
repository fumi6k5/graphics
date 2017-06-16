#include "graphics.h"

/* ウィンドウサイズが変更された場合の座標系の再設定 */
void
resize(int w, int h)
{
  glViewport(0, 0, w, h) ; // 新たなウィンドウのすべての領域を表示領域に設定する
  glLoadIdentity() ;
  gluOrtho2D(0, w, 0, h) ; // ウィンドウの左下を原点に設定する。
}

void
redraw()
{
  glClearColor(1.0, 1.0, 1.0, 1.0) ; // ウィンドウの背景色を白にする
  glClear(GL_COLOR_BUFFER_BIT) ; // ウィンドウの背景色を更新する

  display() ; // 利用者定義のグラフィックス描画関数を呼び出す

  glFlush() ; // 描画処理を完了する
}


/* グラフィックス処理の初期化処理 */
void
initGraphics(int argc, char *argv[], int w, int h)
{
  glutInitWindowSize(w, h) ; // ウィンドウの初期サイズを指定する

  glutInit(&argc, argv) ; // グラフィックシステムの初期化を行う
  glutInitDisplayMode(GLUT_RGBA) ; // 色の指定を３原色で行う
  glutCreateWindow(argv[0]) ; // 表示用のウィンドウを作成する
  glutDisplayFunc(redraw) ; // グラフィックス描画用の関数を登録する
  glutReshapeFunc(resize) ; // ウィンドウの大きさが変更された場合の処理関数を登録する
}

/* 点の描画 */
void
drawPoint(int x, int y)
{
  glBegin(GL_POINTS);

  glVertex2d(x, y);

  glEnd();
}

/* 線の描画 */
void
drawLine(int x, int y, int xe, int ye)
{
  glBegin(GL_LINES);

  glVertex2d(x, y);
  glVertex2d(xe, ye);

  glEnd();
}

/* 四角形の描画 */
void
drawRectangle(int x, int y, int w, int h)
{
  glBegin(GL_LINE_LOOP);

  glVertex2d(x, y);
  glVertex2d(x + w, y);
  glVertex2d(x + w, y + h);
  glVertex2d(x, y + h);

  glEnd();
}

/* 中が塗りつぶされた四角形の描画 */
void
fillRectangle(int x, int y, int w, int h)
{
  glBegin(GL_POLYGON);

  glVertex2d(x, y);
  glVertex2d(x + w, y);
  glVertex2d(x + w, y + h);
  glVertex2d(x, y + h);

  glEnd();
}

/* 円の描画 */
void
drawCircle(int x, int y, int r)
{
  int deg ;

  glBegin(GL_LINE_LOOP);

  for (deg = 0; deg < 360; deg += 10) {
    double t = deg/180.0*M_PI ;
    glVertex2d((int)(x + sin(t) * r), (int)(y + cos(t) * r));
  }

  glEnd();
}

/* 中が塗りつぶされた円の描画 */
void
fillCircle(int x, int y, int r)
{
  int deg ;

  glBegin(GL_POLYGON);

  for (deg = 0; deg <= 360; deg += 10) {
    double t = deg/180.0*M_PI ;
    glVertex2d((int)(x + sin(t) * r), (int)(y + cos(t) * r));
  }

  glEnd();
}

/* 折れ線の描画 */
void
drawLines(POINT point[], int n)
{
  int i ;

  glBegin(GL_LINE_STRIP);

  for (i = 0; i < n; i++) {
    glVertex2d(point[i].x, point[i].y);
  }

  glEnd();
}

/* 多角形の描画 */
void
drawPolygon(POINT point[], int n)
{
  int i ;

  glBegin(GL_LINE_LOOP);

  for (i = 0; i < n; i++) {
    glVertex2d(point[i].x, point[i].y);
  }

  glEnd();
}

/* 中が塗りつぶされた多角形の描画 */
void
fillPolygon(POINT point[], int n)
{
  int i ;

  glBegin(GL_POLYGON);

  for (i = 0; i < n; i++) {
    glVertex2d(point[i].x, point[i].y);
  }

  glEnd();
}
