#include "udpserver/MyUpdServer.hpp"
#include "udpserver/UdpMessage.hpp"
#include <QtNetwork/QNetworkDatagram>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include "handleserver/HandleFunctionFactory.hpp"

MyUpdServer::MyUpdServer(const std::string& host,int port){
    this->qUdpSocket=new QUdpSocket(this);
    qUdpSocket->bind(QHostAddress(host.c_str()),port);
    //connect(qUdpSocket,&QUdpSocket::readyRead,this,&MyUpdServer::hanleMessage);


}


QUdpSocket *MyUpdServer::getQUdpSocket() const {
    return qUdpSocket;
}


