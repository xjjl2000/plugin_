#include "udpserver/MyUpdServer.hpp"
#include "udpserver/UdpMessage.hpp"
#include <QtNetwork/QNetworkDatagram>


MyUpdServer::MyUpdServer(int port){
    this->qUdpSocket=new QUdpSocket(this);
    qUdpSocket->bind(QHostAddress::Any,port);
    //connect(qUdpSocket,&QUdpSocket::readyRead,this,&MyUpdServer::hanleMessage);


}


QUdpSocket *MyUpdServer::getQUdpSocket() const {
    return qUdpSocket;
}


