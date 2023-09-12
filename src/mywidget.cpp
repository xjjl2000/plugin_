#include "mywidget.h"
#include "./UI_rqt_push_button.h"
#include <QtNetwork/QNetworkDatagram>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    updServer=new QUdpSocket(this);
    updServer->bind(QHostAddress::Any,23912);
    connect(updServer,&QUdpSocket::readyRead,this,[this](){
        if(!updServer->hasPendingDatagrams()||
                        updServer->pendingDatagramSize()<=0)
                    return;
                //注意收发两端文本要使用对应的编解码
                QByteArray receivedData;
                 receivedData.resize(updServer->pendingDatagramSize());
                updServer->readDatagram(receivedData.data(), receivedData.size());



                auto recv_datagram=updServer->receiveDatagram();
                QPixmap pixmap;
                QDataStream dataStream(&receivedData, QIODevice::ReadOnly);
                dataStream >> pixmap;

                ui->label_image->setPixmap(pixmap);
                //qDebug()<<"1";
                //qDebug()<<QString::number(pix)<<'\n';


//                ui->textRecv->append(QString("[%1:%2]")
//                                     .arg(recv_datagram.senderAddress().toString())
//                                     .arg(recv_datagram.senderPort()));
//                ui->textRecv->append(recv_text);
    });





}

myWidget::~myWidget()
{
    delete ui;
}

