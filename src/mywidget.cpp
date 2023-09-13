#include <QNetworkDatagram>
#include "mywidget.h"
#include "UI_rqt_push_button.h"
#include "udpserver/UdpMessage.hpp"
#include "handleserver/HandleFunctionFactory.hpp"


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    myUpdServer=new MyUpdServer(23912);
    connect(myUpdServer->getQUdpSocket(),&QUdpSocket::readyRead,this,&myWidget::hanleMessage);
}

myWidget::~myWidget()
{
    delete myUpdServer;
    delete ui;
}

void myWidget::hanleMessage() {
    if(!myUpdServer->getQUdpSocket()->hasPendingDatagrams()|| myUpdServer->getQUdpSocket()->pendingDatagramSize()<=0)
        return;
    //注意收发两端文本要使用对应的编解码
    qDebug()<<"have msg!";
    QByteArray receivedData;
    receivedData.resize(myUpdServer->getQUdpSocket()->pendingDatagramSize());
    myUpdServer->getQUdpSocket()->readDatagram(receivedData.data(), receivedData.size());
    QNetworkDatagram recv_datagram=myUpdServer->getQUdpSocket()->receiveDatagram();
    UdpMessage udpMessage;
    QDataStream dataStream(&receivedData, QIODevice::ReadOnly);
    dataStream >> udpMessage;
    //hanle
    HandleFunctionFactory(handleFunctionFactory);
    HandleFunctionInterface* func=handleFunctionFactory.getHandleFunction(udpMessage.topic);
    func->run(ui,&udpMessage.data);

}



