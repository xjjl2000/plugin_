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


QDataStream &operator<<(QDataStream &output , const UdpMessage &metaInfo){
    output<<metaInfo.topic<<metaInfo.data;
    return output;
}

QDataStream &operator>>(QDataStream &input , UdpMessage &metaInfo){
    input>>metaInfo.topic>>metaInfo.data;
    return input;
}