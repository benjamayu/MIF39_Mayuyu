#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"

#include "TcpNetworking/simpletcpstartpoint.hpp"

<<<<<<< HEAD
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string>
=======
extern void __attach(void);
extern void __attachInterfaces(void);
extern void __attachGenerics(void);
extern void __attachAssets(void);
extern void __attachQImage(void);
extern void __attachWavefront(void);
>>>>>>> 495213c1f7c6d3b98ce96db118545178e72d888c

int main ( int argc, char** argv ) {
    /*
    __attach();
    __attachInterfaces();
    __attachGenerics();
    __attachAssets();*/
    __attachQImage();
    __attachWavefront();

    ResourceHolder::Import( argv[1] );

    QUuid fake;
    SimpleTcpStartPoint::Options options;
    options.connectionPort = 3000;
<<<<<<< HEAD
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
