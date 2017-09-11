#include "keyboard.h"

class MyJavaScriptOperations : public QObject {
    Q_OBJECT
public:
    MyJavaScriptOperations(KeyBoard *k){
 	keyboard = k;
        qDebug() << "In constructor";
    }
 
public slots:
    Q_INVOKABLE
    void submit()
    {
        QVariant f1result = view->page()->mainFrame()->evaluateJavaScript("test()");
        qDebug() << f1result.toString();
    }
 
    Q_INVOKABLE void display(){
 
        qDebug() << "In display method";
 
    }
    KeyBoard *keyborad;
 
};
