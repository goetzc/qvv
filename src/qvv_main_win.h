/****************************************************************************
**
**  QVV Image Viewer
**  Copyright (c) 1999-2020 Vladi Belperchinov-Shabanski
**  <cade@bis.bg> <shabanski@gmail.com> <cade@cpan.org>
**  http://cade.datamax.bg/qvv/
**
****************************************************************************/

#ifndef _QVV_MAIN_WIN_H_
#define _QVV_MAIN_WIN_H_

#include <QMainWindow>
#include <QTreeWidget>
#include <QDir>
#include <QMenu>
#include <QToolBar>
#include <QString>
#include <QDialog>
#include <QPushButton>

#include "ui_qvv_form_confirm_delete.h"

class QvvView;

class QvvConfirmDeleteDialog : public QDialog
{

     Q_OBJECT

  public:
     Ui_ConfirmDelete cd;

     QDialogButtonBox::StandardButton activated_button;

     QvvConfirmDeleteDialog();

  public slots:

     int exec();

     void buttonYes()      { activated_button = QDialogButtonBox::Yes;      };
     void buttonYesToAll() { activated_button = QDialogButtonBox::YesToAll; };
     void buttonNo()       { activated_button = QDialogButtonBox::No;       };
     void buttonCancel()   { activated_button = QDialogButtonBox::Cancel;   };

};

class QvvTreeWidget : public QTreeWidget
{

     Q_OBJECT
     
 public:
     QvvTreeWidget( QWidget *parent );

     void findNext( QString str, int full_match = 0 );

 protected:
     void keyPressEvent( QKeyEvent *event );
     void mousePressEvent( QMouseEvent *event );
     void mouseMoveEvent( QMouseEvent *event );
};

class QvvMainWindow : public QMainWindow
{

     Q_OBJECT

     QToolBar *toolbar;

     int rand_seeded;

     QPoint drag_start_pos;

 public:

     QvvTreeWidget   *tree;

     QList<QvvView*> views;

     QDir            cdir;

     int             last_sort_col;
     Qt::SortOrder   last_sort_ord;

     int             opt_thumbs;
     int             opt_dirs_only;
     
     int last_vx;
     int last_vy;

     QvvMainWindow();
     ~QvvMainWindow();

     void closeAllViews();

     void loadDir( QString path );
     void goToDir( int mode );

     void loadThumbs();

     void goPrevNext( int r, int skip_dirs = 1 );
     void goPrevNextDir( int r );

     void setActiveView( QvvView *view );
     void closeView( QvvView *view );

     void sortColumn( int n );

     int deleteItems( int current_only );

 protected:
     void showEvent( QShowEvent *event );
     void keyPressEvent( QKeyEvent *event );
     void mousePressEvent( QMouseEvent *event );
     void mouseMoveEvent( QMouseEvent *event );

 public slots:
     void toggleSortColumns();

     void enter( QTreeWidgetItem *item );
     void enterCurrent();
     void enterAllSelected();

     void actionTriggered(QAction *action);
     void switchLayoutDirection();

     void slotItemActivated( QTreeWidgetItem *item, int column );

     void slotNewWindow();
     void slotGoUp();
     void slotThumbs();
     void slotCreateThumbs();
     void slotJPEGThumbs();
     void slotSmoothThumbs();
     void slotDirThumbs();

     void slotUseToolbar();
     void slotToggleToolbar();

     void slotChangeDir();
     void slotHomeDir();
     void slotReloadDir();
     void slotShowDirsOnly();

     void slotGoNext();
     void slotGoPrev();

     void slotGoNextDir();
     void slotGoPrevDir();

     void slotSortColumn1();
     void slotSortColumn3();

     void slotRandomItem();

     void slotHelp();
     void slotAbout();

     void slotDeleteSelected();
     void slotDeleteCurrent();

 private:
     void setupMenuBar();
};

#endif
