#ifndef UDPMESSAGE_H  
#define UDPMESSAGE_H  

#include<QObject>

struct UdpMessage
{
    public:
        QString topic;
        QByteArray data;
        friend QDataStream &operator<<(QDataStream &output , const UdpMessage &metaInfo);

        friend QDataStream &operator>>(QDataStream &input , UdpMessage &metaInfo);

};



#endif
