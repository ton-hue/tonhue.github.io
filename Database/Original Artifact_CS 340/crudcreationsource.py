#CRUD creation for mongodb - python **source code

from pymongo import MongoClient
from bson.objectid import ObjectId

from bson import json_util



class CRUD():

#Connection

    def __init__(self, username, password):
        #print('Attempting to connect. . . ')
        try:
            self.client = MongoClient('mongodb://%s:%s@localhost:54265/AAC2' % (Admin, Doritos))
            self.database = self.client.AAC2
            self.collection = self.database.animals

            #print("Connected successfully!")
        except:
            print("Could not Connect to MongoDB.")
            
#Create

    def create(username, password, createInput):
        
        print('Attempting to Create. . . ')
        try:
            mongoConnection = CRUD(username, password)
            mongoConnection.collection.insert(createInput)
            print('Creation successful!')
        except:
            print('Creation failed.')
    
#Read

    def readOne(username, password, readFilter):
        print('Attempting to Read. . . ')
        try:
            mongoConnection = CRUD(username, password)
            cursor = mongoConnection.collection.find_one(readFilter, {"_id":False})
            print(cursor)
            print('Reading successful!')
            #return json.loads(json_util.dumps(cursor))
            return cursor
        except:
            cursor = 'Reading failed'
            return cursor
        
#Read Many

    def readMany(username, password, readFilter):
        print('Attempting to Read. . . ')
        try:
            mongoConnection = CRUD(username, password)
            cursor = mongoConnection.collection.find(readFilter, {"_id":False})
            #for record in cursor:
                #print(record)
            print('Reading successful!')
            #return json.loads(json_util.dumps(cursor))
            return cursor
        except:
            print('Reading failed.')
#Update

    def update(username, password, updateFilter, updateInput):
        print('Attempting to Update. . . ')
        try:
            mongoConnection = CRUD(username, password)
            cursor = mongoConnection.collection.find(updateFilter)
            for record in cursor:
                mongoConnection.collection.update(updateFilter, { "$set": updateInput})
            print('Update successful!')        
        except:
            print('Update failed.')
#Delete  
         
    def delete(username, password, deleteFilter):
        print('Attempting to Delete. . . ')
        try:
            mongoConnection = CRUD(username, password)
            cursor = mongoConnection.collection.find(deleteFilter)
            for record in cursor:
                mongoConnection.collection.remove(deleteFilter)
            print('Deletion successful!')
        except:
            print('Deletion failed.')