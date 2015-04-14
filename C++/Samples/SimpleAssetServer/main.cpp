#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"

#include "TcpNetworking/simpletcpstartpoint.hpp"

#include <fstream>
#include <iostream>
#include <unistd.h>

int main ( int argc, char** argv ) {
    QUuid fake;
    SimpleTcpStartPoint::Options options;
    options.connectionPort = 3000;
    options.maximumConnectedClients = 10;
    SimpleTcpStartPoint server ( options );
    server.start();
    QUuid client;
    while ( true ) {
        while ( client == fake ) {
            client = server.listen();
        }
        ByteBuffer temp;
        ByteBuffer message;
        server.receive(client,temp);
        char* nom = (char*)temp.getData();
        server.receive(client,message); std::cout << "Recv : " << message.getLength() << " bytes" << std::endl;

        std::fstream myfile;
        myfile.open(nom, std::ios::out);
        if(myfile.is_open()) {
            myfile.write((char *)message.getData(), message.getLength());
            myfile.close();
        }
        else {
            std::cout << "BUG" << std::endl;
        }
//        std::cout << message.getData() << std::endl;
//        server.send(client,message); std::cout << "Sent : " << message.getLength() << " bytes" << std::endl;
        client = fake;
    }
    server.stop ();
    return 0;
}
