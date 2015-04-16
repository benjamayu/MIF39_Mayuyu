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
        char* nom = (char*)temp.getData();std::cout << "Nom : " << temp.getData() << std::endl;
        server.receive(client,message); std::cout << "Recv : " << message.getLength() << " bytes" << std::endl;

        std::fstream myfile;
        myfile.open(nom, std::ios::out);
        if(myfile.is_open()) {
            myfile.write((char *)message.getData(), message.getLength());
            myfile.close();
        }
        else {
            std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        }
        client = fake;
    }
    server.stop ();
    return 0;
}
