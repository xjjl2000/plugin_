
#ifndef MYUDPSERVER_H  
#define MYUDPSERVER_H  

#include<QtNetwork/QUdpSocket>
#include "UI_rqt_push_button.h"

class MyUpdServer:public QObject{
    private:
        QUdpSocket* qUdpSocket;
public:
    QUdpSocket *getQUdpSocket() const;



    
    public:
        MyUpdServer(int port);


};

#endif