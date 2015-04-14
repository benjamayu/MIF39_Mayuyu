
#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"

#include "TcpNetworking/simpletcpendpoint.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
extern void __attach(void);
extern void __attachInterfaces(void);
extern void __attachGenerics(void);
extern void __attachAssets(void);
extern void __attachQImage(void);
extern void __attachWavefront(void);
//typedef basic_istringstream<char> istringstream;
int main ( int argc, char** argv ) {
    /*
    __attach();
    __attachInterfaces();
    __attachGenerics();
    __attachAssets();*/
    __attachQImage();
    __attachWavefront();

//    FileDescriptor file ( argv[1]);
//    SharedResourceList ress = ResourceHolder::Load(file);
//    SharedResourcePtr ptr = ress [0];
//    ByteBuffer message = ResourceHolder::ToBuffer(ptr);


    std::fstream myfile;
    myfile.open(argv[1], std::ios::in);
    if(myfile.is_open()) {

        // sauvegarder la position courante
        long pos = myfile.tellg();
        // se placer en fin de fichier
        myfile.seekg( 0 , std::ios::end );
        // récupérer la nouvelle position = la taille du fichier
        long size = myfile.tellg() ;
        // restaurer la position initiale du fichier
        myfile.seekg( pos,  std::ios::beg );
        unsigned char* buff = new unsigned char[size];
        myfile.read((char*)buff,size);

        ByteBuffer message(buff, size);

        std::istringstream iss( argv[1] );
        std::string mot;
        {
            std::cout << mot << '\n';
        }
        while ( std::getline( iss, mot, '/' ) );
        ByteBuffer nom((unsigned char*)mot.c_str(), strlen(argv[1]));


        SimpleTcpEndPoint::Options options;
//        options.serverIP = "192.168.1.111";
        options.serverIP = "127.0.0.1";
        options.connectionPort = 3000;
        SimpleTcpEndPoint client ( options );
        if ( client.open() == false ) exit ( -1 );
//        //    while ( true ) {
        client.send(nom);
        client.send(message); std::cout << "Sent : " << message.getLength() << " bytes" << std::endl;
        //        client.receive(message); std::cout << "Recv : " << message.getLength() << " bytes" << std::endl;
        //    }
        client.close ();
//        delete buff;
    }
    else {
        std::cout << "BUUUUUUG" << endl;
    }
    return 0;
}