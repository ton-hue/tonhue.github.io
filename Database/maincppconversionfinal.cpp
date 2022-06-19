// C++ Query Conversion Using Mongodb, originally from Python.
#include <iostream> //def of objects
#include <string> //standard string
#include <cstdlib> // for purpose functions
#include "mongo/client/dbclient.h" //used to connect c++ to mongodb
#include "mongocxx/database.hpp"//class for connection
#include "mongocxx/uri.hpp" //class for connection
#include "bsoncxx/builder/stream/document.hpp" //to create documents in mongodb
#include "bsoncxx/json.hpp" //for json files
#include "bsoncxx/oid.hpp"// for id's in the database

//will be connecting this to the dockerfile similar to the ipynb file used in
//the orginal artifact.

void run () {
    mongo::DBClientConnection c;
    c.connect("0.0.0.0:54265"); }  //using dbclientconnection from mongo website to connect to local port #.
    // host from cs 340. port number was 54265. This allows handshake for cpp to mongo database


//Connection verification to database put in main class using try method for errors
// during mongodb connection to port number.

int main() //put try method in main to ensure port connection
{
 try {
     run();
     
  std::cout << "Connection Succsessful" << std::endl; } //prints connection succsessful if connected
  
  catch (const mongo::DBException &e) // catch statement made for throw/error
  {
      std::cout << "Caught exception" << e.what() << std::endl;
  } //if caught will print caught exception during connection
  return(0);
}
namespace Conversion{
//strings for contructor to write insert function
constexpr char MongoUri[] = "mongodb://0.0.0.0:54265"; //port connection same from python 
constexpr char Databse [] = "database"; //database from cs 340
constexpr char Collection [] = "animals"; //collection name from cs 340
    
//class made for insert function 
class MongodbQueries {
    public:
    MongoDbHandler()
    : uri(mongocxx::uri(MongoUri)), //initializing uri
    client(mongocxx::client(uri)), //using uri after defining in client
    MongodbQueries(client[Databse]) {} //database contructor
  //creating inserting function to animal collections
  mongocxx::Collection = Databse[animals];
  auto builder = bsoncxx::builder::stream::documents{};
  //made inserts for animal name, id, location using builder
  bsoncxx::document::value::document_add =
  builder << "Animal Name" << "Animal_Name" //insert animal name and insert id
        << "Animal Id" << "Id" << bsoncxx::builder::stream::finalize;
        
  return TRUE; 
}
}
