////////////////////////////////////////
//  File      : dateclock.h           //
//  Written by: g_cigala@virgilio.it  //
//  Copyright : GPL                   //
////////////////////////////////////////

// date and clock on systray

////////////////////////////////////////

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "defs.h"

class QWebView;


////////////////////////////////////////

class KeyBoard : public QFrame
{
    Q_OBJECT

public:
    KeyBoard(QWebView *v,QWidget *parent=0);
    ~KeyBoard();
    void toggle();

public slots:
	void buttonClicked(int key);

private : 
    bool visible;
    QWebView *view;
};

#endif
