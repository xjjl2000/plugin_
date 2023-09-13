#include "udpserver/UdpMessage.hpp"

QDataStream &operator<<(QDataStream &output , const UdpMessage &metaInfo){
    output<<metaInfo.topic<<metaInfo.data;
    return output;
}

QDataStream &operator>>(QDataStream &input , UdpMessage &metaInfo){
    input>>metaInfo.topic>>metaInfo.data;
    return input;
}