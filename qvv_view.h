
#ifndef _QVV_VIEW_H_
#define _QVV_VIEW_H_

#include <QWidget>
#include <QString>
#include <QPixmap>

class QvvMainWindow;

class QvvView : public QWidget
{
    Q_OBJECT

    int xpos;
    int ypos;
    QvvMainWindow *mw;

    QPixmap *pm;

    QString file_name;

    int opt_fit;
    int opt_center;
    int loaded;
    int scale; // in %'s

    int mouse_pan;
    int mouse_pan_x;
    int mouse_pan_y;

    int rotation;

  public:

    QvvView( QvvMainWindow* a_mw );
    ~QvvView();

    void load( QString fn );
    void reView( int a_scale );
/*
    void moverel( int dx, int dy );
    void moveabs( int ax, int ay );

    void statusMsg( const char* msg );

*/
    QvvMainWindow* getMainWindow( QString fn );

    void moverel( int dx, int dy );

  public slots:
    void slotCenter();

    void slotHelp();

  protected:
    void keyPressEvent ( QKeyEvent * e );
    void paintEvent( QPaintEvent * e );
/*
    void mousePressEvent ( QMouseEvent * e );
    void mouseReleaseEvent ( QMouseEvent * e );
    void mouseMoveEvent ( QMouseEvent * e );
    void closeEvent( QCloseEvent * e ) { ViewX = xpos; ViewY = ypos; QWidget::closeEvent( e ); };
*/
};

#endif
