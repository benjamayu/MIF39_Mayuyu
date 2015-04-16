#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"

#include "TcpNetworking/simpletcpstartpoint.hpp"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string>

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
        char* nom = new char[temp.getLength()+1];
        nom = (char*)temp.getData();std::cout << "Nom : " << temp.getData() <<  " taille : " << temp.getLength() << " || " << strlen((char*)temp.getData())  << std::endl;
        nom[temp.getLength()] = '\0';
        server.receive(client,message); std::cout << "Recv : " << message.getLength() << " bytes" << std::endl;

        std::fstream myfile;
        myfile.open((char *)temp.getData(), std::ios::out);
        if(myfile.is_open()) {
            myfile.write((char *)message.getData(), message.getLength());
            myfile.close();
        }
        else {
            std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        }
        client = fake;
        //delete nom;
    }
    server.stop ();
    return 0;
}
