
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
    myfile.open(argv[1]);
    if(myfile.is_open()) {

        long pos = myfile.tellg();
        myfile.seekg( 0 , std::ios::end );
        long size = myfile.tellg();
        myfile.seekg (pos, std::ios::beg);

        std::cout << size << std::endl;

        unsigned char* buff = new unsigned char[size];
        myfile.read((char*)buff,size);

        ByteBuffer message(buff, size);

        // parser la chaine pour recuperer uniquement le nom
        std::istringstream iss( argv[1] );
        std::string mot;
        {
            // RIEN
        }
        while ( std::getline( iss, mot, '/' ) );
        std::cout << "NOM " << mot << " taille : " << mot.length() << std::endl;
        ByteBuffer nom((unsigned char*)mot.c_str(), mot.length());

        SimpleTcpEndPoint::Options options;
//        options.serverIP = "192.168.1.111";
        options.serverIP = "127.0.0.1";
        options.connectionPort = 3000;
        SimpleTcpEndPoint client ( options );
        if ( client.open() == false ) exit ( -1 );
        client.send(nom);
        client.send(message); std::cout << "Sent : " << message.getLength() << " bytes" << std::endl;
        client.close ();
        delete buff;
    }
    else {
        std::cout << "Erreur lors de l'ouverture dur fichier" << endl;
    }
    return 0;
}
