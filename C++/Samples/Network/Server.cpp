#include <iostream>
#include <thread>
#include <vector>
#include "TcpNetworking/simpletcpstartpoint.hpp"

class Client {
	public:
	Client(QUuid quuid,std::thread *thread):quuid(quuid),thread(thread){}
	QUuid getQUuid(){
		return quuid;
	}
	std::thread& getThread(){
		return *thread;
	}
	private:
	QUuid quuid;
	std::thread *thread;
};

SimpleTcpStartPoint *server;
//std::vector<Client> clients;

void ServerThread(QUuid client){
	while(true){
		ByteBuffer message;
		if(!server->receive(client,message))break;
		server->send(client,message);
		std::cout << "Recv/Sent : " << message.getLength() << " bytes" << std::endl;
	}
	std::cout<<"Thread closed"<<std::endl;
}

int main(int argc,char **argv){
	SimpleTcpStartPoint::Options options;
	options.connectionPort=3000;
	options.maximumConnectedClients=16;
	server=new SimpleTcpStartPoint(options);
	server->start();
	while(true){
		QUuid quuid=server->listen();
		std::thread *thread=new std::thread(ServerThread,quuid);
		//Client client(quuid,&thread);
		//clients.push_back(client);
		std::cout<<"Un client s'est connecté"<<std::endl;
	}	
	server->stop();
	delete server;
	return 0;
}
	
